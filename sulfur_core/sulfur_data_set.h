#ifndef SULFUR_CORE_DATA_SET_H
#define SULFUR_CORE_DATA_SET_H

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct  sulfur_dataset {
	size_t size;
	int dimensions;
	int precision; // single or double float
	void* data;
};

typedef struct sulfur_dataset sulfur_dataset_t;

int sulfur_dataset_init(sulfur_dataset_t* set, void* data, size_t size, int dimensions, int precision);

int sulfur_dataset_deinit(sulfur_dataset_t* set);

#ifdef __cplusplus
}
#endif

#endif // SULFUR_CORE_DATA_SET_H

