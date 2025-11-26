#include <stdio.h>
#include <stdlib.h>

typedef int vertex;

typedef struct node *link;
struct node {
    vertex w;
    link next;
};

typedef struct graph *Graph;
struct graph {
    int V;
    int E;
    link *adj; 
};

link NEWnode(vertex w, link next){
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}

Graph GRAPHinit(int V){
    Graph G = malloc(sizeof(*G));
    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link));
    for (int i = 0; i < V; i++)
        G->adj[i] = NULL;
    return G;
}

void GRAPHinsertE(Graph G, vertex v, vertex w){
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->adj[w] = NEWnode(v, G->adj[w]);
    G->E++;
}

int visited[30];
char comp[30];
int idx;

void dfs(Graph G, vertex v){
    visited[v] = 1;
    comp[idx++] = 'a' + v;

    for (link a = G->adj[v]; a != NULL; a = a->next){
        if (!visited[a->w])
            dfs(G, a->w);
    }
}

int main(){
    int N;
    scanf("%d", &N);

    for (int caso = 1; caso <= N; caso++){
        int V, E;
        scanf("%d %d", &V, &E);

        Graph G = GRAPHinit(V);

        for(int i = 0; i < V; i++)
            visited[i] = 0;

        for(int i = 0; i < E; i++){
            char a, b;
            scanf(" %c %c", &a, &b);
            int u = a - 'a';
            int v = b - 'a';
            GRAPHinsertE(G, u, v);
        }

        printf("Case #%d:\n", caso);

        int componentes = 0;

        for (int i = 0; i < V; i++){
            if (!visited[i]){
                idx = 0;
                dfs(G, i);

                for(int x = 0; x < idx; x++){
                    for(int y = x + 1; y < idx; y++){
                        if(comp[x] > comp[y]){
                            char aux = comp[x];
                            comp[x] = comp[y];
                            comp[y] = aux;
                        }
                    }
                }
              
                for(int k = 0; k < idx; k++){
                    printf("%c,", comp[k]);
                }
                printf("\n");

                componentes++;
            }
        }

        printf("%d connected components\n\n", componentes);
    }
}
