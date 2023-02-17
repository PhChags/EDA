/*Q4 - Quantos antecedentes tem um nó no nível n em uma árvore binária? n - 1 
Q5 - Uma árvore estritamente binária com n nós folhas contém quantos nós? n * 2 - 1
Q6 - Considere árvores binárias que representam expressões aritméticas (composta por
operandos compostos por um único algarismo, operações de +, -, * e / e parênteses) como as
apresentadas abaixo.
Q7 - Escreva um algoritmo que receba uma expressão matemática em notação pós-fixa 
(composta por operandos compostos por um único algarismo, operações de +, -, * e /) 
representada por um string e retorne uma árvore binária representando esta expressão. 
A expressão pós-fixa é quando os operandos vem primeiro e depois o operador. Ex: (1+2)*3 fica 12+3*.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    char info;
    struct no *esq;
    struct no *dir;
}TyArv;

TyArv* Insere(TyArv *raiz,char x){
    if(raiz == NULL){
        TyArv *nova = (TyArv*) malloc(sizeof(TyArv));
        nova->dir = NULL;
        nova->esq = NULL;
        nova->info = x;    
        return nova;
    } else if(raiz->esq == NULL){
        char temp = raiz->info;
        raiz->info = x;
        raiz->esq = Insere(raiz->esq, temp);
    } else if(raiz->dir == NULL){
        raiz->dir = Insere(raiz->dir,x);
    } else{
        TyArv *nova_raiz = (TyArv*) malloc(sizeof(TyArv));
        nova_raiz->dir = NULL;
        nova_raiz->esq = raiz;
        nova_raiz->info = x;
        return nova_raiz;
    }
}

void imprime(TyArv *no, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (no != NULL) {
        printf("%c\n", no->info);
        imprime(no->esq, tab + 2);
        printf("\n");
        imprime(no->dir, tab + 2);
    } else printf("vazio");
}

int main(void){
    TyArv *raiz = NULL;
    char info;

    while(scanf("%c", &info)){
        if(info == '\n')
            break;
        if(info != '(' && info != ')' && info != ' ')
            raiz = Insere(raiz,info);
    }

    imprime(raiz, 0);
    printf("\n");
    
    free(raiz);   
    return 0;
}