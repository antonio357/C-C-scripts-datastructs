#include<stdio.h>

/*int save_rest_left;
int val;
int n_100, n_50, n_20, n_10, n_5, n_2, n_1;*/
int save_rest_left;

int func();

int main() {
    //int counter_100, counter_50, counter_20, counter_10, counter_5, counter_2, counter_1 = 0;
    int counter = 6;
    int val;
    int n_100, n_50, n_20, n_10, n_5, n_2, n_1;

    n_100 = 0; 
    n_5 = 0;
    n_50 = 0;   
    n_2 = 0;
    n_20 = 0;   
    n_1 = 0;
    n_10 = 0;

    scanf("%d", &save_rest_left);
    //int initial_value = save_rest_left;

    while(save_rest_left < 1) {
        printf("%d\n", counter);
        if (counter == 6) {val = 100; n_100=func(save_rest_left, val);}
        else if (counter == 5) {val = 50; n_50=func(save_rest_left, val);}
        else if (counter == 4) {val = 20; n_20=func(save_rest_left, val);}
        else if (counter == 3) {val = 10; n_10=func(save_rest_left, val);}
        else if (counter == 2) {val = 5; n_5=func(save_rest_left, val);}
        else if (counter == 1) {val = 2; n_2=func(save_rest_left, val);}
        else if (counter == 0) {val = 1; n_1=func(save_rest_left, val); save_rest_left = 0;}

        //func(save_rest_left, val);

        counter--;
    }
    /*while(check_money < 1) {
        int divide = value%n_100;
        if (divide != 0) {
            save_rest_left = divide; // important
            value -= divide;
            continue;
        }
        if (divide == 0) {
            counter_100 = value/n_100;
        }
        divide = save_rest_left%n_50; 
        if (divide != 0) {

            continue;
        }
    }*/

    printf("%d notas(s) de R$ 100,00\n%d notas(s) de R$ 50,00\n%d notas(s) de R$ 20,00\n%d notas(s) de R$ 10,00\n%d notas(s) de R$ 5,00\n%d notas(s) de R$ 2,00\n%d notas(s) de R$ 1,00", n_100, n_50, n_20, n_10, n_5, n_2, n_1);

    return 0;
}

int func(int value, int num) {
    if (value > num - 1) {
        int ok = value % num;

        if (ok != 0) {
            value -= ok;
            save_rest_left = ok;
        }

        ok = value / num;

        return ok;
    }
    else {return 0;}
}
