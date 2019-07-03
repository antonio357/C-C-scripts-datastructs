#include<stdio.h>
#include<stdlib.h>

int distance(int smallest, int biggest) {
    if (smallest >= 0 && biggest >= 0) return biggest - smallest;
    else if (smallest < 0 && biggest >= 0) return smallest*-1 + biggest;
    else if (smallest < 0 && biggest < 0) return smallest*-1 - biggest*-1;
}

void points(int *p, int k) {
    *p += k * (k - 1)/2;
}

int diferrence(int begin, int end) { // thay are index
    return end - begin; // the retutn will be the k value for points() func
}

int value(int element) {
    distance
    return element - distance; // return the value that must be found
}

int binary_search(int vet[], int end, int distance) {
    int midle, begin = 0, return_position = vet[0] - 1;
    if (vet[begin] == value(vet[end], distance)) return 0;
    while (vet[begin] < value(vet[end], distance)) {
        midle = (end + begin)/2; 
        if (vet[midle] >= value(vet[end], distance)) {
            return_position
        } 
        else if (vet[midle] < value(vet[end], distance))
    }
}

int main() {
    int n, d, i = 0, output = 0;
    scanf("%d %d", &n, &d);
    int *vet = (int*)malloc(n*sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    //for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    printf("%d\n", output);
    free(vet);
    return 0;
}