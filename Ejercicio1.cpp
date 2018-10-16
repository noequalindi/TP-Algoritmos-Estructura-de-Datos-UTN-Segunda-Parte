#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"
#include "structs.hpp"

void cargarRegistroDeGoles(RegistroDeGoles goles[])
{
	
	goles[0].id_partido = 1;
	goles[0].id_gol = 1;
	goles[0].codigo_equipo = 1;
	goles[0].fecha = 14062018;
	strcpy(goles[0].nombre_jugador, "Yuri Gazinski");
	
	goles[1].id_partido = 1;
	goles[1].id_gol = 2;
	goles[1].codigo_equipo = 1;
	goles[1].fecha = 14062018;
	strcpy(goles[1].nombre_jugador, "Denís Chéryshev");
	
	goles[2].id_partido = 1;
	goles[2].id_gol = 3;
	goles[2].codigo_equipo = 1;
	goles[2].fecha = 14062018;
	strcpy(goles[2].nombre_jugador, "Artiom Dziuba");
	
	goles[3].id_partido = 1;
	goles[3].id_gol = 4;
	goles[3].codigo_equipo = 1; //rusia
	goles[3].fecha = 14062018;
	strcpy(goles[3].nombre_jugador, "Aleksandr Golovín");
	
	goles[4].id_partido = 2;
	goles[4].id_gol = 5;
	goles[4].codigo_equipo = 4; //uruguay
	goles[4].fecha = 15062018;
	strcpy(goles[4].nombre_jugador, "José María Giménez");
	
	goles[5].id_partido = 3;
	goles[5].id_gol = 6;
	goles[5].codigo_equipo = 6; //iran
	goles[5].fecha = 15062018;
	strcpy(goles[5].nombre_jugador, "Aziz Bouhaddouz");
	
	goles[6].id_partido = 4;
	goles[6].id_gol = 7;
	goles[6].codigo_equipo = 7; //portugal
	goles[6].fecha = 15062018;
	strcpy(goles[6].nombre_jugador, "Cristiano Ronaldo");
	
	goles[7].id_partido = 4;
	goles[7].id_gol = 8;
	goles[7].codigo_equipo = 7;
	goles[7].fecha = 15062018;
	strcpy(goles[7].nombre_jugador, "Cristiano Ronaldo");
	
	goles[8].id_partido = 4;
	goles[8].id_gol = 8;
	goles[8].codigo_equipo = 8; // españa
	goles[8].fecha = 15062018;
	strcpy(goles[8].nombre_jugador, "Diego Costa");
	
	goles[9].id_partido = 4;
	goles[9].id_gol = 9;
	goles[9].codigo_equipo = 8;
	goles[9].fecha = 15062018;
	strcpy(goles[9].nombre_jugador, "Diego Costa");
	
return;
    
}
void insertar(RegistroDeGoles goles[], int &lenGoles, RegistroDeGoles regGoles, int pos)
{

	for (int i=lenGoles-1; i>=pos; i--)
	{
		goles[i+1]=goles[i];
	}
	
	goles[pos] = regGoles;
	lenGoles ++;
	return;
}

int insertarOrdenado(RegistroDeGoles goles[], int &lenGoles, RegistroDeGoles regGoles)
{
	int i=0;

	while(i < lenGoles && goles[i].codigo_equipo <= regGoles.codigo_equipo) {
		i++;
	}	
	
	insertar(goles, lenGoles, regGoles, i);
	return i;
	
}
void generarRegistro(RegistroDeGoles goles[], int lenGoles)
{
	FILE * fileRegistroDeGoles = fopen("RegistroGoles.dat", "wb");
    RegistroDeGoles regGoles;
    
    for (int i = 0; i < lenGoles; i++) {
    	regGoles.codigo_equipo = goles[i].codigo_equipo;
    	regGoles.fecha = goles[i].fecha;
        regGoles.id_gol = goles[i].id_gol;
        regGoles.id_partido = goles[i].id_partido;
        strcpy(regGoles.nombre_jugador, goles[i].nombre_jugador);
        fwrite(&regGoles, sizeof(RegistroDeGoles), 1, fileRegistroDeGoles);
    }
    fclose(fileRegistroDeGoles);
	return;
}

void mostrarRegistroDeGoles()
{
    FILE * fileRegistroDeGoles = fopen("RegistroGoles.dat", "rb");
    RegistroDeGoles regGoles;
    fread(&regGoles, sizeof(RegistroDeGoles), 1, fileRegistroDeGoles);
    cout << "_______________________________________________________________" << endl;
    cout << "******** REGISTRO DE GOLES DE CADA PARTIDO POR EQUIPO ******** " << endl;
    cout << "_______________________________________________________________" << endl;
    while (!feof(fileRegistroDeGoles))
    {
    	
        cout << "CODIGO DE EQUIPO " << regGoles.codigo_equipo << " -> ";
        cout << "FECHA " << regGoles.fecha << endl;
        cout << "IDENTIFICADOR DEL GOL " << regGoles.id_gol << endl;
        cout << "IDENTIFICADOR DEL PARTIDO " << regGoles.id_partido << endl;
        cout << "NOMBRE DEL JUGADOR " << regGoles.nombre_jugador << endl;
        fread(&regGoles,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
    }
    cout << "_______________________________________________________________" << endl;
    cout << "_______________________________________________________________" << endl;
    cout << "_______________________________________________________________" << endl;
    fclose(fileRegistroDeGoles);
    return;
}
