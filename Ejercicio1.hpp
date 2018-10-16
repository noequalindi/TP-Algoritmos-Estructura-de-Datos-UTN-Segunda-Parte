#ifndef Ejercicio1
#define Ejercicio1

#include "structs.hpp"
void cargarRegistroDeGoles(RegistroDeGoles goles[]);
void generarRegistro(RegistroDeGoles goles[], int lenGoles);
void mostrarRegistroDeGoles();
void insertar(RegistroDeGoles goles[], int &lenGoles, RegistroDeGoles regGoles, int pos);
int insertarOrdenado(RegistroDeGoles goles[], int &lenGoles, RegistroDeGoles regGoles);
#endif // Ejercicio1


