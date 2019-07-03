#include<stdio.h>

#define SIZE 10000

int main() {
    int q_notas_inicias = 0;
    int k = 0, i = 0, c = 0, h = 0;
    int soma_das_notas_musicais = 0;
    int notas_musicais[SIZE];
	  int valor_limit = 0;
    int result = 0;

    while(scanf("%d", &q_notas_inicias) != EOF) {

        soma_das_notas_musicais = 0; result = 1;

        for (k = 0; k < SIZE; k++) {
            notas_musicais[k] = 0;
        }
        
        for (i = 0; i < q_notas_inicias; i++) {
            scanf("%d", &notas_musicais[i]);
            soma_das_notas_musicais += notas_musicais[i];
        }
		
		valor_limit = soma_das_notas_musicais/q_notas_inicias;

        if (soma_das_notas_musicais % q_notas_inicias == 0) {
            // algorítimo principal
          for (c = 0; c < i; c++) {
            //printf("c = %d\n", c);
            if (notas_musicais[c] < valor_limit) {
              result += valor_limit - notas_musicais[c]; 
            }
          }
          printf("%d\n", result);
        }

        else printf("-1\n");
		
		/*for (h = 0; h < i; h++) {
			printf("%d ", notas_musicais[h]);
		}*/
    }

    return 0;
}