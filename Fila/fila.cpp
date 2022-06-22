#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    struct NoFila *ini;
    struct NoFila *fim;
    int nEle;
}Fila;

typedef struct NoFila{

    int dado;
    NoFila *proxFila;
}NoFila;

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

int main(){

    Fila *fila1 = criarF();
    insFila(fila1, 20);
    insFila(fila1, 40);
    insFila(fila1, 50);
    retFila(fila1);
    impFila(fila1);


    return 0;
}