#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "structs.hpp"

void llenarMatriz(GolesJugador* matriz[][7]) { 
    // inicia con punteros vacios
    for (int i = 0; i < 32; i++) {
        for(int j = 0; j<7;j++){
            matriz[i][j] = NULL;
        }
        
    }
    
    FILE* fileRegistroDeGoles = fopen("RegistroGoles.dat", "rb");
    RegistroDeGoles regGol;
    // contador que va de 0 a 31 y recorre la matriz
    int count = 0; //numero de partido jugado     
    
    fread(&regGol, sizeof(RegistroDeGoles), 1, fileRegistroDeGoles);

    int EquipoAnterior = regGol.codigo_equipo; 
    int FechaAnterior = regGol.fecha;  

    while(!feof(fileRegistroDeGoles)) {
        
        while(!feof(fileRegistroDeGoles) && (EquipoAnterior==regGol.codigo_equipo) ){
            
            count=0;
            
            while(!feof(fileRegistroDeGoles) && 
                    EquipoAnterior==regGol.codigo_equipo && 
                    FechaAnterior == regGol.fecha ){
                    
                
                //cout << regGol.codigo_equipo<<" "<<count<<" "<<regGol.fecha<<" "<<regGol.nombre_jugador<<endl; 
                insertarOSumar(matriz[regGol.codigo_equipo][count], regGol.fecha, regGol.nombre_jugador);
                fread(&regGol, sizeof(RegistroDeGoles), 1, fileRegistroDeGoles); 
                
                if (FechaAnterior!=regGol.fecha) count++;

                FechaAnterior=regGol.fecha;
            }

        
        EquipoAnterior=regGol.codigo_equipo;
        }     
        
    }



    fclose(fileRegistroDeGoles);
}


void insertarOSumar(GolesJugador*& p, long fecha, char nombre_jugador[20]) {
    GolesJugador* aux = p;
    GolesJugador* ant = NULL;

    bool found=false;
    
    GolesJugador* nuevo = new GolesJugador();
    nuevo->info.fecha = fecha;
    strcpy(nuevo->info.jugador, nombre_jugador);
    nuevo->info.goles = 1;
    nuevo->sgte = NULL;
    
    // cuando aux es NULL: freno porque llegué al último
    // cuando el registro coincide en jugador y fecha: freno porque le tengo que sumar goles
    while (aux != NULL) {
        if (strcmp(aux->info.jugador, nombre_jugador) == 0 && aux->info.fecha==fecha) {
            cout << "tengo que sumar goles a " << aux->info.jugador<<endl;
            cout << "ya tiene"<< aux->info.goles<< endl ;
            found=true;
            break;
        }
        ant = aux;
        aux = aux->sgte;
    }

    if (found) {
        aux->info.goles++; // lo encontre, solo sumo goles
        cout << "sumo goles a " << aux->info.jugador<<endl;
        cout << "ya tiene"<< aux->info.goles<< endl ;
        
    } else if (ant == NULL) {
        // es el primero
        p = nuevo;
    } else  if(aux==NULL) {
        // llegue al ultimo y no lo encontre

        ant->sgte = nuevo;
        
    }
}

void mostrarMatriz(GolesJugador* matriz[][7]) { 
    GolesJugador* aux = NULL;
    
    for (int i = 0; i < 32; i++) {
        cout<<"---equipo----"<<endl;
        for (int j=0;j<7;j++){
            cout<<"---fecha----"<<endl;
        aux = matriz[i][j];
            while (aux != NULL) {
                cout << aux->info.fecha << " ";
                cout << aux->info.jugador << " ";
                cout << aux->info.goles << endl;
                aux = aux->sgte;
            }
        }
    }
}

void mostrarGolesPorEquipo(GolesJugador* matriz[][7]) {
    char paises[32][13]= 
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
    
    GolesJugador* aux = NULL;
    int goles;
    
    for (int i = 0; i < 32; i++) {
        goles = 0;
        cout << paises[i];
        for (int j = 0; j < 32; j++) {
            aux = matriz[i][j];

            while (aux != NULL) {
                goles += aux->info.goles;
                aux = aux->sgte;
            }
        }
        cout << " HIZO " << goles << " GOLES" << endl;
    }
}
void OcupacionMatriz (GolesJugador *  MatrizResultados[][7]) {
    int goles=0,total=0;

        for(int i=0;i<32;i++){
            cout << i <<"-";
            for(int j=0;j<7;j++){
                if (MatrizResultados[i][j]==NULL) cout << "x" ;
                else {
                        GolesJugador* aux = MatrizResultados[i][j];
                        while( aux!=NULL ) { 
                        goles=goles+aux->info.goles;    
                        aux = aux->sgte; 
                        } 
                        cout << goles;
                        total=total+goles;
                        goles=0;
                }
            
        }
        cout << endl;
    }
    cout << endl<<total;
}

void mostrarPartidos(Partido* partido) 
{ 

}
