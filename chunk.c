#include "chunk.h"
#include "memory.h"
#include "value.h"

void initChunk(Chunk *chunk) {
	chunk->count = 0;
	chunk->capacity = 0;
	chunk->lines = 0;
	chunk->code = NULL;
	chunk->line_numbers = NULL;
	chunk->line_quantity = NULL;
	initValueArray(&chunk->constants);
	initLValueArray(&chunk->long_constants);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
	if (chunk->count + 1 >= chunk->capacity) {
		int old_capacity = chunk->capacity;
		chunk->capacity = GROW_CAPACITY(old_capacity);
		chunk->code = GROW_ARRAY(uint8_t, chunk->code, old_capacity, chunk->capacity);
	}

	if (chunk->line_numbers == NULL && chunk->line_quantity == NULL) {
		chunk->line_numbers = (int*)malloc(sizeof(int) * 1);
		chunk->line_quantity = (int*)malloc(sizeof(int) * 1);

		chunk->line_numbers[0] = line;
		chunk->line_quantity[0] = 1;
		chunk->lines++;
		chunk->code[chunk->count] = byte;
		chunk->count++;
		return;
	}

	if (chunk->line_numbers[chunk->lines - 1] == line) {
		chunk->line_quantity[chunk->lines - 1]++;
	} else {
		chunk->lines++;
		chunk->line_numbers = (int*)realloc(chunk->line_numbers, chunk->lines * sizeof(int));
		chunk->line_quantity = (int*)realloc(chunk->line_quantity, chunk->lines * sizeof(int));
		chunk->line_numbers[chunk->lines - 1] = line;
		chunk->line_quantity[chunk->lines - 1] = 1;
	}

	chunk->code[chunk->count] = byte;
	chunk->count++;
}

int addConstant(Chunk *chunk, Value value) {
	writeValueArray(&chunk->constants, value);
	return chunk->constants.count - 1;
}

int addLConstant(Chunk *chunk, LValue value) {
	writeLValueArray(&chunk->long_constants, value);
	return chunk->long_constants.count - 1;
}

void freeChunk(Chunk *chunk) {
	FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
	FREE_ARRAY(int, chunk->line_numbers, chunk->lines);
	FREE_ARRAY(int, chunk->line_quantity, chunk->lines);
	freeValueArray(&chunk->constants);
	freeLValueArray(&chunk->long_constants);
	initChunk(chunk);
}
