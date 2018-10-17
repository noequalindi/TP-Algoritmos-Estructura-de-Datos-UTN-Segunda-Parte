#ifndef Ejercicio1
#define Ejercicio1
#include <stdio.h>
#include "structs.hpp"


void cargarRegistroDeGoles(RegistroDeGoles goles[]);

void generarRegistro(RegistroDeGoles goles[]);

void mostrarRegistroDeGoles();


Nodo * VectorArbol(RegistroDeGoles goles[], int lenGoles);

void insertarNodo(nodoArbol* &arbol,RegistroDeGoles valor);	

void inOrden(nodoArbol* arbol, FILE* &fileRegistroDeGoles);


#endif // Ejercicio1

