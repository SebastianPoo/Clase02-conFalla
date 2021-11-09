#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include "listaEmpleados.h"
#include "domicilio.h"


typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[10];
    char genero;
    stDomicilio domicilio;
}stPersona;

void muestraUnaPersona(stPersona p);
char *personaToString (stPersona p);
char *personaToCvs (stPersona p);
char *personaToJson (stPersona p);
///void arregloDePersonal (nodo* lista, char *arreglo[], int *validos);



#endif // PERSONA_H_INCLUDED
