// inverte a árvore (filhos da direita tornam-se filhos a esquerda e vice-versa)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
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
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

void imprimeProfundidade(TyNoA *nodo, int altura) {
    altura = altura - 1;
    if (nodo != NULL) {
        printf("%c", nodo->info);
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
}

TyNoA *criaArvore(char entrada[100], int tamanho) {
    char novaEntrada[100];
    int i,j;
    TyNoA *novo;
    novo = NULL;
    if ((tamanho > 0) && (entrada[0] != '*')) {
        novo = (TyNoA *) malloc(sizeof(TyNoA));
        novo->info = entrada[0];
        tamanho = tamanho / 2;

        i = 1;
        j = 0; 
        while (i <= tamanho) {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novaEntrada[i] = '\0';
        novo->esq = criaArvore(novaEntrada, tamanho);

        i = tamanho+1;
        j = 0; 
        while (i <= tamanho*2) {
            novaEntrada[j] = entrada[i];
            i++;
            j++;
        }
        novaEntrada[i] = '\0';
        novo->dir = criaArvore(novaEntrada, tamanho);
    }
    return novo;
}

int main (void) {
    TyNoA* raiz = NULL;
    int tam;
    int altura;
    char entrada[100];

    scanf("%s", entrada);
    tam = strlen(entrada);
    altura = log2(tam + 1);

    raiz = criaArvore(entrada, tam);
    espelho(raiz);
    imprime(raiz,tam);
    printf("\n");
    imprimeProfundidade(raiz,altura);
}