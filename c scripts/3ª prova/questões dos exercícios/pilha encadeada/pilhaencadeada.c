#include<stdlib.h>
#include<stdio.h>
#include"pilhaencadeada.h"

pile* create_pile() {
    pile* pil = (pile*)malloc(sizeof(pile));
    pil->top = NULL;
    return pil;
}

void push(pile* pil, int val) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->next = pil->top;
    new_node->value = val;
    pil->top = new_node;
    return;
}

int pop(pile* pil) {
    if (pil->top == NULL) return -1;
    node* support = pil->top;
    int val = support->value;
    pil->top = pil->top->next;
    free(support);
    return val;
}

void clear_pile(pile* pil) {
    if (pil->top == NULL) return;
    node* support = pil->top;
    pil->top = support->next;
    free(support);
    clear_pile(pil);
}

void del_pile(pile* pil) {
    clear_pile(pil);
    free(pil);
}

void print_pile(pile* pil) {
    if (pil->top == NULL) {
        printf("[]\n");
        return;
    }
    node* support = pil->top;
    printf("[");
    while (support->next != NULL) {
        printf("%d, ", support->value);
        support = support->next;
    }
    printf("%d", support->value);
    printf("]\n");
}
