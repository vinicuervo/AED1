#include <stdio.h>
#include <stdlib.h>

int cmp_even(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;  // crescente
}

int cmp_odd(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return y - x;  // decrescente
}

int main() {
    int N;
    scanf("%d", &N);

    int *even = malloc(N * sizeof(int));
    int *odd  = malloc(N * sizeof(int));

    int e = 0, o = 0;

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (x % 2 == 0)
            even[e++] = x;
        else
            odd[o++] = x;
    }

    qsort(even, e, sizeof(int), cmp_even);
    qsort(odd,  o, sizeof(int), cmp_odd);

    for (int i = 0; i < e; i++)
        printf("%d\n", even[i]);
    for (int i = 0; i < o; i++)
        printf("%d\n", odd[i]);

    free(even);
    free(odd);
    return 0;
}
