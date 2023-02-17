#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

void imprime(TNoA *nodo, int tab) {
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

TNoA *insere(TNoA *no, int chave) { 
    if (no == NULL) { //verifica se a raiz (o nó) é nulo
        no = (TNoA *) malloc(sizeof(TNoA)); //aloca espaço na memoria
        no->chave = chave; //a chave do novo no recebe a chave
        //inicializa os nos filhos
        no->esq = NULL; 
        no->dir = NULL;
    } 
    else if (chave < (no->chave)) //no não nulo e chave menor que chave atual
        no->esq = insere(no->esq, chave); // vai pra esquerda e chama o insere denovo
    else if (chave > (no->chave)) { // se for nulo e não for menor 
        no->dir = insere(no->dir, chave); // chama recursivamente o insere
    }
    else {
        printf("Inserção inválida! "); //caso não seja menor nem maior, ou seja, chave já cadastrada
        exit(1); //saida de erro
    }
    return no;
}

int main(void) {
    TNoA *raiz, *no; 
    raiz = NULL; 
    raiz = insere(raiz, 500); 
    insere(raiz, 600); 
    insere(raiz, 550); 
    insere(raiz, 400); 

    imprime(raiz, 0); 

}



