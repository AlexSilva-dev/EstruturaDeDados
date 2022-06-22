#include <stdio.h>
#include <stdlib.h>

typedef struct arvBNo{
    int folha;
    int *key;            //chaves do nó/ informações armazenadas
    int nKeys;           // número de chaves usadas no nó, no momento atual do nó
    struct arvBNo *sons;    // filhos do nó
} arvB;



arvB* criarNo(int t){
    arvB *novo = (arvB*)malloc(sizeof(arvB));
    (*novo).nKeys = 0;
    (*novo).key = (int*)malloc(sizeof(int)*(2*(t-1)));
    (*novo).sons = (arvB*)calloc(2*t, sizeof(arvB*));
    (*novo).folha = 1;
    return novo;
}

int main(int argc, char const *argv[])
{
    arvB *a1 = NULL;
    a1 = criarNo(2);
    printf("chaves; %d", (*a1).folha );
    return 0;
}
