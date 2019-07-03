#include<stdio.h>

void contador(char ca, char fr[], int *p) {
  int posso = 1;
  int i = 0;
  for (i = 0; fr[i] != '\0'; i++) {
    if (posso == 1) {
      if (fr[i] == ca) {
        (*p)++;
        posso = 0;
      }
    }
    else {
      if (fr[i] == ' ') posso = 1;
    } 
  }
}

int main () {
  char c; char frase[100];
  scanf("%c", &c); scanf("%[^\n]s", frase);
  int cont = 0;
  contador(c, frase, &cont);
  printf("%d", cont);
  return 0;
}
