#include<stdio.h>

int main() {
    long double angulo_baixo_atu, angulo_baixo_ant = 0, angulo_alto_atu, angulo_alto_ant = 0, q_casos, i;
    long double distancia, distancia_ant = 0.0;
    long double inicio_abertura, final_abertura;
    long double incio_da_faixa_de_valor_base = 0.0, final_da_faixa_de_valor_base = 10000.0;
    long double incio_faixa_de_valor_atu, final_da_faixa_de_valor_atu;
    int first_time = 1, may = 0;;

    scanf("%Lf", &q_casos);

    for(i = 0; i <= q_casos; i++) {

        scanf("%Lf %Lf %Lf", &distancia, &inicio_abertura, &final_abertura);

        angulo_baixo_atu = inicio_abertura/distancia; angulo_alto_atu = final_abertura/distancia;

        incio_faixa_de_valor_atu = angulo_baixo_atu; final_da_faixa_de_valor_atu = angulo_alto_atu;

        //confere se ha inetercessoes entre aa faixa de valor base e a faixa de valor atu
        if (!(incio_faixa_de_valor_atu > final_da_faixa_de_valor_base || final_da_faixa_de_valor_atu < incio_da_faixa_de_valor_base)) {
            may++;
            printf("OKAY %d\n", i);
            if (final_da_faixa_de_valor_atu < final_da_faixa_de_valor_base){
                final_da_faixa_de_valor_base = angulo_alto_atu - incio_da_faixa_de_valor_base;
            }
            if (incio_faixa_de_valor_atu > incio_da_faixa_de_valor_base){
                incio_da_faixa_de_valor_base = angulo_baixo_atu + (incio_da_faixa_de_valor_base - angulo_baixo_atu);
            }
              
        }
    

        //final_da_faixa_de_valor_base = angulo_alto_atu;  
        //incio_da_faixa_de_valor_base = final_da_faixa_de_valor_base - incio_da_faixa_de_valor_base;     
        printf("incio_da_faixa_de_valor_base = %Lf\n", incio_da_faixa_de_valor_base);
        printf("may = %d\n", may);
    } 

    if (may == q_casos + 1) {
            printf("Y\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}