/** @brief Funciones Exclusivas para el juego.
*
* Esta liberia contiene aquellas funciones que son de uso poco generico y que fueron creadas para este juego
* y que dificilmente seran utilizadas en otra aplicacion diferente
*
* @file zanahoria.h
* @version 0.1
* @date 22/04/2012
* @author JesusGoku
* 
*/
#ifndef __ZANAHORIA_H__
#define __ZANAHORIA_H__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <my_function.h>
#include <memoria.h>
#include <colores.h>

// Constantes para describir los elementos de tablero
#define ZANAHORIA 'z'
#define CONEJO '&'
#define CADAVER '#'
#define TRAMPOLIN '<'
#define CONEJO_TRAMPOLIN '?'
#define CELDA_VACIA ' '
#define ZANAHORIA_MUERTA 'x'

// Constantes para describir los movimientos
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

// Constantes con el aumento de puntaje
#define PUNTAJE_MOV 5
#define PUNTAJE_CHOQUE 50
#define PUNTAJE_NIVEL 100

// Tasas de aumentos para las etaoas
#define TASA_AUMENTO_CONEJOS 0.25
#define TASA_AUMENTO_TRAMPOLINES 0.2

// Constantes para los tampolines
#define NIVEL_TRAMPOLINES_START 2
#define TRAMPOLINES_INICIALES 2

// Constantes para la partida
#define FILE_PARTIDA "partida.dat"

// Constantes para el Ranking
#define MAX_SIZE_NAME 50
#define RANKING_NUM 10
#define FILE_RANKING "ranking.dat"

/** @brief Estructura de Datos para los datos del Ranking
*/
typedef struct itemRanking {
	char nombre[MAX_SIZE_NAME + 1]; //<! 
	int puntaje;
} ItemRanking;

/** @brief Solicita la cantidad de conejos iniciales al usuario.
*
* Se deben enviar las dimensiones del tablero para calcular una numero max
* para la cantidad de conejos ingresadas por el usuario, cosa de que el juego tenga sentido.
* Se ha establecido arbitrariamente al 10% del tamaño total de casillas disponibles en el tablero
* esto pensando en que a medida de que avanze el juego la cantidad de conejos ira aumentando.
*
* Tambien se fija la cantidad minina de conejos en 2 ya que de lo contrario
* seria imposible que hibiera un choque entre ellos.
*
* @param f puntero a entero con el numero de filas del tablero de juego
* @param c puntero a entero con el numero de columnas del tablero de juego
* @param ci puntero a entero donde se almacenara el numero de conejos iniciales ingresado.
*
*/
void pedirConejosIniciales(int *f, int *c, int *ci);

/** @brief Solicita al usuario las dimensiones del tablero.
*
* Se ha establecido arbitrariamente que las dimensiones del tablero deben de ser impar
* con el objeto de que haya un solo centro en lugar de cuatro cuando las dimensiones del
* tablero es par.
*
* Tambien se ha establecido como tamaño minimo de tablero el numero 5 ya que es el minimo aceptable
* para que caiga la zanahoria en el centro y un 10% de conejos y se pueda desarrollar un juego.
*
* Como comentario adicional se establecen la cantidad de filas y columnas por separado, aun cuando
* para este juego la dimension del tablero es cuadrada, pero he decidido dejarla asi para que pueda ser modificado
* facilmente en caso de que se desee que no sea asi.
*
* @param f puntero a entero donde se almacenara el numero de filas
* @param c puntero a entero donde se almacenara el numero de columnas
*/
void pedirDimensionTablero(int *f, int *c);

/** @brief Inicializa el tablero al equivalente a CELDA_VACIA.
*
* llena todo las casillas del tablero con el caracter representado por la constante
* CELDA_VACIA
*
* @param tablero puntero a la matriz que representa al tablero
* @param f entero con la cantidad de filas del tablero
* @param c entero con la cantidad de columnas del tablero
*
*/
void tablero_ini(char **tablero, int f, int c);

/** @brief Muestra el tablero en pantalla.
*
* @param tablero puntero a la matriz que representa al tablero
* @param f entero con la cantidad de filas del tablero
* @param c entero con la cantidad de columnas del tablero
*
*/
void tablero_view(char **tablero, int f, int c);

/** @brief Muestra el tablero en pantalla de forma espectacular.
*
* Esta es una version mejorar la version anterior que muestra el tablero de una forma
* mas organizada a la vista al simular verdaderamente un tablero y sus casillas
* por donde se desplazan la zanahoria y los conejos que quieren devorarla.
* Tiene la desventaja de ocupar mas espacio para su representacion, lo que limita el
* tamano de los tableros posibles.
*
* @param tablero puntero a la matriz que representa al tablero
* @param filas entero con la cantidad de filas del tablero
* @param columnas entero con la cantidad de columnas del tablero
*
*/
void tablero_pretty_view(char **tablero, const int filas, const int columnas);

/** @brief Ubica a la zanahoria en el centro del escenario.
*
* @param tablero puntero a la matriz que representa al tablero
* @param f entero con la cantidad de filas del tablero
* @param c entero con la cantidad de columnas del tablero
*/
void ubicarZanahoriaInicial(char **tablero, const int f, const int c);

/** @brief Ubica una cierta cantidad de conejos aleatoriamente por el tablero.
*
*
* @param tablero puntero a la matriz que representa al tablero
* @param m entero con la cantidad de filas del tablero
* @param n entero con la cantidad de columnas del tablero
* @param conejos entero con la cantidad de conejos a ubicar aleatoriamente
*
*/
void ubicarConejosIniciales(char **tablero, const int m, const int n, const int conejos);

