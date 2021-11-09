#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct
{
    struct nodo2 * cabezera;
    struct nodo2* cola;
}Fila;



void agregarAfila(Fila*fila,int dato);


#endif // FILA_H_INCLUDED
