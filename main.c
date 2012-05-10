/**
* @brief Juego de la Zanahoria
*
* @file main.c
* @author JesusGoku
* @date 22/04/2012
* @version 0.1
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <my_function.h>
#include <zanahoria.h>
#include <memoria.h>
#include <colores.h>
#include <printascii.h>
#include <lista.h>

#ifndef WINDOWS
#define IS_UNIX 1
#else
#define IS_UNIX 0
#endif // defined WINDOWS

int main(int argc, char **argv)
{
	int m = 0, n = 0; // m para filas, n para columnas
	char ** tablero; // Tablero de juego
	char ** tableroCopia; // Tablero de Copia
	char ** auxiliar; // Apuntador Auxiliar
	int i = 0, j = 0, k = 0; // Variables auxiliares
	int conejosIniciales = 0; // Se almacenaran los conejos ingresados por el usuario
	int puntaje = 0, nivel = 0, conejosVivos = 0; // Estado del juego
	int trampolines = 0; // Se llevara la cantidad de trampolines
	int coordZF = 0, coordZC = 0;
	int siguienteMovimiento = 0;
	Bool gameOver = False;
	Bool movValido = False;
	FILE *fp = NULL;
	Bool recuperarPartida = False;
	ItemRanking ranking[RANKING_NUM];
	ItemRanking paso;
	TipoNodoNombre *lista_partidas;
	int lista_partidas_num;
	char partida_ruta[50];
	char partida_nombre[NODO_NOMBRE_MAX_LENGTH + 1];

	// Inicializo la lista
	lista_partidas = lista_vacia();

	// Cargo el Ranking
	inicializarRanking(ranking, RANKING_NUM);
	cargarRanking(ranking, RANKING_NUM);

	// Doy la bienvenida
	clearScr();
	printZanahoria();
	pausa();
	clearScr();

	// Instrucciones del Juego
	if(!preguntayn("Conoces las reglas del juego?")){
		mostrarAyuda();
	}

	// Lista de Partidas
	lista_partidas = generar_lista_partidas();

	if(lista_partidas != NULL){
		clearScr();
		recuperarPartida = False;
		recuperarPartida = (Bool)preguntayn("Existen partidas guardadas, quieres cargar una?");

		if(recuperarPartida)
		{
			lista_partidas_num = longitud_lista(lista_partidas);
			clearScr();
			printf("Se encontraron %i partida(s):\n\n", lista_partidas_num);
			mostrar_lista(lista_partidas);
			do{
				i = 0;
				printf("\nSelecciona una partida: ");
				clearStdin();
				scanf("%i", &i);
				if(i < 1 || i > lista_partidas_num) printMsjError("Partida no valida!");
			}while(i < 1 || i > lista_partidas_num);
			sprintf(partida_ruta, "%s%s%i%s", FOLDER_PARTIDAS, FILE_PARTIDA_PREFIX, i - 1, FILE_PARTIDA_EXT);
			tablero = cargarPartida(partida_ruta, &m, &n, &conejosIniciales, &conejosVivos, &nivel, &puntaje);
			if(tablero == NULL){
				printMsjError("Error: No se logro conseguir memoria para el tablero!");
				return 1;
			}
		}
	}

	// // Verifico si existe una partida guardada
	// fp = fopen(FILE_PARTIDA, "r");

	// // Existe una partida guardada
	// if(fp != NULL){
		
	// 	// Cierro el fichero para poder abrirlo desde la funcion
	// 	fclose(fp);
	// 	fp = NULL;
		
	// 	clearScr();
	// 	recuperarPartida = False;
	// 	recuperarPartida = (Bool)preguntayn("Existe una partida guardada, desea cargarla?");

	// 	// Si la respuesta fue afirmativa recupero el estado del juego
	// 	if(recuperarPartida)
	// 		tablero = cargarPartida(FILE_PARTIDA, &m, &n, &conejosIniciales, &conejosVivos, &nivel, &puntaje);

	// }

	if(!recuperarPartida){

		// Preguntamos el tamano del tablero
		clearScr();
		pedirDimensionTablero(&m, &n);

		// Preguntamos los conejos iniciales
		clearScr();
		pedirConejosIniciales(&m, &n, &conejosIniciales);
		conejosVivos = conejosIniciales;
		
		// Reservo memoria para el tablero
		tablero = (char **)pedirMemoriaMatriz(m, n, 'c');
		if(tablero == NULL)
		{
			printMsjError("Error: No se logro conseguir memoria para el tablero!");
			return 1;
		}
		tablero_ini(tablero, m , n);

		// Ubico la zanahoria
		ubicarZanahoriaInicial(tablero, m, n);

		// Ubico los conejos iniciales
		ubicarConejosIniciales(tablero, m, n, conejosVivos);


	}

	// Reservo la memoria para una copia del tablero
	tableroCopia = (char **)pedirMemoriaMatriz(m, n, 'c');
	if(tableroCopia == NULL){
		printMsjError("Error: No se logro conseguir memoria para el tablero!");
		return 1;
	}
	// Doy valores iniciales al tablero
	tablero_ini(tableroCopia, m, n);

	// Comienza el Ciclo de Juego
	for(;;){
		clearScr();
		// Muestro el tablero
		tablero_pretty_view(tablero, m , n);
		// Muestro el estado del juego
		println("Conejos Vivos: %i - Nivel: %i - Puntaje: %i", conejosVivos, nivel + 1, puntaje);
		// Pido movimiento al usuario
		siguienteMovimiento = pedirSiguienteMovimiento();
		// Establesco el movimiento como no valido hasta que se demuestre lo contrario
		movValido = False;
		// Realizo el siguiente movimiento si es posible
		if(siguienteMovimiento >= 1 && siguienteMovimiento <= 9){
			// Verificamos si el movimiento ingresado se puede realizar
			// Si es asi movemos la zanahoria
			movValido = ejecutarMovimientoZanahoria(siguienteMovimiento, tablero, m, n, nivel) ? True : False;
			if(!movValido){
				printMsjErrorPausa("Movimiento no valido!");
			}else{
				gameOver = (ejecutarMovimientoConejos(tablero, tableroCopia, m, n, &conejosVivos, &puntaje) == 0) ? True : False;
			}
		}else if(siguienteMovimiento == MOVE_TRANSPORT){
			// Ejecutamos la teletransportacion y movemos a los conejos
			movValido = True;
			ejecutarTeletransportacion(tablero, m , n);
			gameOver = (ejecutarMovimientoConejos(tablero, tableroCopia, m, n, &conejosVivos, &puntaje) == 0) ? True : False;
		}else if(siguienteMovimiento == ACTION_SAVE){
			lista_partidas_num = longitud_lista(lista_partidas);
			clearScr();
			if(lista_partidas_num) printf("Puedes guardar unar partida nueva o sobreescribir una existente.\n\n");
			if(lista_partidas_num && preguntayn("Deseas sobreescribir una partida?")){
				clearScr();
				printf("Hay %i Partida(s) Disponibles:\n\n", lista_partidas_num);
				mostrar_lista(lista_partidas);
				do{
					i = 0;
					printf("\nIngresa el numero de la que deseas sobreescribir: ");
					clearStdin();
					scanf("%i", &i);
					if(i < 1 || i > lista_partidas_num) printMsjError("Partida no valida!");
				}while(i < 1 || i > lista_partidas_num);
				// Sobreescribir una partida
				sprintf(partida_ruta, "%s%s%i%s", FOLDER_PARTIDAS, FILE_PARTIDA_PREFIX, i - 1, FILE_PARTIDA_EXT);
				pedirCadena("\nBreve descripcion partida", partida_nombre, NODO_NOMBRE_MAX_LENGTH);
				if(guardarPartida(partida_ruta, tablero, m, n, partida_nombre, conejosIniciales, conejosVivos, nivel, puntaje)){
					modificar_valor_posicion(lista_partidas, i - 1, partida_nombre);
					printMsjOkPausa("Partida Guardada!");
				}
			}else{
				// Guardar Partida Nueva
				sprintf(partida_ruta, "%s%s%i%s", FOLDER_PARTIDAS, FILE_PARTIDA_PREFIX, lista_partidas_num, FILE_PARTIDA_EXT);
				clearScr();
				pedirCadena("Breve descripcion partida", partida_nombre, NODO_NOMBRE_MAX_LENGTH);
				if(guardarPartida(partida_ruta, tablero, m, n, partida_nombre, conejosIniciales, conejosVivos, nivel, puntaje)){
					lista_partidas = insertar_por_cola(lista_partidas, partida_nombre);
					printMsjOkPausa("Partida Guardada!");
				}
			}
			// // Verficamos si ya existe una partida guardada
			// fp = fopen(FILE_PARTIDA, "r");
			// if(fp != NULL){
			// 	fclose(fp);
			// 	fp = NULL;
			// 	// Preguntamos si desea sobreescribir la partida existe
			// 	if(preguntayn("Ya existe una partida guardada, desea sobreescribirla?")){
			// 		if(guardarPartida(FILE_PARTIDA, tablero, m, n, conejosIniciales, conejosVivos, nivel, puntaje))
			// 			printMsjOkPausa("Partida Guardada!");
			// 	}
			// }else{
			// 	if(guardarPartida(FILE_PARTIDA, tablero, m, n, conejosIniciales, conejosVivos, nivel, puntaje))
			// 		printMsjOkPausa("Partida Guardada!");
			// }
		}else if(siguienteMovimiento == ACTION_QUIT){
			clearScr();
			//println("Gracias por jugar!");
			printGraciasPorJugar();
			break;
		}

		if(movValido){
			puntaje += PUNTAJE_MOV;
			// Intercambio los tableros
			auxiliar = tablero;
			tablero = tableroCopia;
			tableroCopia = auxiliar;

			// Paso de Nivel
			if(conejosVivos == 0){
				// Inicializo el Tablero
				posicionZanahoria(tablero, m, n, &coordZF, &coordZC);
				tablero_ini(tablero, m , n);
				tablero[coordZF][coordZC] = ZANAHORIA;
				// Aumento el nivel en una unidad
				nivel++;
				// Aumento el puntaje
				puntaje += PUNTAJE_NIVEL;
				// Incremento los conejos
				conejosVivos = conejosIniciales + (redondeoEntero(conejosIniciales * TASA_AUMENTO_CONEJOS) * nivel);
				ubicarConejosIniciales(tablero, m , n, conejosVivos);
				// Ubico los Trampolines
				if(nivel >= NIVEL_TRAMPOLINES_START){
					trampolines = TRAMPOLINES_INICIALES + redondeoEntero(TASA_AUMENTO_TRAMPOLINES * (nivel - NIVEL_TRAMPOLINES_START));
					ubicarTrampolines(tablero, m, n, trampolines);
				}
			}
		}

		// Acciones en caso de Perder el Juego
		if(gameOver){
			clearScr();
			// tablero_view(tablero, m, n);
			printConejoGameOver();
			// Verificamos si puede entrar al ranking
			if(puntaje > ranking[0].puntaje){
				paso.puntaje = puntaje;
				pedirCadena("\nFelicidades has ingresado al ranking!!\n\nDate tu nombre", paso.nombre, MAX_SIZE_NAME);
				i = ingresarRanking(ranking, RANKING_NUM, &paso);
				clearScr();
				mostrarRankingDestacado(ranking, RANKING_NUM, i);
			}
			break;
		}
	} // for - ciclo de juego

	// Libero la memoria otorgada para el tablero
	liberarMemoriaMatriz((void **)tablero);
	liberarMemoriaMatriz((void **)tableroCopia);
	tablero = tableroCopia = NULL;

	// Guarda el Ranking en el disco
	guardarRanking(ranking, RANKING_NUM);

	return 0;
}
