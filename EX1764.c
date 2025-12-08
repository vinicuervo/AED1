#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[40000];
int rankv[40000];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;

    if (rankv[a] < rankv[b]) {
        parent[a] = b;
    } else if (rankv[b] < rankv[a]) {
        parent[b] = a;
    } else {
        parent[b] = a;
        rankv[a]++;
    }
}

int cmp(const void *a, const void *b) {
    Edge *e1 = (Edge*)a;
    Edge *e2 = (Edge*)b;
    return e1->w - e2->w;
}

int main() {
    int M, N;

    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;

        Edge *edges = malloc(N * sizeof(Edge));

        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
        }

        // inicializa Union-Find
        for (int i = 0; i < M; i++) {
            parent[i] = i;
            rankv[i] = 0;
        }

        qsort(edges, N, sizeof(Edge), cmp);

        long long total = 0;
        int used = 0;

        for (int i = 0; i < N && used < M - 1; i++) {
            int ru = find(edges[i].u);
            int rv = find(edges[i].v);

            if (ru != rv) {
                unite(ru, rv);
                total += edges[i].w;
                used++;
            }
        }

        printf("%lld\n", total);

        free(edges);
    }

    return 0;
}
