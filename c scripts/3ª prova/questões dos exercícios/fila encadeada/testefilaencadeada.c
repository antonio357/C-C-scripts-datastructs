#include<stdio.h>
#include"filaencadeada.h"

int main() {
    row* r = create_row();
    print_row(r);
    int i;
    for (i = 0; i < 10; i++) {
        append(r, i);
        print_row(r);
    }
    for (i = 0; i < 10; i++) {
        printf("elemento removido = %d\n", drop(r));
        print_row(r);
    }
    for (i = 0; i < 100; i++) append(r, i);
    print_row(r);
    clear_row(r);
    print_row(r);
    return 0;
}