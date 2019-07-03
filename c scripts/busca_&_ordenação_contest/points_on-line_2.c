#include<stdio.h>
#include<stdlib.h>

void score(int end, int begin, int *p) {
    if (begin > end) return;
    //printf("score\n");
    int k = end - begin;
    *p += k * (k - 1)/2;
}

int binary_search(int vet[], int value, int end) {
    //printf("binary_search\n");
    end--;
    int begin = 0; int position = end + 10; int midle;
    if (vet[begin] >= value) return 0;
    if (vet[end] == value) return end;
    if (vet[end] < value) return position; 
    while (end - begin > 1) {
        midle = (end + begin)/2;
        //printf("begin = %d, end = %d, midle = %d, position = %d\n", begin, end, midle, position);
        if (vet[midle] == value) return midle;
        else if (vet[midle] > value) {
            end = midle - 1;
            //position = end;
        }
        else if (vet[midle] < value) begin = midle + 1;
    }
    if (vet[end] >= value) return end;
    if (vet[begin] >= value) return begin;
    //return position;
}

int main() {
    int n, d, i = 0, output = 0;
    scanf("%d %d", &n, &d);
    int *vet = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    //printf("position = %d\n", binary_search(vet,1,2));
    for (i = n - 1; i > 0; i--) {
      //printf("i from for = %d\n", vet[i]);
        score(i, binary_search(vet, vet[i] - d, i), &output);
    }
    printf("%d\n", output);
    free(vet);
    return 0;
}