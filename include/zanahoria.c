#ifndef __ZANAHORIA_C__
#define __ZANAHORIA_C__

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <my_function.h>
#include <memoria.h>
#include <colores.h>
#include <zanahoria.h>

/************************************
/* FUNCIONES DE PETICION AL USUARIO
/***********************************/

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
	println("Dimensiones Recomendadas:\n");
	println("\tVentana Estandar: 9x9 casilleros");
	println("\tPantala Completa (1280x800px): 23x23 casilleros\n");
	do{
		printf("Ingrese Dimension Tablero (Numero impar >= %i y <= %i): ", TABLERO_MIN_SIZE, TABLERO_MAX_SIZE);
		clearStdin();
		scanf("%i", f);
		if(*f < TABLERO_MIN_SIZE || *f > TABLERO_MAX_SIZE || *f % 2 == 0) println("Dimension no valida.");
	}while(*f < TABLERO_MIN_SIZE || *f > TABLERO_MAX_SIZE || *f % 2 == 0);
	*c = *f;
}

/***********************************
/* FUNCIONES DEL TABLERO
/**********************************/

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
			if(tablero[i][j] == ZANAHORIA) fijarColorTextoEstilo(COLOR_CYAN, ESTILO_PARPADEANTE);
			printf("%c ", tablero[i][j]);
			if(tablero[i][j] == ZANAHORIA) fijarColorNormal();
		}
		putchar('\n');
	}
}

void tablero_pretty_view(char **tablero, const int filas, const int columnas){
	int i = 0, j = 0, k = 0;
	// Imprimo la Primera linea
	putchar('+');
	for(k = 0; k < columnas; k++) printf(" - +");
	putchar('\n');
	
	for( i = 0; i < filas; i ++){
		// Imprimo el primer caracter de cada fila
		putchar('|');
		for( j = 0; j < columnas; j++){
			printf(" %c |", tablero[i][j]);
		}
		// Imprimo la linea divisoria a cada fila
		putchar('\n');
		putchar('+');
		for(k = 0; k < columnas; k++) printf(" - +");
		putchar('\n');

	}
}

/******************************
/* FUNCIONES DE INICIALIZACION
******************************/

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

