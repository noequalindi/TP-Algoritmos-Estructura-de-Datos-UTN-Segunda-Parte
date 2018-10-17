#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;

#include "Ejercicio1.hpp"
#include "structs.hpp"

int main() {
	
	nodoArbol * arbol = NULL;
	

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
	system("Pause");
	return 0;
}
