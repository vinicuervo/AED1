#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void push(Node **top, int v) {
    Node *new = (Node*) malloc(sizeof(Node));
    new->val = v;
    new->next = *top;
    *top = new;
}

void pop(Node **top) {
    if (*top == NULL) return;
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

int peek(Node *top) {
    if (top == NULL) return -1;
    return top->val;
}

void clearStack(Node **top) {
    while (*top) pop(top);
}

int main() {
    int N;

    while (scanf("%d", &N) && N != 0) {

        while (1) {
            int target[1001];
            scanf("%d", &target[0]);
            if (target[0] == 0) break;

            for (int i = 1; i < N; i++)
                scanf("%d", &target[i]);

            Node *stack = NULL;
            int next = 1;
            int ok = 1;

            for (int i = 0; i < N; i++) {
                int want = target[i];

                // empilha até conseguir o que queremos no topo
                while (next <= N && peek(stack) != want) {
                    push(&stack, next);
                    next++;
                }

                // se o topo não for o desejado -> impossível
                if (peek(stack) != want) {
                    ok = 0;
                    break;
                }

                // remove topo
                pop(&stack);
            }

            clearStack(&stack);

            printf(ok ? "Yes\n" : "No\n");
        }

        printf("\n");
    }

    return 0;
}
