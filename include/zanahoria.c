#ifndef __ZANAHORIA_C__
#define __ZANAHORIA_C__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <my_function.h>

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
#define PUNTAJE_ETAPA 100

void pedirConejosIniciales(int *f, int *c, int *ci){
	int max = (int)floor( (*c) * (*f) * 0.1 );
	do{
		printf("Conejos Iniciales (>= 2 y <= %i): ", max);
		clearStdin();
		scanf("%i", ci);
		if(*ci < 2 || *ci > max) println("Cantindad no valida.");
	}while(*ci < 2 || *ci > max);
}

void pedirDimensionTablero(int *f, int *c){
	do{
		printf("Dimensiones Tablero (Numero impar >= 5 y <= 255): ");
		clearStdin();
		scanf("%i", f);
		if(*f < 5 || *f > 255 || *f % 2 == 0) println("Dimension no valida.");
	}while(*f < 5 || *f > 255 || *f % 2 == 0);
	*c = *f;
}

void tablero_ini(char **tablero, int f, int c){
	int i = 0, j = 0;
	for(i = 0; i < f; i++)
		for(j = 0; j < c; j++)
			tablero[i][j] = CELDA_VACIA;
}

void tablero_view(char **tablero, int f, int c){
	int i = 0, j = 0;
	for(i = 0; i < f; i++){
		for(j = 0; j < c; j++){
			printf("%c ", tablero[i][j]);
		}
		putchar('\n');
	}
}

void ubicarZanahoriaInicial(char **tablero, const int f, const int c){
	int coordZF = (int)floor(f / 2.0);
	int coordZC = (int)floor(c / 2.0);
	tablero[coordZF][coordZC] = ZANAHORIA;
}

void ubicarConejosIniciales(char **tablero, const int m, const int n, const int conejos){
	int i = 0, j = 0, k = 0;
	srand(time(NULL));
	for(i = conejos; i > 0;){
		j = rand() % m;
		k = rand() % n;
		if(tablero[j][k] == CELDA_VACIA){
			tablero[j][k] = CONEJO;
			i--;
		}
	}
}

void posicionZanahoria(char **tablero, const int filas, const int columnas, int *coordZF, int *coordZC){
	int i, j;
	int located = 0;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			if(tablero[i][j] == ZANAHORIA){
				*coordZF = i;
				*coordZC = j;
				located = 1;
				break;
			}
		}
		if(located) break;
	}
}

int pedirSiguienteMovimiento(){
	int mov = 0;
	char movIn = 0;
	do{
		printf("Ingresa tu siguiente movimiento: ");
		clearStdin();
		scanf("%c", &movIn);
		movIn = tolower(movIn);
		switch(movIn){
			case MOV_TOP_N:
			case MOV_TOP_C:
				mov = MOVE_TOP;
				break;
			case MOV_TOPRIGHT_N:
			case MOV_TOPRIGHT_C:
				mov = MOVE_TOPRIGHT;
				break;
			case MOV_RIGHT_N:
			case MOV_RIGHT_C:
				mov = MOVE_RIGHT;
				break;
			case MOV_BOTTOMRIGHT_N:
			case MOV_BOTTOMRIGHT_C:
				mov = MOVE_BOTTOMRIGHT;
				break;
			case MOV_BOTTOM_N:
			case MOV_BOTTOM_C:
				mov = MOVE_BOTTOM;
				break;
			case MOV_BOTTOMLEFT_N:
			case MOV_BOTTOMLEFT_C:
				mov = MOVE_BOTTOMLEFT;
				break;
			case MOV_LEFT_N:
			case MOV_LEFT_C:
				mov = MOVE_LEFT;
				break;
			case MOV_TOPLEFT_N:
			case MOV_TOPLEFT_C:
				mov = MOVE_TOPLEFT;
				break;
			case MOV_CENTER_N:
			case MOV_CENTER_C:
				mov = MOVE_CENTER;
				break;
			case MOV_TRANSPORT_C:
				mov = MOVE_TRANSPORT;
				break;
			case ACTION_QUIT_C:
				mov = ACTION_QUIT;
				break;
			case ACTION_SAVE_C:
				mov = ACTION_SAVE;
				break;
			default:
				mov = 0;
		}
		if(mov == 0) println("Movimiento no valido");
	}while(mov == 0);
	return mov;
}

