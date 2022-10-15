// Nó com maior valor de informação

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TyNoA;


TyNoA *maior(TyNoA *no) {
    while(no->dir != NULL)
        no = no->dir;
    return no;
}

void imprime(TyNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TyNoA *insere(TyNoA *no, int chave) {
    if (no == NULL) {
        no = (TyNoA *) malloc(sizeof(TyNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

int main(void) {
    TyNoA *raiz, *no;
    raiz = NULL;

    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    scanf("%s", l);
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        raiz = insere(raiz, valor);
        ptr = strtok(NULL, delimitador);
    }

    no = maior(raiz);
    if (no != NULL) {
        printf("%d", no->chave);
    }
}