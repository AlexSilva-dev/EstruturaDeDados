#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila* criarF(){
    Fila *nova = (Fila*)malloc(sizeof(Fila));
    (*nova).ini = NULL;
    (*nova).fim = NULL;
    (*nova).nEle = 0;
}

void insFila(Fila *f, int dd){
    NoFila *novoNo = (NoFila*)malloc(sizeof(NoFila));
    (*novoNo).dado = dd;
    (*novoNo).proxFila = NULL;
    if((*f).ini == NULL){
        (*f).ini = novoNo;
    } else{
        (*f).fim->proxFila = novoNo;
    }
    (*f).fim = novoNo;
    (*f).nEle++;
}

void retFila(Fila *f){

    NoFila *aux = (*f).ini;
    if((*f).ini){
        (*f).ini = (*f).ini->proxFila;
        free(aux);
    }else{
        printf("Erro! Lista vazia");
    }
}

void impFila(Fila *f){
    NoFila *no = (*f).ini;
    while(no != NULL){
        printf("%d\n", (*no).dado);
        no = (*no).proxFila;
    }
}

