#pragma once

#ifndef structs_hpp
#define structs_hpp

struct RegistroDeGoles {
    int id_gol;
    int codigo_equipo;
    long fecha;
    char nombre_jugador[20];
    int id_partido;
};

struct nodoArbol {
    nodoArbol* izq;
    RegistroDeGoles info;
    nodoArbol* der;
};

struct Info {
    char jugador[20];
    long fecha;
    int goles;
};

struct GolesJugador {
    Info info;
    GolesJugador *sgte;
};

struct Equipo {
    int codigo_equipo;
    RegistroDeGoles infoGol;
};

struct Partido {
    int id_partido;
    Equipo equipos;
    Partido* sgtePartido;
};

struct InfoGoles {
    char nombre_jugador[20];
    int id_gol;
    long int fecha;
    Partido *partidos;
};

struct Nodo {
    RegistroDeGoles info;
    Nodo* sgte;
};


struct arbolPaisesGoles {
	char nombre_pais [12];
	int cantGoles;
};
struct nodoArbolEquipos
{
<<<<<<< HEAD
	nodoArbolEquipos* izq;
	arbolPaisesGoles info;
    nodoArbolEquipos* der;
=======
	nodoArbolEquipo* izq;
    Info infoGoles; 
    nodoArbolEquipo* der;
>>>>>>> 65c042ac90202fd3f5ba760c911190c1472d1c01
};

#endif /* structs_hpp */
