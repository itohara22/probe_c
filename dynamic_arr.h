#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H

typedef struct {
	int size;
	int* arr;
    int capacity;
} dynamic_arr;

dynamic_arr* new_da();

int da_push(dynamic_arr*,int);

int da_pop(dynamic_arr*, int*);

void da_destroy(dynamic_arr*);

#endif
