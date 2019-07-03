#include <stdio.h>

#define SIZE 1060

int main() {

    while(1) {
        int i = 0;
        int diferenssa = 0;
        char caracter;
        char frase[SIZE];
        char anterior;
        char atual;
        int armazenamento = 0;
        char ok = 'Y';

        frase[i] = getchar();
        if (frase[0] == '*') break;
        if (frase[i] != ' ') {
            anterior = frase[i];
            armazenamento = 1;
        }

        while (1) {
            i++;
            frase[i] = getchar();

            if (frase[i] == '\n') {
                frase[i + 1] = '\0';
                break;
            } 

            if (armazenamento == 0 && frase[i] != ' ') {
                anterior = frase[i];
                armazenamento = 1;
            }

            if (armazenamento == 1 && frase[i] != ' ' && frase[i - 1] == ' ') {
                atual = frase[i];
                armazenamento = 2;
            }

            if (armazenamento == 2) {
                diferenssa = atual - anterior;
                anterior = atual;
                armazenamento = 1;
                
                if (!(diferenssa == 32 || diferenssa == -32 || diferenssa == 0)) {
                    ok = 'N';
                }
            }
        }
        printf("%c\n", ok);
        // pirnta a stringa que foi colocada na entrada
        /*i = 0;
        do {
            printf("%c", frase[i]);
            i++;
        }while(frase[i] != '\0');*/
    }

    return 0;
}