#include<stdio.h>

int main() {
    struct ponto {
        double x;
        double y;
    };

    struct ponto p;
    p.x = 12;
    p.y = 15;

    struct ponto *pp;
    pp->x = 78;


    printf("p.x = %.2lf\np.y = %.2lf\n", p.x, p.y);
    printf("p.x = %.2lf\np.y = %.2lf\n", (*pp).x, (*pp).y);


    


    return 0;
}