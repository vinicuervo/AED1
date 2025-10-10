#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int deck[50]; // máximo de 50 cartas
        int front = 0, rear = 0;

        // inicializa o baralho
        for (int i = 1; i <= n; i++) {
            deck[rear++] = i;
        }

        printf("Discarded cards:");

        int first = 1; // controla vírgulas

        while (rear - front > 1) { // enquanto tiver mais de uma carta
            if (first) {
                printf(" %d", deck[front++]); // descarta a primeira
                first = 0;
            } else {
                printf(", %d", deck[front++]);
            }

            // move a próxima carta para o final
            deck[rear++] = deck[front++];
        }

        printf("\nRemaining card: %d\n", deck[front]);
    }

    return 0;
}
