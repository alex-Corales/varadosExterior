#ifndef LISTAUNI_H_INCLUDED
#define LISTAUNI_H_INCLUDED
#endif // LISTAUNI_H_INCLUDED

#include <malloc.h>

typedef struct{
    datos vipd;
    struct nodo *next;
}nodo;

typedef struct{
    nodo *acceso; //cabecera de la lista
    nodo *cursor;
    nodo *cursoraux;
}lista;

void init(lista *p){
    (*p).acceso = NULL;
    (*p).cursor = NULL;
    (*p).cursoraux = NULL;
}

int isFull(lista p){
    nodo *n;
    n = (nodo*)malloc(sizeof(nodo));

    if(n == NULL){
        free(n);
        return 1;
    }else{
        free(n);
        return 0;
    }
}

//Lista vacia
int isEmpty(lista p){
    if(p.acceso == NULL)
        return 1;
    else
        return 0;
}

//Fuera de estructura
int isOos(lista p){
    if(p.cursor == NULL)
        return 1;
    else
        return 0;
}

datos copyc(lista p){
    return p.cursor->vipd;
}
//Insertar un elemento a la lista
void insertlist(lista *p, datos varado){
    nodo *aux=(nodo*)malloc(sizeof(nodo));
    if(aux!=NULL){
        if(((*p).cursor)==((*p).acceso)){
            (*p).acceso=aux;
            aux->next=(*p).cursor;
            (*p).cursor=(*p).acceso;
            (*p).cursoraux=(*p).acceso;
        }
        else{
            (*p).cursoraux->next=aux;
            aux->next=(*p).cursor;
            (*p).cursor=aux;
        }
        (*p).cursor->vipd=varado;
    }
}

void suppress(lista *p){
    if(((*p).cursor)==((*p).acceso)){
        (*p).acceso=(*p).cursor->next;
        free((*p).cursor);
        (*p).cursor=(*p).acceso;
        (*p).cursoraux=(*p).acceso;
    }
    else{
        (*p).cursoraux->next=(*p).cursor->next;
        free((*p).cursor);
        (*p).cursor=(*p).cursoraux->next;
    }
}
//colocar el cursor al principio
void reset(lista *p){
    (*p).cursor=(*p).acceso;
    (*p).cursoraux=(*p).acceso;
}
//Apuntar al nodo siguiente
void forwardlist(lista *p){
     (*p).cursoraux=(*p).cursor;
     (*p).cursor=(*p).cursor->next;
}


