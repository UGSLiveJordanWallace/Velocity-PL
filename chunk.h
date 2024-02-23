#ifndef velocity_chunk
#define velocity_chunk

#include "common.h"
#include "value.h"

typedef enum {
	OP_CONSTANT_LONG,
	OP_CONSTANT,
	OP_RETURN,
} OpCode;

typedef struct {
	int count;
	int capacity;
	uint8_t* code;
	ValueArray constants;
	LValueArray long_constants;
	int* line_numbers;
	int* line_quantity;
	int lines;
} Chunk;

void initChunk(Chunk* chunk);
void writeChunk(Chunk* chunk, uint8_t byte, int line);
int addConstant(Chunk* chunk, Value value);
int addLConstant(Chunk* chunk, LValue value);
void freeChunk(Chunk* chunk);

#endif
