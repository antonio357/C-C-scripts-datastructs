#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int vet[], int len) {
    int r; 
    int l;
    int i;
    int armazena;
    for (r = 1; r < len; r++) {
        for (l = r - 1; l > -1 && vet[l] > vet[l + 1]; l--) {
            armazena = vet[l];
            vet[l] = vet[l + 1];
            vet[l + 1] = armazena;
        }
        //for (i = 0; i < len; i++) printf("%d ", vet[i]);
        //printf("\n");
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    int vet[n];
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    insertion_sort(vet, n);
    for (i = 0; i < n; i++) printf("%d ", vet[i]);
    return 0;
}