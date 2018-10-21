#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "structs.hpp"

void procesarRegistroDeGoles(FILE *fileRegistroDeGoles, Partido*&partidos, Equipo equipos[])
{
	fileRegistroDeGoles = fopen ("RegistroGoles.dat","rb");
	RegistroDeGoles regGol;
	int i=0;
	fread(&regGol,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
	while(!feof(fileRegistroDeGoles)){
		
		while (equipos[i].codigo_equipo == regGol.codigo_equipo)
		{
		
		agregarPartido(partidos, regGol.codigo_equipo, regGol.id_partido,regGol.id_gol, regGol.nombre_jugador, regGol.fecha);
		fread(&regGol,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
		i++;
		}
	}	
	fclose(fileRegistroDeGoles);	
	return;
}



void agregarPartido(Partido* partido, int codigo_equipo, int id_partido, int id_gol, char nombre_jugador[], long int fecha)
{
	InfoGoles infoGol;
	Partido* partido;
	Partido* partidos;
	infoGol.id_gol = id_gol;
	strcpy(infoGol.nombre_jugador, nombre_jugador);
	infoGol.fecha = fecha;
	infoGol.partidos = NULL;
	
	Partido* partido = buscarEInsertarPartido(partidos,infoGol);
	return;
		
}

Partido* buscarEInsertarPartido(Partido* partidos, RegistroDeGoles infoGol)
{
	Partido* buscado = buscarPartido(partidos,infoGol.id_partido);
	if(buscado == NULL){
		buscado = insertarOrdenadoPartido(partidos,infoGol);		
	}
	return buscado;
}
Partido* insertarOrdenadoPartido(Partido*&partidos, RegistroDeGoles infoGol){
	Partido* nuevo = new Partido();
	nuevo->id_partido = infoGol.id_partido;
	nuevo->sgtePartido = NULL;
	Partido* aux = p;
	Partido* ant = NULL;
	
	while (aux != NULL && aux->id_partido <= infoGol.id_partido){
		ant = aux;
		aux = aux->sgtePartido;
	}
	
    if(ant == NULL){
    	partidos = nuevo;
	} else {
		ant->sgtePartido = nuevo;
		
	}
	nuevo->sgtePartido = aux;
	return nuevo;
}

Partido* BuscarPartido(Partido* partido, int numeroPartido) 
{
	Partido* aux = partido;
	while(aux!=NULL && aux->id_partido != numeroPartido) {
		aux = aux->sgtePartido;
	}
	return aux;
}
void mostrarPartidos(Partido* partido) 
{ 
    Partido* aux = partido;
    while( aux!=NULL ) { 
       cout << aux->id_partido << endl;
       cout << "Equipo " << aux->equipos.codigo_equipo << endl;
       cout << "Gol " << aux->equipos.infoGol.id_gol << endl; 
       cout << "___________________________" << endl;
       aux = aux->sgtePartido; 
    } 
}
