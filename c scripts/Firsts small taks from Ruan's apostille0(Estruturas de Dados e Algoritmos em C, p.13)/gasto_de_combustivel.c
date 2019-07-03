#include<stdio.h>

int main () {
    double time, vm, gas;

    scanf("%lf", &time);
    scanf("%lf", &vm);

    gas = (time*vm)/12;

    printf("%.3lf", gas);
    return 0;
}
