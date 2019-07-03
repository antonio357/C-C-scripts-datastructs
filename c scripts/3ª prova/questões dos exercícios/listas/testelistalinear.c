#include <stdio.h>
#include<string.h>
#include "listalinear.h"

int main() {
    lista *l = criaLista(5);
    insere(l,10);
    insere(l,20);
    insere(l,5);
    printLista(*l);
    remove_pos(l,1);
    printLista(*l);
    insere(l,40);
    insere(l,60);
    insere(l,70);
    printf("Max: %d\n",l->max);
    insere(l,90);
    printf("Max: %d\n",l->max);
    insere(l,100);
    printLista(*l);
    printf("Elemento pos %d = %d\n", 3, get(*l,3));
    printf("Elemento pos %d = %d\n", 1, get(*l,1));  
    //libera(l);
    int p, v, veryf;
    do {
        p = -1024;
        v = -1024;
        veryf = -1024;
        char func[3];
        printf("digite aa <-> para hasElement\n");
        printf("digite ss <-> para inserPosition\n");
        printf("digite dd <-> para removeElement\n");
        scanf("%s", func);
        if (strcmp(func, "aa") == 0) {
            printf("digite um valor:\n");
            scanf("%d", &v);
            printf("retorno da funssao >>> %d\n", hasElement(l, v));
            printLista(*l);
        }
        else if (strcmp(func, "ss") == 0) {
            printf("digite um valor:\n");
            scanf("%d", &v);
            printf("digite uma posissao:\n");
            scanf("%d", &p);
            printf("lista antes de inserir o %d n posissao %d\n", v, p);
            printLista(*l);
            printf("retorno da funssao >>> %d\n", insertPosition(l, v, p));
            printf("lista depois de inserir o %d n posissao %d\n", v, p);
            printLista(*l);
        }
        else if (strcmp(func, "dd") == 0) {
            printf("digite um valor:\n");
            scanf("%d", &v);
            printf("lista antes da remover %d\n", v);
            printLista(*l);
            printf("retorno da funssao >>> %d\n", removeElement(l, v));
            printf("lista depois da remover %d\n", v);
            printLista(*l);
        }
        printf("se este for o ultimo caso de teste digite -1 caso contrario digite qualquer outro numero\n");
        scanf("%d", &veryf);

    } while(veryf != -1);
    /*printf("begins here\n");
    printf("1 - %d\n", hasElement(l, 10));
    printf("2 - %d\n", hasElement(l, 1)); 
    printf("3 - %d\n", insertPosition(l, 50, 2));
    printLista(*l);
    printf("4 - tem que ter o 50 na posissao 2\n");
    printf("5 - %d\n", insertPosition(l, 156, 1024));
    printLista(*l);
    printf("6 - nope is pra ter 156 na posissao 1024");
    printf("7 - %d\n", removeElement(l, 10));
    printf("8 - nope is mais pra ter o elemento 10\n");
    printLista(*l);   
    printf("9 - %d\n", removeElement(l, 145));
    printf("10 - nope is pra conseguir remover o elemento 145\n");
    printLista(*l); 
    libera(l);*/
    return 0;
}
