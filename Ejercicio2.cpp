#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "structs.hpp"

void llenarMatriz(GolesJugador* matriz[][64]) {
    // inicia con punteros vacios
    for (int i = 0; i < 32; i++) {
        for(int j = 0; j < 64; j++) {
            matriz[i][j] = NULL;
        }
    }
    
    FILE* fileRegistroDeGoles = fopen("RegistroGoles.dat", "rb");
    RegistroDeGoles regGol;
    
    fread(&regGol, sizeof(RegistroDeGoles), 1, fileRegistroDeGoles);
    while(!feof(fileRegistroDeGoles)) {
        insertarOSumar(matriz[regGol.codigo_equipo][regGol.id_partido], regGol.fecha, regGol.nombre_jugador);
        fread(&regGol, sizeof(RegistroDeGoles), 1, fileRegistroDeGoles);
    }
    
    fclose(fileRegistroDeGoles);
}


void insertarOSumar(GolesJugador*& p, long fecha, char nombre_jugador[20]) {
    GolesJugador* aux = p;
    GolesJugador* ant = NULL;
    GolesJugador* nuevo = new GolesJugador();
    
    nuevo->info.fecha = fecha;
    strcpy(nuevo->info.jugador, nombre_jugador);
    nuevo->info.goles = 1;
    nuevo->sgte = NULL;
    
    bool found = false;
    
    // cuando aux es NULL: freno porque llegué al último
    // cuando el registro coincide en jugador y fecha: freno porque le tengo que sumar goles
    while (aux != NULL) {
        if (strcmp(aux->info.jugador, nombre_jugador) == 0 && aux->info.fecha==fecha) {
            found = true;
            break;
        }
        ant = aux;
        aux = aux->sgte;
    }

    if (found) {
        // lo encontré. Solo sumo goles
        aux->info.goles++;
    } else if (ant == NULL) {
        // es el primero
        p = nuevo;
    } else  if(aux==NULL) {
        // llegue al ultimo y no lo encontre

        ant->sgte = nuevo;
    }
}

void mostrarMatriz(GolesJugador* matriz[][64]) {
    GolesJugador* aux = NULL;
    
    for (int i = 0; i < 32; i++) {
        //cout<<"---equipo----"<<endl;
        for (int j=0; j<64 ;j++){
            //cout<<"---fecha----"<<endl;
            aux = matriz[i][j];
            while (aux != NULL) {
                cout << "el " << aux->info.fecha;
                cout << " " << aux->info.jugador;
                cout << " hizo " << aux->info.goles << " goles" << endl;
                aux = aux->sgte;
            }
        }
    }
}

void mostrarGolesPorEquipo(GolesJugador* matriz[][64]) {
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
    
    cout << "--------------------------" << endl;
    cout << "---- GOLES POR EQUIPO ----" << endl;
    cout << "--------------------------" << endl;
    
    GolesJugador* aux = NULL;
    int goles;
    
    for (int i = 0; i < 32; i++) {
        goles = 0;
        cout << paises[i];
        for (int j = 0; j < 64; j++) {
            aux = matriz[i][j];

            while (aux != NULL) {
                goles += aux->info.goles;
                aux = aux->sgte;
            }
        }
        cout << " HIZO " << goles << " GOLES" << endl;
    }
    cout << "__________________________" << endl;
    cout << "vvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << endl;
}

void mostrarGolesPorFecha(GolesJugador* matriz[][64]) {
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
    
    cout << "--------------------------" << endl;
    cout << "---- GOLES POR FECHA -----" << endl;
    cout << "--------------------------" << endl;
    
    GolesJugador* aux = NULL;
    long fechaAnterior = 0;
    
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 32; j++) {
            aux = matriz[j][i];
            
            while (aux != NULL) {
                if (fechaAnterior != aux->info.fecha) {
                    cout << endl;
                    cout << "FECHA: " << aux->info.fecha << endl;
                    fechaAnterior = aux->info.fecha;
                }
                cout << ">> " << aux->info.jugador << " DE " << paises[j] << endl;
                cout << ">> HIZO " << aux->info.goles << " GOLES" << endl;
                aux = aux->sgte;
            }
        }
    }
    cout << "__________________________" << endl;
    cout << "vvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << endl;
}

void mostrarGolesPorJugador(GolesJugador* matriz[][64]) {
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
    
    cout << "--------------------------" << endl;
    cout << "---- GOLES POR JUGADOR ---" << endl;
    cout << "--------------------------" << endl;
    
    GolesJugador* aux = NULL;
    GolesJugador* goleadores = NULL;
    bool encontrado;
    
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 64; j++) {
            aux = matriz[i][j];
            
            while (aux != NULL) {
                buscarEInsertarOrdenado(goleadores, aux, encontrado);
                aux = aux->sgte;
            }
        }
    }
    mostrarGoleadores(goleadores);
    
    cout << "__________________________" << endl;
    cout << "vvvvvvvvvvvvvvvvvvvvvvvvvv" << endl << endl;
}

void mostrarGoleadores(GolesJugador* goleadores) {
    GolesJugador* aux = goleadores;

    while (aux != NULL) {
        cout << aux->info.jugador;
        cout << " HIZO " << aux->info.goles << " GOLES" << endl;
        aux = aux->sgte;
    }
}

GolesJugador* insertarOrdenado(GolesJugador*& goleadores, GolesJugador* p) {
    GolesJugador* nuevo = new GolesJugador();
    strcpy(nuevo->info.jugador, p->info.jugador);
    nuevo->info.goles = p->info.goles;
    nuevo->sgte = NULL;
    GolesJugador* aux = goleadores;
    GolesJugador* ant = NULL;
    
    while (aux != NULL && aux->info.jugador[0] <= p->info.jugador[0]) {
        ant = aux;
        aux = aux->sgte;
    }
    
    if(ant == NULL) {
        goleadores = nuevo;
    } else {
        ant->sgte = nuevo;
    }
    nuevo->sgte = aux;
    return nuevo;
}

GolesJugador* buscar(GolesJugador* p, char nombre_jugador[20]) {
    GolesJugador* aux = p;
    while(aux!=NULL && strcmp(aux->info.jugador, nombre_jugador) != 0) {
        aux = aux->sgte;
    }
    return aux;
}

GolesJugador* buscarEInsertarOrdenado(GolesJugador*& goleadores, GolesJugador* p, bool &enc) {
    GolesJugador* buscado = buscar(goleadores, p->info.jugador);
    if(buscado == NULL) {
        buscado = insertarOrdenado(goleadores, p);
        enc = false;
    } else {
        buscado->info.goles += p->info.goles;
        enc = true;
    }
    return buscado;
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
