#include<stdio.h>

int its_only_spaces (char str[100]) {
    int f = 0;

    for (f = 0; f < 100; f++) {
        if (str[f] == '\n') break;
        else if (str[f] != ' ') {
            return 0;
        }
    }
    return 1;
}


int main(void) {
    int q_casos = 0;
    int i = 0, k = 0;
    int counter = 0;
    char name[100];
    char saida[50];

    scanf("%d\n", &q_casos);

    for (k = 0; k < q_casos; k++) {
        scanf("%[^\n]s", name);
        counter = 0;
        if (its_only_spaces(name) == 1) {
            printf("\n");
        }
        else {
            for (i = 0; i < 100; i++) {
                if (name[i] == '\n') break;
                else if (name[i] != ' ' && name[i - 1] == ' ') {
                    saida[counter] = name[i];
                    counter++;
                }
            }
            if (name[0] != ' ') printf("%c", name[0]);
            printf("%s\n", saida);
        }
    }

    return 0;
}