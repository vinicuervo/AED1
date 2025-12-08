#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;          // nó de início (e fim) – lido mas não altera o cálculo no modelo sem ciclos
        int V, A;

        scanf("%d", &N);
        scanf("%d %d", &V, &A);

        // Como X <= 7, V <= 49 -> dá para usar matriz pequena (50x50 com folga)
        int adj[50][50] = {0};
        int unique = 0;

        for (int i = 0; i < A; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            if (!adj[x][y]) {          // primeira vez que vemos esta aresta (desconsiderando direção)
                adj[x][y] = 1;
                adj[y][x] = 1;
                unique++;
            }
        }

        printf("%d\n", 2 * unique);
    }

    return 0;
}
