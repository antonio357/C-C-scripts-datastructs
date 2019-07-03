#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char str[51];
    int po;
} str_po;

int compara(const void *v1, const void *v2) {
    if (strlen(v1) == strlen(v2)) {
        str_po *_v1 = (str_po*)v1;
        str_po *_v2 = (str_po*)v2;
        if (_v1->po > _v2->po) return 1;
        else if (_v1->po < _v2->po) return -1;
    }
    else if (strlen(v1) > strlen(v2)) return -1;
    else if (strlen(v1) < strlen(v2)) return 1;
}

int main() {
    int N, i = 0, count_spaces = 0, c = 0, j = 0, k = 0, cont = 0, casildes_que_moi_de_var = 0, ok;
    scanf("%d", &N);
    getchar();
    char letra;
    for (i = 0; i < N; i++) {
        char str[(51+1)*50]; 
        c = 0; count_spaces = 0; cont = 0;
        do {
            letra = getchar();
            if (letra == ' ') {count_spaces++; str[c++] = letra;}
            else if (letra == '\n') str[c] = '\0';
            else str[c++] = letra;
        } while(letra != '\n');
        //printf("str = %s;\ncount_spaces = %d;\n", str, count_spaces);
        ok = count_spaces + 1;
        str_po array_str_po[ok];

        char sub_str[51];
        for (j = 0; ; j++) {
            if (str[j] == ' ' || str[j] == '\0') {
                sub_str[k] = '\0';
                k = 0;
                //printf("cont = %d\n", cont);
                //printf("%s\n", sub_str);
                array_str_po[cont].po = cont;
                strcpy(array_str_po[cont++].str, sub_str);
            }
            else {
                sub_str[k++] = str[j];
            }
            if (str[j] == '\0') break;
        }
        qsort(array_str_po, ok, sizeof(str_po), compara);
        for (casildes_que_moi_de_var = 0; casildes_que_moi_de_var < ok; casildes_que_moi_de_var++) {
          if (casildes_que_moi_de_var == ok - 1) printf("%s", array_str_po[casildes_que_moi_de_var].str);
          else printf("%s ", array_str_po[casildes_que_moi_de_var].str);
        } printf("\n");
    }
    //for (i = 0; i < N; i++) printf("%s\n", matriz[i]);
    return 0;
}