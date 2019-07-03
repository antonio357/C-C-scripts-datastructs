#include<stdio.h>

int main() {
    int num1, num2, num3, num4, horas, minutos, segundos;

    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    num1 *= 3600;
    num2 *= 60;
    num3 *= 3600;
    num4 *= 60;

    num1 += num2;
    num3 += num4;

    if (num1 == num3 && num2 - num4 == 1) {
        horas = 23;
        minutos = 59;
    }

    else if (num1 < num3) {
        segundos = num3 - num1;

        horas = segundos/3600;
        minutos = (segundos - (horas * 3600))/60;
    }

    else if (num1 > num3) {
        segundos = num1 - num3;

        horas = segundos/3600;
        minutos = (segundos - (horas * 3600))/60;
    }

    else if (num1 == num3) {
        horas = 24;

        minutos = (segundos%3600)/60;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", horas, minutos);
    return 0;
}