#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
using namespace std;
#include "/Users/canteros/Documents/Algoritmos/TP_AyED_Segunda_Parte/Ejercicio1.hpp"
#include "/Users/canteros/Documents/Algoritmos/TP_AyED_Segunda_Parte/Ejercicio1.cpp"
#include "/Users/canteros/Documents/Algoritmos/TP_AyED_Segunda_Parte/structs.hpp"

int main() {
	
	int lenGoles = 169;	
	RegistroDeGoles goles[lenGoles];
	cargarRegistroDeGoles(goles);
	cout << "prueba"<<endl;
	generarRegistro(goles, lenGoles);
	mostrarRegistroDeGoles();
	
	InfoGoles matriz[32][8];
	InfoGoles* listaDeGoles = NULL;
	
	return 0;
}
