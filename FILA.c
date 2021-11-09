
#include "stdio.h"
#include "stdlib.h"
#include "listaEmpleados.h"
#include "listaDobleEmpleados.h"
#include "persona.h"
#include "FILA.h"





///agregar a la Fila
/**void agregarAfila(Fila*fila,int dato)
{
    nodoDoble* nuevo= crearNodoDoble(dato);
    if(fila->cabezera==NULL)
    {
        fila->cabezera=nuevo;
        fila->cola=nuevo;
    }
    else
    {
        fila->cabezera=agregaralfinal(fila->cabezera,nuevo);
        fila->cola=nuevo;
    }
}
int* topeFila (Fila*fila){

    return fila->cola;
}
**/
///mostrar fila
/**void mostrarFila(Fila * fila){

    Fila* seg = fila;
    printf("\nTope ----------------------------------------------------------------- Base\n\n\n");
   while(seg != NULL){
    printf("%d  ", seg->cabezera);
    seg = seg->siguiente;
   }
    printf("\n\nTope ----------------------------------------------------------------- Base\n\n");
}
**/
///fila vacia
int filaVacia(Fila * fila){

    int flag = 0;
    if(fila == NULL)
        flag = 1;
    return flag;
}
