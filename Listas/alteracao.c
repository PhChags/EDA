#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

void altera(TLista* li, int vantigo, int vnovo) {
    TLista* aux = li;
    while(aux != NULL){
        if(aux->info == vantigo)
            aux->info = vnovo;
        aux = aux->prox;
    }
}

void imprime_lista(TLista *li) {
    TLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

TLista* insere_fim (TLista* li, int i) {
    TLista* novo = (TLista*) malloc(sizeof(TLista));
    novo->info = i;
    novo->prox = NULL;
    TLista* p = li;
    TLista* q = li;
    while (p != NULL) {
        q = p;
        p = p->prox;
    }
    if (q != NULL)
        q->prox = novo;
    else
        li = novo;
    return li;
}

int main (void) {
    TLista* lista = NULL;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;
    int valor_antigo, valor_novo;

    scanf("%s", l);
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        lista = insere_fim(lista, valor);
        ptr = strtok(NULL, delimitador);
    }

    scanf("%d", &valor_antigo);
    scanf("%d", &valor_novo);
    altera(lista, valor_antigo, valor_novo);
    imprime_lista(lista);
}