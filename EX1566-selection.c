#include <stdio.h>

void selectionSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // acha o menor elemento do resto
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }

        // troca
        int tmp = v[i];
        v[i] = v[minIndex];
        v[minIndex] = tmp;
    }
}

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {
        int n;
        scanf("%d", &n);

        int alturas[n];

        for (int i = 0; i < n; i++)
            scanf("%d", &alturas[i]);

        selectionSort(alturas, n);

        // imprime resultado ordenado
        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");
    }

    return 0;
}
