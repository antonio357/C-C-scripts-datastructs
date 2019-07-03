//isac hamburgers
#include <stdio.h>

long long mayI(long long qnt, int *bsc, int *storage, int *prices, long long rubles) {
  long long rubles_need = 0;
  for (int i = 0; i < 3; i++) {
    long long temp = ((bsc[i]*qnt) - storage[i])*prices[i];
    if (temp >= 0 ) rubles_need += temp;
  }
  return rubles_need;
}

long long binarySearch(int *bsc, int *storage, int *prices, long long rubles) {
  long long start = 0, end = 300*rubles, asw = 0;
  while(end >= start) {
    long long mid = (start + end) / 2;
    if (mayI(mid, bsc, storage, prices, rubles) <= rubles) {
      if (mid > asw){
        asw = mid;
      }
      start = mid + 1;
    } else {
      end = mid -1;
    }
  }
  return asw; 
}

int main(void) {
  int b = 0;
  int s = 0;
  int c = 0;

  char str[120];
  scanf("%s", str);

  
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == 'B') b++;
    else if (str[i] == 'S') s++;
    else if (str[i] == 'C') c++;
  }

  int storing[3];
  int prices[3];

  for (int i = 0; i < 3; i++) {
    scanf("%i", &storing[i]);
  }
  for (int i = 0; i < 3; i++) {
    scanf("%i", &prices[i]);
  }

  
  long long rubles;
  scanf("%I64d", &rubles);

  int bsc[] = {b, s, c};


  long long teste = binarySearch(bsc, storing, prices, rubles);
  printf("%I64d", teste);
  return 0;
}