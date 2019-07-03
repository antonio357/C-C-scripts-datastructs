#include<stdio.h>

int main() {
	int n = 0, x = 0, y = 0, sm = 0, i = 0, k = 0, a = 0;
	
	//printf("%d %d %d %d %d %d\n", n,x,y,sm,i,k);
	scanf("%d", &n);
	//printf("%d %d %d %d %d %d\n", n,x,y,sm,i,k);
	
	for (a = 0; a < n; a++) {
		scanf("%d %d", &x, &y);
		//printf("got input\n");
		//printf("\n");
		sm = 0;
		
		for (i = 0, k = x; i < y*2; i++, k++) {
			if (k % 2 != 0) {
					sm += k;
					//printf("k = %d\n",k);
			}
			//printf("i = %d\n", i);
		}
		printf("%d\n", sm);
	}
	

	return 0;
}