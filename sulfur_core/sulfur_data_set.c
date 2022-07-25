#include "sulfur_data_set.h"

int sulfur_dataset_init(sulfur_dataset_t* set, void* data, size_t size, int dimensions, int precision)
{
	void* new_data = malloc(size);
	if (new_data == NULL) {
		return 0;
	}
	memcpy(data, new_data, size);
	set->data = new_data;
	set->size = size;
	set->dimensions = dimensions;
	set->precision = precision;
	return 1;
}

int sulfur_dataset_deinit(sulfur_dataset_t* set)
{
	if (set->data == NULL) {
		return 0;
	}
	free(set->data);
	set->data = NULL;
	set->size = 0;
	return 1;
}