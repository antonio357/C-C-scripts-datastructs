#include<stdio.h>

int main() {
    int hora_inicial = 0, minuto_inicial = 0, hora_final = 0, minuto_final = 0, hora_resultante = 0, minuto_resultante = 0;

    scanf("%d %d %d %d", &hora_inicial, &minuto_inicial, &hora_final, &minuto_final);

    if (hora_inicial == hora_final) { 
        hora_resultante = 24;
        
        if (minuto_inicial == minuto_final) {
            minuto_resultante = 0;
        }
        else if (minuto_inicial > minuto_final) {
                minuto_inicial -= 60;
                minuto_inicial *= -1;
                minuto_resultante = minuto_inicial + minuto_final;

                if (hora_resultante*60 > minuto_resultante) {
                    hora_resultante--;
                }
        }
        else if (minuto_inicial < minuto_final) {
            minuto_resultante = minuto_final - minuto_inicial;
            hora_resultante = 0;
        }
    }

    else if (hora_inicial > hora_final) {
        hora_resultante = 24 - (hora_inicial - hora_final);

        if (minuto_inicial > minuto_final) {
                minuto_inicial -= 60;
                minuto_inicial *= -1;
                minuto_resultante = minuto_inicial + minuto_final;

                if (hora_resultante*60 > minuto_resultante) {
                    hora_resultante--;
                }
        }
        else if (minuto_inicial < minuto_final) {
            minuto_resultante = minuto_final - minuto_inicial;
        }    
    }  

    else if (hora_inicial < hora_final) {
        hora_resultante = hora_final - hora_inicial;

        if (minuto_inicial > minuto_final) {
                minuto_inicial -= 60;
                minuto_inicial *= -1;
                minuto_resultante = minuto_inicial + minuto_final;

                if (hora_resultante*60 > minuto_resultante) {
                    hora_resultante--;
                }
        }
        else if (minuto_inicial < minuto_final) {
            minuto_resultante = minuto_final - minuto_inicial;
        }
    }

    if (hora_resultante <= 0 && minuto_resultante <= 0) {
        hora_resultante = 0;
    }
    else if (hora_resultante > 24 || hora_resultante == 24 && minuto_resultante > 0) {
        hora_resultante = 24;
        minuto_resultante = 0;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", hora_resultante, minuto_resultante);
    return 0;
}