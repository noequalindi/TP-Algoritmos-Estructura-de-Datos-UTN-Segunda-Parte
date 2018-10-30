#ifndef Ejercicio1
#define Ejercicio1
#include <stdio.h>
#include "structs.hpp"

void cargarRegistroDeGoles(RegistroDeGoles goles[]);
void generarRegistro(nodoArbolGoles* arbolGoles);
void mostrarRegistroDeGoles();


Nodo * VectorArbol(RegistroDeGoles goles[], int lenGoles);
nodoArbolGoles * VectorAArbol(RegistroDeGoles goles[], int lenGoles); 	//Cargamos la informacion a un arbol binario, siguiendo criterio de orden por Equipo y por fecha.

void insertarNodoGoles(nodoArbolGoles* &arbolGoles,RegistroDeGoles valor);
void inOrden(nodoArbolGoles* arbolGoles, FILE* &fileRegistroDeGoles);

#endif // Ejercicio1
