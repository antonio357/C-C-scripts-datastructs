#include<stdio.h>

#define SIZE 10000

int main() {
    int q_dados = 0;
    int magnitudes[SIZE];
    int i = 0, k = 0, j = 0;
    int num_ant = 0, num_prox = 0;
    int counter_pikes = 0;

    while (1) {
        scanf("%d", &q_dados);

        if (q_dados == 0) break;

        counter_pikes = 0;

        for (k = 0; k < SIZE; k++) {
            magnitudes[k] = 0;
        }

        for (i = 0; i < q_dados; i++) {
            scanf("%d", &magnitudes[i]);
        }
        
        i--;
        //printf("i = %d\n", i);
        for (j = 0; j <= i; j++) {
            if (j == 0) {
                num_ant = magnitudes[i];
                num_prox = magnitudes[j + 1];
            }

            else if (j == i) {
                num_ant = magnitudes[j - 1];
                num_prox = magnitudes[0];
            }

            else {
                num_ant = magnitudes[j - 1];
                num_prox = magnitudes[j + 1];
            }

            /*if ((num_ant < magnitudes[j] && num_prox < magnitudes[j]) && (num_ant > magnitudes[j] && num_prox > magnitudes[j])) {
                counter_pikes++;
            }*/
            if (num_ant < magnitudes[j] && num_prox < magnitudes[j]) {
                counter_pikes++;
            }
            else if (num_ant > magnitudes[j] && num_prox > magnitudes[j]) {
                counter_pikes++;
            }
            else counter_pikes = counter_pikes;
        }

        printf("%d\n", counter_pikes);

    }

    return 0;
}