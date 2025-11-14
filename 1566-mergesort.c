#include <stdio.h>

void merge(int v[], int aux[], int inicio, int meio, int fim) {
    int i = inicio;
    int j = meio + 1;
    int k = inicio;

    while (i <= meio && j <= fim) {
        if (v[i] <= v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }

    while (i <= meio) aux[k++] = v[i++];
    while (j <= fim) aux[k++] = v[j++];

    for (int p = inicio; p <= fim; p++)
        v[p] = aux[p];
}

void mergesort(int v[], int aux[], int inicio, int fim) {
    if (inicio >= fim) return;

    int meio = (inicio + fim) / 2;
    mergesort(v, aux, inicio, meio);
    mergesort(v, aux, meio + 1, fim);
    merge(v, aux, inicio, meio, fim);
}

int main() {
    int nc;
    scanf("%d", &nc);

    while (nc--) {
        int n;
        scanf("%d", &n);

        static int v[3000000];
        static int aux[3000000];

        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);

        mergesort(v, aux, 0, n - 1);

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");
    }

    return 0;
}
