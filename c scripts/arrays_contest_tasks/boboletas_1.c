#include<stdio.h>

int main () {

    int linhas = 0, colunas = 0;
    int i = 0, k = 0, n = 0, r = 0, h = 0, o = 0, e = 0;
    int linha_local = 0, coluna_local = 0;
    int reincidiu = 0;

    while(scanf("%d", &linhas) != EOF) {
        colunas = linhas;

        int counter = 0;
        int matriz[linhas][colunas];
        int lista_arm[linhas*2];
        int matriz_ljv[linhas][colunas];

        for (e = 0; e < linhas*2; e++) {

          lista_arm[e] = 0;

        }

        for (i = 0; i < linhas; i++) {

            for (k = 0; k < colunas; k ++) {

                scanf("%d", &matriz[i][k]);
                matriz_ljv[i][k] = 0;

            }
        }

        /*for (o = 0; o < linhas; o++) {

            for (h = 0; h < linhas; h++) {

                printf("matriz[%d][%d] = %d\n\nmatriz_ljv[%d][%d] = %d\n", o, h, matriz[o][h], o, h, matriz_ljv[o][h]);

            }

        }*/

        for (n = 0; n < linhas*2; n++) {

            scanf("%d %d", &linha_local, &coluna_local);
            linha_local--; coluna_local--;
            matriz_ljv[linha_local][coluna_local] = matriz[linha_local][coluna_local];

            if (n > 0) {
              reincidiu = 0;
                for (r = 0; r < n; r++) {
                  //printf("%d < +- > %d\n", matriz_ljv[linha_local][coluna_local], lista_arm[r]);
                  //printf("n = %d\n", n);
                    if (matriz_ljv[linha_local][coluna_local] == lista_arm[r]) {
                      //printf("OKAY\n");
                        reincidiu++;
                        break;
                    }
                    /*else if (matriz_ljv[linha_local][coluna_local] != lista_arm[r]) {
                      //printf("kkkk\n");
                        lista_arm[n] = matriz_ljv[linha_local][coluna_local];
                    }*/
                }
        
            }
            else if (n == 0) {
                lista_arm[0] = matriz_ljv[linha_local][coluna_local];
            }

            if (reincidiu == 0) {lista_arm[n] = matriz_ljv[linha_local][coluna_local];}

            //else if (reincidiu > 0) {printf("reincidiu = %d\n", reincidiu);}

        }

        /*for (o = 0; o < linhas; o++) {

            for (h = 0; h < linhas; h++) {

                printf("matriz[%d][%d] = %d\n\nmatriz_ljv[%d][%d] = %d\n", o, h, matriz[o][h], o, h, matriz_ljv[o][h]);

            }

        }*/  

        /*for (h = 0; h < linhas*2; h++) {

          if (h < linhas*2 - 1) printf("%d ", lista_arm[h]);

          else printf("%d\n", lista_arm[h]);

        }*/

        for (h = 0; h < linhas*2; h++) {
            if (lista_arm[h] > 0) counter++;
        }

        printf("%d\n", counter);   

    }

    return 0;
}