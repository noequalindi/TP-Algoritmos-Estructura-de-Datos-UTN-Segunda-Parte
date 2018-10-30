#ifndef Ejercicio2
#define Ejercicio2

#include <stdio.h>
#include "../structs.hpp"

void llenarMatriz(GolesJugador* matriz[][64]);
void mostrarMatriz(GolesJugador* matriz[][64]);
void mostrarGolesPorEquipo(GolesJugador* matriz[][64]);
void mostrarGolesPorFecha(GolesJugador* matriz[][64]);
void mostrarGolesPorJugador(GolesJugador* matriz[][64]);
void mostrarGoleadores(GolesJugador* goleadores);

GolesJugador* insertarOrdenado(GolesJugador*& goleadores, GolesJugador* p);
GolesJugador* buscar(GolesJugador* p, char nombre_jugador[20]);
GolesJugador* buscarEInsertarOrdenado(GolesJugador* &goleadores, GolesJugador* p, bool &enc);

void insertarOSumar(GolesJugador*& p, long fecha, char nombre_jugador[20]);

#endif
