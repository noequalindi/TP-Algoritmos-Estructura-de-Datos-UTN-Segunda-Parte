
#ifndef structs_hpp
#define structs_hpp

struct RegistroDeGoles
{
	int id_gol;
	int codigo_equipo;
	long int fecha;
	char nombre_jugador[20];
	int id_partido;	
};
struct Equipo
{
	int codigo_equipo;
	RegistroDeGoles infoGol;
};

struct Partido
{
	int id_partido;
	Equipo equipos;
	Partido *sgtePartido;
};
struct InfoGoles
{
	char nombre_jugador[20];
	int id_gol;
	long int fecha;
	Partido *partidos;
};






struct nodoArbol{
		nodoArbol* izq;
		RegistroDeGoles info;
		nodoArbol* der;			
	};
	

struct Nodo{
RegistroDeGoles info;
 Nodo* sig;
};


struct GolesJugador {

	long int fecha;
	char nombre_jugador[20];
	int CantGoles;
	GolesJugador *sgte;
};

GolesJugador * MatrizResultados [32][7];




#endif /* structs_hpp */
