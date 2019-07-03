#include<stdio.h>

int main(void) {
    int altura = 0, largura = 0;
    int i = 0, k = 0;

    while(1) {
        scanf("%d %d", &altura, &largura);
        if (altura == 0 && largura == 0) break;        
        
        int lis[largura];
        int diferenssa = 0; 
        int iterassoes = 0;

        for (i = 0; i < largura; i++) {
            scanf("%d", &lis[i]);
            if (i == 0) {
                iterassoes += altura - lis[0];
            }
            else if (i > 0) {
                if (lis[i] <  lis[i - 1]) {
                    iterassoes += lis[i - 1] - lis[i];
                }
            }  
        }
        printf("%d\n", iterassoes);        
    }
    return 0;
}