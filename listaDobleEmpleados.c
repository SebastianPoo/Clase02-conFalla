#include "stdio.h"
#include "stdlib.h"
#include "listaDobleEmpleados.h"
#include "persona.h"
#include "empleado.h"


nodoDoble* inicListaDoble()
{
    return NULL;
}

void muestraUnNodoDoble(nodoDoble* nodo)
{
    muestraUnEmpleado (nodo->dato);
}

nodoDoble* crearNodoDoble(stEmpleado dato)
{
    nodoDoble* nuevo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

nodoDoble* agregarAlPrincipioDoble(nodoDoble* lista, nodoDoble* nuevoNodo)
{
    nuevoNodo->siguiente = lista;
    if(lista)
    {
        lista->anterior=nuevoNodo;
    }
    return nuevoNodo;
}

void mostrarListaDoble(nodoDoble* lista)
{
    nodoDoble* seg = lista;
    while(seg!=NULL)
    {
        muestraUnEmpleado(seg->dato);
        seg = seg->siguiente;
    }
}

void mostrarListaDobleConPuntero(nodoDoble* lista)
{
    nodoDoble* seg = lista;
    while(seg!=NULL)
    {

        printf("\n<---anterior--->%p-<---Actual--->%p-<--Siguiente--->%p",seg->anterior,seg,seg->siguiente);

        seg = seg->siguiente;
    }
}

nodoDoble* agregarAlFinalDeDoble(nodoDoble* lista, nodoDoble* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodoDoble* ultimo = buscaUltimoEnDoble(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior=ultimo;
    }

    return lista;
}

nodoDoble* buscaUltimoEnDoble(nodoDoble* lista)
{
    nodoDoble* seg = lista;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg;
}

///funcion auxiliar: borrar nodo 1ro
nodoDoble *borrarPrimero(nodoDoble*lista)
{
    nodoDoble*aBorrar=lista;
    if(lista!=NULL)
    {
        lista=lista->siguiente;
        if(lista!=NULL)
        lista->anterior=NULL;
        free(aBorrar);
    }
    return lista;
}
