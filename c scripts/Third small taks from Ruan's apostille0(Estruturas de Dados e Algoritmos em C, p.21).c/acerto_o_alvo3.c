#include<stdio.h>

int main() {
    long double asb, ast, ait, aib;
    long double dis, ia, fa;
    int i, q_casos, may = 1, ft = 1;

    scanf("%d", &q_casos);

    for(i = 0; i <= q_casos; i++) {

        scanf("%Lf %Lf %Lf", &dis, &ia, &fa);

        if (ft == 1) {
            asb = fa/dis ; aib = ia/dis;
            ft--;
        }
        else {
            ast = fa/dis ; ait = ia/dis;

            if (asb >= ast && ast >= aib) {
                asb = ast;
                if (aib >= ait) {
                    aib = aib;
                }
                else if (aib < ait) {
                    aib = ait;
                }
            }

            else if(asb < ast && ait <= asb) {
                asb = asb;
                if (ait > aib) {
                    aib = ait;
                }
                else if (ait <= aib) {
                    aib = aib;
                }
            }

            else {
              may--;
              //break;
            }
        }

    } 

    if (may == 1) {
            printf("Y\n");
    }
    else {
        printf("N\n");
    }

    return 0;
}