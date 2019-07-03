#include<stdio.h>

int main() {
    long double angulo_baixo_atu, angulo_baixo_ant = 0, angulo_alto_atu, angulo_alto_ant = 0, q_casos, i, may = 0;
    long double distancia, distancia_ant = 0.0;
    long double inicio_abertura, final_abertura;
    int first_time = 1;

    scanf("%Lf", &q_casos);

    for(i = 0; i <= q_casos; i++) {

        scanf("%Lf %Lf %Lf", &distancia, &inicio_abertura, &final_abertura);

        if (first_time == 1) {
            angulo_baixo_ant = inicio_abertura/distancia; angulo_alto_ant = final_abertura/distancia;
            first_time--;
        }

        angulo_baixo_atu = inicio_abertura/distancia; angulo_alto_atu = final_abertura/distancia;

        /*if (angulo_baixo_atu > angulo_alto_ant || angulo_alto_atu < angulo_baixo_ant) {
            may = may;
        }
        else {
            may++;
        }*/

        if (!(angulo_baixo_atu > angulo_alto_ant || angulo_alto_atu < angulo_baixo_ant)){
            may++;
        }

        /*if (angulo_baixo_atu >= angulo_baixo_ant && angulo_baixo_atu <= angulo_alto_ant) {
            may++;
        }
        else if (angulo_baixo_atu < angulo_baixo_ant && angulo_alto_atu >= angulo_baixo_ant) {
            may++;
        }
        else if (angulo_baixo_atu <= angulo_alto_ant && angulo_alto_atu > angulo_alto_ant) {
            may++;
        }*/
        /*else if (angulo_baixo_atu < angulo_baixo_ant && angulo_alto_atu > angulo_baixo_ant) {
            may++;
        }*/
        /*printf("\n");
        printf("angulo_baixo_ant = %Lf, angulo_alto_ant = %Lf\n", angulo_baixo_ant, angulo_alto_ant);
        printf("angulo_baixo_atu = %Lf, angulo_alto_atu = %Lf\n", angulo_baixo_atu, angulo_alto_atu);
        //printf("angulo_baixo_ant = %Lf, angulo_alto_ant = %Lf\n", angulo_baixo_ant, angulo_alto_ant);*/
        //printf("may = %Lf\n", may);
        /*if (distancia <= distancia_ant) {
            may = -10050;
        }/*
        /*printf("distancia = %Lf\n", distancia);
        printf("distancia_ant = %Lf\n", distancia_ant);*/
        angulo_alto_ant = angulo_alto_atu; angulo_baixo_ant = angulo_baixo_atu; distancia_ant = distancia;
        /*printf("distancia = %Lf\n", distancia);
        printf("distancia_ant = %Lf\n", distancia_ant);*/
        /*printf("angulo_baixo_ant = %Lf, angulo_alto_ant = %Lf\n", angulo_baixo_ant, angulo_alto_ant);
        printf("\n");*/
    } 

    if (may == q_casos + 1) {
            printf("Y\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}