#include<stdio.h>

int fat(int num) {
    if (num == 1) return 1;
    return num * fat(num - 1);
}
double pw(double num, int ex) {
    if (ex == 1) return num;
    return num * pw(num, ex - 1);
}
double seno(double x, int qt) {
    int n = 2 * qt + 1;
    if (qt == 0) return x;
    else if (qt == 1) return x - (pw(x, 3)/fat(3));
    else if (qt > 1) {
        if (qt % 2 == 0) return seno(x, qt - 1) + (pw(x, n)/fat(n));
        else if (qt % 2 != 0) return seno(x, qt - 1) - (pw(x, n)/fat(n));
    }
}
int main() {
    printf("%d\n", fat(1));
    printf("%lf\n", pw(5, 3));
    printf("%lf\n", seno(30, 5));
    return 0;
}