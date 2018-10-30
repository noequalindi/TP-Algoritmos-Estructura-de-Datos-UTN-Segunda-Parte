using namespace std;
#include <iostream>
#include <string.h>
#include "structs.hpp"
#include "Ejercicio3.hpp"
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
   
       //cout << vecPaisesGoles[i].nombre_pais << ": " << vecPaisesGoles[i].cantGoles <<endl; 
    }
	
    return;
}
nodoArbolEquipos * insertarPaisesYGolesEnArbol(arbolPaisesGoles vecPaisesGoles[], int lenPaises) 	
{
	nodoArbolEquipos * raizEquipos = NULL;
	for(int i=0; i < lenPaises; i++) {
        insertarEnArbolDePaises(raizEquipos, vecPaisesGoles[i]); //se guarda la información del vector en el arbol binario
    }
    return raizEquipos;
}

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
void mostrarArbolEquipoYGoles(nodoArbolEquipos *arbolEquipos)
{
	cout << "____________________________________________"<<endl;
	cout << " ********* EQUIPOS ORDENADOS POR CANTIDAD GOLES EN ORDEN (MENOR A MAYOR) ******** "<< endl;
	inOrdenGoles(arbolEquipos);
	return;
}

    
