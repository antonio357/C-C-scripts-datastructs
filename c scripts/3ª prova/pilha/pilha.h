#include<stdlib.h>
#include<stdio.h>

#define size 10

typedef struct {
    int vet[size];
    int top;
} pile;

pile* create_pile(); // create pile

int push(pile* pil, int val);

int pop(pile* pil);

void print_pile(pile* pil);