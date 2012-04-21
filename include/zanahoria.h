#ifndef __ZANAHORIA_H__
#define __ZANAHORIA_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <my_function.h>
#include <memoria.h>

#define ZANAHORIA 'z'
#define CONEJO '&'
#define CADAVER '#'
#define TRAMPOLIN '<'
#define CONEJO_TRAMPOLIN '?'
#define CELDA_VACIA '_'

#define MOV_TOP_N '8'
#define MOV_TOP_C 'u'
#define MOV_TOPLEFT_N '7'
#define MOV_TOPLEFT_C 'y'
#define MOV_LEFT_N '4'
#define MOV_LEFT_C 'h'
#define MOV_BOTTOMLEFT_N '1'
#define MOV_BOTTOMLEFT_C 'n'
#define MOV_BOTTOM_N '2'
#define MOV_BOTTOM_C 'm'
#define MOV_BOTTOMRIGHT_N '3'
#define MOV_BOTTOMRIGHT_C ','
#define MOV_RIGHT_N '6'
#define MOV_RIGHT_C 'k'
#define MOV_TOPRIGHT_N '9'
#define MOV_TOPRIGHT_C 'i'
#define MOV_CENTER_N '5'
#define MOV_CENTER_C 'j'

#define MOV_TRANSPORT_C 't'
#define ACTION_QUIT_C 'q'
#define ACTION_SAVE_C 's'

#define MOVE_TOP 8
#define MOVE_TOPLEFT 7
#define MOVE_LEFT 4
#define MOVE_BOTTOMLEFT 1
#define MOVE_BOTTOM 2
#define MOVE_BOTTOMRIGHT 3
#define MOVE_RIGHT 6
#define MOVE_TOPRIGHT 9
#define MOVE_CENTER 5

#define MOVE_TRANSPORT 10
#define ACTION_QUIT 11
#define ACTION_SAVE 12

#define PUNTAJE_MOV 5
#define PUNTAJE_CHOQUE 50
#define PUNTAJE_NIVEL 100

#define TASA_AUMENTO_CONEJOS 0.25

#define TASA_AUMENTO_CONEJOS 0.25
#define TASA_AUMENTO_TRAMPOLINES 0.2

#define NIVEL_TRAMPOLINES_START 2
#define TRAMPOLINES_INICIALES 2

#define FILE_PARTIDA "partida.dat"

void pedirConejosIniciales(int *f, int *c, int *ci);
void pedirDimensionTablero(int *c, int *f);

void tablero_ini(char **tablero, int f, int c);
void tablero_view(char **tablero, int f, int c);

void ubicarZanahoriaInicial(char **tablero, const int f, const int c);
void ubicarConejosIniciales(char **tablero, const int m, const int n, const int conejos);
void ubicarTrampolines(char **tablero, const int m, const int n, const int trampolines);


void posicionZanahoria(char **tablero, const int filas, const int columnas, int *coordZF, int *coordZC);
int pedirSiguienteMovimiento();
int ejecutarMovimientoZanahoria(const int mov, char **tablero, const int filas, const int columnas);
int ejecutarMovimientoConejos(char **tablero, char **tableroCopy, const int filas, const int columnas, int *conejosVivos, int *puntaje);
void ejecutarTeletransportacion(char **tablero, const int filas, const int columnas);

char **cargarPartida(char *ficheroName, int *filas, int *columnas, int *conejosIniciales, int *conejosVivos, int *nivel, int *puntaje);
int guardarPartida(char *ficheroName, char **tablero, const int filas, const int columnas, const int conejosIniciales, const int conejosVivos, const int nivel, const int puntaje);

#endif // __ZANAHORIA_H__
