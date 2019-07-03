#include<stdio.h>

int main() {
	int num = 0, divid = 1, ok = 0;
	
	scanf("%d", &num);
	
	do {
		ok = num % divid;
		
		if (ok == 0) {
			printf("%d\n", divid);
		}
		
		divid++;
	} while(num >= divid);
	
	return 0;
}