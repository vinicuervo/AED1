#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1000005];
    char *set[200000];
    int q = 0;

    while (scanf("%s", s) != EOF) {
        int existe = 0;

        for (int i = 0; i < q; i++) {
            if (strcmp(set[i], s) == 0) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            set[q] = malloc(strlen(s) + 1);
            strcpy(set[q], s);
            q++;
        }
    }

    printf("%d\n", q);
    return 0;
}
