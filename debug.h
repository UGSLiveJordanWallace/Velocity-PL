#ifndef velocity_debugger
#define velocity_debugger

#include "chunk.h"
#include <stdio.h>

void disassembleChunk(Chunk* chunk, const char* title);
int disassembleInstruction(Chunk* chunk, int offset);
int getLine(Chunk* chunk, int index);

#endif
