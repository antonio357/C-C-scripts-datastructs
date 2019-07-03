#include<stdio.h>
#include<stdlib.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node;

typedef struct {
    node* top;
} pile;

pile* create_pile();

void push(pile* pil, int val);

int pop(pile* pil);

void clear_pile(pile* pil);

void print_pile(pile* pil);

void del_pile(pile* pil);