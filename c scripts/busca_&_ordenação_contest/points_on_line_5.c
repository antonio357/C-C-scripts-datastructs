#include<stdio.h>
#include<stdlib.h>

void score(int end, int begin, long long *p, int vet[], int value) {
    if (vet[begin] < value) return;
    int k = end - begin;
    *p += (long long)(k * (k - 1)/2);
}

int main() {
    int n, d, i = 0; long long output = 0; int difference; int b;
    scanf("%d %d", &n, &d);
    int *vet = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    for (i = n - 1; i > 0; i--) {
        difference = vet[i] - d;
        //printf("difference = %d\n", difference);
        b = i;
        //printf("b before = %d\n", b);
        while(vet[b] > difference && b > 0) b--;
        //printf("b after = %d\n", b);
        score(i, b, &output, vet, difference);
        //printf("output = %I64d\n", output);
    }
    printf("%I64d\n", output);
    free(vet);
    return 0;
}