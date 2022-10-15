#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TLista;

TLista* exclui(TLista* li, int valor) {
    TLista* aux = li;
    TLista* ant = li;
    while(aux != NULL){
        if(aux->info == valor){
            if(aux == li)
                li = li->prox;
            else if(aux->prox == NULL)
                ant->prox = NULL;
            else
                ant->prox = aux->prox;
            free(aux);
            aux = ant;
        }
        if(ant != aux) 
            ant = ant->prox;
        aux = aux->prox;
    }
    return li;
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

    scanf("%s", l);
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        lista = insere_fim(lista, valor);
        ptr = strtok(NULL, delimitador);
    }

    scanf("%d", &valor);
    lista = exclui(lista, valor);
    imprime_lista(lista);
}