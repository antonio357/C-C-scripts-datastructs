#include<stdlib.h>
#include<stdio.h>

#define size 6

typedef struct {
    int len;
    int begin;
    int vet[size];
} row;

row* create_row();

void row_append(row* r, int val);

int drop_begin(row* r);

void print_row(row* r);