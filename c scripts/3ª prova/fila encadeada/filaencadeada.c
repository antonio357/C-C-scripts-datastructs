#include<stdlib.h>
#include"filaencadeada.h"

row* create_row() {
    row* r = (row*)malloc(sizeof(row));
    r->begin = NULL;
    r->end = NULL;
    return r;
}

void append(row* r, int val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->next = NULL;
    if (r->end == NULL && r->begin == NULL) {
        r->begin = new_node;
        r->end = new_node;
    }
    else {
        r->end->next = new_node; 
        r->end = new_node;
    }
    return;
}

int drop(row* r) {
    if (r->end == NULL && r->begin == NULL) return -1;
    int val = r->begin->value;
    node* support = r->begin;
    r->begin = r->begin->next;
    free(support);
    if (r->begin == NULL) r->end = NULL;
    return val;
} 

void clear_row(row* r) {
    if (r->end == NULL && r->begin == NULL) return;
    node* support = r->begin;
    r->begin = r->begin->next;
    free(support);
    if (r->begin == NULL) r->end = NULL;
    clear_row(r);
}

void print_row(row* r) {
    if (r->end == NULL && r->begin == NULL) {
        printf("[]\n");
        return;
    }
    printf("[");
    node* support = r->begin;
    while(support->next != NULL) {
        printf("%d, ", support->value);
        support = support->next;
    }
    printf("%d", support->value);
    printf("]\n");
    return;
}
