#include<stdio.h>

#define SIZE 1000

int main() {
    int q_casos = 0, i = 0, c = 0;
    int grau_suspeita[SIZE];
    int segundo_mais_suspeito = 0;
    int primeiro_mais_suspeito = 0;
    int k = 0, limp = 0, rp = 0;
    int index_mais_suspeito = 0;
    int index_segundo_mais_suspeito = 0;

    while(1) {
        scanf("%d", &q_casos);

        if (q_casos == 0) break;

        else {

            index_mais_suspeito = 0;
            index_segundo_mais_suspeito = 0;
            segundo_mais_suspeito = 0;
            primeiro_mais_suspeito = 0;            

            for (limp = 0; limp < SIZE; limp++) {
                grau_suspeita[limp] = 0;
            }

            for (i = 0; i < q_casos; i++) {

                scanf("%d", &grau_suspeita[i]);

            }

            // algorítimo pra avaliar qual o primeiro mais suspeito
            for (rp = 0; rp < SIZE; rp++) {
                if (grau_suspeita[rp] > primeiro_mais_suspeito) {
                    primeiro_mais_suspeito = grau_suspeita[rp];
                    //printf("rp = %d\n", rp);
                    index_mais_suspeito = rp + 1;
                }
                /*else if (grau_suspeita[rp] <= primeiro_mais_suspeito) {
                    primeiro_mais_suspeito = primeiro_mais_suspeito;
                    //printf("rp = %d\n", rp);
                    index_mais_suspeito = rp + 1;
                }*/
            }

            //printf("primeiro_mais_suspeito = %d, index_mais_suspeito = %d\n", primeiro_mais_suspeito, index_mais_suspeito);
            
            // algorítimo pra avaliar qual o segundo mais suspeito
            for (c = 0; c < SIZE; c++) {
                if (grau_suspeita[c] > segundo_mais_suspeito && grau_suspeita[c] < primeiro_mais_suspeito) {
                    segundo_mais_suspeito = grau_suspeita[c];
                    //printf("rp = %d\n", rp);
                    index_segundo_mais_suspeito = c + 1;
                }
            }

            //printf("segundo_mais_suspeito = %d, index_segundo_mais_suspeito = %d\n", segundo_mais_suspeito, index_segundo_mais_suspeito);

            /*for (k = 0; k < SIZE; k++) {
                printf("grau_suspeita[%d] = %d\n", k, grau_suspeita[k]);
            }*/

            printf("%d\n", index_segundo_mais_suspeito);

        }
        
    }

    return 0;
}