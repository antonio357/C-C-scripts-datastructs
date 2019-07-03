#include<stdio.h>

#define SIZE 10000
#define SIZE_1 61

int main() {
    int q_botas = 0, i, k = 0, h = 0, t = 0;
    int num = 0, pares_possiveis = 0;
    int vet_D[SIZE]; int vet_E[SIZE]; int num_possiveis[SIZE_1];
    char par[2];
    int _par = 0;
    int counter_in_vet_D = 0, counter_in_vet_E = 0;

    while(scanf("%d", &q_botas) != EOF) {
        //par[500] = 'C';
        /*for (k = 0; k < 61; k++) {
            printf("num_possiveis[%d] = %d\n", k, num_possiveis[k]);
        }*/
        for (i = 0; i < q_botas; i++) {
            scanf("%d %s", &num, par);

            /*if (par[0] == 'D') {_par = 0;}
            else if (par[0] == 'E') {_par = 1;}*/

            if (par[0] == 'D') {  // D
                vet_D[i] = num;
                vet_E[i] = 0;
            }
            else if (par[0] == 'E') { // E
                vet_E[i] = num;
                vet_D[i] = 0;
            }

            num_possiveis[num] = num;

            //printf("%d\n", i);
            //printf("vet_D[%d] = %d\n", i, vet_D[i]);
            //printf("vet_E[%d] = %d\n", i, vet_E[i]);
            //printf("par[0] = %c\n", par[0]);
            //vet[i] = num;
            /*printf("par[500] = %c\n", par[500]);
            printf("par[i] = %c\n", par[i]);
            printf("par = %s\n", par);
            printf("vet[%d] = %d\n", i, vet[i]);
            /*if (i >= 1) {
                for (k = i - 1; k >= 0; k--) {
                    if (vet[k] == vet[i] && par[i] != par[k]) {

                    }
                }
            }*/
        }
        //printf("%d\n", i); quebra o primeiro for com i
        for (k = 30; k < SIZE_1; k++) {
            if (num_possiveis[k] != 0) {
                for (h = 0; h <= i; k++) {}
                for () {}
                num_possiveis[k] = 0;
            }
        }
    
    }

    return 0;
}