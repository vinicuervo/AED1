#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} celula;

int comparacao(celula *c1, celula *c2){
    celula *d1, *d2;

    d1 = c1->seg;
    d2 = c2->seg;

    while (d1 != NULL && d2 != NULL){
        if (d1->conteudo != d2->conteudo)
            return 0;
        d1 = d1->seg;
        d2 = d2->seg;
    }

    if (d1 == NULL && d2 == NULL) return 1;
    else 
        return 0;
}

int main(){
    celula cabeca1, cabeca2, *p1, *p2;
    int n1, n2;

    cabeca1.seg = NULL;
    cabeca2.seg = NULL;

    printf("Digite o tamanho da lista 1: ");
    scanf("%d", &n1);

    printf("Digite o tamanho da lista 2: ");
    scanf("%d", &n2);

    p1 = &cabeca1;
    for (int i = 0 ; i < n1; i++){
        celula *nova = (celula *) malloc(sizeof(celula));
        scanf("%d", &nova->conteudo);
        nova->seg = NULL;
        p1->seg = nova;
        p1 = nova;
    }

    p2 = &cabeca2;
    for (int i = 0 ; i < n2; i++){
        celula *nova = (celula *) malloc(sizeof(celula));
        scanf("%d", &nova->conteudo);
        nova->seg = NULL;
        p2->seg = nova;
        p2 = nova;
    }

    if (comparacao(&cabeca1, &cabeca2)){
        printf("As listas sao iguais\n");
    } else {
        printf("As listas sao diferentes\n");
    }

    return 0;
}