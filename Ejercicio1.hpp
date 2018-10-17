#ifndef Ejercicio1
#define Ejercicio1
#include <stdio.h>
#include "structs.hpp"


void cargarRegistroDeGoles(RegistroDeGoles goles[]);

void generarRegistro(nodoArbol* arbol);

void mostrarRegistroDeGoles();


Nodo * VectorArbol(RegistroDeGoles goles[], int lenGoles);
nodoArbol * VectorAArbol(RegistroDeGoles goles[], int lenGoles); 	//Cargamos la informacion a un arbol binario, siguiendo criterio de orden por Equipo y por fecha.


void insertarNodo(nodoArbol* &arbol,RegistroDeGoles valor);	

void inOrden(nodoArbol* arbol, FILE* &fileRegistroDeGoles);


#endif // Ejercicio1

