#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>

int main() {
    int value = -11; 
    int * teste = (int *)malloc(sizeof(int));
    
    printf("%p\n", teste);

    for (;;){
        printf("%i", teste);
        continue;
    }

    
}