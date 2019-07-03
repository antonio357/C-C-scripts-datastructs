#include<stdio.h>

#define SIZE 61

int main() {
    while (1) {
        char palavra_numerica[SIZE];
        char caracter;
        int i = 0;
        int k = 0;
        int must_brk = 0;
        int must_brk_1 = 0;
        int must_brk_2 = 0;
        int counter_size = 0;
        char primeiro_caracter = 'n';
        char segundo_caracter = 'n';
        char terceiro_caracter = 'n';

        while(1) {
            caracter = getchar();
            if (i == 0 && caracter == '\n') {
                must_brk_2 = 1;
            }
            if(i >= 0 && i < 4) {
                if (i == 0 && caracter == '0') {primeiro_caracter = '1';}
                else if ( i == 1 && caracter == '0') {segundo_caracter = '1';}
                else if (i == 2 && caracter == '\n') {terceiro_caracter = '1';}
                if (primeiro_caracter == '1' && segundo_caracter == '1' && terceiro_caracter == '1') {
                    must_brk = 1;
                    break;
                }
            }
            if (caracter == 'O' || caracter == 'o') {caracter = '0';}
            else if (caracter == 'l') {caracter = '1';}
            else if (caracter == ',' || caracter == ' ') {continue;}
            palavra_numerica[i] = caracter;
            i++;
            counter_size++;
            if (palavra_numerica[i - 1] == '\n') break;
        } 

        if (must_brk_2 == 1) {
            printf("error\n");
            continue;
        }
        
        if (must_brk == 1) {
            printf("0\n");
            break;
        }

        palavra_numerica[i] = '\0';
        for (k = 0; k < i; k++) {
            if ((!(palavra_numerica[k] >= 48 && palavra_numerica[k] <= 57)) || palavra_numerica[0] == '\n') {
                printf("error\n");
                must_brk_1 = 1;
                break;
            }
        }

        if (must_brk_1 == 0) {
            for (k = 0; k < i + 5; k++) {
                printf("%c", palavra_numerica[k]);
            }
        }
        printf("counter_size = %d\n", counter_size);
    }
    return 0;
}