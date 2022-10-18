#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int info;
    struct Lista *prox;
} TyLista;


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

TyLista *inverter(TyLista *L){
    TyLista *novo = NULL;
    TyLista *aux;
    
    for(aux = L; aux; aux = aux->prox)
        novo = insere(novo, aux->info);
    
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

    printf("\n\n===================== Lista Antes da Inversao =====================\n\n");
    imprime_lista(lista);
    TyLista *invertida = inverter(lista);
    printf("\n\n===================== Lista Apos Inversao =====================\n\n");
    imprime_lista(invertida);
}