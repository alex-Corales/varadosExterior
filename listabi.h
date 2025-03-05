typedef struct{
    datos vipd;
    struct nodo *next;
    struct nodo *previous;
}nodo;

typedef struct{
    nodo *acceso;
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
        return 1;
    }else{
        free(n);
        return 0;
    }
}

int isEmpty(lista p){
    if(p.acceso == NULL)
        return 1;
    else
        return 0;
}

int isOos(lista p){
    if(p.cursor == NULL)
        return 1;
    else
        return 0;
}

datos copyc(lista p){
    return p.cursor->vipd;
}

void insertlist(lista *p, datos varado){
    nodo *aux=(nodo*)malloc(sizeof(nodo));
    if(aux!=NULL){
        if((*p).acceso==NULL){
            aux->vipd=varado;
            (*p).acceso=aux;
            aux->next=(*p).cursor;
            aux->previous=NULL;
            (*p).cursor=(*p).cursoraux=(*p).acceso;
        }else if(((*p).cursor)==((*p).acceso)){
            (*p).cursor->vipd=varado;
            (*p).acceso=aux;
            aux->next=(*p).cursor;
            (*p).cursor->previous=aux;
            aux->previous=NULL;
            (*p).cursor=(*p).cursoraux=(*p).acceso;
        }else if((*p).cursor != NULL){
            (*p).cursor->vipd=varado;
            aux->next=(*p).cursor;
            aux->previous=(*p).cursoraux;
            (*p).cursor->previous=aux;
            (*p).cursoraux->next=aux;
            (*p).cursor=aux;
        }else{
            aux->vipd=varado;
            (*p).cursoraux->next=aux;
            aux->next=NULL;
            aux->previous=(*p).cursoraux;
            (*p).cursor=aux;
        }

    }
}

void suppress(lista *p){
    if(((*p).cursor)==((*p).acceso)){
        (*p).acceso=(*p).cursor->next;
        free((*p).cursor);
        (*p).cursor=(*p).acceso;
    }else if(((*p).cursor)!=NULL){
        (*p).cursoraux->next = (*p).cursor->next;
        (*p).cursor->previous = (*p).cursoraux->next;
        free((*p).cursor);
        (*p).cursor = (*p).cursoraux->next;
    }else{
        (*p).cursoraux->next = (*p).cursor->next;
        free((*p).cursor);
        (*p).cursor = (*p).cursoraux->next;
    }
}

void reset(lista *p){
    (*p).cursor=(*p).acceso;
    (*p).cursoraux=(*p).acceso;
}
void forwardlist(lista *p){
    (*p).cursoraux=(*p).cursor;
    (*p).cursor=(*p).cursor->next;
}

void backward(lista *p){
    (*p).cursoraux=(*p).cursor;
    (*p).cursor=(*p).cursor->previous;
}
