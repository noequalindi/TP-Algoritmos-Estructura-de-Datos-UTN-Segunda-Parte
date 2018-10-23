#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "structs.hpp"


void inicializarMatriz (GolesJugador *  MatrizResultados[][7]) {

	for (int i=0;i<32;i++){
		for(int j=0;j<7;j++){
			MatrizResultados[i][j]=NULL;

		}
	}
}

void procesarRegistroDeGoles(FILE *fileRegistroDeGoles, GolesJugador *  MatrizResultados[][7])
{
	fileRegistroDeGoles = fopen ("RegistroGoles.dat","rb");
	RegistroDeGoles regGol,GolAnterior;
	int partido=0;

	fread(&regGol,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
	GolAnterior=regGol;

	while(!feof(fileRegistroDeGoles)){
		
		while (!feof(fileRegistroDeGoles)&& regGol.codigo_equipo==GolAnterior.codigo_equipo ){

			while (!feof(fileRegistroDeGoles)&& regGol.codigo_equipo==GolAnterior.codigo_equipo && regGol.fecha==GolAnterior.fecha ) {
				
				//AgregarGolEnMatriz(MatrizResultados[regGol.codigo_equipo][partido], regGol);
				fread(&regGol,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
				GolAnterior=regGol;
			}
			partido++;
		}
	}
	fclose(fileRegistroDeGoles);	
	return;
}


void AgregarGolEnMatriz(GolesJugador *partido, RegistroDeGoles regGol){

GolesJugador* nuevo=new GolesJugador();


if (partido==NULL) { 
	partido=nuevo;
	strcpy(nuevo->   nombre_jugador,regGol.nombre_jugador);
	nuevo->fecha=regGol.fecha;
	nuevo->CantGoles=1;
	nuevo->sgte=NULL;
	}
else {
	
	
	if(partido->nombre_jugador==regGol.nombre_jugador){
		partido->CantGoles++;
		delete nuevo;

	}
	else {
		//buscar jugador ???

	}	
		

	}

}




/*

void agregarPartido(Partido* partido, int codigo_equipo, int id_partido, int id_gol, char nombre_jugador[], long int fecha)
{
	InfoGoles infoGol;
	Partido* partidos;

	infoGol.id_gol = id_gol;
	strcpy(infoGol.nombre_jugador, nombre_jugador);
	infoGol.fecha = fecha;
	infoGol.partidos = NULL;
	
	partido = buscarEInsertarPartido(partidos,infoGol);
	return;
		
}

Partido* buscarEInsertarPartido(Partido* partidos, RegistroDeGoles infoGol)
{
	Partido* buscado = BuscarPartido(partidos,infoGol.id_partido);
	if(buscado == NULL){
		buscado = insertarOrdenadoPartido(partidos,infoGol);		
	}
	return buscado;
}
Partido* insertarOrdenadoPartido(Partido*&partidos, RegistroDeGoles infoGol){
	Partido* nuevo = new Partido();
	nuevo->id_partido = infoGol.id_partido;
	nuevo->sgtePartido = NULL;
	Partido* aux = partidos;
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
*/
