#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

#include "Ejercicio1.hpp"
#include "Ejercicio1.cpp" //incluido para compilar en vscode

#include "Ejercicio2.hpp"
#include "Ejercicio1.cpp"
#include "Ejercicio2.cpp"
#include "structs.hpp"

int main() {
	nodoArbol * arbol = NULL;
	// FILE * fileRegistroDeGoles;
	// Partido *partidos;
	// Partido *partido;
	// RegistroDeGoles infoGol;
	// Equipo equipos[32];
	// int codigo_equipo, id_partido, id_gol, numeroPartido;
	// char nombre_jugador[20];
	// long int fecha;
	int lenGoles = 169;

    // **********************************
    // *** EJERCICIO 1 ******************
    // **********************************
	RegistroDeGoles goles[lenGoles];
	// Generamos vector con informacion en memoria.
	cargarRegistroDeGoles(goles);
	// Cargamos la informacion a un arbol binario, siguiendo criterio de orden por Equipo y por fecha.
	arbol = VectorAArbol(goles, lenGoles);
	// Leemos el arbol con metodo InOrden y guardamos en archivo.
	generarRegistro(arbol);
	// Mostramos contenido en consola, recorriendo el archivo, para verificacion.
	//mostrarRegistroDeGoles();
	
    // **********************************
    // *** EJERCICIO 2 ******************
    // **********************************
    // Este array es la matriz: 32 posiciones de punteros
    	GolesJugador* matriz[32][7];
    // este método inicializa la matriz lee el archivo y llena la matriz
		llenarMatriz(matriz);
    // la muestro para verificarla
		mostrarMatriz(matriz);
    // la matriz ya tiene esta forma
    // [0] -> info, sgte -> info, sgte -> ...
    // [...]
    // [31] -> info, sgte -> info, sgte -> ...
    	//mostrarGolesPorEquipo(matriz);
    
    
	// procesarRegistroDeGoles(fileRegistroDeGoles, partidos, equipos);
	
	/*
	agregarPartido(partido, codigo_equipo, id_partido, id_gol, nombre_jugador, fecha);
	buscarEInsertarPartido(partidos, infoGol);
	insertarOrdenadoPartido(partidos, infoGol);
	BuscarPartido(partido, numeroPartido);
	mostrarPartidos(partido);
	*/
	// system("Pause");
	return 0;
}
