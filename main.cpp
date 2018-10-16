#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;
#include "Ejercicio1.hpp"
#include "structs.hpp"

int main() {
	
	int lenGoles = 10;	
	RegistroDeGoles goles[lenGoles];
	cargarRegistroDeGoles(goles);
	cout << "prueba"<<endl;
	generarRegistro(goles, lenGoles);
	mostrarRegistroDeGoles();
	
	InfoGoles matriz[32][8];
	InfoGoles* listaDeGoles = NULL;
	
	return 0;
}
