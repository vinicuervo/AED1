#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} celula;

void vetorDaLista(int v[], int n, celula *c){
    celula *p;
    p = c->seg;
    for (int i = 0; i < n; i++){
        v[i] = p->conteudo;
        p = p->seg;
    }
}

int main(){
    celula cabeca, *p;
    int n, i = 0, *v;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    
    cabeca.seg = NULL;
    p = &cabeca;
    for (i = 0; i < n; i++){
        celula *nova = (celula *) malloc(sizeof(celula));
        scanf("%d", &nova->conteudo);
        nova->seg = NULL;
        p->seg = nova;
        p = nova;
    }

    vetorDaLista(v, n, &cabeca);

    printf("Vetor copiado da lista: ");
    for (i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    printf("\n");

    p = cabeca.seg;
    celula *temp;
    while (p != NULL){
        temp = p;
        p = p->seg;
        free(temp);
    }

    free(v);
    return 0;
}