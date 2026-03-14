#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
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

// Returns error codes
int ll_push_front(linked_list* ll, int val){
    if (ll == NULL){
        fprintf(stderr,"Invalid linked list");
        return 0;
    }

    node* new_node = malloc(sizeof(node));
    if(new_node == NULL){
       fprintf(stderr,"Cannot allocate new node");
       return 0;
    }

    new_node->val = val;
    new_node->right = ll->head;
    ll->head = new_node;
    ll->size++;
    return 1;
}

int ll_push_back(linked_list* ll, int val){
    if(ll==NULL){
        fprintf(stderr,"Invalid linked list");
        return 0;
    }

    node* new_node = malloc(sizeof(node));
    if(new_node == NULL){
       fprintf(stderr,"Cannot allocate new node");
       return 0;
    }

    new_node->val = val;
    new_node->right = NULL; // need to do this or right will contain garbage

    if(ll->head == NULL){
       ll->head = new_node;
       ll->tail = new_node;
    }else{
       ll->tail->right = new_node;
       ll->tail = new_node;
    }
    ll->size++;
    return 1;
}


int ll_pop_front(linked_list* ll, int* val){
    if(ll==NULL){
        return 0;
    }

    if(val == NULL){
        *val = ll->head->val;
    }

    node* tmp = ll->head->right;
    free(ll->head);
    if(tmp != NULL){
        ll->head = tmp;
    }else{
        ll->tail = NULL;
    }
    ll->size--;
    return 1;
}
