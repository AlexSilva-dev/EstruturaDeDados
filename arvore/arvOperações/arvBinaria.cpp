#include <stdio.h>
#include <stdlib.h>

typedef struct arvB
{
     int dado;
     arvB *fe;
     arvB *fd;
}arvB;


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

arvB* copiaArv(arvB *raiz){ // Faz uma copia da arvore
    arvB *nova = (arvB*)malloc(sizeof(arvB));

    if(!raiz){
        return NULL;
    }else{
        return criarArv((*raiz).dado, copiaArv((*raiz).fe), copiaArv((*raiz).fd));
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


arvB* busca(arvB *raiz, int dd){ // n deu certo
    printf("%d", (*raiz).dado);
    if(!raiz){
        return NULL;
    }else if((*raiz).dado == dd){
        return raiz;
    }else{
        return busca((*raiz).fe, dd);
     
    }
}

arvB* buscaR(arvB *raiz, int dd){   // busca recursiva em arvore de busca
    if(!raiz){
        return NULL;
    }else if((*raiz).dado == dd){
         return raiz;
    }else if((*raiz).dado > dd){
        return buscaR((*raiz).fe, dd);

    }else{
        return buscaR((*raiz).fd, dd);
    }
}


int main(){

    arvB *arv1 = criarArv(50, NULL,NULL);
    (*arv1).fe = criarArv(40, NULL, NULL);
    (*arv1).fd = criarArv(79, NULL, NULL);
    (*arv1).fd->fd = criarArv(120, NULL, NULL);
    inserir(arv1, 10);
    inserir(arv1, 44);
    inserir(arv1, 78);
    impArv(arv1);
    printf("\n\n%d\n", (*arv1).fd->fe->dado);
    
    arvB *resp = criarArv( buscaR(arv1, 10)->dado, NULL, NULL);
    printf("%d", (*resp).dado);
    //impArv(arvCopia);
    //printf("%d\n%d\n%d", (*arv1).dado, (*arv1).fe->dado, (*arv1).fd->dado);

    return 0;
}