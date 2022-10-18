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

int compara(TyAB *arv, TyAB *avr){
    if (arv == NULL && avr == NULL) 
        return 1;
    
    return (arv && avr) && (arv->info == avr->info) && compara(arv->esq, avr->esq) && compara(arv->dir, avr->dir);
}

int main(void) {
    TyAB *a1, *a2; 
    inicializa(&a1);
    inicializa(&a2);
    int valor, comparador;

    printf("\n\n============= Construindo Arvore 1 =============\n\n");
    do
    {
        scanf("%d", &valor);
        if (valor > 0)
            insere(&a1, valor);
    } while (valor > 0);
    
    printf("\n\n============= Construindo Arvore 2 =============\n\n");
    do
    {
        scanf("%d", &valor);
        if (valor > 0)
            insere(&a2, valor);
    } while (valor > 0);

    printf("\n\n============= Arvore 1 =============\n\n");
    imprime(a1, 0);
    printf("\n\n============= Arvore 2 =============\n\n");
    imprime(a1, 0);
    printf("\n\n\n");
    comparador = compara(a1, a2);
    if (comparador == 1) 
        printf("Elas sao iguais");
    else
        printf("Elas sao diferentes");
}