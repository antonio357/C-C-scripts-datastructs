#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

int compareIdade(const void *a, const void *b) {
    Pessoa *p1 = (Pessoa*)a;
    Pessoa *p2 = (Pessoa*)b;

    return (p1->idade - p2->idade);
}

int compareNome(const void *a, const void *b) {
    Pessoa *p1 = (Pessoa*)a;
    Pessoa *p2 = (Pessoa*)b;
    return strcmp(p1->nome, p2->nome);
}

int main() {
    Pessoa vp[] = {{"pedro", 20}, 
                    {"joao", 40}, 
                    {"maria", 60}, 
                    {"jose", 22}};
    qsort(vp, 4, sizeof(Pessoa), compareNome);
    for (int i = 0; i < 4; i++) {
        printf("Nome: %s\n", vp[i].nome);
        printf("Idade: %s\n", vp[i].idade);
    }
    return 0;
}