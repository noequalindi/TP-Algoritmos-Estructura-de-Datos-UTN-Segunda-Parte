
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

struct InfoGoles
{
	char nombre_jugador[20];
	int goles;
	long int fecha;
	InfoGoles *sgte;
};
struct Partido
{
	int id_partido;
	InfoGoles info;
	Partido *sgte;
};
struct Equipo
{
	int codigo_equipo;
	Partido info;
};







#endif /* structs_hpp */
