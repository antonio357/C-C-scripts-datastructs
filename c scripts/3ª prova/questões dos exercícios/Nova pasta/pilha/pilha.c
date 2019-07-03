#include<stdlib.h>
#include<stdio.h>
#include"pilha.h"

pile* create_pile() {
    pile* pil = (pile*)malloc(sizeof(pile));
    pil->top = 0;
    return pil;
}

int push(pile* pil, int val) {
    if (pil->top == size) return -1;
    else pil->vet[pil->top] = val;
    pil->top++;
    return 0;
}

int pop(pile* pil) {
    if (pil->top == 0) return -1;
    int val = pil->vet[pil->top - 1];
    pil->vet[pil->top - 1] = 0;
    pil->top--;
    return val; 
} 

void print_pile(pile* pil) {
    int i;
    printf("[");
    for (i = 0; i < size; i++) {
        if (i == size - 1) printf("%d", pil->vet[i]);
        else printf("%d, ", pil->vet[i]);
    }
    printf("]\n");
    return;
}