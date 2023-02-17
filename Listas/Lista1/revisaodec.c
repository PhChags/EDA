/*Q1 - Escreva um programa que, infinitamente, leia um número inteiro n, que representa o
tamanho,seguida de uma sequência de n números inteiros, e determine o comprimento
máximo de um segmento crescente destes n números. Exemplos:Na sequência 5, 10, 3,2, 4,
7, 9, 8, 5 o comprimento do segmento crescente máximo é 4.Na sequência 10, 8, 7, 5, 2 o
comprimento de um segmento crescente máximo é 1.Seu programa para quando n for menor ou igual a zero. 
#include <stdio.h>

int main (void){
    int n, contador = 0, maior_contado = 0;

    printf("Tamanho da lista: ");
    scanf("%d", &n);
    while(n > 0){
        int sequencia[n];
        printf("Criando lista\n");
        
        for (int i = 0; i < n; i++)
            scanf("%d", &sequencia[i]);
        for (int x = n - 1; x > -1; x--){
            if(sequencia[x] > sequencia[x - 1]){
                contador++;
            } else if(contador > maior_contado){
                maior_contado = contador;
                contador = 0;
            }
        }
        if(contador > maior_contado)
            maior_contado = contador;
        
        printf("O comprimento do segmento crescente maximo eh: %d\n", maior_contado);
        contador = 0;
        maior_contado = 0;
        printf("Tamanho da lista: ");
        scanf("%d", &n);    
    }
    

    return 0;
}*/
/*Q2 - Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um
número n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta
deste programa deve ser “1100”. Seu programa para quando n for menor que zero.
#include <stdio.h>

int main (void){
    int n, bin;

    scanf("%d", &n);
    printf("\nA representação binaria de %d, eh: ", n);
    while (n > 0){
        for (int i = 31; i > -1; i--){
            bin = n >> i;
            if(bin & 1) {
                printf("1");
            } else {
                printf("0");
            }
        }
        printf("\n");
        scanf("%d", &n);
    }

    return 0;
}*/
/*Seja a seguinte seqüência de instruções em um programa C:
        int *pti;
        int veti[]={10,7,2,6,3};
        pti = veti;
Qual afirmativa é falsa?
a. *pti é igual a 10
b. *(pti+2) é igual a 2
c. pti[4] é igual a 3 (X)
d. pti[1] é igual a 10
e. *(veti+3) é igual a 6*/
/*Q3 - O que significa o operador asterisco em cada um dos seguintes casos:
a) int *p; ponteiro
b) cout << *p; sinceramente não sei 
c) *p = x*5; primeiro ponteiro; segundo multiplição
d) cout << *(p+1); ta deslocando um ponteiro*/