int ejecutarMovimientoZanahoria(const int mov, char **tablero, const int filas, const int columnas){
	int coordMoveF, coordMoveC;
	int coordZF, coordZC;
	int y = 0, x = 0;
	int i = 0, j = 0;
	// Determinamos la magnitud del movimiento
	switch(mov){
		case MOVE_TOP:
			y = -1;
			break;
		case MOVE_TOPRIGHT:
			y = -1;
			x = 1;
			break;
		case MOVE_RIGHT:
			x = 1;
			break;
		case MOVE_BOTTOMRIGHT:
			y = 1;
			x = 1;
		case MOVE_BOTTOM:
			y = 1;
			break;
		case MOVE_BOTTOMLEFT:
			y = 1;
			x = -1;
			break;
		case MOVE_LEFT:
			x = -1;
			break;
		case MOVE_TOPLEFT:
			y = -1;
			x = -1;
			break;
		default:
			y = 0;
			x = 0;
	}
	// Buscamos la zanahoria y revisamos si se pude mover
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			if(tablero[i][j] == ZANAHORIA){
				coordZF = i;
				coordZC = j;
				break;
			}
		}
	}
	// Valido que sea un mov. en el tablero y que la celda este vacia
	coordMoveF = coordZF + y;
	coordMoveC = coordZC + x;
	if( (coordMoveF) < filas && (coordMoveF) >= 0 && (coordMoveC) < columnas && (coordMoveC) >= 0 && tablero[coordMoveF][coordMoveC] == CELDA_VACIA){
		tablero[coordMoveF][coordMoveC] = ZANAHORIA;
		tablero[coordZF][coordZC] = CELDA_VACIA;
	}else return 0;
	return 1;
}

int ejecutarMovimientoConejos(char **tablero, char **tableroCopia, const int filas, const int columnas, int *conejosVivos, int *puntaje){
	int i, j;
	int coordZC, coordZF;
	int coordMoveF, coordMoveC;
	// Borramos el tablero copia
	tablero_ini(tableroCopia, filas, columnas);
	// Transladamos desde el tablero al tablero copia
	// La zanahoria, los cadaveres y trampolines
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			if(tablero[i][j] == ZANAHORIA || tablero[i][j] == CADAVER || tablero[i][j] == TRAMPOLIN){
				tableroCopia[i][j] = tablero[i][j];
				// Guardamos la nueva posicion de la zanahoria
				if(tablero[i][j] == ZANAHORIA){
					coordZF = i;
					coordZC = j;
				}
			}
		}
	}
	// Ahora comenzamos a mover los conejos acercandose a la zanahoria
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			if(tablero[i][j] == CONEJO){
				// Establecemos la posicion a la que lo moveremos
				if(coordZF > i) coordMoveF = i + 1;
				else if(coordZF < i) coordMoveF = i - 1;
				else coordMoveF = i;

				if(coordZC > j) coordMoveC = j + 1;
				else if(coordZC < j) coordMoveC = j - 1;
				else coordMoveC = j;

				// Verificamos el contenido del destino
				switch(tableroCopia[coordMoveF][coordMoveC]){
					case CELDA_VACIA:
						tableroCopia[coordMoveF][coordMoveC] = CONEJO;
						break;
					case CONEJO:
						tableroCopia[coordMoveF][coordMoveC] = CADAVER;
						(*puntaje) += PUNTAJE_CHOQUE * 2;
						(*conejosVivos) -= 2;
						break;
					case CADAVER:
						tableroCopia[coordMoveF][coordMoveC] = CADAVER;
						(*puntaje) += PUNTAJE_CHOQUE;
						(*conejosVivos) -= 1;
						break;
					case ZANAHORIA:
						tableroCopia[coordMoveF][coordMoveC] = 'X';
						return 0;
						break;
					case TRAMPOLIN:
						tableroCopia[coordMoveF][coordMoveC] = CONEJO_TRAMPOLIN;
						break;
				}
			}
		}
	}
	return 1;
}

void ejecutarTeletransportacion(char **tablero, const int filas, const int columnas){
	int y = 0, x = 0;
	int coordZF, coordZC;
	int done = 0;
	// Determinamos las cordenadas actuales de la Zanahoria
	posicionZanahoria(tablero, filas, columnas, &coordZF, &coordZC);
	// Inicializamos la semilla para generar los valores aleatorios
	srand(time(NULL));
	// Buscamos una posicion donde teletransportarla
	while(1){
		y = rand() % filas;
		x = rand() % columnas;
		if(tablero[y][x] == CELDA_VACIA){
			tablero[y][x] = ZANAHORIA;
			done = 1;
			break;
		}
	}
	if(done) tablero[coordZF][coordZC] = CELDA_VACIA;
}

#endif // __ZANAHORIA_C__