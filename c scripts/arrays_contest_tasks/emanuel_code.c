#include<stdio.h>

int main(void) {
    int altura = 0, largura = 0;
    int i = 0, k = 0;

    while(1) {
        scanf("%d %d", &altura, &largura);
        if (altura == 0 && largura == 0) break;

        int igualdades_ant = 0, igualdades_atu = altura;
        int lista_referencial[largura];
        int lista_base[largura];
        int menor_caso = altura;
        int valor_igual_anteriror = altura + 1;
        int valor_igual = altura;
        int menor_index_valor_igual = 0;
        int index_valor_igual = 0;
        int counter = 0;
        for (i = 0; i < largura; i++) {
            scanf("%d", &lista_referencial[i]);
            lista_base[i] = altura;
            if (lista_referencial[i] < menor_caso) menor_caso = lista_referencial[i];
        }
        
    }

printf("%d %d", altura, largura);

    return 0;
}