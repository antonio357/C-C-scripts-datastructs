#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int num;
    int mod;
} elem;

int compara(const void *p1, const void *p2) {
    elem *c_p1 = (elem*)p1; elem *c_p2 = (elem*)p2;
    //printf("num1 = %d, num2 = %d\n", c_p1->num, c_p2->num);
    //printf("mod1 = %d, mod2 = %d\n", c_p1->mod, c_p2->mod);
    if (c_p1->mod == c_p2->mod) {
      //printf("entrou em mods iguais\n");
      if (c_p1->num % 2 == 0 && c_p2->num % 2 != 0) {
        //printf("1º\n");
        return 1;
      }
      else if (c_p1->num % 2 != 0 && c_p2->num % 2 == 0) {
        //printf("2º\n");
        return -1;
      }
      else if (c_p1->num % 2 != 0 && c_p2->num % 2 != 0) {
        //printf("3º\n");
        if (c_p1->num > c_p2->num) return -1;
        //printf("passou\n");
        return 1;
      }
      else if (c_p1->num % 2 == 0 && c_p2->num % 2 == 0) {
        //printf("4º\n");
        if (c_p1->num < c_p2->num) return -1;
        //printf("passou\n");
        return 1;
      }
    }
    else {
      //printf("entrou em mods diferentes\n");
      if (c_p1->mod < c_p2->mod) return -1;
      //printf("passou\n");
      return 1;
    }
}

int main() {
    
    while(1) {
        int N, M, i = 0;
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) {
            printf("%d %d\n", 0, 0);
            break;
        }
        printf("%d %d\n", N, M);
        elem vet[N];
        for (i = 0; i < N; i++) {
            scanf("%d", &vet[i].num);
            vet[i].mod = vet[i].num % M;
        }
        qsort(vet, N, sizeof(elem), compara);
        //printf("depois_da_ordenação\n");
        for (i = 0; i < N; i++) printf("%d\n", vet[i].num);
    }

    return 0;
}