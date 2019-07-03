#include<stdio.h>

#define SIZE 2001

int main() {
    int q_entradas = 0;
    int i = 0, num, k = 0, g = 0;
    int entradas[SIZE];

    scanf("%d", &q_entradas);

    for (k = 0; k < SIZE; k++) {
        entradas[k] = 0;
    }

    for (i = 0; i < q_entradas; i++) {
        scanf("%d", &num);

        entradas[num]++;
    }

    for (g = 0; g < SIZE; g++) {
        if (entradas[g] > 0) {

            printf("%d aparece %d vez(es)\n", g, entradas[g]);
        }
    }

    return 0;
}