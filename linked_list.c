#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct {
    int val;
    struct node* right;
} node;

typedef struct {
    node* head;
    node* tail;
    int size;
} linked_list;


linked_list* new_ll() {

    linked_list *a = malloc(sizeof(linked_list));
    a->head = malloc(sizeof(node));
    if (a->head == NULL) {
        free(a);
        fprintf(stderr, "Unable to allocate memory for head of linked list");
        return NULL;
    }

    a->tail = malloc(sizeof(node));
    if (a->tail == NULL) {
        free(a->head);
        free(a);
        fprintf(stderr, "Unable to allocate memory for tail of linked list");
        return NULL;
    }

    a->size = 0;
    return a;
}


void ll_destroy(linked_list* ll){
    if (ll == NULL) {
        return;
    }
    free(ll->head);
    free(ll->tail);
    free(ll);
}




