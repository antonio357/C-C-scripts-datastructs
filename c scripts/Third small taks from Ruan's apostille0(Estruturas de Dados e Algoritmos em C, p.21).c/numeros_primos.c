#include<stdio.h>

int main() {
	int numb = 0, i = 0,  div = 0, eh_primo = 1, n;
	
    scanf("%d", &n);
	//i = 0;
	
	/*for (i = 0; i < numb; i++)*/ do {
		
		scanf("%d", &numb);
		div = 2;
		if (numb > 1) {
			eh_primo = 1;
		}
		else if (numb == 1) {
			eh_primo = 0;
		} // tudo isso é para caso a entrada seja 1 mas como a questão determina que (1 < numb <= 10000000)
			// então não é necessário
		
		while(div < numb) {
			
			
			if (numb % div == 0){
				
				eh_primo = 0;
				break;
			}
			
			div++;
		}
		
		i++;
		
		if (eh_primo == 1) {
			printf("%d eh primo\n", numb);
		}
		else {
			printf("%d nao eh primo\n", numb);
		}
	}while(i < n);
	
	return 0;
}