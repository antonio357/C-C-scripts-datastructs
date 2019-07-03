#include<stdio.h>
#include<stdlib.h>

int main() {
    char *recipe = (char*)malloc(101*sizeof(char));
    int q_breads = 0, q_sausage = 0, q_chese = 0;
    scanf("%[^\n]s", recipe);
    int i;

    // counts how many of each ingredient its necessary to make one um hemburger
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

    // first_part
    int _bread = 0;
    int _sausage = 0;
    int _chese = 0;
    if (q_breads > 0) _bread = (bread*p_bread);
    if (q_sausage > 0) _sausage = (sausage*p_sausage);
    if (q_chese > 0) _chese = (chese*p_chese);

    // second_part converting the ingredients that he have since the very begining to money
    //printf("before after convertion = %lld\n", rubles);
    //printf("%d %d %d\n", _bread , _sausage , _chese);
    rubles += _bread + _sausage + _chese;
    //printf("rubles after convertion = %lld\n", rubles);

    // total price of an ingredient per hamburguer
    int $_bread_ph = q_breads*p_bread;
    int $_sausage_ph = q_sausage*p_sausage;
    int $_chese_ph = q_chese*p_chese;

    // total price of one hamburger
    int total_p = $_bread_ph + $_sausage_ph + $_chese_ph;

    // perncetage of money of each element from the total price of hamburger
    double bread_$_percent = (q_breads*p_bread/total_p);
    double sausage_$_percent = (q_sausage*p_bread/total_p);
    double chese_$_percent = (q_chese*p_bread/total_p);

    // procecins the quantity that he can do for sure
    //printf("rubles = %lld\n", rubles);
    //printf("total_p of a hamburguer = %d\n", total_p);
    //if (rubles < total_p) printf("here is the mistake\n");
    while (rubles > total_p) {
        q_hamburgers += (long long)(rubles/total_p);
        rubles -= (long long)(q_hamburgers*total_p); 
    }

    printf("%I64d\n", q_hamburgers); 

    return 0;
}