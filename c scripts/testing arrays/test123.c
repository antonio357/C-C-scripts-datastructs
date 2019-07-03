#include<stdio.h>
#include<math.h>

double getPI(int n) {
  if (n == 0) {return 4.0;}
  else if (n > 0) {return getPI(n - 1) + (pow(-1, n) * (4/(2*n + 1)));}
}

int main() {
  int n = 0;
  scanf("%d", &n);
  printf("%Lf", getPI(n));
  printf("");
  return 0;
}