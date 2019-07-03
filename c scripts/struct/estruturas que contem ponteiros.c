#include<stdio.h>

int main() {

    struct horario{
        int *phora;
        int *pminuto;
        int *psegundos;
    };

    struct horario hoje;

    int hora = 200;
    int minuto = 300;
    int segundos = 400;


    hoje.phora = &hora;
    hoje.pminuto = &minuto;
    hoje.psegundos = & segundos;

    printf("Hora = %d\n", *hoje.phora);
    printf("Minuto = %d\n", *hoje.pminuto);
    printf("Segundo = %d\n", *hoje.psegundos);

    *hoje.psegundos = 1000;
     printf("Segundo = %d\n", *hoje.psegundos);
    return 0;
}