#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

int q_sands(int lis[], int n, int value) {
    int q = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        if (value == 0) break;
        if (lis[i] >= value) q += (int)lis[i]/value;
    }
    return q;
}

int busca_binaria(int lis[], int n, int maior, int q_ps) {
    int inicio = 1; int fim = maior;
    int mediana = (int)((fim - inicio)/2);

    while (True) {
        if ((int)((fim - inicio)/2) == 0) {
          if (q_sands(lis,n,inicio) >= q_ps) return inicio;
          else if (q_sands(lis,n,fim) >= q_ps) return fim;
        }

        if (q_sands(lis,n,inicio) == q_ps) return inicio;
        if (q_sands(lis,n,fim) == q_ps) return fim;
        
        mediana = (int)((fim - inicio)/2) + inicio;

        //printf("inicio = %d, fim = %d, mediana = %d, q_ps = %d, q_psn = 3000\n", inicio, fim, mediana, q_sands(lis,n,mediana));

        if (q_sands(lis,n,mediana) != q_ps) {
            if (q_sands(lis,n,mediana) < q_ps) {
                fim = mediana;
            }
            else if (q_sands(lis,n,mediana) > q_ps) {
                inicio = mediana;
            }
        }
        else if (q_sands(lis,n,mediana) == q_ps) return mediana;
    }
}

int main () {
    int n; //N
    int k; // k
    int menor;
    int maior;
    int i = 0;

    scanf("%d", &n);
    scanf("%d", &k);

    int *lis = (int*)malloc(k*sizeof(int));
    if (lis == NULL) {
        printf("Deu erro\n");
        return - 1;
    }

    for (i = 0; i < k; i++) {
        scanf("%d", &lis[i]);
        if (i == 0) {
            menor = 1; maior = lis[i];
        }
        else if (i > 0 && lis[i] > maior) {
            maior = lis[i];
        } 
    } 
    printf("%d\n",busca_binaria(lis, k, maior, n));
    //printf("%d\n", q_sands(lis,k,595));
    return 0;
}