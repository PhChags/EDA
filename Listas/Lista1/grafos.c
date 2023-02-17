/*Q13 - Desenhe os seguintes grafos: -> Feito na folha
a) G(V, E), onde V = {1, 2, 3, 4, 5, 6} e E = {(2, 5), (6, 1), (5, 3), (2, 3)}.
b) G(V, E), onde V = {1, 2, 3, 4, 5, 6} e E = {{2, 5}, {6, 1}, {5, 3}, {2, 3}}.*/
/*Q14 - Faça uma função para obter todos os nós adjacentes (vizinhos) a um nó do grafo, dado
que o grafo é representado por uma lista de adjacências.

void busca_adjacentes(TGrafo *g, int v){
    TGrafo *pv = busca_vertice(g,v);
    TVizinho *viz = NULL;
    //checa se ambos os vértices existem
    if((pv != NULL)) {
        //percorre a lista de vizinhos de v1 procurando por v2
        viz = pv->prim_vizinho;
        printf("Vizinhos de %d: ", v);
        while (viz != NULL) {
            printf("%d\n", viz);
            viz = viz->prox;
        }
    }
}*/

/*Q15 - Faça uma função para obter todos os nós adjacentes (vizinhos) a um nó do grafo, dado
que o grafo é representado por uma matriz de adjacências.*/

/*Q16 - Seja um grafo G cujos vértices são os inteiros de 1 a 8 e os vértices adjacentes a cada  ́
vértice são dados pela tabela abaixo: -> Feito na folha
(a) Desenhe o grafo G.
(b) Represente o grafo por meio de uma matriz de adjacência.
(c) Represente o grafo por meio de uma lista de adjacência.*/