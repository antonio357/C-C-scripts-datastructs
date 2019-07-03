#include<stdio.h>

int main() {
    double angulo_baixo_atu, angulo_baixo_ant = 0, angulo_alto_atu, angulo_alto_ant = 0, q_casos, i, may = 0;
    double distancia, distancia_ant = 0.0;
    double inicio_abertura, final_abertura;
    int first_time = 1;

    scanf("%lf", &q_casos);

    for(i = 0; i <= q_casos; i++) {

        scanf("%lf %lf %lf", &distancia, &inicio_abertura, &final_abertura);

        if (first_time == 1) {
            angulo_baixo_ant = inicio_abertura/distancia; angulo_alto_ant = final_abertura/distancia;
            first_time--;
        }

        angulo_baixo_atu = inicio_abertura/distancia; angulo_alto_atu = final_abertura/distancia;

        if (angulo_baixo_atu > angulo_alto_ant || angulo_alto_atu < angulo_baixo_ant) {
            may--;
        }
        else {
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
        printf("angulo_baixo_ant = %lf, angulo_alto_ant = %lf\n", angulo_baixo_ant, angulo_alto_ant);
        printf("angulo_baixo_atu = %lf, angulo_alto_atu = %lf\n", angulo_baixo_atu, angulo_alto_atu);
        //printf("angulo_baixo_ant = %lf, angulo_alto_ant = %lf\n", angulo_baixo_ant, angulo_alto_ant);*/
        //printf("may = %lf\n", may);
        /*if (distancia <= distancia_ant) {
            may = -10050;
        }/*
        /*printf("distancia = %lf\n", distancia);
        printf("distancia_ant = %lf\n", distancia_ant);*/
        angulo_alto_ant = angulo_alto_atu; angulo_baixo_ant = angulo_baixo_atu; distancia_ant = distancia;
        /*printf("distancia = %lf\n", distancia);
        printf("distancia_ant = %lf\n", distancia_ant);*/
        /*printf("angulo_baixo_ant = %lf, angulo_alto_ant = %lf\n", angulo_baixo_ant, angulo_alto_ant);
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