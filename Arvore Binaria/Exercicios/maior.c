#include <stdio.h>
#include <stdlib.h>

typedef struct ab {
    int info;
    struct ab *esq, *dir;
} TyAB;

void inicializa(TyAB **noRaiz) {
    *noRaiz = NULL;
}

void imprime(TyAB *nodo, int tab) {
    for (int i = 0; i < tab; i++) 
        printf("-");
    if (nodo != NULL) {
        printf("%d\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

void insere(TyAB **arv, int num) {
    if ((*arv == NULL)){
        *arv = (TyAB *) malloc(sizeof(TyAB));
        (*arv)->info = num;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
    } else if (num < (*arv)->info){
        insere(&((*arv)->esq), num);
    } else
        insere(&((*arv)->dir), num);
}

int maior(TyAB *arv){
    TyAB *aux = arv;

    while (aux->dir){
        aux = aux->dir;
    }
    
    return aux->info;
}

int main(void) {
    TyAB *raiz; 
    inicializa(&raiz);
    int valor, maior_elem;

    do
    {
        scanf("%d", &valor);
        if (valor > 0)
            insere(&raiz, valor);
    } while (valor > 0);

    imprime(raiz, 0);
    printf("\n\n\n");
    maior_elem = maior(raiz);
    printf("Maior elemento da Arvore eh: %d", maior_elem);
}