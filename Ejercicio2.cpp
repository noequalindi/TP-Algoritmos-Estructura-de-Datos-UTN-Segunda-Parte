#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "structs.hpp"

<<<<<<< HEAD

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


=======
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
            
            break;
        }
        ant = aux;
        aux = aux->sgte;
    }

    if (ant == NULL) {
        // es el primero
        p = nuevo;
    } else if (aux == NULL) {
        // llegué al último y no lo encontré
        ant->sgte = nuevo;
    } else {
        // lo encontré. Solo sumo goles
        aux->info.goles++;
        cout << "sumo goles a " << aux->info.jugador<<endl;;
        cout << "le quedan "<< aux->info.goles<<endl;
        
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
//void inicializarMatriz (GolesJugador *  MatrizResultados[][7]) {
//
//    for (int i=0;i<32;i++){
//        for(int j=0;j<7;j++){
//            MatrizResultados[i][j]=NULL;
//
//        }
//    }
//}
//
//void procesarRegistroDeGoles(FILE *fileRegistroDeGoles, GolesJugador *  MatrizResultados[][7])
//{
//    fileRegistroDeGoles = fopen ("RegistroGoles.dat","rb");
//    RegistroDeGoles regGol,GolAnterior;
//    int partido=0;
//    int equipo=0;
//
//    fread(&regGol,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
//    GolAnterior=regGol;
//
//    while(!feof(fileRegistroDeGoles)){
//
//        while (!feof(fileRegistroDeGoles)&& regGol.codigo_equipo==GolAnterior.codigo_equipo ){
//
//            
//                AgregarGolEnMatriz(MatrizResultados[regGol.codigo_equipo][partido], regGol);
//                fread(&regGol,sizeof(RegistroDeGoles),1,fileRegistroDeGoles);
//                GolAnterior=regGol;
//            }
//            partido++;
//        }
//    }
//    fclose(fileRegistroDeGoles);
//    return;
//}
//
//
//void AgregarGolEnMatriz(GolesJugador *partido, RegistroDeGoles regGol){
//
//GolesJugador* nuevo=new GolesJugador();
//
//if (partido==NULL) {
//    partido=nuevo;
//    strcpy(nuevo->nombre_jugador,regGol.nombre_jugador);
//    nuevo->fecha=regGol.fecha;
//    nuevo->CantGoles=1;
//    nuevo->sgte=NULL;
//    }
//else {
//    if(partido->nombre_jugador==regGol.nombre_jugador){
//        partido->CantGoles++;
//        delete nuevo;
//
//    }
//    else {
//        //buscar jugador ???
//
//    }
//
//
//    }
//
//}
>>>>>>> master


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
