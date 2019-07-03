#include<stdio.h>

int main() {
    int q_alunos = 0, i = 0, aluno = 0, nota = 0;
    int turma = 0;

    while(1) {

        scanf("%d", &q_alunos);

        if (q_alunos == 0) break; 

        
        turma++;
        int maior_nota = -1;
        int notas[q_alunos];
        int ordem_entrada[q_alunos];
        int ordem_saida[q_alunos]; 
        int counter = 0;

        for (i = 0; i < q_alunos; i++) {
            scanf("%d %d", &aluno, &nota);

            if (nota > maior_nota) maior_nota = nota; 

            ordem_entrada[i] = aluno;
            notas[i] = nota;
    
        }

        for (i = 0; i < q_alunos; i++) {
            if (notas[i] == maior_nota) {
                ordem_saida[counter] = ordem_entrada[i];
                counter++;
            }
        }

        printf("Turma %d\n", turma);

        for (i = 0; i < counter; i++) {
            if (i >= counter - 1) printf("%d \n", ordem_saida[i]);
            else printf("%d ", ordem_saida[i]);            
        }

        printf("\n");

    }

    return 0;
}