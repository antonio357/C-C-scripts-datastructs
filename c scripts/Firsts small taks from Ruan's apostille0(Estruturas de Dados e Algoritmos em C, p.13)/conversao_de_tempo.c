#include<stdio.h>

int main() {
    int seconds = 0;
    int minuts = 0;
    int hours = 0;

    scanf("%d", &seconds);

    hours = seconds/3600;
    minuts = (seconds%3600)/60;
    seconds = seconds%60;
    
    printf("%d:%d:%d\n", hours, minuts, seconds);
    return 0;
}
