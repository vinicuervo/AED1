#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} celula;

celula *listaEncadeada(int v[], int n, celula *c){
    celula *nova, *p;

    p = c;

    for (int i = 0 ; i < n ; i++){
        nova = (celula*) malloc(sizeof(celula));
        nova->conteudo = v[i];
        nova->seg = NULL;

        p->seg = nova;
        p = nova;
    }

    return p;
}

int main(){
    celula cabeca, *ultimo, *p;
    int n, i, *v;


    cabeca.seg = NULL;

    scanf("%d", &n);

    v = (int*) malloc (n * sizeof(int));
    for (i = 0; i < n ; i++){
        scanf("%d", &v[i]);
    }

    ultimo = listaEncadeada(v, n, &cabeca);
    
    p = cabeca.seg;
    while (p != NULL){
        printf("%d -> ", p->conteudo);
        p = p->seg;
    }
    printf("NULL");

    free(v);
    return 0;
}