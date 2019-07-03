#include<stdio.h>

int main() {
    int value = 0, initial_value = 0;

    scanf("%d", &value);
    initial_value = value;

    int store_001 = value % 100;
    value -= store_001;
    int store_100 = value/100;

    int store_002 = store_001 % 50;
    store_001 -= store_002;
    int store_50 = store_001/50;

    int store_003 = store_002 % 20;
    store_002 -= store_003;
    int store_20 = store_002/20;

    int store_004 = store_003 % 10;
    store_003 -= store_004;
    int store_10 = store_003/10;

    int store_005 = store_004 % 5;
    store_004 -= store_005;
    int store_5 = store_004/5;

    int store_006 = store_005 % 2;
    store_005 -= store_006;
    int store_2 = store_005/2.0;

    int store_007 = store_006 % 1;
    store_006 -= store_007;
    int store_1 = store_006/1;
    
    printf("%d\n%d nota(s) de R$ 100,00\n%d nota(s) de R$ 50,00\n%d nota(s) de R$ 20,00\n%d nota(s) de R$ 10,00\n%d nota(s) de R$ 5,00\n%d nota(s) de R$ 2,00\n%d nota(s) de R$ 1,00\n", initial_value, store_100, store_50, store_20, store_10, store_5, store_2, store_1);
    return 0;
}
