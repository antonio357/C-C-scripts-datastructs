#include<stdio.h>

int main() {
    char name[50];
    double fixed_salary, total_sales, TOTAL;

    scanf("%s", name);
    scanf("%lf", &fixed_salary);
    scanf("%lf", &total_sales);

    TOTAL = fixed_salary + total_sales*0.15;

    printf("TOTAL = R$ %.2lf", TOTAL);
    return 0;
}
