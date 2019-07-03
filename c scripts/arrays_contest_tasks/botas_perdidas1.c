#include<stdio.h>

#define SIZE_1 31

int main() {
    int q_botas = 0, i = 0, k = 0, h = 0, t = 0, d = 0, e = 0;
    int num = 0;
    int vet_D[SIZE_1]; 
    int vet_E[SIZE_1];
    char par[2];

    while(scanf("%d", &q_botas) != EOF) {

        e = 0;

        for (h = 0; h < SIZE_1; h++) {
            vet_D[h] = 0;
        }

        for (t = 0; t < SIZE_1; t++) {
            vet_E[t] = 0;
        }
        
        for (i = 0; i < q_botas; i++) {
            scanf("%d %s", &num, par);

            if (par[0] == 'D') {
                vet_D[num - 30]++;
            }
            else if (par[0] == 'E') {
                vet_E[num - 30]++;
            }

        }

        // apos armazenar totos os valores
        /*for (k = 0; k < SIZE_1; k++) {
            printf("vet_D[%d] = %d", k+30, vet_D[k]);
        }
        for (k = 0; k < SIZE_1; k++) {
            printf("vet_E[%d] = %d", k+30, vet_E[k]);
        }*/

        for (d = 0; d < SIZE_1; d++) {
            if (vet_D[d] != 0) {
                if (vet_D[d] > vet_E[d]) {
                    e += vet_E[d];
                }
                else if (vet_D[d] <= vet_E[d]) {
                    e += vet_D[d];
                }
            }
        }
        printf("%d\n", e);
    }

    return 0;
}    