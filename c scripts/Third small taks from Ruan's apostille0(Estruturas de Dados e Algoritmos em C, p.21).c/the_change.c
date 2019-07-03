#include<stdio.h>

int main() {
    double q_cases = 0, money = 0, brands = 0, price = 0, change_atu = 0.0, change_best = 0.0;
    int i = 0, k = 0;
    int divid = 0;

    scanf("%lf", &q_cases);

    for (i = 0; i < q_cases; i++) {
        scanf("%lf %lf", &money, &brands);
        change_best = 0.0;

        for (k = 0; k < brands; k++) {
            scanf("%lf", &price);

        if (price <= money) {
            divid = money/price;
            /*printf("\n");
            printf("divid = %d\n", divid);
            printf("\n");*/
            change_atu = money - (divid*price);
            if (change_atu >= change_best) {
                change_best = change_atu;
            }
        }    
            
        }

        printf("%.2lf\n", change_best);
    }

    return 0;
}