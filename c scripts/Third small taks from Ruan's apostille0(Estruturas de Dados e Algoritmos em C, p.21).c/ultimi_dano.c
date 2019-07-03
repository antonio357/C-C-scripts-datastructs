#include<stdio.h>

int main() {
    int andre_atk, beto_atk, andre_time, beto_time, boss_hp = 1, q_casos;
    int andre = 1, beto = 1;
    int andre_time_inicial, beto_time_inicial;
    int i, ultimo_atk = 0;

    scanf("%d", &q_casos);

    for (i = 0; i < q_casos; i++) {
        scanf("%d %d %d %d", &andre_atk, &andre_time, &beto_atk, &beto_time);
        scanf("%d", &boss_hp);
        boss_hp -= andre_atk;
        if (boss_hp <= 0) {
                printf("Andre\n");
                continue;
            }
        boss_hp -= beto_atk;
        if (boss_hp <= 0) {
                printf("Beto\n");
                continue;
            }
        //andre_time--; beto_time--;
        andre_time_inicial = andre_time;
        beto_time_inicial = beto_time;
        //andre = 0; beto = 0;
        //printf("boss_hp = %d\n", boss_hp);

        while(1) {
            //printf("andre_time = %d, beto_time = %d\n", andre_time, beto_time);
            andre_time--;
            beto_time--;
            if (andre_time <= 0) {
                //printf("andre_time = %d, beto_time = %d\n", andre_time, beto_time);
                //printf("\n");
                //printf("andre_atk = %d, boss_hp = %d - %d\n", andre_atk, boss_hp, andre_atk);
                boss_hp -= andre_atk;
                //printf("boss_hp = %d\n", boss_hp);
                andre_time = andre_time_inicial;
            }
            if (boss_hp <= 0) {
                printf("Andre\n");
                break;
            }
            
            
            if (beto_time <= 0) {
                //printf("andre_time = %d, beto_time = %d\n", andre_time, beto_time);
                //printf("\n");
                //printf("beto_atk = %d, boss_hp = %d - %d\n", beto_atk, boss_hp, beto_atk);
                boss_hp -= beto_atk;
                //printf("boss_hp = %d\n", boss_hp);
                beto_time = beto_time_inicial;
            }
            if (boss_hp <= 0) {
                printf("Beto\n");      
                break;
            }
            
        }
    }
    return 0;
}