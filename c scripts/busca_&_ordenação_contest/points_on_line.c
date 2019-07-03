#include<stdio.h>
#include<stdlib.h>

int binary_search(const int vet[] , int smallest_index, int biggest_index, int limit) {
    while(biggest_index - smallest_index > limit) {
        if (distance(vet[smallest_index], vet[biggest_index]) > limit) {
            biggest_index = (int)((biggest_index + 1)/2);
        }
        else if (distance(vet[smallest_index], vet[biggest_index]) <= limit) {
            biggest_index = (int)((biggest_index + 1)/2);
        }
    }
}

int distance(int smallest, int biggest) {
    if (smallest >= 0 && biggest >= 0) return biggest - smallest;
    else if (smallest < 0 && biggest >= 0) return smallest*-1 + biggest;
    else if (smallest < 0 && biggest < 0) return smallest*-1 - biggest*-1;
}

int main() {
    int n;
    int d;
    int i;
    int smallest;
    scanf("%d %d", &n, &d);
    int *vet = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    // begin the process
    int n_limit = (int)(n/2);
    for (i = 0; i < n_limit + 1; i++) {
        
    }
    free(vet);
    return 0;
}