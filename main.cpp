#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

#include "structs.hpp"

#include "Ejercicio1.hpp"
#include "Ejercicio1.cpp"//incluido para compilar en vscode

#include "Ejercicio2.hpp"
#include "Ejercicio2.cpp"//incluido para compilar en vscode


#include "Ejercicio3.cpp" //incluido para compilar en vscode
#include "Ejercicio3.hpp"


int main() {

	nodoArbolGoles * arbolGoles = NULL;

	int lenGoles = 169;

    // **********************************
    // *** EJERCICIO 1 ******************
    // **********************************
	RegistroDeGoles goles[lenGoles];
	// Generamos vector con informacion en memoria.
	cargarRegistroDeGoles(goles);
	// Cargamos la informacion a un arbol binario, siguiendo criterio de orden por Equipo y por fecha.
	arbolGoles = VectorAArbolGoles(goles, lenGoles);
	// Leemos el arbol con metodo InOrden y guardamos en archivo.
	generarRegistro(arbolGoles);
	// Mostramos contenido en consola, recorriendo el archivo, para verificacion.
	
	
    // **********************************
    // *** EJERCICIO 2 ******************
    // **********************************
    // Este array es la matriz: 32x64 posiciones de punteros
    GolesJugador* matrizGoles[32][64];
    // este método inicializa la matriz lee el archivo y llena la matriz
    llenarMatriz(matrizGoles);

	//Luego se muestran los datos segun ordenados segun la consigna.
    mostrarGolesPorEquipo(matrizGoles);
    mostrarGolesPorFecha(matrizGoles);
    mostrarGolesPorJugador(matrizGoles);

	
    // **********************************
    // *** EJERCICIO 3 ******************
    // **********************************
	
	int lenPaises = 32;
	//Declaramos un vector auxiliar para sumarizar la cantidad de goles por pais.
	arbolPaisesGoles vecPaisesGoles[lenPaises];
	// recorremos la matriz de goles y llenamos el vector auxiliar.
	cargarDatosParaArbol(matrizGoles, vecPaisesGoles);
	// declaramos un nodo raiz de un arbol binario, que nos permitira mostrar el resultado en orden.
	nodoArbolEquipos * arbolEquipos = NULL;
	// con este metodo recorremos el vector e insertamos la informacion en el arbol binario. 
	arbolEquipos = insertarPaisesYGolesEnArbol(vecPaisesGoles, lenPaises);
	// recorremos el contenido del arbol binario, siguendo el metodo InOrden, para mostrarlo de menor a mayor.
	mostrarArbolEquipoYGoles(arbolEquipos);
	
	return 0;
}
