#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
    }No;

    typedef struct Lista{
        struct No *inicio;
        struct No *fim;
        int tam;
    }Lista;

    void criarNoInicio(Lista *l, int v){
        
        No *novoNo = (No*)malloc(sizeof(No));
        if((*l).inicio){
            No *ant = (*l).inicio;
            (*ant).anterior = novoNo;
        }
        (*novoNo).valor = v;
        (*novoNo).proximo = (*l).inicio;
        (*novoNo).anterior = NULL;
        (*l).inicio = novoNo;
        if((*l).fim == NULL){
            (*l).fim = novoNo;
        }
        (*l).tam++;

    }

    void fimLista(Lista *ll, int nValor){
        No *ult;
        ult = (*ll).inicio;
        while((*ult).proximo){
            ult = (*ult).proximo;
        }
        No *novoNo = (No*) malloc(sizeof(No));
        (*novoNo).valor = nValor;
        (*novoNo).proximo = NULL;
        (*novoNo).anterior = ult;
        (*ult).proximo = novoNo;

        (*ll).tam++;
    }

    void printarLista(Lista l){
        No *n1 = l.inicio;
        No *n2 = l.fim;
        printf("do começo ao final\n");
        while (n1 != NULL)
        {
            printf("%d ", (*n1).valor);
            n1 = (*n1).proximo;
        }
        printf("\ndo final para o começo\n");
        
        while(n2 != NULL){
            printf("%d ", (*n2).valor);
            n2 = (*n2).anterior;
        }
        printf("\nTamanho: %d", l.tam);
        
    }


    int main(){
        Lista l1;
        l1.inicio = NULL;
        l1.fim = NULL;
        l1.tam = 0;
        criarNoInicio(&l1, 10);
        criarNoInicio(&l1, 2);
        fimLista(&l1, 66);
        fimLista(&l1, 44);
        printarLista(l1);

        
        return 0;

    }
