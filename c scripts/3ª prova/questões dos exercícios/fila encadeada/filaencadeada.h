#include<stdlib.h>
#include<stdio.h>

struct node {
    int value;
    struct node* next;
};

typedef struct node node;

typedef struct {
    node* begin;
    node* end;
} row;

row* create_row();

void append(row* r, int val);

int drop(row* r);

void clear_row(row* r);

void print_row(row* r);