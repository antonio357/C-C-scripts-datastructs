#include<stdio.h>

int main() {
	double result;
	double i, k;
	int a;
	
	for (i = 1, k = 1, a = 1, result = 0; i <= 39; i += 2, k *= 2, a += 2) {
		result += i/k;
		//printf("result _%d = %lf/%lf = %lf\n", a, i, k, result);
		//printf("%lf/%lf +\n",i, k);
		//break;
	}
	
	printf("%.2lf\n", result);
	return 0;
}