#include<stdio.h>

int main() {
    int andre_atk, beto_atk, andre_time, beto_time, boss_hp = 1, q_casos;
    int andre = 0, beto = 0;
    int andre_time_inicial, beto_time_inicial;
    int i;

    scanf("%d", &q_casos);

    for (i = 0; i < q_casos; i++) {
        scanf("%d %d %d %d", &andre_atk, &andre_time, &beto_atk, &beto_time);
        scanf("%d", &boss_hp);
        andre_time_inicial = andre_time;
        beto_time_inicial = beto_time;
        andre = 0; beto = 0;
        boss_hp -= andre_atk;
        boss_hp -= beto_atk;

        while(1) {
            printf("andre_time = %d, beto_time = %d\n", andre_time, beto_time);
            //printf("boss_hp = %d\n", boss_hp);
            andre_time--;
            beto_time--;
            if (andre_time < 0) {
                printf("boss_hp = %d\n", boss_hp);
                boss_hp -= andre_atk;
                printf("andre_atk\n");
                andre_time = andre_time_inicial;
                if (boss_hp <= 0) {
                    andre++;
                    //printf(" \n");
                    printf("Andre\n");
                    //printf(" \n");
                    break;
                }
            }
            if (beto_time < 0) {
                printf("boss_hp = %d\n", boss_hp);
                boss_hp -= beto_atk;
                printf("beto_atk\n");
                beto_time = beto_time_inicial;
                if (boss_hp <= 0) {
                    beto++;
                    //printf(" \n");
                    printf("Beto\n");
                    //printf(" \n");
                    break;
                }
            }
        }
    }

    return 0;
}