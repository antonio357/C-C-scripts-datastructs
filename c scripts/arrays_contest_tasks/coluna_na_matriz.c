#include<stdio.h>

int main() {
    char operassao;
    int i = 0, k = 0, coluna = 0;
    double matriz[12][12];
    double soma = 0;
    double media = 0;

    scanf("%d %c", &coluna, &operassao); 
    //printf("operassao = %c", operassao);

    soma = 0; media = 0;


    for (i = 0; i < 12; i++) {
        for (k = 0; k < 12; k++) {
            scanf("%lf", &matriz[i][k]);
            if (k == coluna) soma += matriz[i][k];
        }
    }

    media = (double)soma/(double)12.0;
    
    if (operassao == 'M') {
        printf("%.1lf\n", media);
    }

    else {
        printf("%.1lf\n", soma);
    }
    
    return 0;
}