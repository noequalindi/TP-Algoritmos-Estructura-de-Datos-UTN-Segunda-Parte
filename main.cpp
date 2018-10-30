#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

#include "Ejercicio1.hpp"
//incluido para compilar en vscode
//#include "Ejercicio1.cpp"
#include "Ejercicio2.hpp"
//incluido para compilar en vscode
//#include "Ejercicio2.cpp"
#include "structs.hpp"
#include "Ejercicio3.hpp"


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
    // Este array es la matriz: 32x64 posiciones de punteros
    GolesJugador* matriz[32][64];
    // este método inicializa la matriz lee el archivo y llena la matriz
    llenarMatriz(matriz);
//    la muestro para verificarla
//    mostrarMatriz(matriz);
    mostrarGolesPorEquipo(matriz);
    mostrarGolesPorFecha(matriz);
    mostrarGolesPorJugador(matriz);

	
    // **********************************
    // *** EJERCICIO 3 ******************
    // **********************************
	int lenPaises = 32;
	arbolPaisesGoles vecPaisesGoles[lenPaises];
	cargarDatosParaArbol(matriz, vecPaisesGoles);
	nodoArbolEquipos * arbolEquipos = NULL;
	arbolEquipos = insertarPaisesYGolesEnArbol(vecPaisesGoles, lenPaises);
	mostrarArbolEquipoYGoles(arbolEquipos);
	system("Pause");
	return 0;
}
