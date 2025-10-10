#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int stack[MAX], queue[MAX], pq[MAX];
        int top = 0;           // topo da pilha
        int front = 0, rear = 0; // fila
        int pq_size = 0;       // tamanho da priority queue

        int is_stack = 1, is_queue = 1, is_pq = 1;

        for (int i = 0; i < n; i++) {
            int op, x;
            scanf("%d %d", &op, &x);

            if (op == 1) {
                // Inserir nas três estruturas
                stack[top++] = x;
                queue[rear++] = x;
                pq[pq_size++] = x;
            } else if (op == 2) {
                // Remover e verificar
                if (top == 0) {
                    // todas vazias
                    is_stack = is_queue = is_pq = 0;
                    continue;
                }

                // Pilha
                if (is_stack) {
                    if (stack[top - 1] == x)
                        top--;
                    else
                        is_stack = 0;
                }

                // Fila
                if (is_queue) {
                    if (queue[front] == x)
                        front++;
                    else
                        is_queue = 0;
                }

                // Priority Queue (max-heap manual)
                if (is_pq) {
                    // achar o maior
                    int max_idx = 0;
                    for (int j = 1; j < pq_size; j++)
                        if (pq[j] > pq[max_idx])
                            max_idx = j;

                    if (pq[max_idx] == x) {
                        // remover o maior
                        pq[max_idx] = pq[--pq_size];
                    } else {
                        is_pq = 0;
                    }
                }
            }
        }

        int total = is_stack + is_queue + is_pq;

        if (total == 0)
            printf("impossible\n");
        else if (total > 1)
            printf("not sure\n");
        else if (is_stack)
            printf("stack\n");
        else if (is_queue)
            printf("queue\n");
        else if (is_pq)
            printf("priority queue\n");
    }

    return 0;
}
