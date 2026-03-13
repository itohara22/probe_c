#include <float.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int* arr;
    int capacity;
} dynamic_arr;

dynamic_arr*  new_da() {
    dynamic_arr* a = malloc(sizeof(dynamic_arr)); // NOTE: malloc returns NULL if it fails to allocate memory
    // a->size = 0;
    (*a).size =0;
    a->capacity = 2;
    a->arr = malloc( a->capacity * sizeof(int));

    if (a->arr == NULL){
        free(a);
        fprintf(stderr, "Unable to allocate memory for dynamic array");
        return NULL;
    }

    return a;
}

// will return error status
int da_push(dynamic_arr* da,int val){
    if (da == NULL){
        return 0;
    }

    if (da->size == da->capacity){
        int* temp = realloc(da->arr, 2 * da->capacity * sizeof(int));
        if (temp == NULL){
            fprintf(stderr, "Unable to resize array");
            return 0;
        }
        da->arr = temp; // dont free temp we will lost the data
        da->capacity = 2*da->capacity;
    }

    da->arr[da->size] = val;
    da->size++;
    return 1;
}

// Returns error status
int da_pop( dynamic_arr* da, int* p_to_val){
    if(da == NULL || da->arr == NULL){
        return 0;
    }
    if (p_to_val != NULL){ // null check
        *p_to_val = da->arr[da->size -1]; // put the value to pointer to value
    }
    da->size--;

    // shrinking array
    if (da->capacity > 1 && da->size*4 <= da->capacity){
        // Shrinking only when size id 1/4 of capacity to prevent ocillation of growing and shrinking
        int* temp = realloc(da->arr, (da->capacity / 2) * sizeof(int));
        if (temp != NULL){
            da->arr = temp; // we will not throw an if unable to decrease capacity
            da->capacity = da->capacity /2;
        }
    }
    return 1;
}

void da_destroy( dynamic_arr* da){
    if (da == NULL){
        return;
    }
    // free must be done like valid parenthesis
    free(da->arr);
    free(da);
    return;
}