/** @brief Ubicar los tamprolines aleatoriamente por el tablero.
*
* @param tablero puntero a la matriz que representa al tablero
* @param m entero con la cantidad de filas del tablero
* @param n entero con la cantidad de columnas del tablero
* @param trampolines entero con la cantidad de tableros a ubicar aleatoriamente
*/
void ubicarTrampolines(char **tablero, const int m, const int n, const int trampolines);

/** @brief Devuelve las coordenas de la zanahoria en el tablero.
*
* @param tablero puntero a la matriz que representa al tablero
* @param filas entero con la cantidad de filas del tablero
* @param columnas entero con la cantidad de columnas del tablero
* @param coordZF puntero a entero donde se almacenara la coordena fila de la zanahoria
* @param coordZC puntero a entero donde se almacenara la coordena columna de la zanahoria
*/
void posicionZanahoria(char **tablero, const int filas, const int columnas, int *coordZF, int *coordZC);

/** @brief Pide el siguiemte movimiento a ejecutar al usuario.
*
* Se encarga de validar que al menos sea un comando de juego valido o lo vuelve a pedir
*
* @return devuelve un entero que representa el movimiento ingresado por el usuario
*/
int pedirSiguienteMovimiento();

/** @brief Ejecuta el movimiento de la zanahoria hasta mov.
*
* El movimiento se ejecuta siempre de que sea un movimiento valido
* es decir que no se salga del tablero o que no haya otro objeto
* en la casilla a la que se desea mover.
*
* Ademas se debe validar que para que el movimiento sea valido, no exista el riesgo
* de que en la casilla a donde se va a mover vaya a ser comido. Por eso se utilizan dos
* funciones auxiliares para verificar las dos vecindades de si hay algun potencial conejo
* que pueda hacer invalida la jugada. Por ese motivo se pasa el nivel que a primeras podria
* parecer inecesario pero a como los trampolines solo comienzan a aparecer desde el 2do
* nivel y estos son lo que permiten a los conejos saltar de a dos espacios, no tiene sentido
* gastar tiempo llamando a la funcion que se encarga de revisar la segunda vecindad si no
* hay riesgo aun.
*
* Para realizar el ahorro comentado en el parrafo anterior se aprovecha la evaluacion de
* expresiones logicas de C por cortocircuito evaluando si el nivel es menos que el nivel
* en que comienzan a aparecer los trampolines O verificar la vecindad, y ya que hasta que
* se alcanze el nivel la primera expresion siempre dara verdadero, se ya sabe que la expresion
* es verdadera y no ejecutara la funcion para revisar la vecindad. No asi cuando se alcanza el
* nivel para los trampolines donde la primera expresion dara falso y C se vera obligado a
* evaluar la seguna expresion, osea la funcion que verifica el segundo cuandrante para
* conocer el valor de verdad de la expresion, dependiendo ahora exclusivamente de ella el
* valor de la expresion.
*
* @param mov entero que representa al movimiento que solicito el usuario
* @param tablero puntero a la matriz que representa al tablero
* @param filas entero con la cantidad de filas del tablero
* @param columnas entero con la cantidad de columnas del tablero
* @param nivel entero con el nivel en el que se encuentra el juego
*
* @return Devuelve 0 si el movimiento no es valido, y 1 si lo es y la mueve hasta la posicion
*/
int ejecutarMovimientoZanahoria(const int mov, char **tablero, const int filas, const int columnas, const int nivel);

/** @brief Ejecuta el movimiento de todos los conejos persiguiendo al conejo
*
* @param tablero puntero a la matriz que representa al tablero
* @param tableroCopy puntero a la matriz que representa a una copia del tablero para poder realizar los movimientos
* @param filas entero con la cantidad de filas del tablero
* @param columnas entero con la cantidad de columnas del tablero
* @param conejosVivos puntero a entero donde se almacena la cantidad de conejos vivos que se disminuira en caso de colision de conejos
* @param puntaje puntero a entero donde se lleva el puntaje que ira aumentando en caso de colision de acuerdo a los establecido en la constante PUNTAJE_CHOQUE
*
* @return Devuelve 0 en caso de que un conejo haya caido sobre la zanahoria, en caso contrario retorna 1
*/
int ejecutarMovimientoConejos(char **tablero, char **tableroCopy, const int filas, const int columnas, int *conejosVivos, int *puntaje);
void ejecutarTeletransportacion(char **tablero, const int filas, const int columnas);
int verificarVecindadZanahoria(char **tablero, const int m, const int n, const int f, const int c, const int salto);
int verificarPrimeraVecindadZanahoria(char **tablero, const int m, const int n, const int f, const int c);
int verificarSegundaVecindadZanahoria(char **tablero, const int m, const int n, const int f, const int c);

char **cargarPartida(char *ficheroName, int *filas, int *columnas, int *conejosIniciales, int *conejosVivos, int *nivel, int *puntaje);
int guardarPartida(char *ficheroName, char **tablero, const int filas, const int columnas, const int conejosIniciales, const int conejosVivos, const int nivel, const int puntaje);

void mostrarRanking(ItemRanking *ranking, const int n);

/**
* @brief Muestra el ranking destacando una poscion
*
* @param ranking puntero a estructura que contiene el ranking
* @param n entero correspondiente al tamano del ranking
* @param pos entero con la posicion que se desea destacar
*
*/
void mostrarRankingDestacado(ItemRanking *ranking, const int n, const int pos);
int ingresarRanking(ItemRanking *ranking, const int n, ItemRanking *elemento);
int guardarRanking(ItemRanking *ranking, const int n);
int cargarRanking(ItemRanking *ranking, const int n);
void inicializarRanking(ItemRanking *ranking, const int n);

#endif // __ZANAHORIA_H__
