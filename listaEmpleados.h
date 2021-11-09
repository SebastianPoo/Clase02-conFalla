#ifndef LISTAEMPLEADOS_H_INCLUDED
#define LISTAEMPLEADOS_H_INCLUDED
#include "persona.h"
#include "empleado.h"

typedef struct _nodo{
    stEmpleado dato;
    struct _nodo *siguiente;
}nodo;

nodo* inicLista();
nodo* crearNodo(stEmpleado e);
nodo* agregarAlPrincipio(nodo* lista, nodo* nuevoNodo);
nodo* agregarAlFinal(nodo* lista, nodo* nuevo);
nodo* buscaUltimo(nodo* lista);
nodo* buscaEmpleado(nodo* lista, char apellido[]);
void mostrarLista(nodo* lista);
void muestraUnNodo(nodo* nodo);
int ContarLista(nodo* lista);
nodo* unirLista(nodo* lista1, nodo* lista2);
nodo* unirLista2(nodo* lista1, nodo* lista2);
nodo* agregarEnOrdenApellido (nodo* lista, nodo* nuevo);
nodo* borrarNodo (char apellido[], nodo* lista);
nodo* agregaOrdenadoRecursivo (nodo* lista, nodo* nuevo);


#endif // LISTAEMPLEADOS_H_INCLUDED
