#include <stdio.h>

void ordenar_decrescente(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[i]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    int casos;
    scanf("%d", &casos);

    while (casos--) {
        int qtd_alunos;
        scanf("%d", &qtd_alunos);

        int notas_original[qtd_alunos];
        int notas_ordenadas[qtd_alunos];

        // Ler as notas
        for (int i = 0; i < qtd_alunos; i++) {
            scanf("%d", &notas_original[i]);
            notas_ordenadas[i] = notas_original[i];
        }

        // Ordenar em ordem decrescente
        ordenar_decrescente(notas_ordenadas, qtd_alunos);

        // Contar quantos permaneceram na mesma posição
        int cont = 0;
        for (int i = 0; i < qtd_alunos; i++) {
            if (notas_original[i] == notas_ordenadas[i]) {
                cont++;
            }
        }

        printf("%d\n", cont);
    }

    return 0;
}
