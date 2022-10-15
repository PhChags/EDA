#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TyNoA;

TyNoA *inicializa(void) {
    return NULL;
}

void posOrdem(TyNoA* a) {
    if (a!= NULL) {
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%c\n",a->info);
    }
}
 
TyNoA *criaNo(char ch) {
    TyNoA *novo;
    novo = (TyNoA *) malloc(sizeof(TyNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int main(void) {
    TyNoA *raiz;
    raiz = criaNo('A'); 
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    posOrdem(raiz);
}