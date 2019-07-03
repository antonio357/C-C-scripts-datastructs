#include<stdio.h>

int main() {
    int num, h, m, s; // num comes in seconds

    scanf("%d", &num);

    s = num;
    h = 0;
    m = 0;

    while(s > 59) {
        if(s > 59) {
            s -= 60;
            m++;
        }

        if(m > 59) {
            m -= 60;
            h++;
        }
    }

    

    printf("%d:%d:%d", h,m,s);
    return 0;
}
