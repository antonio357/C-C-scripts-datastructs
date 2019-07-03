#include<stdio.h>

int main() {
    int num1, num2, num3, num4, horas = 0, minutos = 0, segundos;

    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    num1 *= 3600;
    num2 *= 60;
    num3 *= 3600;
    num4 *= 60;

    num1 += num2;
    num3 += num4;

    if (num1 < num3) {
        segundos = num3 - num1;

        //horas = segundos/3600;
        //minutos = (segundos%3600)/60;

        while(1) {
            if (segundos < 59) {
                break;
            }
            if (segundos >= 59) {
                minutos += 1;
                segundos -= 60;
                if (minutos > 59) {
                    horas += 1;
                    minutos -= 59;
                }
            }
        }
    }

    else if (num1 > num3) {
        segundos = num1 - num3;

        //  horas = segundos/3600;
        //minutos = (segundos%3600)/60;

         while(1) {
             if (segundos <= 59) {
                break;
            }
            if (segundos > 59) {
                minutos += 1;
                segundos -= 60;
                if (minutos > 59) {
                    horas += 1;
                    minutos -= 59;
                }
            }
        }
    }

    else if (num1 == num3) {
        horas = 24;

        minutos = (segundos%3600)/60;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
    return 0;
}