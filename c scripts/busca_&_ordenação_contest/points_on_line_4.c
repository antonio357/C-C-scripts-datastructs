#include<stdio.h>
#include<stdlib.h>

void score(int end, int begin, long long *p) {
    if (begin > end) return;
    int k = end - begin;
    *p += (long long)(k * (k - 1)/2);
}

int binary_search(int vet[], int value, int end) {
    end--;
    int begin = 0; int position = end + 10; int midle;
    if (vet[begin] >= value) return 0;
    if (vet[end] == value) return end;
    if (vet[end] < value) return position; 
    while (end - begin > 1) {
        midle = (end + begin)/2;
        if (vet[midle] == value) return midle;
        else if (vet[midle] > value) end = midle - 1;
        else if (vet[midle] < value) begin = midle + 1;
    }
    if (vet[end] >= value) position = end;
    if (vet[midle] >= value) position = midle;
    if (vet[begin] >= value) position = begin;
    return position;
}

int main() {
    int n, d, i = 0; long long output = 0;
    scanf("%d %d", &n, &d);
    int *vet = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    for (i = n - 1; i > 0; i--) {
        score(i, binary_search(vet, vet[i] - d, i), &output);
    }
    printf("%I64d\n", output);
    free(vet);
    return 0;
}