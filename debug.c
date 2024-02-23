#include "debug.h"
#include "chunk.h"
#include "value.h"

void disassembleChunk(Chunk *chunk, const char *title) {
	printf("\n--------------------------------------------------------------\nChunk: %s\n", title);
	for (int i = 0; i < chunk->count;) {
		i = disassembleInstruction(chunk, i);
	}
}

static int simpleInstruction(const char* name, int offset) {
	printf("%s\n", name);
	return offset + 1;
}

static int constantInstruction(const char* name, Chunk* chunk, int offset) {
	uint8_t constant = chunk->code[offset + 1];
	printf("%-8s %4d ", name, constant);
	printValue(chunk->constants.values[constant]);	
	printf("\n");
	return offset + 2;
}

static int lConstantInstruction(const char* name, Chunk* chunk, int offset) {
	uint8_t constant = chunk->code[offset + 1];
	printf("%-8s %4d ", name, constant);
	printLValue(chunk->long_constants.values[constant]);
	printf("\n");
	return offset + 2;
}

int disassembleInstruction(Chunk *chunk, int offset) {
	printf("\t%04d ", offset);

	int line = getLine(chunk, offset);
	printf("%d ", line);

	uint8_t instruction = chunk->code[offset];
	switch(instruction) {
		case OP_CONSTANT_LONG:
			return lConstantInstruction("OP_CONSTANT_LONG", chunk, offset);
		case OP_CONSTANT:
			return constantInstruction("OP_CONSTANT", chunk, offset);
		case OP_RETURN:
			return simpleInstruction("OP_RETURN", offset);
		default:
			printf("\tOPERATION CODE NOT RECOGNIZED %d", instruction);
			return offset + 1;
	}

	return offset++;
}

int getLine(Chunk* chunk, int index) {
	int opcodes = 0;
	int line = 0;
	for (int i = 0; i < chunk->lines; i++) {
		opcodes += chunk->line_quantity[i];
		if (index < opcodes) {
			line = chunk->line_numbers[i];
			break;
		}
	}
	return line;
}
