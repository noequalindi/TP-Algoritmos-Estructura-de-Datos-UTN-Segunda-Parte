#ifndef Ejercicio2
#define Ejercicio2
#include <stdio.h>
#include "structs.hpp"

void procesarRegistroDeGoles(FILE *fileRegistroDeGoles, Partido*&partidos, Equipo equipos[]);
void agregarPartido(Partido* partido, int codigo_equipo, int id_partido, int id_gol, char nombre_jugador[], long int fecha);
Partido* buscarEInsertarPartido(Partido* partidos, RegistroDeGoles infoGol);
Partido* insertarOrdenadoPartido(Partido*&partidos, RegistroDeGoles infoGol);
Partido* BuscarPartido(Partido* partido, int numeroPartido);
void mostrarPartidos(Partido* partido);


void inicializarMatriz (GolesJugador *  MatrizResultados[][7]);


#endif

