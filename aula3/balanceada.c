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
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    }
    else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

TNoA *criaArvoreBalanceada(TNoA *raiz, int *v, int inicio, int fim) { //balanceada tem como função escolher a ordem de inserção na árvore
    //(entra com a raiz da arvore, o vetor com os elementos a serem inseridos, o inicio e o fim para o calculo do meio)
    if (inicio <= fim) { //verifica sse ainda tem algo para inserir
        int meio = (inicio + fim) / 2; //cria o meio
        if (raiz == NULL) {//se for primeiro nó a ser inserido tem que atualizar a raiz da arvore
            raiz = insere(raiz, v[meio]); //usando a mesma função insere mas escolhendo a ordem de inserção, insere o elemento do meio do vetor
        }
        else insere(raiz, v[meio]); //se não estiver vazia chama a insere para ela encontra o local correto do elemento
        //constroi subárvores esquerda e direita
        criaArvoreBalanceada(raiz, v, inicio, meio - 1);
        criaArvoreBalanceada(raiz, v, meio + 1, fim);
        //fica sambando para a criação das subarvores, vai primeiro a esquerda, logo em seguida para direita, por isso ele manda o meio - 1 e o meio + 1
    }
    return raiz;
}

int main(void) {
    int tam = 7;
    int v[7] = {150, 300, 400, 500, 600, 800, 900};
    TNoA *raiz = NULL;
    raiz = criaArvoreBalanceada(raiz,v,0,tam-1); 
    imprime(raiz, 0);   
}


