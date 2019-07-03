#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

int main() {
    char *recipe = (char*)malloc(101*sizeof(char));
    int q_breads = 0, q_sausage = 0, q_chese = 0;
    scanf("%[^\n]s", recipe);
    int i;

    // counts how many of each ingredient its necessary to make one um hamburger
    for (i = 0; recipe[i] != '\0'; i++) {
        if (recipe[i] == 'B') q_breads++;
        else if (recipe[i] == 'S') q_sausage++;
        else if (recipe[i] == 'C') q_chese++;
    }

    // the ingredients that he already does have since the very beginig
    int bread = 0, sausage = 0, chese = 0;
    scanf("%d %d %d", &bread, &sausage, &chese); 

    // the related prices of each ingredient
    int p_bread = 0, p_sausage = 0, p_chese = 0;
    scanf("%d %d %d", &p_bread, &p_sausage, &p_chese); 

    // quantity of money that he begins
    long long rubles = 0, q_hamburgers = 0;
    scanf("%I64d", &rubles);
    //printf("%ld\n", rubles);

    // calculating with the money
    int total_p = (q_breads*p_bread) + (q_sausage*p_sausage) + (q_chese*p_chese);
    while (rubles >= total_p) {
      q_hamburgers += rubles/total_p;
      rubles -= total_p * q_hamburgers;
    }

    //calculate how many hamburgers he can do with the rest of the money
    int bread_key;
    int sausage_key;
    int chese_key;
    while (1) {
        bread_key = False;
        sausage_key = False;
        chese_key = False;
        if (q_breads > 0) {
            if (bread < q_breads) {
                while (rubles >= p_bread && bread < q_breads) {
                    rubles -= p_bread;
                    bread++;
                }
            }
            if (bread >= q_breads) {
                bread -= q_breads;
                bread_key = True;
            }
        }
        else bread_key = True;
        if (q_sausage > 0) {
            if (sausage < q_sausage) {
                while (rubles >= p_sausage && sausage < q_sausage) {
                    rubles -= p_sausage;
                    sausage++;
                }
            }
            if (sausage >= q_sausage) {
                sausage -= q_sausage;
                sausage_key = True;
            }
        }
        else sausage_key = True;
        if (q_chese > 0) {
            if (chese < q_chese) {
                while (rubles >= p_chese && chese < q_chese) {
                    rubles -= p_chese;
                    chese++;
                }
            }
            if (chese >= q_chese) {
                chese -= q_chese;
                chese_key = True;
            }
        }
        else chese_key = True;
        if (bread_key == True && sausage_key == True && chese_key == True) {
          q_hamburgers++;
          continue;
        }
        else break;
    }

    printf("%I64d\n", q_hamburgers); 

    return 0;
}