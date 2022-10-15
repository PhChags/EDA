#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct vizinho {
    int id_vizinho;
    int peso;
    struct vizinho *prox;
}TyVizinho;

typedef struct grafo{
    int id_vertice;
    int cor;
    TyVizinho *prim_vizinho;
    struct grafo *prox;
}TyGrafo;

TyGrafo *insere_vertice(TyGrafo *g, int id) {
    TyGrafo *vertice = (TyGrafo *) malloc(sizeof(TyGrafo));
    vertice->id_vertice = id;
    vertice->cor = -1;
    vertice->prox = g;
    vertice->prim_vizinho = NULL;
    return vertice;
}

void libera_vizinho(TyVizinho *vizinho) {
    if (vizinho != NULL) {
        libera_vizinho(vizinho->prox);
        free(vizinho);
    }
}

void libera_vertice(TyGrafo *vertice) {
    if (vertice != NULL) {
        libera_vizinho(vertice->prim_vizinho);
        libera_vertice(vertice->prox);
        free(vertice);
    }
}

TyGrafo *busca_vertice(TyGrafo *vertice, int id) {
    while ((vertice != NULL) && (vertice->id_vertice != id)) {
        vertice = vertice->prox;
    }
    return vertice;
}

TyVizinho *busca_vizinho(TyVizinho *vizinho, int id) {
    while ((vizinho != NULL) && (vizinho->id_vizinho != id)) {
        vizinho = vizinho->prox;
    }
    return vizinho;
}

void insere_aresta(TyGrafo *g, int origem, int destino, int peso) {
    TyGrafo *vertice = busca_vertice(g, origem);
    TyVizinho *vizinho = (TyVizinho *) malloc(sizeof(TyVizinho));
    vizinho->id_vizinho = destino;
    vizinho->peso = peso;
    vizinho->prox = vertice->prim_vizinho;
    vertice->prim_vizinho = vizinho;
}

void imprime(TyGrafo *vertice) {
    while (vertice != NULL) {
        printf("Vertice: %d\n", vertice->id_vertice);
        printf("Vizinhos: ");
        TyVizinho *vizinho = vertice->prim_vizinho;
        while (vizinho != NULL) {
            printf("%d ", vizinho->id_vizinho);
            vizinho = vizinho->prox;
        }
        printf("\n\n");
        vertice = vertice->prox;
    }
}

int ehNaoOrientado(TyGrafo *g) {
    TyGrafo *vertice = g;
    while(vertice != NULL){
        TyVizinho *aresta = vertice->prim_vizinho;
        while(aresta != NULL){
            TyGrafo *verticeAux = busca_vertice(g, aresta->id_vizinho);
            TyVizinho *arestaAux = busca_vizinho(verticeAux->prim_vizinho, vertice->id_vertice);
            if(arestaAux == NULL)
                return 0;
            else if(aresta->peso != arestaAux->peso)
                return 0;
            aresta = aresta->prox;
        }
        vertice = vertice->prox;
    }
    return 1;
}

int main() {
    /* A função main lê os dados de entrada, cria o grafo e chama a função solicitada no problema
    * depois imprime o resultado
    * ELA NÃO DEVE SER MODIFICADA
    * */
    int num_vertices, num_arestas;
    int id;
    int origem, destino, peso;
    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int i;
    TyGrafo *g = NULL;

    //le numero de vertices
    scanf("%d", &num_vertices);
    //le e cria os vertices
    for (i = 0; i < num_vertices; i++) {
        scanf("%s", l);
        id = atoi(l);
        g = insere_vertice(g, id);
    }

    //Le numero de arestas e depois le os dados de cada aresta
    //Cria as arestas no grafo
    scanf("%d", &num_arestas);
    for (i = 0; i < num_arestas; i++) {
        scanf("%s", l);
        //quebra a string de entrada
        ptr = strtok(l, delimitador);
        origem = atoi(ptr);
        ptr = strtok(NULL, delimitador);
        destino = atoi(ptr);
        ptr = strtok(NULL, delimitador);
        peso = atoi(ptr);
        insere_aresta(g, origem, destino, peso);
    }

    imprime(g);

    printf("%d", ehNaoOrientado(g));
    libera_vertice(g);
}