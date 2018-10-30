#ifndef Ejercicio3
#define Ejercicio3

using namespace std;
#include <iostream>
#include <string.h>
#include "../structs.hpp"
void cargarDatosParaArbol(GolesJugador * matriz[][64], arbolPaisesGoles vecPaisesGoles[]); 
nodoArbolEquipos * insertarPaisesYGolesEnArbol(arbolPaisesGoles vecPaisesGoles[], int lenPaises); 
void insertarEnArbolDePaises(nodoArbolEquipos *&arbolEquipos, arbolPaisesGoles infoGoles);
void inOrdenGoles(nodoArbolEquipos *arbolEquipos);
void mostrarArbolEquipoYGoles(nodoArbolEquipos *arbolEquipos);

#endif
