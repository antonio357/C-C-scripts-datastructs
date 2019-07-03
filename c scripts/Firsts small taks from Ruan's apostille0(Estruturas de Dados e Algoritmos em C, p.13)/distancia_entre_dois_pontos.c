#include<stdio.h>
#include<math.h>

int main() {
    double p1,x1,y1;
    double p2,x2,y2;
    double distance;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    p1 = (x2 - x1); p2 = (y2 - y1);
    distance = sqrt(p1*p1 + p2*p2);

    printf("%.4lf", distance);
    return 0;
}
