#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *left, *right;
} Node;

Node* newNode(int v) {
    Node* n = malloc(sizeof(Node));
    n->val = v;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* root, int v) {
    if (root == NULL) return newNode(v);
    if (v < root->val) root->left = insert(root->left, v);
    else root->right = insert(root->right, v);
    return root;
}

typedef struct queue {
    Node* data[600];
    int ini, fim;
} Queue;

void initQueue(Queue* q) {
    q->ini = q->fim = 0;
}

void push(Queue* q, Node* x) {
    q->data[q->fim++] = x;
}

Node* pop(Queue* q) {
    return q->data[q->ini++];
}

int empty(Queue* q) {
    return q->ini == q->fim;
}


void bfs(Node* root) {
    Queue q;
    initQueue(&q);

    push(&q, root);
    int first = 1;

    while (!empty(&q)) {
        Node* u = pop(&q);

        if (!first) printf(" ");
        first = 0;
        printf("%d", u->val);

        if (u->left) push(&q, u->left);
        if (u->right) push(&q, u->right);
    }
}

int main() {
    int C; 
    scanf("%d", &C);

    for (int c = 1; c <= C; c++) {

        int N;
        scanf("%d", &N);

        Node* root = NULL;
        for (int i = 0; i < N; i++) {
            int x;
            scanf("%d", &x);
            root = insert(root, x);
        }

        printf("Case %d:\n", c);
        bfs(root);
        printf("\n\n");
    }

    return 0;
}
