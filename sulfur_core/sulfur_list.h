#ifndef SULFUR_CORE_LIST_H
#define SULFUR_CORE_LIST_H

#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

struct sulfur_list_item {
	size_t size;
	const char* data;
};
typedef struct sulfur_list_item sulfur_list_item_t;


struct sulfur_list {
	size_t size;
	sulfur_list_item_t* items;
};
typedef struct sulfur_list sulfur_list_t;


#ifdef __cplusplus
}
#endif

#endif // SULFUR_CORE_LIST_H
