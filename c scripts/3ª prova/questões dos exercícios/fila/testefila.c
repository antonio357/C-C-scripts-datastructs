#include<stdio.h>
#include"fila.h"

int main() {
    int i;
    row* r = create_row();
    print_row(r);
    for (i = 1; i < size+1; i++) {
        row_append(r, i);
        print_row(r);
    }
    print_row(r);
    for (i = 1; i < size+1; i++) {
        drop_begin(r);
        print_row(r);
    }
    print_row(r);
    int counter = 2;
    for (i = 1; i < size*3; i++) {
        if (counter > 0) {
            row_append(r, i);
        }
        else if (counter == 0){
            drop_begin(r);
        }
        else counter = 2;
        print_row(r);
        counter--;
    }
    printf("saiu do loop\n");
    for (i = 1; i < 6; i++) row_append(r, i);
    print_row(r);
    return 0;
}