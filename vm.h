#ifndef velocity_vm
#define velocity_vm

#include "chunk.h"

typedef struct {
	Chunk* chunk;
} VM;

void initVM();
void freeVM();

#endif
