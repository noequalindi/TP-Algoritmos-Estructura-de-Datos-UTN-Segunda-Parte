#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"
#include "structs.hpp"

int main() {
	
	nodoArbol * arbol = NULL;
	FILE *fileRegistroDeGoles;
	Partido *partidos;
	Partido *partido;
	RegistroDeGoles infoGol;
	Equipo equipos[32];
	int codigo_equipo, id_partido, id_gol, numeroPartido; 
	char nombre_jugador[20];
	long int fecha;
	int lenGoles = 169;	

	RegistroDeGoles goles[lenGoles];
	//Generamos vector con informacion en memoria.
	cargarRegistroDeGoles(goles);
	//Cargamos la informacion a un arbol binario, siguiendo criterio de orden por Equipo y por fecha.
	arbol=VectorAArbol(goles,lenGoles);
	// Leemos el arbol con metodo InOrden y guardamos en archivo.
	generarRegistro(arbol);
	//Mostramos contenido en consola, recorriendo el archivo,  para verificacion.
	mostrarRegistroDeGoles();
	
	//ejercicio 2
	procesarRegistroDeGoles(fileRegistroDeGoles, partidos, equipos);
	
	
	/*
	agregarPartido(partido, codigo_equipo, id_partido, id_gol, nombre_jugador, fecha);
	buscarEInsertarPartido(partidos, infoGol);
	insertarOrdenadoPartido(partidos, infoGol);
	BuscarPartido(partido, numeroPartido);
	mostrarPartidos(partido);
	*/


	system("Pause");
	return 0;
}
