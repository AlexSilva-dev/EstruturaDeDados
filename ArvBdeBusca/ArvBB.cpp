#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


typedef struct NoArvBB No;
typedef struct ArvBB ArvBB;

struct NoArvBB{
    int chave;
    char *inf;
    No *fd;     //filho direito
    No *fe;     //filho esquerdo
};

struct ArvBB{
    No *primeiroNo;
    int tNos;   //total de nos
};



No* buscaIterativa(No *raiz, int chave){

    while(raiz != NULL){

        if(raiz->chave == chave){
            printf("\nChave %d encontrada no iterativo, seu dado e; %s", raiz->chave, raiz->inf);
            return raiz;
        }else if(chave < raiz->chave){
            raiz = raiz->fe;
        }else{
            raiz = raiz->fd;
        }
    
    }
    printf("\nNão encontrado! iterativo");
    return NULL;
}

No* buscaRecursiva(No *raiz, int chave){
    if(raiz == NULL){
        printf("\nNão encontrado! Na recursao");
        return NULL;
    }

    if(chave == raiz->chave){
        printf("\nChave %d encontrada na recursao, seu dado e; %s", raiz->chave, raiz->inf);
        return raiz;
    }else if(chave < raiz->chave){
        buscaRecursiva(raiz->fe, chave);
    }else{
        buscaRecursiva(raiz->fd, chave);
    }
    
}

No* inserir(No *raiz, int chave, char infor[30] ){
    
    if(raiz == NULL){
        raiz = (No*)malloc(sizeof(No));
        raiz->chave = chave;
        raiz->inf = infor;
        raiz->fd = NULL;
        raiz->fe = NULL;
        printf("        (Inserido!)");
        return raiz;

    }

    if(chave < raiz->chave){
        raiz->fe = inserir(raiz->fe, chave, infor);
    }else if(chave > raiz->chave){
        raiz->fd = inserir(raiz->fd, chave, infor);
    }else{
        printf("Chave já existe!");
        exit(0);
    }
    return raiz;
}

void imprimirPreOrdem(No *raiz){    //pre ordem
    
    if(raiz == NULL) return;
    printf("c:%d Nome: %s | ", raiz->chave, raiz->inf);
    imprimirPreOrdem(raiz->fe);
    imprimirPreOrdem(raiz->fd);
    return;
}

void imprimirPosOrdem(No *raiz){

    if(raiz == NULL) return;
    imprimirPosOrdem(raiz->fe);
    imprimirPosOrdem(raiz->fd);
    printf("c:%d Nome: %s | ", raiz->chave, raiz->inf);


}

void simetricaImprimir(No *raiz){
    if(raiz){
        simetricaImprimir(raiz->fe);
        printf("c:%d Nome: %s | ", raiz->chave, raiz->inf);
        simetricaImprimir(raiz->fd);
    }
    return;
}

int main(){

    No *arv1 = (No*)malloc(sizeof(No));
    arv1->chave = 18;
    arv1->fd = NULL;
    arv1->fe = NULL;
    char *a = (char*)malloc(sizeof(char)*30);
    a = "alex";
    arv1->inf = a;


    int chav;
 
    while(true){
        char *nome = (char*)malloc(sizeof(char)*30);

        printf("\nDigite a chave:\n");
        scanf("%d", &chav);
        if(chav < 0)break;
        printf("\nDigite o nome:\n");
        scanf("%s", nome);

        inserir(arv1, chav, nome);
        printf("\nRAIZ  chave; %d", arv1->chave);
    }

    imprimirPreOrdem(arv1);
    printf("\n\n");
    imprimirPosOrdem(arv1);
    printf("\n\n");
    simetricaImprimir(arv1);
    
    buscaIterativa(arv1, 5);
    buscaIterativa(arv1, 10);

    buscaRecursiva(arv1, 5);
    buscaRecursiva(arv1, 10);


    return 0;
}