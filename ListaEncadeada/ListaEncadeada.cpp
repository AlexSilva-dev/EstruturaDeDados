#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;
}No;

typedef struct Lista{
    No *inicio;
    int tamanho;
}Lista;

void iniLista(Lista *l, int nValor){
    No *novo = (No*)malloc(sizeof(No));
    (*novo).valor = nValor;
    (*novo).proximo = (*l).inicio;
    (*l).inicio = novo;
    (*l).tamanho++;
}

void fimLista(Lista ll, int valor){
    
}

void impLista(Lista l){
    printf("\n\nNos da lista: %d", l.tamanho);
    printf("\nElementos da lista: ");
    No *p = l.inicio;
    while(p){
        printf("%d", (*p).valor);
        p = (*p).proximo;
    }

}
int main(){
    printf("ola");
    Lista l1;
    l1.inicio = NULL;
    l1.tamanho = 0;
    impLista(l1);
    iniLista(&l1, 20);
    impLista(l1);
    
    return 0;
}