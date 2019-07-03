#include<stdio.h>

int main() {
    int q_cartas, carta_mesa, limit_pontuador, result = 0;
    int counter = 0;
    int Alice = 0, Bob = 0, vez_alice = 1, vez_bob = 0;
    int carta_pegada;

    scanf("%d %d %d", &q_cartas, &carta_mesa, &limit_pontuador);

    for (counter = 1; counter < q_cartas ; counter++) {

        scanf("%d", &carta_pegada);

        result = carta_mesa - carta_pegada;
        if (result < 0) {
            result *= -1;
        }

        if (counter % 2 != 0) { // aqui quem pontua é alice
            if (result <= limit_pontuador) {
            carta_mesa = carta_pegada;
            Alice += result;
            }
        }
        else if (counter % 2 == 0) { // aqui quem pontua é bob
            if (result <= limit_pontuador) {
            carta_mesa = carta_pegada;
            Bob += result;
            }
        }
    }

    printf("%d %d\n", Alice, Bob);
    return 0;
}