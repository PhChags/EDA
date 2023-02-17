#include <stdlib.h>
#include <stdio.h>

/*
 * Esse código assume que o grafo é íntegro (não existem arestas para nós que não existem
 */

typedef struct vizinho { //representa vertice e aresta; representa as ligações dos grafos; chama-se vizinho pois representam quem o vertice/grafo consegue acessar 
    int id_vizinho;
    struct vizinho *prox;
}TVizinho;

typedef struct grafo{ //vertice, representam as "bolinhas" dos grafos
    int id_vertice;
    TVizinho *prim_vizinho;
    struct grafo *prox;
}TGrafo;

TGrafo *inicializa(){ //só retorna NULL
    return NULL;
}

void imprime(TGrafo *g){
    while(g != NULL){
        printf("Vértice %d\n", g->id_vertice);
        printf("Vizinhos: ");
        TVizinho *v = g->prim_vizinho;
        while(v != NULL){
            printf("%d ", v->id_vizinho);
            v = v->prox;
        }
        printf("\n\n");
        g = g->prox;
    }
}

void libera_vizinho(TVizinho *v){ //libera toodos os vizinhos
    if(v != NULL) {
        libera_vizinho(v->prox);
        free(v);
    }
}

void libera(TGrafo *g){ //libera o grafo inteiro
    if(g != NULL){
        libera_vizinho(g->prim_vizinho);
        libera(g ->prox);
        free(g);
    }
}

TGrafo* busca_vertice(TGrafo* g, int x){ //procura na lista vertical até encontra o vertice
    while((g != NULL) && (g->id_vertice != x)) {
        g = g->prox;
    }
    return g;
}

TVizinho* busca_aresta(TGrafo *g, int v1, int v2){ //procura o primeiro vertice na lista vertical depois, vai pra lista de vizinhos
    TGrafo *pv1 = busca_vertice(g,v1);
    TGrafo *pv2 = busca_vertice(g,v2);
    TVizinho *resp = NULL;
    //checa se ambos os vértices existem
    if((pv1 != NULL) && (pv2 != NULL)) {
        //percorre a lista de vizinhos de v1 procurando por v2
        resp = pv1->prim_vizinho;
        while ((resp != NULL) && (resp->id_vizinho != v2)) {
            resp = resp->prox;
        }
    }
    return resp;
}

TGrafo *insere_vertice(TGrafo *g, int x){ //insere um novo vertice no começo
    TGrafo *p = busca_vertice(g, x); //verifica se já existe
    if(p == NULL){
        p = (TGrafo*) malloc(sizeof(TGrafo)); //aloca a memoria (cria um novo negocinho no grafico)
        p->id_vertice = x; //adicionar a informação
        p->prox = g; //seu proximo aponta para o antigo primeiro do grafo
        p->prim_vizinho = NULL; //inicializa seu primeiro vizinho como nulo
        g = p; //novo g (ponteiro que aponta o primeiro da lista), passa a ser o vertice recem adicionado
    }
    return g; //retorna g
}

void insere_um_sentido(TGrafo *g, int v1, int v2){ 
    TGrafo *p = busca_vertice(g, v1); //procura o vertice que tera a ligação
    TVizinho *nova = (TVizinho *) malloc(sizeof(TVizinho)); //malloca espaço da nova ligação
    //adiciona os dados da ligação
    nova->id_vizinho = v2; 
    nova->prox = p->prim_vizinho; 
    p->prim_vizinho = nova; //coloca a nova ligação no começo
}

void insere_aresta(TGrafo *g, int v1, int v2){ //insere em não direcionado/ no orientado basta chamar uma unica vez a função insere_um_sentido
    TVizinho *v = busca_aresta(g, v1, v2); //busca os vertices
    if(v == NULL) {
        insere_um_sentido(g, v1, v2); //insere em um dos vertices
        insere_um_sentido(g, v2, v1); //insere no outro vertice
    }
}

void retira_um_sentido(TGrafo *g, int v1, int v2){ 
    TGrafo *p = busca_vertice(g, v1); //busca o vertice
    if(p != NULL) {
        TVizinho *ant = NULL; //cria uma variavel vizinho anterior
        TVizinho *atual = p->prim_vizinho; //cria uma variavel atual vizinho
        while ((atual) && (atual->id_vizinho != v2)) { //loop para encontrar vizinho a ser excluido
            ant = atual; //atualiza o valor do vizinho anterior
            atual = atual->prox; //atualiza o valor do vizinho atual
        }
        if (ant == NULL) //v2 era o primeiro nó da lista de vizinhos
            p->prim_vizinho = atual->prox; //passa o "cargo" de primeiro vizinho para o proximo vizinho
        else
            ant->prox = atual->prox; //"pula" o vizinho; da uma ignorada nele
        free(atual); //libera esse vizinho
    }
}

void retira_aresta(TGrafo *g ,int v1, int v2){ //retira grafo não direcionado/ no ordenado basta chamar uma unica vez a função insere_um_sentido
    TVizinho* v = busca_aresta(g,v1,v2); //busca os elementos
    if(v != NULL) {
        retira_um_sentido(g, v1, v2); //remove uma aresta
        retira_um_sentido(g, v2, v1); //remove a outra
    }
}


TGrafo *retira_vertice(TGrafo *g, int v){
    TGrafo* p = g;
    TGrafo* ant = NULL;
    while((p != NULL) && (p->id_vertice != v)) {
        ant = p;
        p = p->prox;
    }
    TVizinho* v1 = p->prim_vizinho;
    while(p->prim_vizinho != NULL){
        retira_aresta(g, v, v1);
    }
    if(ant == NULL)
        g = p->prox;
    else
        ant->prox = p->prox;
    free(p);

    return g;
}

int main(){
    TGrafo *g = inicializa();
    g = insere_vertice(g, 1);
    g = insere_vertice(g, 2);
    g = insere_vertice(g, 3);
    g = insere_vertice(g, 4);
    insere_aresta(g, 1, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 3);
	insere_aresta(g, 2, 4);
    imprime(g);
    retira_aresta(g, 3, 2);
    printf("Grafo após exclusão da aresta (3,2): \n\n");
    imprime(g);
    retira_vertice(g,2);
    printf("Grafo após exclusão do vértice 2: \n\n");
    imprime(g);
    libera(g);


}
