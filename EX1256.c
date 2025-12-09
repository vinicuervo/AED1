#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M, C;
        scanf("%d %d", &M, &C);

        int table[200][200];
        int sizes[200] = {0};

        for (int i = 0; i < M; i++) {
            sizes[i] = 0;
        }

        for (int i = 0; i < C; i++) {
            int key;
            scanf("%d", &key);
            int h = key % M;
            table[h][sizes[h]++] = key;
        }

        for (int i = 0; i < M; i++) {
            printf("%d -> ", i);
            for (int j = 0; j < sizes[i]; j++) {
                printf("%d -> ", table[i][j]);
            }
            printf("\\\n");
        }

        if (N) printf("\n"); // linha em branco entre casos
    }

    return 0;
}
