#include "chunk.h"
#include "common.h"
#include "debug.h"

int main(int argc, const char* argv[]) {
	Chunk chunk;
	initChunk(&chunk);

	int constant = addConstant(&chunk, 38);
	writeChunk(&chunk, OP_CONSTANT, 43);
	writeChunk(&chunk, constant, 43);
	int constant2 = addConstant(&chunk, 18);
	writeChunk(&chunk, OP_CONSTANT, 53);
	writeChunk(&chunk, constant2, 53);
	int constant3 = addConstant(&chunk, 4743957);
	writeChunk(&chunk, OP_CONSTANT, 57);
	writeChunk(&chunk, constant3, 57);
	int constant4 = addLConstant(&chunk, 3979328);
	writeChunk(&chunk, OP_CONSTANT_LONG, 58);
	writeChunk(&chunk, constant4, 58);

	writeChunk(&chunk, OP_RETURN, 59);
	disassembleChunk(&chunk, "test chunk");
	freeChunk(&chunk);
	return 0;
}
