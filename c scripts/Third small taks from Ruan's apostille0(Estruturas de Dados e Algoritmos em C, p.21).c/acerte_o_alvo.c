#include<stdio.h>

int main() {
    double n = 0, di = 0, bi = 0, ti = 0, di_ant = 0;
    double i = 0, lei_de_forma = 0;
    double k_min = 0, k_max = 0;
    double ma = 0, mi = 0, may = 0;


    scanf("%lf", &n);

    if (n == 0) {
        scanf("%lf %lf %lf", &di, &bi, &ti);
        if (ti > bi && di > di_ant) {printf("Y\n");}

        else {printf("N\n");}
    }

    else {
        for (i = 0; i <= n; i++) {
            di_ant = di;

            scanf("%lf %lf %lf", &di, &bi, &ti);
            //if (ti <= bi) {break;} // no hole in the wall

            if (lei_de_forma == 0) {
                k_min = bi/di;
                k_max = ti/di;
                //printf("lei_de_forma = %lf\n", lei_de_forma);
                lei_de_forma = 1;
                //printf("lei_de_forma = %lf\n", lei_de_forma);
            }

            ma = k_max*di; mi = k_min*di;

            if (bi <= ma && ti >= mi && ti > bi && di > di_ant) {
                may++;
            }
            /*printf("\n");
            printf("k_max = %lf, k_min = %lf\n", k_max, k_min);
            printf("bi = %lf, ti = %lf, di = %lf\n", bi, ti, di);
            printf("ma = %lf, mi = %lf\n", ma, mi);
            printf("may = %lf\n", may);
            printf("\n");*/

        }
        if (may == n + 1) {
            printf("Y\n");
        }
        else {
            printf("N\n");
        }
    }
    return 0;
}
    