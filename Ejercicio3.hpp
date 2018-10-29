using namespace std;
#include <iostream>
#include <string.h>
#include "structs.hpp"
nodoArbolEquipo * matrizEnArbol(GolesJugador* matriz[][64]); 
void insertarEnArbol(nodoArbolEquipo *&arbolEquipos,int goles);
void inOrdenGoles(nodoArbolEquipo *arbolEquipos);

