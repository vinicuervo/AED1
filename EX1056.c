#include <stdio.h>
#include <string.h>

#define MAX 105

int n, m;
int A[MAX], B[MAX];
int adj[MAX][MAX];  
int used[MAX];
int matchR[MAX];    

int dfs(int u) {
    for (int v = 0; v < m; v++) {
        if (!adj[u][v] || used[v]) continue;
        used[v] = 1;
        if (matchR[v] == -1 || dfs(matchR[v])) {
            matchR[v] = u;
            return 1;
        }
    }
    return 0;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    for (int tc = 1; tc <= T; tc++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &A[i]);

        scanf("%d", &m);
        for (int j = 0; j < m; j++) scanf("%d", &B[j]);

        memset(adj, 0, sizeof(adj));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] == 0) {
                    if (B[j] == 0) adj[i][j] = 1;   
                } else {
                    if (B[j] % A[i] == 0) adj[i][j] = 1; 
                }
            }
        }

        memset(matchR, -1, sizeof(matchR));
        int matching = 0;
        for (int i = 0; i < n; i++) {
            memset(used, 0, sizeof(used));
            if (dfs(i)) matching++;
        }

        printf("Case %d: %d\n", tc, matching);
    }

    return 0;
}
