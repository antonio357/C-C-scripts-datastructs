#include<stdio.h>

int main() {
	int ant = 0, atu = 0, fail = 0, first_time = 1, tr = 1;

	//FILE *file;
	//file = fopen("C:\Users\carlo\OneDrive\Área de Trabalho\C\Third small taks from Ruan's apostille0(Estruturas de Dados e Algoritmos em C, p.21).c\texto_entrada.txt", "r");

	//if (file == NULL) {
		//printf("Nao da pra achar o arquivo!!!\n");
	//}
	
	while (scanf("%d", &atu) != EOF) {
		
		if (ant > atu) {
			fail = 1;
		}
		
		if (fail == 1 && first_time >= 1) {
      		ant++;
			printf("%d\n", ant);
			first_time--;
		}
    
    ant = atu;
	}
	if (first_time == 1) {
		atu++;
		printf("%d\n", atu);
	}

	/*if (fail == 0) {
		ant++;
		printf("%d\n", ant);
	}*/
	return 0;
}