#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define True 1
#define False 0

    int verifyListInt(const char palavra[]) {
        int q_num = 0;
        int may = True; 

        for (int i = 0; palavra[i] != '\0'; i++) { 
            if (palavra[i] != ' ' && (palavra[i] < '0' || palavra[i] > '9')) return 0;
            if (may == True) {
                if (palavra[i] >= '0' && palavra[i] <= '9') {
                    q_num++;
                    may = False;
                }
            }
            else if (may == False) {
                if (palavra[i] < '0' || palavra[i] > '9'){
                    may = True;
                }
            } 
        }
        //printf("string = %s\n", palavra);
        //printf("q_num = %d\n", q_num);
        return q_num;
    }

    int* splitInt(const char palavra[], int *len) {
        if (verifyListInt(palavra) == 0) {
            *len = 0;
            return NULL;
        }
        *len = verifyListInt(palavra);
        int *array_int = (int*)malloc(verifyListInt(palavra)*sizeof(int));
        int counter = 0;
        int i = 0;
        int j = 0;

        //printf("counter = %d\n",counter);
        for (j = 0; j < *len; j++) {
            char *palavra_numerica = (char*)calloc(10, sizeof(char));
            int count = 0;
            int may = False;
            for (i = counter; palavra[i] != '\0'; i++) {
                counter++;
                if (palavra[i] >= '0' && palavra[i] <= '9') may = True;
                else if ((palavra[i] < '0' || palavra[i] > '9') || palavra[i] == ' ') may = False;
                if (may == True) {
                    if (palavra[i] >= '0' && palavra[i] <= '9') {
                        palavra_numerica[count] = palavra[i];
                        count++;
                    }
                }
                else if (may == False) {
                    if (i > 0) {
                        if (palavra[i - 1] >= '0' && palavra[i - 1] <= '9') {
                            palavra_numerica[count] = ' ';
                            break;
                        }
                    }
                }
            }
            array_int[j] = atoi(palavra_numerica);
            //printf("j = %d\n", j);
            //printf("counter = %d\n", counter);
            free(palavra_numerica);
        }
        return array_int;
    }

int main() {

    char ent[100];
    scanf("%[^\n]s" , ent);
    int size;
    int *ent_int = splitInt(ent,&size);
    
    if (ent_int == NULL) {
        printf ("String inválida");
        return -1; 
    }

    printf ("Size: %d\n" , size); 

    for (int i = 0; i < size; i++) {
      printf ("%d " ,ent_int[i]) ; 
    }

    return 0;
}