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

TyAB *copia(TyAB *arv){
    if(arv == NULL)
        return NULL;
    
    TyAB *novo;
    novo = (TyAB *) malloc(sizeof(TyAB));
    novo->info = arv->info;
    novo->esq = copia(arv->esq);
    novo->dir = copia(arv->dir);
    return novo;
}

int main(void) {
    TyAB *raiz, *copiada; 
    inicializa(&raiz);
    int valor;

    do
    {
        scanf("%d", &valor);
        if (valor > 0)
            insere(&raiz, valor);
    } while (valor > 0);
    
    imprime(raiz, 0);
    printf("\n\n\n");
    copiada = copia(raiz);
    imprime(copiada, 0);
};