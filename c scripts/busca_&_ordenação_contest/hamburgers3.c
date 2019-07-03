#include<stdio.h>
#include<stdlib.h>

#define True 1
#define False 0

typedef struct {
    char nome;
    int tem;
    int price;
    int its_null;
} ing;

int compara(const void *p1, const void *p2) {
    ing *_p1 = (ing*)p1; ing *_p2 = (ing*)p2;
    if (_p1->its_null == True || _p2->its_null == True) {
        if (_p1->its_null == True && _p2->its_null == False) return 1;
        else if (_p1->its_null == False && _p2->its_null == True) return -1;
    }
    else if (_p1->its_null == False && _p2->its_null == False) {
        if (_p1)
    }
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

    ing vet[3];
    // names
    vet[0].nome = 'B'; vet[1].nome = 'S'; vet[2].nome = 'C';

    // if its null
    if (q_breads == 0) vet[0].its_null = True;
    else  vet[0].its_null = False;
    if (q_sausage == 0) vet[1].its_null = True;
    else vet[1].its_null = False;
    if (q_chese) vet[2].its_null = True;
    else vet[2].its_null = False;

    // the ingredients that he already does have since the very beginig
    scanf("%d %d %d", &vet[0].tem, &vet[1].tem, &vet[2].tem); 

    // the related prices of each ingredient
    scanf("%d %d %d", &vet[0].price, &vet[1].price, &vet[2].price); 

    // quantity of money that he begins
    long long rubles = 0, q_hamburgers = 0;
    scanf("%I64d", &rubles);
    //printf("%lld\n", rubles);

    qsort(vet, 3, sizeof(ing), compara);

    // completing the quantity of ingredients that he needs to make the inicial hamburgers
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
        bread -= co_prop;
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