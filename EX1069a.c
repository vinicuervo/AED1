#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // consome '\n'

    char s[1001];

    for (int i = 0; i < N; i++) {
        fgets(s, 1001, stdin);

        int len = strlen(s);
        if (len > 0 && s[len - 1] == '\n') s[len - 1] = '\0';

        int diamante = 0;
        int aberto = 0; // número de '<' ainda não fechados

        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] == '<') {
                aberto++;         // empilha conceitualmente
            } else if (s[j] == '>') {
                if (aberto > 0) { // há '<' disponível
                    aberto--;
                    diamante++;
                }
            }
            // ignora '.' ou outros caracteres
        }

        printf("%d\n", diamante);
    }

    return 0;
}

