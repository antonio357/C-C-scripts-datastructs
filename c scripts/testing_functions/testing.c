#include<stdio.h>

float celsius_fahrenheit (float c) {
    float f;
    f = 1.8 * c + 32;
    return f;
}

int main(void) {
    float c;
    float f;
    printf("Entre com temperatura em celsius: ");
    scanf("%f", &c);
    f = celsius_fahrenheit(c);
    printf("Temperatura em Fahreheit: %f\n", f);
    return 0;
}