void ubicarTrampolines(char **tablero, const int m, const int n, const int trampolines){
	int i = 0, j = 0, k = 0;
	srand(time(NULL));
	for(i = trampolines; i > 0;){
		j = rand() % m;
		k = rand() % n;
		if(tablero[j][k] == CELDA_VACIA){
			tablero[j][k] = TRAMPOLIN;
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

/********************************************
/* FUNCIONES PARA EJECUTAR MOVIMIENTOS
/*******************************************/

int ejecutarMovimientoZanahoria(const int mov, char **tablero, const int filas, const int columnas, const int nivel){
	int coordMoveF, coordMoveC;
	int coordZF, coordZC;
	int y = 0, x = 0;
	int i = 0, j = 0;
	// Determinamos la magnitud del movimiento segun la direccion ingresada
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
		case MOVE_CENTER:
			// No hay movimiento que hacer y retornomar movimiento correcto
			//return 1;
			y = 0;
			x = 0;
		default:
			y = 0;
			x = 0;
	}
	// Buscamos la zanahoria y revisamos si se pude mover
	posicionZanahoria(tablero, filas, columnas, &coordZF, &coordZC);
	// Valido que sea un mov. en el tablero y que la celda este vacia
	coordMoveF = coordZF + y;
	coordMoveC = coordZC + x;
	if( (coordMoveF) < filas && (coordMoveF) >= 0 && (coordMoveC) < columnas && (coordMoveC) >= 0 && ( tablero[coordMoveF][coordMoveC] == CELDA_VACIA || tablero[coordMoveF][coordMoveC] == ZANAHORIA ) && verificarPrimeraVecindadZanahoria(tablero, filas, columnas, coordMoveF, coordMoveC) && ( nivel < NIVEL_TRAMPOLINES_START || verificarSegundaVecindadZanahoria(tablero, filas, columnas, coordMoveF, coordMoveC) ) ){
		if(coordMoveF != coordZF || coordMoveC != coordZC){
			tablero[coordMoveF][coordMoveC] = ZANAHORIA;
			tablero[coordZF][coordZC] = CELDA_VACIA;
		}
	}else return 0;
	return 1;
}

int ejecutarMovimientoConejos(char **tablero, char **tableroCopia, const int filas, const int columnas, int *conejosVivos, int *puntaje){
	int i, j;
	int coordZC, coordZF;
	int coordMoveF, coordMoveC;
	int movSize;
	int zanahoriaViva = 1;
	// Borramos el tablero copia
	tablero_ini(tableroCopia, filas, columnas);
	// Transladamos desde el tablero al tablero copia
	// La zanahoria, los cadaveres y trampolines
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			if(tablero[i][j] == ZANAHORIA || tablero[i][j] == CADAVER || tablero[i][j] == TRAMPOLIN || tablero[i][j] == CONEJO_TRAMPOLIN){
				// Si es que es un conejo sobre un trampolin lo copio solo como trampolin, ya que el conejo se movera
				tableroCopia[i][j] = (tablero[i][j] == CONEJO_TRAMPOLIN) ? TRAMPOLIN : tablero[i][j];
				// Guardamos la posicion de la zanahoria
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
			if(tablero[i][j] == CONEJO || tablero[i][j] == CONEJO_TRAMPOLIN){
				// Fijamos la magnitud del movimiento
				movSize = tablero[i][j] == CONEJO ? 1 : 2;
				// Establecemos la posicion a la que lo moveremos
				if(coordZF > i) coordMoveF = ((i + movSize) > coordZF) ? (i + 1) : (i + movSize);
				else if(coordZF < i) coordMoveF = ((i - movSize) < coordZF) ? (i - 1) : (i - movSize);
				else coordMoveF = i;

				if(coordZC > j) coordMoveC = ((j + movSize) > coordZC) ? (j + 1) : (j + movSize);
				else if(coordZC < j) coordMoveC = ((j - movSize) < coordZC) ? (j - 1) : (j - movSize);
				else coordMoveC = j;

				// Verificamos el contenido del destino
				switch(tableroCopia[coordMoveF][coordMoveC]){
					case CELDA_VACIA:
						tableroCopia[coordMoveF][coordMoveC] = CONEJO;
						break;
					case CONEJO:
					case CONEJO_TRAMPOLIN:
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
					case ZANAHORIA_MUERTA:
						tableroCopia[coordMoveF][coordMoveC] = ZANAHORIA_MUERTA;
						zanahoriaViva = 0;
						break;
					case TRAMPOLIN:
						tableroCopia[coordMoveF][coordMoveC] = CONEJO_TRAMPOLIN;
						break;
				}
			}
		}
	}
	return zanahoriaViva;
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

int verificarVecindadZanahoria(char **tablero, const int m, const int n, const int f, const int c, const int salto){
	int i = 0;
	int j = f - salto; // Representa a las filas
	int k = c; // Representa a las columnas
	char celda = (salto == 1) ? CONEJO : CONEJO_TRAMPOLIN;
	for( i = 1; i <= 8; i++){
		if(j >= 0 && j < m && k >= 0 && k < n) // Verifico si es una coordenada valida
			if(tablero[j][k] == celda) // Verifico si hay un conejo o un conejo en trampolin
				return 0;
		if( i >= 0 && i < 2 ) k += salto;
		if( i >= 2 && i < 4 ) j += salto;
		if( i >= 4 && i < 6 ) k -= salto;
		if( i >= 6 && i < 8 ) j -= salto;
	}
	return 1;
}

int verificarPrimeraVecindadZanahoria(char **tablero, const int m, const int n, const int f, const int c){
	int i = 0;
	int j = f - 1; // Representa a las filas, me ubico una fila mas arriba para comenzar
	int k = c; // Representa a las columnas, y me quedo en la misma columna
	int saltos = 8;
	int quiebre[4];
	for(i = 0; i < 4; i++) quiebre[i] = (int)(saltos * (i + 1) / 4);

	for( i = 1; i <= 8; i++){
		if(j >= 0 && j < m && k >= 0 && k < n) // Verifico si es una coordenada valida
			if(tablero[j][k] == CONEJO || tablero[j][k] == CONEJO_TRAMPOLIN) // Verifico si hay un conejo o un conejo en trampolin
				return 0;
		if( i >= 0 && i < quiebre[0] ) k += 1;
		if( i >= quiebre[0] && i < quiebre[1] ) j += 1;
		if( i >= quiebre[1] && i < quiebre[2] ) k -= 1;
		if( i >= quiebre[2] && i < quiebre[3] ) j -= 1;
	}
	return 1;
}

int verificarSegundaVecindadZanahoria(char **tablero, const int m, const int n, const int f, const int c){
	int i = 0;
	int j = f - 2; // Representa a las filas, Me ubico en 2 filas mas arriba para comenzar
	int k = c - 1; // Representa a las columnas, Me ubico una columna mas a la izquierda para comenzar
	int saltos = 16;
	int quiebre[4];
	for(i = 0; i < 4; i++) quiebre[i] = (int)(saltos * (i + 1) / 4);
		
	for( i = 1; i <= 8; i++){
		if(j >= 0 && j < m && k >= 0 && k < n) // Verifico si es una coordenada valida
			if(tablero[j][k] == CONEJO_TRAMPOLIN) // Verifico si hay un conejo o un conejo en trampolin
				return 0;
		if( i >= 0 && i < quiebre[0] ) k += 1;
		if( i >= quiebre[0] && i < quiebre[1] ) j += 1;
		if( i >= quiebre[1] && i < quiebre[2] ) k -= 1;
		if( i >= quiebre[2] && i < quiebre[3] ) j -= 1;
	}
	return 1;
}

/************************************
/* FUNCIONES SALVAR Y CARGAR PARTIDA
/***********************************/

char **cargarPartida(char *ficheroName, int *filas, int *columnas, int *conejosIniciales, int *conejosVivos, int *nivel, int *puntaje){
	FILE *fp;
	char **tablero;
	int i,j;
	fp = fopen(ficheroName, "r");
	if(fp == NULL) return NULL;
	fscanf(fp, "%i\n", conejosIniciales);
	fscanf(fp, "%i\n", conejosVivos);
	fscanf(fp, "%i\n", nivel);
	fscanf(fp, "%i\n", puntaje);
	fscanf(fp, "%i\n", filas);
	fscanf(fp, "%i\n", columnas);
	tablero = (char **)pedirMemoriaMatriz(*filas, *columnas, 'c');
	for(i = 0; i < *filas; i++){
		for(j = 0; j < (*columnas) - 1; j++){
			fscanf(fp, "%c", &tablero[i][j]);
			tablero[i][j] = tablero[i][j] == '_' ? CELDA_VACIA : tablero[i][j];
		}
		fscanf(fp, "%c\n", &tablero[i][j]);
		tablero[i][j] = tablero[i][j] == '_' ? CELDA_VACIA : tablero[i][j];
	}
	fclose(fp);
	return tablero;
}

int guardarPartida(char *ficheroName, char **tablero, const int filas, const int columnas, const int conejosIniciales, const int conejosVivos, const int nivel, const int puntaje){
	FILE *fp;
	int i,j;
	char guardar;
	fp = fopen(ficheroName, "w");
	if(fp == NULL) return 0;
	fprintf(fp, "%i\n", conejosIniciales);
	fprintf(fp, "%i\n", conejosVivos);
	fprintf(fp, "%i\n", nivel);
	fprintf(fp, "%i\n", puntaje);
	fprintf(fp, "%i\n", filas);
	fprintf(fp, "%i\n", columnas);
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			guardar = tablero[i][j] == CELDA_VACIA ? '_' : tablero[i][j];
			fprintf(fp ,"%c", guardar);
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
	return 1;
}

/*****************************************
/* FUNCIONES PARA ADMINISTRAR EL RANKING
/****************************************/

void mostrarRanking(ItemRanking *ranking, const int n){
	int i;
	// El Titulo
	printLuminoso("RANKING");
	printf("\n");
	// El Ranking
	for(i = n - 1; i >= 0; i--){
		if(i % 2) fijarColorTexto(COLOR_CYAN);
		else fijarColorTexto(COLOR_VERDE);
		printf("%2i) Puntaje: %5i * Por: %s\n", n - i, ranking[i].puntaje, ranking[i].nombre);
	}
	fijarColorNormal();
}

void mostrarRankingDestacado(ItemRanking *ranking, const int n, const int pos){
	int i, j;
	// El Titulo
	printLuminoso("RANKING");
	printf("\n");

	// Muestro el encabezado de las columnas
	fijarColorTexto(COLOR_PURPURA);
	for( j = 0; j < 40; j++) putchar('-');
	printf("\n|%4s |%20s |%9s |\n", "Pos.", "Nombre", "Puntaje");
	for( j = 0; j < 40; j++) putchar('-');
	putchar('\n');
	fijarColorNormal();

	// Imprimo el ranking
	for(i = n - 1; i >= 0; i--){
		if(i == (n - pos)) fijarColorTextoEstilo(COLOR_MARRON, ESTILO_INVERSO);
		printf("|%4i |%20s |%9i |\n", n - i, ranking[i].nombre, ranking[i].puntaje);
		fijarColorNormal();
	}
	for( j = 0; j < 40; j++) putchar('-');
	putchar('\n');
}

int ingresarRanking(ItemRanking *ranking, const int n, ItemRanking *elemento){
	int i;
	if(elemento->puntaje > ranking[0].puntaje){

		for(i = 0; i < n; i++){
			if(elemento->puntaje > ranking[i].puntaje){
				if( (i + 1) < n){
					ranking[i].puntaje = ranking[i + 1].puntaje;
					strcpy(ranking[i].nombre, ranking[i + 1].nombre);
				}else{
					ranking[i].puntaje = elemento->puntaje;
					strcpy(ranking[i].nombre, elemento->nombre);
				}
			}else{
				if(i - 1 >= 0){
					ranking[i - 1].puntaje = elemento->puntaje;
					strcpy(ranking[i - 1].nombre, elemento->nombre);
				}else{
					ranking[i].puntaje = elemento->puntaje;
					strcpy(ranking[i].nombre, elemento->nombre);
				}
				break;
			}
		}

	}else return 0; // No ingresa al Ranking
	// Retorno la posicion en el Ranking
	return n - i + 1;
}

int guardarRanking(ItemRanking *ranking, const int n){
	FILE *fp;
	fp = fopen(FILE_RANKING, "wb");
	if(fp == NULL) return 0;
	fwrite(ranking, sizeof(ItemRanking) * n, 1, fp);
	fclose(fp);
	return 1;
}

int cargarRanking(ItemRanking *ranking, const int n){
	FILE *fp;
	fp = fopen(FILE_RANKING, "rb");
	if(fp == NULL) return 0;
	fread(ranking, sizeof(ItemRanking) * n, 1, fp);
	fclose(fp);
	return 1;
}

void inicializarRanking(ItemRanking *ranking, const int n){
	int i;
	for(i = 0; i < n; i++){
		ranking[i].puntaje = 0;
		strcpy(ranking[i].nombre, "---");
	}
}

#endif // __ZANAHORIA_C__
