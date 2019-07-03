#include<stdlib.h>
#include<stdio.h>
#include"fila.h"

row* create_row() {
    row* r = (row*)malloc(sizeof(row));
    r->begin = 0;
    r->len = 0;
    int i;
    for (i = 0; i < size; i++) r->vet[i] = 0;
    return r;
}

void row_append(row* r, int val) {
    int end = 0;
    if (r->len < size) {
        end = (r->begin + r->len) % size;
        r->vet[end] = val;
        r->len++;
    }
    return;
}

int drop_begin(row* r) {
    if (r->len == 0) return -1;
    int val = r->vet[r->begin];
    r->vet[r->begin] = 0;
    r->begin = (r->begin + 1) % size; 
    r->len--;
    return val;
}

void print_row(row* r) {
    if (r->len == 0) {
        printf("[]\n");
        return;
    }
    int i;
    printf("[");
    for (i = 0; i < size; i++) {
        if (i == size - 1) printf("%d", r->vet[i]);
        else printf("%d, ", r->vet[i]);
    }
    printf("]\n");
    return;
}