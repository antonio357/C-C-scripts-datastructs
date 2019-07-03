#include<stdio.h>
#include"pilha.h"

int main() {
    int i;
    pile* pile1 = create_pile();
    print_pile(pile1);
    for (i = 1; i < size+1; i++) push(pile1, i);
    printf("pile1->top = %d\n", pile1->top);
    print_pile(pile1);
    for (i = 1; i < size+1; i++) pop(pile1);
    printf("pile1->top = %d\n", pile1->top);
    print_pile(pile1);
    return 0;
}