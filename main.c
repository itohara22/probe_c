#include "dynamic_arr.h"
#include <stdio.h>

int main() {
    dynamic_arr* da = new_da();

    da_push(da,1);
    da_push(da,2);
    da_push(da,3);
    da_push(da,4);

    for(int i=0;i< da->size;i++){
        printf("val: %d\n",da->arr[i]);
    }

    printf("size: %d\n",da->size);
    da_pop(da, NULL);
    printf("size: %d\n",da->size);

    for(int i=0;i< da->size;i++){
        printf("val: %d\n",da->arr[i]);
    }

	return 0;
}
