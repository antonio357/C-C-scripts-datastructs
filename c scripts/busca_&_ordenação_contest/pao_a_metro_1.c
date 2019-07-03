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

int mediana(int inicio, int fim) {
    int position;
    int len = (fim - inicio) + 1;
    if (len%2 == 0) {
       position = (int)((fim + inicio)/2);
    }
    else if (len%2 != 0) {
       position = (inicio + fim)/2;
    }
    return position;
}

int busca_binaria(int lis[], int n, int maior, int q_ps) {
    int inicio = 1; int fim = maior; int first_time = True;
    int test; int valor; int ant = 0; int atu = 0;
    if (q_sands(lis,n,inicio) == q_ps) return inicio;
    else if ( q_sands(lis,n,fim) == q_ps) return fim;
    int counter = 0;
    while(True) {
        if (counter == 20) return -1;
        counter++;

        test = mediana(inicio, fim);
        valor = q_sands(lis,n,test);
        printf("inicio = %d, fim = %d, mediana = %d, retorno = %d\n",inicio,fim,test,valor);
        if (valor == q_ps) {
            atu = test;
        }
        else if (valor != q_ps) {
            if (valor > q_ps) {
                inicio = test;
            }
            else if (valor < q_ps) {
                fim = test;
            }
        }
        if (first_time == True) {
            ant = atu;
            first_time = False;
        }
        else {
            if (atu > ant) {}
        }
        if ((fim - inicio) <= 2) break;
    }
    return ant;
}

int main () {
    int n;
    int k; 
    int maior;
    int i = 0;

    scanf("%d", &n);
    scanf("%d", &k);

    int *lis = (int*)malloc(k*sizeof(int));
    if (lis == NULL) {
        printf("didn't allocated the vector\n");
        return - 1;
    }

    for (i = 0; i < k; i++) {
        scanf("%d", &lis[i]);
        if (i == 0) {
            maior = lis[i];
        }
        else if (i > 0 && lis[i] > maior) {
            maior = lis[i];
        } 
    } 
    printf("%d\n",busca_binaria(lis, k, maior, n));
    printf("fim = %d\n", maior);
    int lis1[2] = {45, 85};
    printf("ok = %d\n", q_sands(lis1,2,42));
    //printf("%d\n", q_sands(lis,k,595));
    return 0;
}