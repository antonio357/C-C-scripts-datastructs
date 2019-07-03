#include<stdio.h>

int main(void) {  
    while(1) {
        int linhas = 0;
        int i = 0;
        char caracter;
        int s = 0;
        int h = 0;
        int b = 0;
        scanf("%d", &linhas);
        getchar();
        if (linhas == 0) break;
        char frases_saida[linhas][100];
        int tamanho_das_strings_armazenadas[linhas];
        int tamanho_da_maior_string = 0;
        for (i = 0; i < linhas; i++) {
            char frase[100];
            int k = 0;
            int counter = 0;
            int id = 0;
            do {
                caracter = getchar();
                frase[id] = caracter; 
                id++;
            } while(caracter != '\n'); frase[id] = '\0';
            //processar a string para remover os exessos de espaços;
            // vai ate o '\n'
            //printf("id = %d\n", id);
            int primeira_letra = 0;
            for (k = 0; k < id; k++) {
                if (primeira_letra == 1) {
                    if (frase[k] == ' ' && frases_saida[i][counter - 1] != ' ') {
                        frases_saida[i][counter] = frase[k];
                        counter++;
                    }
                    if (frase[k] != ' ') {
                        frases_saida[i][counter] = frase[k];
                        counter++;
                    }
                }
                else if (frase[k] != ' ') {
                    frases_saida[i][counter] = frase[k];
                    counter++;
                    primeira_letra = 1;
                }               
            }
            //printf("counter = %d\n", counter);
            //printf("counter = %d\n", counter); // counter - 1 == tamanho da string armazenada;
            //certifica que no final da string vai ter o '\0'
            frases_saida[i][counter] = '\0';
            // armazena a informação dos tamnahos das strings;
            tamanho_das_strings_armazenadas[i] = counter - 1;
            // ganbiarra pra tirar o último espaço da string se ela tiver um espaço no final
            if (frases_saida[i][counter - 2] == ' ') {
                frases_saida[i][counter - 2] = '\n';
                frases_saida[i][counter - 1] = '\0';
                tamanho_das_strings_armazenadas[i]--;
            }
            //printf("tamanho_das_strings_armazenadas[%d] = %d\n", i, tamanho_das_strings_armazenadas[i]);
            //armazena o tamanho da maior string
            if (i == 0) tamanho_da_maior_string = tamanho_das_strings_armazenadas[0];
            else if (i > 0) {
                if (tamanho_das_strings_armazenadas[i] > tamanho_da_maior_string) tamanho_da_maior_string = tamanho_das_strings_armazenadas[i];
            }
        }
        // printa as frases
        for (s = 0; s < linhas; s++) {
            if (tamanho_da_maior_string - tamanho_das_strings_armazenadas[s] == 0) {
                for (h = 0; h < 100; h++) {
                    if (frases_saida[s][h] == '\0') break;
                    //if (frases_saida[s][h] == ' ') printf("*");
                    else printf("%c", frases_saida[s][h]);
                }
            }
            else {
                for (b = 0; b < (tamanho_da_maior_string - tamanho_das_strings_armazenadas[s]) ;b++) printf(" ");
                for (h = 0; h < 100; h++) {
                    if (frases_saida[s][h] == '\0') break;
                    //if (frases_saida[s][h] == ' ') printf("*");
                    else printf("%c", frases_saida[s][h]);
                }
            }
        }
        printf("\n");
        //printf("tamanho_da_maior_string = %d\n", tamanho_da_maior_string);
    }
    return 0;
}