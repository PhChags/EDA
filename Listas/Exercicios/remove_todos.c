#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista* prox;
} TyLista;

TyLista* exclui(TyLista* L, int valor) {
    TyLista* aux = L;
    TyLista* ant = L;
    while(aux != NULL){
        if(aux->info == valor){
            if(aux == L)
                L = L->prox;
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
    return L;
}

void imprime_lista(TyLista *li) {
    TyLista* p;
    for (p = li; p != NULL; p = p->prox)
        printf("%d ", p->info);
}

TyLista* insere (TyLista* li, int i) {
    TyLista* novo = (TyLista*) malloc(sizeof(TyLista));
    novo->info = i;
    novo->prox = li;
    
    return novo;
}

int main (void) {
    TyLista* lista = NULL;
    int valor;

    do {
        scanf("%d", &valor);
        if (valor > 0)
            lista = insere(lista, valor);
    } while(valor > 0);

    printf("\n\n===================== Lista Antes da Remocao =====================\n\n");
    imprime_lista(lista);
    printf("\n\n===================== Lista Apos Remocao =====================\n\n");
    scanf("%d", &valor);
    lista = exclui(lista, valor);
    imprime_lista(lista);
}