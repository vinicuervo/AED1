#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXC 10005
#define MAXV 50005
#define INF INT_MAX

typedef struct {
    int to;
    int cost;
} Edge;

Edge graph[MAXC][50];
int deg[MAXC];

typedef struct {
    int dist;
    int v;
    int parity;
} Node;

Node heap[2 * MAXC + 5];
int heapSize = 0;

void swap(Node *a, Node *b) {
    Node tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int dist, int v, int parity) {
    heapSize++;
    heap[heapSize].dist = dist;
    heap[heapSize].v = v;
    heap[heapSize].parity = parity;

    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

Node pop() {
    Node top = heap[1];
    heap[1] = heap[heapSize];
    heapSize--;

    int i = 1;
    while (1) {
        int left = i*2;
        int right = left + 1;
        int smallest = i;

        if (left <= heapSize && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= heapSize && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return top;
}

int empty() {
    return heapSize == 0;
}

int dist[MAXC][2];
int visited[MAXC][2];

int main() {
    int C, V;

    while (scanf("%d %d", &C, &V) == 2) {
        for (int i = 1; i <= C; i++) deg[i] = 0;

        for (int i = 0; i < V; i++) {
            int a, b, g;
            scanf("%d %d %d", &a, &b, &g);
            graph[a][deg[a]++] = (Edge){b, g};
            graph[b][deg[b]++] = (Edge){a, g};
        }

        for (int i = 1; i <= C; i++) {
            dist[i][0] = dist[i][1] = INF;
            visited[i][0] = visited[i][1] = 0;
        }

        heapSize = 0;

        dist[1][0] = 0;
        push(0, 1, 0);

        while (!empty()) {
            Node top = pop();
            int d = top.dist;
            int u = top.v;
            int p = top.parity;

            if (visited[u][p]) continue;
            visited[u][p] = 1;

            for (int i = 0; i < deg[u]; i++) {
                int v = graph[u][i].to;
                int w = graph[u][i].cost;

                int np = p ^ 1; // troca de paridade
                if (d + w < dist[v][np]) {
                    dist[v][np] = d + w;
                    push(dist[v][np], v, np);
                }
            }
        }

        if (dist[C][0] == INF) printf("-1\n");
        else printf("%d\n", dist[C][0]);
    }

    return 0;
}
