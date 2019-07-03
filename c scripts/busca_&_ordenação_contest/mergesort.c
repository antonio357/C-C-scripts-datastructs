#include<stdio.h>
#include<stdlib.h>

void merge(int vet[], int l, int m, int r) {
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2];
    
}

void merge_sort(int vet[], int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2; 
        merge_sort(vet, l, m);
        merge_sort(vet, m+1, r);
        merge(vet, l, m, r);
    }
}



int main() {
    int n, i;
    scanf("%d", &n);
    int vet[n];
    for (i = 0; i < n; i++) scanf("%d", &vet[i]);
    merge_sort(vet, 0, n - 1);
    for (i = 0; i < n; i++) printf("%d ", vet[i]);
    return 0;
}