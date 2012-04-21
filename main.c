#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <my_function.h>
#include <zanahoria.h>
#include <memoria.h>

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
	FILE * fp;
	Bool recuperarPartida;

	// Limpio la pantalla
	clearScr();
	// Doy la bienvenida
	println("Bienvenido al Juego de la Zanahoria");

	// Verifico si existe una partida guardada
	fp = fopen(FILE_PARTIDA, "r");

	// Existe una partida guardada
	if(fp != NULL){
		
		// Cierro el fichero para poder abrirlo desde la funcion
		fclose(fp);

		recuperarPartida = False;
		recuperarPartida = (Bool)preguntayn("Existe una partida guardada, desea cargarla? (y/n): ");

		// Si la respuesta fue afirmativa recupero el estado del juego
		if(recuperarPartida)
			tablero = cargarPartida(FILE_PARTIDA, &m, &n, &conejosIniciales, &conejosVivos, &nivel, &puntaje);

	}

	if(!recuperarPartida){

		// Preguntamos el tamano del tablero
		pedirDimensionTablero(&m, &n);

		// Preguntamos los conejos iniciales
		pedirConejosIniciales(&m, &n, &conejosIniciales);
		conejosVivos = conejosIniciales;
		
		// Reservo memoria para el tablero
		tablero = (char **)pedirMemoriaMatriz(m, n, 'c');
		tablero_ini(tablero, m , n);

		// Ubico la zanahoria
		ubicarZanahoriaInicial(tablero, m, n);

		// Ubico los conejos iniciales
		ubicarConejosIniciales(tablero, m, n, conejosVivos);


	}


	// Reservo la memoria para una copia del tablero
	tableroCopia = (char **)pedirMemoriaMatriz(m, n, 'c');
	// Doy valores iniciales al tablero
	tablero_ini(tableroCopia, m, n);

	// Comienza el Ciclo de Juego
	for(;;){
		clearScr();
		// Muestro el tablero
		tablero_view(tablero, m , n);
		// Muestro el estado del juego
		println("Conejos Vivos: %i - Nivel: %i - Puntaje: %i", conejosVivos, nivel, puntaje);
		// Pido movimiento al usuario
		siguienteMovimiento = pedirSiguienteMovimiento();
		// Establesco el movimiento como no valido hasta que se demuestre lo contrario
		movValido = False;
		// Realizo el siguiente movimiento si es posible
		if(siguienteMovimiento >= 1 && siguienteMovimiento <= 9){
			// Verificamos si el movimiento ingresado se puede realizar
			// Si es asi movemos la zanahoria
			movValido = ejecutarMovimientoZanahoria(siguienteMovimiento, tablero, m, n) ? True : False;
			if(!movValido){
				println("Movimiento no valido!...");
				clearStdin();
				getc(stdin);
			}else{
				gameOver = (ejecutarMovimientoConejos(tablero, tableroCopia, m, n, &conejosVivos, &puntaje) == 0) ? True : False;
			}
		}else if(siguienteMovimiento == MOVE_TRANSPORT){
			// Ejecutamos la teletransportacion y movemos a los conejos
			movValido = True;
			ejecutarTeletransportacion(tablero, m , n);
			gameOver = (ejecutarMovimientoConejos(tablero, tableroCopia, m, n, &conejosVivos, &puntaje) == 0) ? True : False;
		}else if(siguienteMovimiento == ACTION_SAVE){
			if(guardarPartida(FILE_PARTIDA, tablero, m, n, conejosIniciales, conejosVivos, nivel, puntaje))
				pausaMensaje("Partida Guardada!");
			// break;
		}else if(siguienteMovimiento == ACTION_QUIT){
			clearScr();
			println("Gracias por jugar!");
			break;
		}

		if(movValido){
			puntaje += PUNTAJE_MOV;
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
			println("GAME OVER!");
			break;
			// Pendiente: Podria preguntar si desea iniciar otra partida
		}
	} // for - ciclo de juego

	// Libero la memoria otorgada para el tablero
	liberarMemoriaMatriz((void **)tablero);
	liberarMemoriaMatriz((void **)tableroCopia);

	return 0;
}
