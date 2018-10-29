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
struct nodoArbolEquipo
{
	nodoArbolEquipo* izq;
    Info infoGoles; 
    nodoArbolEquipo* der;
};
#endif /* structs_hpp */
