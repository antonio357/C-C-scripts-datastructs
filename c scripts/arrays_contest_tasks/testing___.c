#include<stdio.h>

int palin (char str[], int s, int d) {
    if (s == d || s == d - 1) {
        if (str[s] == str[d]) {
            return 1;
        }
        else {return 0;}
    }
    else {
        if (str[s] == str[d]) {
            return palin(str, (s + 1), (d - 1));
        }
        else {return 0;}
    }
}

int main (void) {
    char pala[100];
    int si = 0;
    scanf("%s", pala);
    printf("pala = %s\n",pala);
    while(1) {
        if (pala[si+1] == '\n' || pala[si+1] == '\0') break;
        si++;
    }
    printf("si = %d\n", si);
    int eh_palin = palin(pala, 0, si);
    if (eh_palin == 1) printf("PALINDROMO\n");
    else printf("NAO\n");
    return 0;
}