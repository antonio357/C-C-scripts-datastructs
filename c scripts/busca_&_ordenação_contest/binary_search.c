#include<stdio.h>
#include<stdlib.h>

int binary_search(int vet[], int len, int value) {
    int begin = 0, end = len - 1, midle, first_position = len+10;
    if (vet[end] == value) first_position = end;
    if (vet[begin] == value) return 0;
    while (end >= begin) {
        midle = (end + begin)/2;
        //printf("begin = %d, end = %d, midle = %d\n", begin, end, midle);
        //printf("first_position = %d\n", first_position);
        if (vet[midle] == value) {
            if (midle < first_position) first_position = midle;
            end = midle - 1;
        }
        else if (vet[midle] > value) end = midle - 1;
        else if (vet[midle] < value) begin = midle + 1;
    }
    if (first_position == len+10) return -1;
    return first_position;
}

int main () {
    int n = 0, q = 0, i = 0;
    scanf("%d %d", &n, &q);
    int *vet = (int*)malloc(n*sizeof(int));
    int *vet_1 = (int*)malloc(q*sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    for (i = 0; i < q; i++) scanf("%d", &vet_1[i]);
    for (i = 0; i < q; i++) printf("%d\n", binary_search(vet, n, vet_1[i]));
    return 0;
}