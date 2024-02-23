#include "value.h"
#include "memory.h"
#include <stdio.h>

void initValueArray(ValueArray *arr) {
	arr->count = 0;
	arr->capacity = 0;
	arr->values = NULL;
}

void initLValueArray(LValueArray *arr) {
	arr->count = 0;
	arr->capacity = 0;
	arr->values = NULL;
}

void writeValueArray(ValueArray *arr, Value value) {
	if (arr->count + 1 > arr->capacity) {
		int old_capacity = arr->capacity;
		arr->capacity = GROW_CAPACITY(old_capacity);
		arr->values = GROW_ARRAY(Value, arr->values, old_capacity, arr->capacity);
	}

	arr->values[arr->count] = value;
	arr->count++;	
}

void writeLValueArray(LValueArray *arr, LValue value) {
	if (arr->count + 1 > arr->capacity) {
		int old_capacity = arr->capacity;
		arr->capacity = GROW_CAPACITY(old_capacity);
		arr->values = GROW_ARRAY(LValue, arr->values, old_capacity, arr->capacity);
	}

	arr->values[arr->count] = value;
	arr->count++;
}

void freeValueArray(ValueArray *arr) {
	FREE_ARRAY(Value, arr->values, arr->capacity);
	initValueArray(arr);
}

void freeLValueArray(LValueArray *arr) {
	FREE_ARRAY(LValue, arr->values, arr->capacity);
	initLValueArray(arr);
}

void printValue(Value value) {
	printf("%g", value);
}

void printLValue(LValue value) {
	printf("%Lf", value);
}
