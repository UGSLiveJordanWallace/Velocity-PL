#ifndef velocity_value
#define velocity_value

#include "common.h"

typedef double Value;
typedef long double LValue;

typedef struct {
	int capacity;
	int count;
	Value* values;
} ValueArray;

typedef struct {
	int capacity;
	int count;
	LValue* values;
} LValueArray;

void initValueArray(ValueArray* arr);
void writeValueArray(ValueArray* arr, Value value);
void freeValueArray(ValueArray* arr);
void printValue(Value value);

void initLValueArray(LValueArray* arr);
void writeLValueArray(LValueArray* arr, LValue value);
void freeLValueArray(LValueArray* arr);
void printLValue(LValue value);

#endif
