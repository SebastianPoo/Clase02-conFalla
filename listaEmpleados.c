#include "stdio.h"
#include "stdlib.h"
#include "listaEmpleados.h"
#include "persona.h"
#include "empleado.h"


nodo* inicLista()
{
    return NULL;
}

void muestraUnNodo(nodo* nodo)
{
    muestraUnEmpleado(nodo->dato);
}

nodo* crearNodo(stEmpleado dato)
{
    nodo* nuevo = (nodo*)malloc(sizeof(nodo));
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    return nuevo;
}

nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo)
{
    nuevoNodo->siguiente = lista;
    return nuevoNodo;
}

void mostrarLista(nodo* lista)
{
    nodo* seg = lista;
    while(seg!=NULL)
    {
        muestraUnEmpleado(seg->dato);
        seg = seg->siguiente;
    }
}

int ContarLista(nodo* lista)
{
    int cont=0;
    nodo* seg = lista;
    while(seg!=NULL)
    {
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}

nodo* agregarAlFinal(nodo* lista, nodo* nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodo* ultimo = buscaUltimo(lista);
        ultimo->siguiente = nuevo;
    }

    return lista;
}

nodo* buscaUltimo(nodo* lista)
{
    nodo* seg = lista;
    while(seg->siguiente!=NULL)
    {
        seg=seg->siguiente;
    }
    return seg;
}

int cuentaLista(nodo* lista)
{
    int cont=0;
    nodo* seg = lista;
    while(seg!=NULL)
    {
        cont++;
        seg = seg->siguiente;
    }
    return cont;
}


nodo* buscaEmpleado(nodo* lista, char apellido[])
{
    nodo* seg = lista;

    while(seg!=NULL && strcmp(seg->dato.persona.apellido,apellido)!=0)
    {
        seg = seg->siguiente;
    }

    return seg;
}

nodo* agregarEnOrdenPorLegajo(nodo* lista, nodo* nuevoNodo)
{
    if (!lista)
    {
        lista=nuevoNodo;
    }
    else
    {
        if(nuevoNodo->dato.legajo<lista->dato.legajo)
        {
            lista=agregarAlPrincipio(lista,nuevoNodo);
        }
        else
        {
            nodo* ante=lista;
            nodo* seg= lista->siguiente;
            while(seg!=NULL && nuevoNodo->dato.legajo>seg->dato.legajo)
            {
                ante=seg;
                seg=seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->siguiente=seg;
        }
    }
    return  lista;
}

nodo* unirLista(nodo* lista1, nodo* lista2)
{

    lista1 = agregarAlFinal(lista1, lista2);

    return lista1;
}


nodo* unirLista2(nodo* lista1, nodo* lista2)
{
    nodo* seg1 = lista1;
    nodo* seg2 = lista2;
    nodo* lista3;
    while(seg1!=NULL)
    {
        lista3 = agregarAlFinal(lista3, seg1);
        seg1 = seg1->siguiente;
    }
    while(seg2!=NULL)
    {
        lista3 = agregarAlFinal(lista3, seg2);
        seg2 = seg2->siguiente;
    }
    return lista3;
}

nodo* agregarEnOrdenApellido (nodo* lista, nodo* nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;

    }
    else
    {
        if(strcmp(nuevo->dato.persona.apellido, lista->dato.persona.apellido)>0)
        {
            lista=agregarAlPrincipio(lista,nuevo);

        }
        else
        {
            nodo* anterior=lista;
            nodo* aux=lista->siguiente;
            while(aux && strcmp(nuevo->dato.persona.apellido,aux->dato.persona.apellido)>0)
            {
                anterior=aux;
                aux=aux->siguiente;
            }
            nuevo->siguiente=aux;
            anterior->siguiente=nuevo;
        }
    }
    return lista;
}


nodo* borrarNodo (char apellido[], nodo* lista)
{
    nodo* aux;
    nodo* ante;
    if (lista && strcmp(apellido,lista->dato.persona.apellido)==0)
    {
        aux=lista;
        lista=lista->siguiente;
        free(aux);
    }
    else
    {
        aux=lista;
        while(aux && strcmp(apellido, lista->dato.persona.apellido)!=0)
        {
            ante=aux;
            aux=aux->siguiente;
        }
        if (aux)
        {
            ante->siguiente=aux->siguiente;
            free(aux);
        }
    }
    return lista;
}

nodo* agregaOrdenadoRecursivo (nodo* lista, nodo* nuevo)
{
    if (lista==NULL)
    {
        lista=nuevo;
    }
    else
    {

        if (strcmp(lista->dato.persona.apellido,nuevo->dato.persona.apellido)>0)
        {
            nuevo->siguiente=lista;
            lista=nuevo;
        }
        else
        {
            lista->siguiente=agregaOrdenadoRecursivo(lista->siguiente,nuevo);
        }
    }

    return lista;
}
