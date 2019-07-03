#include<stdio.h>

// reminding that p1 < p2 and c1 > c2;

int main() {
    int p1 = 0.0, p2 = 0.0; double c1 = 0.0, c2 = 0.0; 
    int q = 0, counter = 0, counter_years = 0;

    scanf("%d", &q);
    //p2 = 1;
    //p1 = 1;


    for (counter = 0; counter < q; counter++) {

        scanf("%d %d %lf %lf", &p1, &p2, &c1, &c2);

        do {
            //printf("okay\n");
            //p1++;
            //printf("p1 = %e\np2 = %e\ncounter_years = %d\n", p1, p2, counter_years);

            p1 += p1*(c1/100);
            p2 += p2*(c2/100);
            counter_years++;

            if (counter_years > 100) {
                break;
            }

        } while(p1 <= p2);

        if (counter_years <= 100) {printf("%d anos.\n", counter_years);}
        else {printf("Mais de 1 seculo.\n");}

        counter_years = 0;

    }
    return 0;
}
