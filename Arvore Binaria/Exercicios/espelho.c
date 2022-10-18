// inverte a árvore (filhos da direita tornam-se filhos a esquerda e vice-versa)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct noA {
    int info;
    struct noA *esq, *dir;
} TyNoA;

void espelho(TyNoA *raiz) {
    TyNoA *aux = raiz;
    TyNoA *temp = raiz;
    temp = aux->esq;
    aux->esq = aux->dir;
    aux->dir = temp;
    if(raiz->esq != NULL)
        espelho(raiz->esq);
    if(raiz->dir != NULL)
        espelho(raiz->dir);
}

void imprime(TyNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}
/*
void imprimeProfundidade(TyNoA *nodo, int altura) {
    altura = altura - 1;
    if (nodo != NULL) {
        printf("%d", nodo->info);
        if (altura > 0) {
            imprimeProfundidade(nodo->esq, altura);
            imprimeProfundidade(nodo->dir, altura);
        }
    } else {
        printf("*");
        if (altura > 0) {
            imprimeProfundidade(NULL, altura);
            imprimeProfundidade(NULL, altura);
        }
    }
}*/

void *insere(TyNoA **arv, int num, int alt) {
    if ((*arv == NULL)){
        *arv = (TyNoA *) malloc(sizeof(TyNoA));
        (*arv)->info = num;
        (*arv)->esq = NULL;
        (*arv)->dir = NULL;
    } else if (num < (*arv)->info){
        insere(&((*arv)->esq), num, ++alt);
    } else
        insere(&((*arv)->dir), num, ++alt);
}

int main (void) {
    TyNoA* raiz = NULL;
    int alt = 0, valor;

    do{
        scanf("%d", &valor);
        if (valor > 0)
            insere(&raiz, valor, alt);
    } while (valor > 0);
    
    printf("\n\n============= Arvore Antes do Espelhamento =============\n\n");
    imprime(raiz, 0);
    printf("\n\n=============== Arvore Apos Espelhamento ===============\n\n");
    espelho(raiz);
    imprime(raiz, 0);
    printf("\n");
    //imprimeProfundidade(raiz,altura);
}