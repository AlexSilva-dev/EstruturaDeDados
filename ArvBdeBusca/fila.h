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

Fila* criarF();

void insFila(Fila *f, int dd);

void retFila(Fila *f);

void impFila(Fila *f);