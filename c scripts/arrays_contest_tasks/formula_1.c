#include<stdio.h>

int main () {
    int q_linhas = 0, q_elementos_por_linha = 0;
    int i = 0, k = 0, l = 0, w = 0, r = 0;

    while(1) {

        scanf("%d %d", &q_linhas, &q_elementos_por_linha);

        if (q_linhas == 0 && q_elementos_por_linha == 0) break;

        int matriz[q_linhas][q_elementos_por_linha];

        for (i = 0; i < q_linhas; i++) {
            for (k = 0; k < q_elementos_por_linha) {
                scanf("%d", &matriz[i][k]);
            }
        }

    }

    return 0;
}