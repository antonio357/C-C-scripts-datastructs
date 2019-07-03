#include<stdio.h>

int main () {

    int linhas = 0, colunas = 0;
    int i = 0, k = 0, n = 0, r = 0, h = 0;
    int linha_local = 0, coluna_local = 0;

    while(scanf("%d", &linhas) != EOF) {
        colunas = linhas;

        int counter = 0;
        int matriz[linhas][colunas];
        int lista_arm[linhas*2];
        int matriz_locais_ja_visitados[linhas][colunas];

        for (i = 0; i < linhas; i++) {
            for (k = 0; k < colunas; k ++) {
                scanf("%d", &matriz[i][k]);
                matriz_locais_ja_visitados[i][k] = 0;
            }
        }

        for (n = 0; n < n*2; n++) {
            scanf("%d %d", &linha_local, &coluna_local);
            matriz_locais_ja_visitados[linha_local][coluna_local] = matriz[linha_local][coluna_local];

            if (n > 0) {
                for (r = 0; r < n; r++) {
                    if (matriz_locais_ja_visitados[linha_local][coluna_local] == lista_arm[r]) {
                        break;
                    }
                    else {
                        lista_arm[n] = matriz_locais_ja_visitados[linha_local][coluna_local];
                    }
                }
            }
            else if (n == 0) {
                lista_arm[0] = matriz_locais_ja_visitados[linha_local][coluna_local];
            }
        
        }

        for (h = 0; h < linhas*2; h++) {
            if (lista_arm[h] > 0) counter++;
        }

        printf("%d\n", counter);

    }

    return 0;
}