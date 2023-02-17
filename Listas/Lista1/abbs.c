/*Para as próximas questões, assuma que esta é a struct do nó da árvore.
    typedef struct reg {
        int chave;
        int conteudo;
        struct reg *esq, *dir;
    } noh;
Q8 - Suponha que x->esq->chave ≤ x->chave para cada nó x dotado de filho esquerdo e
x->chave ≤ x->dir->chave para cada nó x dotado de filho direito. Essa árvore é de busca? Não, pois não existem chaves iguais em ABB
Q9 - Escreva uma função que decida se uma dada árvore binária é ou não é de busca.
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
        int chave;
        int conteudo;
        struct reg *esq, *dir;
} noh;

int eh_ABB(noh *raiz){
    if(!((raiz->esq->chave < raiz->chave) && (raiz->dir->chave > raiz->chave)))
        return 0;
    else
        return 1;
}

noh *insere_ABB(noh *no, int chave) {
    if (no == NULL) {
        no = (noh *) malloc(sizeof(noh));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere_ABB(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere_ABB(no->dir, chave);
    }
    else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

noh *insere(noh *no, int chave) { 
    noh *novo;
    novo = (noh *) malloc(sizeof(noh));
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

int main (void){
    noh *raiz, *no;
    int resp, resp1;

    raiz = NULL;
    raiz = insere_ABB(raiz, 500);
    insere_ABB(raiz, 600);
    insere_ABB(raiz, 550);
    insere_ABB(raiz, 400);
    
    no = NULL;
    no = insere(no, 500);
    no->dir = insere(no, 600);
    no->esq = insere(no, 550);
    no->dir = insere(no, 400);

    resp = eh_ABB(raiz);
    if (resp == 1)
        printf("Eh ABB");
    else
        printf("Nao eh ABB");
    
    resp1 = eh_ABB(no);
    if (resp1 == 1)
        printf("\nEh ABB");
    else
        printf("\nNao eh ABB");

    return 0;
}*/
/*Q10 - Suponha que as chaves 50 30 70 20 40 60 80 15 25 35 45 36 são inseridas, nesta
ordem, numa árvore de busca inicialmente vazia. Desenhe a árvore que resulta. Em
seguida remova o nó que contém 30.-> Feito em folha
Q11 - Considere árvores binárias de busca cujos nós têm a estrutura indicada abaixo.
Escreva uma função que receba a raiz de uma tal árvore e o endereço de um nó x e devolva o endereço do pai de x.
    typedef struct reg {
        int chave;
        int conteudo;
        struct reg *esq, *dir;
    } noh;
Se x não pertence à árvore, a função deve devolver NULL. O consumo de tempo de sua
função deve ser limitado pela profundidade de x.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int chave;
    int conteudo;
    struct reg *esq, *dir;
} noh;

void imprime(noh *nodo, int tab) {
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

noh *busca_pai(noh *no, int x) {
    noh *ant;
    while (no != NULL) {
        if (no->chave == x)
            return ant; //achou retorna o ponteiro para o nó
        else if (no->chave > x){
            ant = no;
            no = no->esq;
        }else{
            ant = no;
            no = no->dir;
        }
    }
    return NULL; //não achou, retorna null
}

noh *buscaRecursiva(noh *no, int chave) {
    if (no == NULL)
        return NULL;
    else if (no->chave == chave)
        return no;
    else if (no->chave > chave)
        return buscaRecursiva(no->esq, chave);
    else
        return buscaRecursiva(no->dir, chave);
}

noh *insere(noh *no, int chave) {
    if (no == NULL) {
        no = (noh *) malloc(sizeof(noh));
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

int main(void) {
    noh *raiz, *no;
    raiz = NULL;
    raiz = insere(raiz, 500);
    insere(raiz, 600);
    insere(raiz, 550);
    insere(raiz, 400);
    imprime(raiz, 0);

    no = busca_pai(raiz, 550);
    if (no != NULL) {
        printf("\n\nEncontrou nó de chave %d.", no->chave);
    } else printf("Não encontrou!");

    no = busca_pai(raiz, 400);
    if (no != NULL) {
        printf("\n\nEncontrou nó de chave %d.\n", no->chave);
    } else printf("Não encontrou!\n");

    imprime(raiz, 0);

}