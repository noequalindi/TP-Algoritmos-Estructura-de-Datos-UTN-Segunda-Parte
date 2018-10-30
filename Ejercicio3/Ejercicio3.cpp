using namespace std;
#include <iostream>
#include <string.h>
#include "../structs.hpp"
#include "Ejercicio3.hpp"

//procedimiento para crear un vector auxiliar que contenga el nombre del pais y la cantidad de goles que hizo.
void cargarDatosParaArbol(GolesJugador * matriz[][64], arbolPaisesGoles vecPaisesGoles[]) 
{
	char paises[32][13] = 
    {
        "ARGENTINA",
        "AUSTRALIA",
        "BELGIUM",
        "BRAZIL",
        "COLOMBIA",
        "COSTA RICA",
        "CROATIA",
        "DENMARK",
        "EGYPT",
        "ENGLAND",
        "FRANCE",
        "GERMANY",
        "ICELAND",
        "IRAN",
        "JAPAN",
        "MEXICO",
        "MOROCCO",
        "NIGERIA",
        "PANAMA",
        "PERU",
        "POLAND",
        "PORTUGAL",
        "RUSSIA",
        "SAUDI ARABIA",
        "SENEGAL",
        "SERBIA",
        "SOUTH KOREA",
        "SPAIN",
        "SWEDEN",
        "SWITZERLAND",
        "TUNISIA",
        "URUGUAY"
    };
    
    int goles;	
	GolesJugador* aux = NULL;
    
    for (int i = 0; i < 32; i++) {
        goles = 0;
        
        strcpy(vecPaisesGoles[i].nombre_pais, paises[i]); // se utiliza el vector nuevo para guardar la informacion de la matriz, con otra estructura diferente que contempla la cantidad de goles y el nombre del pais
        
        for (int j = 0; j < 64; j++) {
            aux = matriz[i][j];
            while (aux != NULL) {
                goles += aux->info.goles;
                aux = aux->sgte;
                
            }
            vecPaisesGoles[i].cantGoles = goles; 
        }
    }
	
    return;
}

//funcion para recorrer el vector auxiliar y enviar  la informacion sobre paises y la cantidad de goles que estos realizaron a un arbol binario.
nodoArbolEquipos * insertarPaisesYGolesEnArbol(arbolPaisesGoles vecPaisesGoles[], int lenPaises) 	
{
	nodoArbolEquipos * raizEquipos = NULL;
	for(int i=0; i < lenPaises; i++) {
        insertarEnArbolDePaises(raizEquipos, vecPaisesGoles[i]); //se guarda la informaci�n del vector en el arbol binario
    }
    return raizEquipos;
}

//procedimiento estandard de insercion en arbol binario. 
void insertarEnArbolDePaises(nodoArbolEquipos *&arbolEquipos, arbolPaisesGoles infoGoles) 
{
    
        if(arbolEquipos == NULL) 
		{
		nodoArbolEquipos* aux = new nodoArbolEquipos();
		aux->info = infoGoles;
		aux->izq = NULL;
		aux->der = NULL;
		arbolEquipos = aux;
	} else {
		
		if (infoGoles.cantGoles < arbolEquipos->info.cantGoles) // se ordena por cantidad de goles de cada equipo
		{
        insertarEnArbolDePaises(arbolEquipos->izq, infoGoles);
    	
		} else {
		if (infoGoles.cantGoles >= arbolEquipos->info.cantGoles) {
            insertarEnArbolDePaises(arbolEquipos->der, infoGoles);
        } 
		}

	}
        return;
}


//Procedimiento para recorrer el arbol binario de equipos usando el metodo InOrden, y mostrarlo en pantalla.
void inOrdenGoles(nodoArbolEquipos *arbolEquipos)
{
	if (arbolEquipos != NULL)
	{

		inOrdenGoles(arbolEquipos->izq);
		cout << arbolEquipos->info.nombre_pais << ": "<< arbolEquipos->info.cantGoles << endl;
		inOrdenGoles(arbolEquipos->der);
	}
	return;
}

//procedimiento que imprime encabezado del listado solicitado
void mostrarArbolEquipoYGoles(nodoArbolEquipos *arbolEquipos)
{
	cout << "____________________________________________"<<endl;
	cout << " ********* EQUIPOS ORDENADOS POR CANTIDAD GOLES EN ORDEN (MENOR A MAYOR) ******** "<< endl;
	inOrdenGoles(arbolEquipos);
	return;
}
