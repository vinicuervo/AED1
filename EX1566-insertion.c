#include <stdio.h>

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {

        int n;
        scanf("%d", &n);

        int freq[231] = {0};  // alturas de 20 a 230

        // "inserção": cada altura encontrada incrementa sua posição correta
        for (int i = 0; i < n; i++) {
            int h;
            scanf("%d", &h);
            freq[h]++;
        }

        // impressão ordenada
        int first = 1;
        for (int h = 20; h <= 230; h++) {
            while (freq[h]--) {
                if (!first) printf(" ");
                printf("%d", h);
                first = 0;
            }
        }
        printf("\n");
    }

    return 0;
}
