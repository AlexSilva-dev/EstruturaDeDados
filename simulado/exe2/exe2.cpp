#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <stdatomic.h>

typedef struct arvB
{
     int dado;
     struct arvB *fe;
     struct arvB *fd;
}arvB;

typedef struct Fila{
    struct NoFila *ini;
    struct NoFila *fim;
    int nEle;
}Fila;

typedef struct NoFila{

    void *info;
    struct NoFila *proxFila;
}NoFila;

Fila* criarF(){
    Fila *nova = (Fila*)malloc(sizeof(Fila));
    (*nova).ini = NULL;
    (*nova).fim = NULL;
    (*nova).nEle = 0;
}

void insFila(Fila *f, void *dd){
    NoFila *novoNo = (NoFila*)malloc(sizeof(NoFila));
    (*novoNo).info = dd;
    (*novoNo).proxFila = NULL;
    if((*f).ini == NULL){
        (*f).ini = novoNo;
    } else{
        (*f).fim->proxFila = novoNo;
    }
    (*f).fim = novoNo;
    (*f).nEle++;
    return;
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
    printf("\n(");
    while(no != NULL){
        struct arvB *raiz = (arvB*)((*no).info);
        printf("%d ", (raiz->dado));
        
        no = (*no).proxFila;
        //free(raiz);
    } 
    printf(")\n");
}
//
//
//
//             ARVORE
//
//
//


arvB* criarArv(int dd, arvB *fe, arvB *fd){ //criar arvore
    arvB *nova = (arvB*)malloc(sizeof(arvB));
    (*nova).dado = dd;
    (*nova).fe = fe;
    (*nova).fd = fd;

    return nova;
}

arvB* inserir(arvB *raiz, int dd){  //  inserir elementos na arv de busca
    if(!raiz){
        raiz = criarArv(dd, NULL, NULL);
        }else if (dd < (*raiz).dado && (!(*raiz).fe)){
            (*raiz).fe = criarArv(dd, NULL, NULL);
            printf("\ninserido\n");
            return (*raiz).fe;
        }else if(dd > (*raiz).dado && (!(*raiz).fd)){
            (*raiz).fd = criarArv(dd, NULL, NULL);
            printf("\ninserido\n");
            return (*raiz).fd;
        }else if(dd < (*raiz).dado && ((*raiz).fe)){
            return inserir((*raiz).fe, dd);
        }else if( dd > (*raiz).dado && ((*raiz).fd)){
            return inserir((*raiz).fd, dd);
        }
}



void impArv(arvB *raiz){ // imprime a arvore Caminhamento Pre-ordem
    if(!raiz){
        //printf("NULL");
        return;
    }else{
        printf("%d\n",(*raiz).dado);
        impArv((*raiz).fe);
        impArv((*raiz).fd);
    }
}

void imprAvrLargura(arvB *raiz){
    Fila *f1 =  (Fila*)malloc(sizeof(Fila));
    f1 = criarF();
    
    if(raiz){
        void *r = (void*)raiz;
        insFila(f1, r);
        //impFila(f1);
        int dd = (*raiz).dado;
        while((*f1).ini != NULL){
            dd = (*raiz).dado;
            printf("%d - ", dd);
            retFila(f1);
            if((*raiz).fe != NULL){
                r = (void*)(*raiz).fe;
                insFila(f1, r);
            }
            if((*raiz).fd != NULL){
                r = (void*)(*raiz).fd;
                insFila(f1, r);
            }
            impFila(f1);
            raiz = (arvB*)(*f1).ini->info;

    }
    }
}

int main(){
    arvB *a1 = criarArv(50, NULL, NULL);
    inserir(a1, 30);
    inserir(a1, 80);
    inserir(a1, 110);
    inserir(a1, 33);
    //impArv(a1);
    imprAvrLargura(a1);
    return 0;
}