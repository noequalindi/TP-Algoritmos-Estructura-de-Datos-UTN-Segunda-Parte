#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;
#include "Ejercicio1.hpp"
#include "Ejercicio1.cpp"
#include "structs.hpp"

int main() {
	
	int lenGoles = 169;	

	RegistroDeGoles goles[lenGoles];

	cargarRegistroDeGoles(goles);

	generarRegistro(goles, lenGoles);

	mostrarRegistroDeGoles();
	
	return 0;
}
