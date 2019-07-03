#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasNoLetter(char *array) {
    for (int i = 0; array[i] != '\n'; i++) {
        if (array[i] != 'o' && array[i] != 'O' && array[i] != 'l' && (array[i] < '0' || array[i] > '9') && array[i] != ',' && array[i] != ' ')return false;
    }
    return true;
}

bool onlyComma(char *array){
    int counter1 = 0;
    for (int i = 0; array[i] != '\n'; i++) {
        if (array[i] >= '0' && array[i] <= '9' || array[i] == 'o' || array[i] == 'O' || array[i] == 'l') return false;

    }


    return true;
}

int main() {
    char valor[80];

    while (fgets(valor, 80 * sizeof(char), stdin) != NULL) {


        int counter = 0;
        char final[80];
        unsigned long long int finalvalue;

        if (valor[0] == '\n' || (valor[0] == ' ' && valor[1] == '\n') ){
            printf("error\n");
        } else {
            if (onlyComma(valor)) {
                printf("error\n");
                continue;
            }
            if (hasNoLetter(valor)) {
                for (int i = 0; valor[i] != '\n'; i++) {
                    if ((valor[i] >= '0' && valor[i] <= '9') || valor[i] == 'l' || valor[i] == 'o' || valor[i] == 'O') {
                        if (valor[i] == 'l') {
                            final[counter] = '1';
                        } else if (valor[i] == 'o' || valor[i] == 'O') {
                            final[counter] = '0';
                        } else {
                            final[counter] = valor[i];
                        }
                        counter++;
                    }
                }

                final[counter] = '\0';
                if (atoll(final) > 2147483647) {
                    printf("error\n");

                } else {
                    printf("%lld\n", atoll(final));
                }

            } else {
                printf("error\n");
            }
        }


    }

    return 0;
}