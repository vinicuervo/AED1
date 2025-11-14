#include <stdio.h>

void heapify(int v[], int n, int i) {
    int maior = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && v[left] > v[maior])
        maior = left;

    if (right < n && v[right] > v[maior])
        maior = right;

    if (maior != i) {
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;
        heapify(v, n, maior);
    }
}

void heapsort(int v[], int n) {
    // Constrói o heap máximo
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    // Extrai elementos do heap
    for (int i = n - 1; i > 0; i--) {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0);
    }
}

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {
        int n;
        scanf("%d", &n);

        static int v[3000000];  // alocado globalmente → cabe tranquilo

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        heapsort(v, n);

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
