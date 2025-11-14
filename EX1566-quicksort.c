#include <stdio.h>

void quicksort(int v[], int left, int right) {
    int i = left, j = right;
    int pivot = v[(left + right) / 2];

    while (i <= j) {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;
        if (i <= j) {
            int tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quicksort(v, left, j);
    if (i < right) quicksort(v, i, right);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        int *v = malloc(N * sizeof(int));
        for (int i = 0; i < N; i++)
            scanf("%d", &v[i]);

        quicksort(v, 0, N - 1);

        for (int i = 0; i < N; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");

        free(v);
    }
}
