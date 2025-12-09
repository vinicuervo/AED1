#include <stdio.h>
#include <stdlib.h>

#define MAXN 2005

int N, M;
int head[MAXN], headR[MAXN], to[4000005], nxt[4000005], toR[4000005], nxtR[4000005];
int used[MAXN];
int tot, totR;

void add_edge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

void add_edgeR(int u, int v) {
    toR[++totR] = v;
    nxtR[totR] = headR[u];
    headR[u] = totR;
}

void dfs(int u) {
    used[u] = 1;
    for (int e = head[u]; e; e = nxt[e]) {
        int v = to[e];
        if (!used[v]) dfs(v);
    }
}

void dfsR(int u) {
    used[u] = 1;
    for (int e = headR[u]; e; e = nxtR[e]) {
        int v = toR[e];
        if (!used[v]) dfsR(v);
    }
}

int main() {
    while (1) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;

        for (int i = 1; i <= N; i++) {
            head[i] = headR[i] = 0;
        }
        tot = totR = 0;

        for (int i = 0; i < M; i++) {
            int v, w, p;
            scanf("%d %d %d", &v, &w, &p);

            add_edge(v, w);
            if (p == 2) add_edge(w, v);

            add_edgeR(w, v);
            if (p == 2) add_edgeR(v, w);
        }

        for (int i = 1; i <= N; i++) used[i] = 0;
        dfs(1);
        int ok = 1;
        for (int i = 1; i <= N; i++)
            if (!used[i]) ok = 0;

        for (int i = 1; i <= N; i++) used[i] = 0;
        dfsR(1);
        for (int i = 1; i <= N; i++)
            if (!used[i]) ok = 0;

        printf("%d\n", ok);
    }

    return 0;
}
