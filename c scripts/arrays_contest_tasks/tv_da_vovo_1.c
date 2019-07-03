#include<stdio.h>

int main() {

    int linhas = 0, colunas = 0;
    int l = 0, c = 0, cdc, li = 0, ci = 0;
    int x = 0, y = 0, x_ = 0, y_ = 0;
    int coluna_ci = 0, linha_li = 0;
    int teste = 1;

    while(1) {

        scanf("%d %d", &linhas, &colunas);

        if (linhas == 0 && colunas == 0) break;

        int matriz[linhas][colunas];
        int matriz_c[linhas][colunas];
        x = 0; y = 0;

        // armazena os valores na matriz
        for (l = 0; l < linhas; l++) {

            for (c = 0; c < colunas; c ++) {

                scanf("%d", &matriz[l][c]);
                //printf("matriz[%d][%d] = %d\n", l, c, matriz[l][c]);

            }

        }

        //recebe as correções de acordo com os comandos de correção
        while(1) {

            scanf("%d %d", &x_, &y_);

            x += x_; y += y_;

            if (x_ == 0 && y_ == 0) {

                //realiza as correções na matriz de acordo com as cordenadas x
            if (x != 0) {

                if (x > 0) {

                    for (li = 0; li < linhas; li++) {

                        for (ci = 0; ci < colunas; ci++) {

                            coluna_ci = ci + x;
                            while (coluna_ci > colunas - 1) {coluna_ci -= colunas;} 
                            matriz_c[li][coluna_ci] = matriz[li][ci];

                        }

                    }

                }

                else if (x < 0) {

                    for (li = 0; li < linhas; li++) {

                        for (ci = 0; ci < colunas; ci++) {

                            coluna_ci = ci + x;
                            while (coluna_ci < 0) {coluna_ci += colunas;} 
                            matriz_c[li][coluna_ci] = matriz[li][ci];

                        }

                    }

                }

                for (l = 0; l < linhas; l++) {

                    for (c = 0; c < colunas; c++) {

                        matriz[l][c] = matriz_c[l][c];

                    }

                }

            }

            if (y != 0) {

                if (y > 0) {

                    for (ci = 0; ci < colunas; ci++) {

                        for (li = 0; li < linhas; li++) {

                            linha_li = li - y;
                            while (linha_li < 0) {linha_li += linhas;} 
                            matriz_c[linha_li][ci] = matriz[li][ci];

                        }

                    }

                }

                else if (y < 0) {

                    for (ci = 0; ci < colunas; ci++) {

                        for (li = 0; li < linhas; li++) {

                            linha_li = li - y;
                            while (linha_li > linhas - 1) {linha_li -= linhas;} 
                            matriz_c[linha_li][ci] = matriz[li][ci];

                        }

                    }

                }

                for (l = 0; l < linhas; l++) {

                    for (c = 0; c < colunas; c++) {

                        matriz[l][c] = matriz_c[l][c];

                    }

                }

            }
            
            break;

            }  

        }

        //printa a matriz
            printf("Teste %d\n", teste);

            for (l = 0; l < linhas; l++) {

                for (c = 0; c < colunas; c++) {

                    if (c == colunas - 1) printf("%d\n", matriz[l][c]);

                    else printf("%d ", matriz[l][c]);


                }

            }

            printf("\n");

            teste++;

    }

    return 0;
}