#include <stdio.h>
#include <string.h>

char pre[30], in[30];

void build_post(int preL, int preR, int inL, int inR) {
    if (preL > preR) return;

    char root = pre[preL];

    int k;
    for (k = inL; k <= inR; k++)
        if (in[k] == root)
            break;

    int leftSize = k - inL;

    build_post(preL + 1, preL + leftSize, inL, k - 1);
    build_post(preL + leftSize + 1, preR, k + 1, inR);

    putchar(root);
}

int main() {
    while (scanf("%s %s", pre, in) == 2) {
        int n = strlen(pre);
        build_post(0, n - 1, 0, n - 1);
        putchar('\n');
    }
    return 0;
}
