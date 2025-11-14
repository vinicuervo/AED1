#include <stdio.h>
#include <string.h>

#define MAXV 10000

int reverse_int(int x){
    int r = 0;
    while (x > 0){
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int main(){
    int T;
    if (scanf("%d", &T) != 1) return 0;
    while (T--){
        int A, B;
        scanf("%d %d", &A, &B);

        static int dist[MAXV + 1];
        // inicializa dist com -1
        for (int i = 0; i <= MAXV; i++) dist[i] = -1;

        // fila simples (circular)
        static int q[MAXV + 5];
        int head = 0, tail = 0;

        dist[A] = 0;
        q[tail++] = A;

        while (head < tail){
            int u = q[head++];

            if (u == B){
                printf("%d\n", dist[u]);
                break;
            }

            // operação +1
            int v = u + 1;
            if (v <= MAXV && dist[v] == -1){
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }

            // operação reverse
            v = reverse_int(u);
            if (v <= MAXV && dist[v] == -1){
                dist[v] = dist[u] + 1;
                q[tail++] = v;
            }
        }
    }
    return 0;
}
