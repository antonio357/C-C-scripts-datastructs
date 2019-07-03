#include<stdio.h>

int main() {
	int count = 0, limit = 0, counter = 1, counter_max = 0, atual = 0, anterior = 0;
	
	scanf("%d", &limit);
	
	for (count = 0; count < limit; count++) {
		
		scanf("%d", &atual);
		
		if (atual == anterior) {
			
			counter++;
		}
		else {
			
			counter = 0;
		}
		
		if (counter > counter_max) {
				
				counter_max = counter;
		}
		
		anterior = atual;
		
	}
	
	counter_max++;
  
	printf("%d\n", counter_max);
	
	return 0;
}