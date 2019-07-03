#include<stdio.h>

#define SIZE 10000

int main() {
    int altura = 0, largura = 0;
    int i = 0, k = 0, r = 0, d = 0;
    int alturas_inicias[SIZE];
    int alturas_finais[SIZE];
    int binary_check[SIZE];
    int counter = 1, counter_many = 0;
    int inicio_da_leitura = 0;
    int barreira = 0, diferenssa_ant = 0, diferenssa_atu = 0, diferenssa = 0;

    while(1) {
        scanf("%d %d", &altura, &largura);
        if (altura == 0 && largura == 0) break;

        counter_many = 0;

        for (k = 0; k < SIZE; k++) {
            alturas_inicias[k] = 0;
            alturas_finais[k] = 0;
            binary_check[k] = 0;
        }

        for (i = 0; i < largura; i++) {

            scanf("%d", &alturas_finais[i]);
            alturas_inicias[i] = altura;

        } 

        //printf("i = %d\n", i);
        
		do {
            
            counter = 1; diferenssa_ant = 0; diferenssa_atu = 0; diferenssa = 0;

            for (d = 0; d < i; d++) {

                if (alturas_inicias[d] > alturas_finais[d]) {
                    alturas_inicias[d]--;
                    counter--;
                }

                if (d > 0) {
                    if (alturas_inicias[d - 1] != alturas_inicias[d]) { 
                        if (alturas_inicias[d - 1] < alturas_inicias[d]) {
                            diferenssa_ant = alturas_inicias[d - 1] - alturas_inicias[d];
                        }
                        else if (alturas_inicias[d - 1] > alturas_inicias[d] && diferenssa_ant != 0) {
                            diferenssa_atu = alturas_inicias[d - 1] - alturas_inicias[d];
                        }
                    } 
                }
                if (diferenssa_ant + diferenssa_atu == 0 && diferenssa_ant != 0 && diferenssa_atu != 0) {
                    counter_many++;
                    diferenssa_ant = 0; diferenssa_atu = 0;
                }
			}
            counter_many++;

        } while (counter != 1);

        counter_many--;
        printf("%d\n", counter_many);

    }
    return 0;
}