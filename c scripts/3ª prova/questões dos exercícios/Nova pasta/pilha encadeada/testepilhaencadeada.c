#include<stdio.h>
#include"pilhaencadeada.h"

int check_string(char vet[], pile* pil) {
    int i = 0; 
    int check;
    int its_ok = 1;
    for (i = 0; vet[i] != '\0'; i++) {
        if (vet[i] == '[' || vet[i] == '(' || vet[i] == '{') push(pil, vet[i]);
        else if (vet[i] == ']' || vet[i] == ')' || vet[i] == '}') {
            check = pop(pil);
            if (vet[i] == ']' && check == '[') continue;
            else if (vet[i] == ')' && check == '(') continue;
            else if (vet[i] == '}' && check == '{') continue;
            else {
                its_ok = 0;
                break;
            }
        }
    }
    if (pil->top != NULL) its_ok = 0;
    return its_ok;
}

int main() { 
    int i;
    pile* pil = create_pile();
    print_pile(pil);
    for (i = 0; i < 6; i++) {
        push(pil, i);
        print_pile(pil);
    }
    print_pile(pil);
    for (i = 0; i < 6; i++) {
        pop(pil);
        print_pile(pil);
    }
    print_pile(pil);
    for (i = 0; i < 6; i++) push(pil, i);
    print_pile(pil);
    clear_pile(pil);
    print_pile(pil);

    // atividade do final do material do suap sobre pilha
    int N;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        pile* pil1 = create_pile();
        char vet[100];
        scanf("%s", vet);
        if (check_string(vet, pil1) == 1) printf("OK\n");
        else printf("WRONG\n");
        del_pile(pil1);
    }
    return 0;
}