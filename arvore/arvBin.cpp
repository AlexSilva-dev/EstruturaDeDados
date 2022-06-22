#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    No *fe;
    No *fd;
}No;
 
typedef struct Arv
{
    No *inicio;
    int tam;
}Arv;

No* criarNo(int nV){
    No *novo = (No*) malloc(sizeof(No));
    (*novo).info = nV;
    return novo;

}

int main(){

    Arv arv1;
    arv1.inicio = NULL;
    arv1.tam = 0;

    arv1.inicio = criarNo(50);
    No *raiz = arv1.inicio;
    printf("%d ", raiz->info);

    raiz->fe = criarNo(30);
     

    printf("\n%d", raiz->fe->info);
    return 0;

}