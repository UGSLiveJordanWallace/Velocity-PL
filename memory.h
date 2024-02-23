#ifndef velocity_memory
#define velocity_memory

#include "common.h"

#define GROW_CAPACITY(capacity) \
	((capacity) < 8 ? 8 : (capacity) * 2)
#define GROW_ARRAY(type, pointer, old_capacity, capacity) \
	(type*)reallocate(pointer, sizeof(type) * (old_capacity), sizeof(type) * (capacity))
#define FREE_ARRAY(type, pointer, old_capacity) \
	reallocate(pointer, sizeof(type) * old_capacity, 0)

void* reallocate(void* pointer, size_t old_size, size_t new_size);

#endif
