#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "structs.hpp"
/*
void crearListaAPartirDeArchivo(InfoGoles *listaDeGoles, Equipo equipos[])
{

for(int i=0; i<32; i++) {
    for (int j=0; j<7; j++) {
	agregarNodoInfoGoles(listaDeGoles, matriz[i][j]);  	
}
}
return;
}
  void agregarNodoInfoGoles(InfoGoles*& p, InfoGoles x) 
{ 
     InfoGoles* nuevo = new InfoGoles(); 
     nuevo->goles = x.goles; 
     nuevo->fecha = x.fecha;
     strcpy(nuevo->nombre_jugador, x.nombre_jugador);
     nuevo->sgte = NULL; 
     if( p==NULL ){ 
       p = nuevo; 
    } else { 
      InfoGoles* aux = p; 
      while(aux->sgte!=NULL ){ 
         aux = aux->sgte; 
      } 
      aux->sgte = nuevo; 
    } 
}
*/

/*void procesarRegistroDeGoles(FILE *f, InfoGoles* &goles){
	FILE * regGoles = fopen (RegistroGoles,"rb");
	Archivo reg;
	fread(&reg,sizeof(Archivo),1,regGoles);
	while(!feof(regGoles)){
		agregarGoles(goles,reg.id_gol,reg.codigo_equipo,reg.fecha,reg.nombre_jugador);
		fread(&reg,sizeof(Archivo),1,regGoles);
	}	
	fclose(regGoles);	
	return;
}*/


