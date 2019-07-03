#include<stdio.h>
#include<stdlib.h>

char wich_one_have_most(int v1, int v2, int v3) {
    if(v1 >= v2 && v1 > v3) return 'B';
    if(v1 >= v3 && v1 > v2) return 'B';
    else if (v2 >= v1 && v2 > v3) return 'S';
    else if (v2 >= v3 && v2 > v1) return 'S';
    else if (v3 >= v1 && v3 > v2) return 'C';
    else if (v3 >= v2 && v3 > v1) return 'C';
    else if (v1 == v2 && v1 == v3) return 'B';
}

char wich_one_have_less(int v1, int v2, int v3) {
    if(v1 <= v2 && v1 < v3) return 'B';
    if(v1 <= v3 && v1 < v2) return 'B';
    else if (v2 <= v1 && v2 < v3) return 'S';
    else if (v2 <= v3 && v2 < v1) return 'S';
    else if (v3 <= v1 && v3 < v2) return 'C';
    else if (v3 <= v2 && v3 < v1) return 'C';
    else if (v1 == v2 && v1 == v3) return 'B';
}

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
    //printf("%lld\n", rubles);

    // calculating with the money
    int total_p = (q_breads*p_bread) + (q_sausage*p_sausage) + (q_chese*p_chese);
    q_hamburgers += rubles/total_p;
    rubles -= total_p * q_hamburgers;

    // completing the quantity of ingredients that he needs to make the very last hamburgers with the left money
    char the_most_one_he_have = wich_one_have_most(bread, sausage, chese);
    if (the_most_one_he_have == 'B') {
        while (bread % q_breads != 0 && rubles - p_bread >= 0) {
            rubles -= p_bread;
            bread++;
        }
        int coeficiente_prop = q_breads/bread;
        while (rubles - p_sausage >= 0 || rubles - p_chese >= 0) {
            if (sausage / q_sausage < coeficiente_prop && q_sausage > 0) {
                rubles -= p_sausage;
                sausage++; 
            }
            if (chese / q_chese < coeficiente_prop && q_chese > 0) {
                rubles -= p_chese;
                chese++;
            }
        } 
    }
    else if (the_most_one_he_have == 'S') {
        while (sausage % q_sausage != 0 && rubles - p_sausage >= 0) {
            rubles -= p_sausage;
            sausage++;
        }
        int coeficiente_prop = q_sausage/sausage;
        while (rubles - p_bread >= 0 || rubles - p_chese >= 0) {
            if (bread / q_breads < coeficiente_prop && q_breads > 0) {
                rubles -= p_bread;
                bread++; 
            }
            if (chese / q_chese < coeficiente_prop && q_chese > 0) {
                rubles -= p_chese;
                chese++;
            }
        }
    }
    else if (the_most_one_he_have == 'C') {
        while (chese % q_chese != 0 && rubles - p_chese >= 0) {
            rubles -= p_chese;
            chese++;
        }
        int coeficiente_prop = q_sausage/sausage;
        while (rubles - p_bread >= 0 || rubles - p_sausage >= 0) {
            if (bread / q_breads < coeficiente_prop && q_breads > 0) {
                rubles -= p_bread;
                bread++; 
            }
            if (sausage / q_sausage < coeficiente_prop && q_sausage > 0) {
                rubles -= p_sausage;
                sausage++;
            }
        }
    }

    //calculate how many hamburgers he can do already
    char the_less_one_he_have = wich_one_he_have_less(bread, sausage, chese);
    if (the_less_one_he_have == 'B') {
        int co_prop = bread / q_breads;
        q_hamburgers += co_prop;
        bread -= co_prop * q_breads;
        int  
    }
    else if (the_less_one_he_have == 'S') {}
    else if (the_less_one_he_have == 'C') {}


    int total_p = (q_breads*p_bread) + (q_sausage*p_sausage) + (q_chese*p_chese);

    while (rubles > total_p) {
        q_hamburgers += (rubles/total_p);
        rubles -= (q_hamburgers*total_p); 
    }

    while (bread >= q_breads && sausage >= q_sausage && chese >= q_chese) {
        bread -= q_breads;
        sausage -= q_sausage;
        chese -= q_chese;
        q_hamburgers++;
    }

    printf("%I64d\n", q_hamburgers); 

    return 0;
}