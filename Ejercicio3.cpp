using namespace std;
#include <iostream>
#include <string.h>
#include "structs.hpp"
#include "Ejercicio3.hpp"
nodoArbolEquipo * matrizEnArbol(GolesJugador * matriz[][64]) 
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
    nodoArbolEquipo * raiz = NULL;
    
    for (int i = 0; i < 32; i++) {
        goles = 0;
        cout << paises[i] << " ";
        for (int j = 0; j < 64; j++) {
            aux = matriz[i][j];
            while (aux != NULL) {
                goles += aux->info.goles;
                insertarEnArbol(raiz, goles);
                aux = aux->sgte;
                
            }
      
        }
       
    }
	
    return raiz;
}
    
void insertarEnArbol(nodoArbolEquipo *&arbolEquipos, Info infogoles) {
    
       if (arbolEquipos == NULL)
    	{
    	nodoArbolEquipo* nuevo = new nodoArbolEquipo();
     
       nuevo->infoGoles.goles = infogoles.goles;
       nuevo->izq = NULL;
       nuevo->der = NULL;
    	} else 
		{
    	if (infogoles.goles < arbolEquipos->infoGoles.goles)
    	{
		
    	insertarEnArbol(arbolEquipos->izq, infogoles);
    	} else { 
    	insertarEnArbol(arbolEquipos->der, infogoles);
	
	}
}

}


void inOrdenGoles(nodoArbolEquipo *arbolEquipos)
{
	while (arbolEquipos != NULL)
	{
		inOrdenGoles(arbolEquipos->izq);
		cout << arbolEquipos->infoGoles.goles << endl;
		inOrdenGoles(arbolEquipos->der);
	}
	return;
}

    
