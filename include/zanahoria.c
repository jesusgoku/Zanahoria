#ifndef __ZANAHORIA_C__
#define __ZANAHORIA_C__

#include <colores.h>
#include <ctype.h>
#include <lista.h>
#include <math.h>
#include <memoria.h>
#include <my_function.h>
#include <printascii.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <zanahoria.h>

/*************************************
 * FUNCIONES DE PETICION AL USUARIO
 ************************************/

void pedirConejosIniciales(int *f, int *c, int *ci) {
    int max = (int)floor((*c) * (*f) * CONEJOS_INICIALES_MAX_TASA);
    println("Cantidad de Conejos Iniciales:\n");
    println("\t- Deben ser minimo 2 conejos, para que puedan chocar",
            CONEJOS_INICIALES_MIN);
    println("\t- Deben ser maximo un %.0f%% de las casillas disponibles",
            CONEJOS_INICIALES_MAX_TASA * 100);
    println("\tpara que la zanahoria se pueda mover en el escenario.");
    do {
        printf("\nConejos Iniciales (%i <= Conejos <= %i): ",
               CONEJOS_INICIALES_MIN, max);
        clearStdin();
        scanf("%i", ci);
        if (*ci < CONEJOS_INICIALES_MIN || *ci > max)
            printMsjError("Cantindad no valida.");
    } while (*ci < CONEJOS_INICIALES_MIN || *ci > max);
}

void pedirDimensionTablero(int *f, int *c) {
    println("Reglas Dimension Tablero:");
    println("\t- Debe ser un numero impar (Para que haya un solo centro).");
    println("\t- Debe ser mayor que %i (para que se pueda realizar el juego).",
            TABLERO_MIN_SIZE);
    println("\t- Debe ser menor de %i (para que quepa en la pantalla).",
            TABLERO_MAX_SIZE);
    println("\nDimensiones Recomendadas:\n");
    println("\t1) 9x9   casilleros - Consola Estandar (80x25)");
    println("\t2) 23x23 casilleros - Consola Pantalla Completa (1280x800px)");
    println("\t3) Dimension Personalizada.");
    do {
        printf("\nIngrese una opcion: ");
        clearStdin();
        scanf("%i", f);
        if (*f < 1 || *f > 3) printMsjError("Opcion no valida.");
    } while (*f < 1 || *f > 3);
    if (*f == 3) {
        do {
            printf(
                "\nIngrese Dimension Tablero (Numero impar, %i <= Dimension <= "
                "%i): ",
                TABLERO_MIN_SIZE, TABLERO_MAX_SIZE);
            clearStdin();
            scanf("%i", f);
            if (*f < TABLERO_MIN_SIZE || *f > TABLERO_MAX_SIZE || *f % 2 == 0)
                printMsjError("Dimension no valida.");
        } while (*f < TABLERO_MIN_SIZE || *f > TABLERO_MAX_SIZE || *f % 2 == 0);
    } else
        *f = (*f == 1) ? 9 : 23;
    *c = *f;
}

/***********************************
 * FUNCIONES DEL TABLERO
 **********************************/

void tablero_ini(char **tablero, int f, int c) {
    int i = 0, j = 0;
    for (i = 0; i < f; i++)
        for (j = 0; j < c; j++) tablero[i][j] = CELDA_VACIA;
}

void tablero_view(char **tablero, int f, int c) {
    int i = 0, j = 0;
    for (i = 0; i < f; i++) {
        for (j = 0; j < c; j++) {
            if (tablero[i][j] == ZANAHORIA)
                fijarColorTextoEstilo(COLOR_CYAN, ESTILO_PARPADEANTE);
            printf("%c ", tablero[i][j]);
            if (tablero[i][j] == ZANAHORIA) fijarColorNormal();
        }
        putchar('\n');
    }
}

void tablero_pretty_view(char **tablero, const int filas, const int columnas) {
    int i = 0, j = 0, k = 0;
    // Imprimo la Primera linea
    putchar('+');
    for (k = 0; k < columnas; k++) printf(" - +");
    putchar('\n');

    for (i = 0; i < filas; i++) {
        // Imprimo el primer caracter de cada fila
        putchar('|');
        for (j = 0; j < columnas; j++) {
            switch (tablero[i][j]) {
                case ZANAHORIA:
                    fijarColorTexto(COLOR_ROJO);
                    break;
                case CONEJO:
                    fijarColorTexto(COLOR_MARRON);
                    break;
                case CONEJO_TRAMPOLIN:
                    fijarColorTexto(COLOR_VERDE);
                    break;
                case TRAMPOLIN:
                    fijarColorTexto(COLOR_AZUL);
                    break;
                case CADAVER:
                    fijarColorTexto(COLOR_PURPURA);
                    break;
                case ZANAHORIA_MUERTA:
                    fijarColorTexto(COLOR_PURPURA);
                    break;
            }
            printf(" %c ", tablero[i][j]);
            fijarColorNormal();
            printf("|");
        }
        // Imprimo la linea divisoria a cada fila
        putchar('\n');
        putchar('+');
        for (k = 0; k < columnas; k++) printf(" - +");
        putchar('\n');
    }
}

/******************************
 * FUNCIONES DE INICIALIZACION
 ******************************/

void ubicarZanahoriaInicial(char **tablero, const int f, const int c) {
    int coordZF = (int)floor(f / 2.0);
    int coordZC = (int)floor(c / 2.0);
    tablero[coordZF][coordZC] = ZANAHORIA;
}

void ubicarConejosIniciales(char **tablero, const int m, const int n,
                            const int conejos) {
    int i = 0, j = 0, k = 0;
    srand(time(NULL));
    for (i = conejos; i > 0;) {
        j = rand() % m;
        k = rand() % n;
        if (tablero[j][k] == CELDA_VACIA) {
            tablero[j][k] = CONEJO;
            i--;
        }
    }
}

void ubicarTrampolines(char **tablero, const int m, const int n,
                       const int trampolines) {
    int i = 0, j = 0, k = 0;
    srand(time(NULL));
    for (i = trampolines; i > 0;) {
        j = rand() % m;
        k = rand() % n;
        if (tablero[j][k] == CELDA_VACIA) {
            tablero[j][k] = TRAMPOLIN;
            i--;
        }
    }
}

void posicionZanahoria(char **tablero, const int filas, const int columnas,
                       int *coordZF, int *coordZC) {
    int i, j;
    int located = 0;
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (tablero[i][j] == ZANAHORIA) {
                *coordZF = i;
                *coordZC = j;
                located = 1;
                break;
            }
        }
        if (located) break;
    }
}

int pedirSiguienteMovimiento() {
    int mov = 0;
    char movIn = 0;
    do {
        printf("Ingresa tu siguiente movimiento: ");
        clearStdin();
        movIn = 0;
        movIn = getc(stdin);
        movIn = tolower(movIn);
        switch (movIn) {
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
        if (mov == 0) println("Movimiento no valido");
    } while (mov == 0);
    return mov;
}

/********************************************
 * FUNCIONES PARA EJECUTAR MOVIMIENTOS
 *******************************************/

int ejecutarMovimientoZanahoria(const int mov, char **tablero, const int filas,
                                const int columnas, const int nivel) {
    int coordMoveF, coordMoveC;
    int coordZF, coordZC;
    int y = 0, x = 0;
    int i = 0, j = 0;
    // Determinamos la magnitud del movimiento segun la direccion ingresada
    switch (mov) {
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
            // return 1;
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
    if ((coordMoveF) < filas && (coordMoveF) >= 0 && (coordMoveC) < columnas &&
        (coordMoveC) >= 0 &&
        (tablero[coordMoveF][coordMoveC] == CELDA_VACIA ||
         tablero[coordMoveF][coordMoveC] == ZANAHORIA) &&
        verificarPrimeraVecindadZanahoria(tablero, filas, columnas, coordMoveF,
                                          coordMoveC) &&
        (nivel < NIVEL_TRAMPOLINES_START ||
         verificarSegundaVecindadZanahoria(tablero, filas, columnas, coordMoveF,
                                           coordMoveC))) {
        if (coordMoveF != coordZF || coordMoveC != coordZC) {
            tablero[coordMoveF][coordMoveC] = ZANAHORIA;
            tablero[coordZF][coordZC] = CELDA_VACIA;
        }
    } else
        return 0;
    return 1;
}

int ejecutarMovimientoConejos(char **tablero, char **tableroCopia,
                              const int filas, const int columnas,
                              int *conejosVivos, int *puntaje) {
    int i, j;
    int coordZC, coordZF;
    int coordMoveF, coordMoveC;
    int movSize;
    int zanahoriaViva = 1;
    // Borramos el tablero copia
    tablero_ini(tableroCopia, filas, columnas);
    // Transladamos desde el tablero al tablero copia
    // La zanahoria, los cadaveres y trampolines
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (tablero[i][j] == ZANAHORIA || tablero[i][j] == CADAVER ||
                tablero[i][j] == TRAMPOLIN ||
                tablero[i][j] == CONEJO_TRAMPOLIN) {
                // Si es que es un conejo sobre un trampolin lo copio solo como
                // trampolin, ya que el conejo se movera
                tableroCopia[i][j] = (tablero[i][j] == CONEJO_TRAMPOLIN)
                                         ? TRAMPOLIN
                                         : tablero[i][j];
                // Guardamos la posicion de la zanahoria
                if (tablero[i][j] == ZANAHORIA) {
                    coordZF = i;
                    coordZC = j;
                }
            }
        }
    }
    // Ahora comenzamos a mover los conejos acercandose a la zanahoria
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            if (tablero[i][j] == CONEJO || tablero[i][j] == CONEJO_TRAMPOLIN) {
                // Fijamos la magnitud del movimiento
                movSize = tablero[i][j] == CONEJO ? 1 : 2;
                // Establecemos la posicion a la que lo moveremos
                if (coordZF > i)
                    coordMoveF =
                        ((i + movSize) > coordZF) ? (i + 1) : (i + movSize);
                else if (coordZF < i)
                    coordMoveF =
                        ((i - movSize) < coordZF) ? (i - 1) : (i - movSize);
                else
                    coordMoveF = i;

                if (coordZC > j)
                    coordMoveC =
                        ((j + movSize) > coordZC) ? (j + 1) : (j + movSize);
                else if (coordZC < j)
                    coordMoveC =
                        ((j - movSize) < coordZC) ? (j - 1) : (j - movSize);
                else
                    coordMoveC = j;

                // Verificamos el contenido del destino
                switch (tableroCopia[coordMoveF][coordMoveC]) {
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

void ejecutarTeletransportacion(char **tablero, const int filas,
                                const int columnas) {
    int y = 0, x = 0;
    int coordZF, coordZC;
    int done = 0;
    // Determinamos las cordenadas actuales de la Zanahoria
    posicionZanahoria(tablero, filas, columnas, &coordZF, &coordZC);
    // Inicializamos la semilla para generar los valores aleatorios
    srand(time(NULL));
    // Buscamos una posicion donde teletransportarla
    while (1) {
        y = rand() % filas;
        x = rand() % columnas;
        if (tablero[y][x] == CELDA_VACIA) {
            tablero[y][x] = ZANAHORIA;
            done = 1;
            break;
        }
    }
    if (done) tablero[coordZF][coordZC] = CELDA_VACIA;
}

int verificarVecindadZanahoria(char **tablero, const int m, const int n,
                               const int f, const int c, const int salto) {
    int i = 0;
    int j = f - salto;  // Representa a las filas
    int k = c;          // Representa a las columnas
    char celda = (salto == 1) ? CONEJO : CONEJO_TRAMPOLIN;
    for (i = 1; i <= 8; i++) {
        if (j >= 0 && j < m && k >= 0 &&
            k < n)  // Verifico si es una coordenada valida
            if (tablero[j][k] ==
                celda)  // Verifico si hay un conejo o un conejo en trampolin
                return 0;
        if (i >= 0 && i < 2) k += salto;
        if (i >= 2 && i < 4) j += salto;
        if (i >= 4 && i < 6) k -= salto;
        if (i >= 6 && i < 8) j -= salto;
    }
    return 1;
}

int verificarPrimeraVecindadZanahoria(char **tablero, const int m, const int n,
                                      const int f, const int c) {
    int i = 0;
    int j = f - 1;  // Representa a las filas, me ubico una fila mas arriba para
                    // comenzar
    int k = c;      // Representa a las columnas, y me quedo en la misma columna
    int saltos = 8;
    int quiebre[4];
    for (i = 0; i < 4; i++) quiebre[i] = (int)(saltos * (i + 1) / 4);

    for (i = 1; i <= 8; i++) {
        if (j >= 0 && j < m && k >= 0 &&
            k < n)  // Verifico si es una coordenada valida
            if (tablero[j][k] == CONEJO ||
                tablero[j][k] == CONEJO_TRAMPOLIN)  // Verifico si hay un conejo
                                                    // o un conejo en trampolin
                return 0;
        if (i >= 0 && i < quiebre[0]) k += 1;
        if (i >= quiebre[0] && i < quiebre[1]) j += 1;
        if (i >= quiebre[1] && i < quiebre[2]) k -= 1;
        if (i >= quiebre[2] && i < quiebre[3]) j -= 1;
    }
    return 1;
}

int verificarSegundaVecindadZanahoria(char **tablero, const int m, const int n,
                                      const int f, const int c) {
    int i = 0;
    int j = f - 2;  // Representa a las filas, Me ubico en 2 filas mas arriba
                    // para comenzar
    int k = c - 1;  // Representa a las columnas, Me ubico una columna mas a la
                    // izquierda para comenzar
    int saltos = 16;
    int quiebre[4];
    for (i = 0; i < 4; i++) quiebre[i] = (int)(saltos * (i + 1) / 4);

    for (i = 1; i <= 16; i++) {
        if (j >= 0 && j < m && k >= 0 &&
            k < n)  // Verifico si es una coordenada valida
            if (tablero[j][k] == CONEJO_TRAMPOLIN)  // Verifico si hay un conejo
                                                    // o un conejo en trampolin
                return 0;
        if (i >= 0 && i < quiebre[0]) k += 1;
        if (i >= quiebre[0] && i < quiebre[1]) j += 1;
        if (i >= quiebre[1] && i < quiebre[2]) k -= 1;
        if (i >= quiebre[2] && i < quiebre[3]) j -= 1;
    }
    return 1;
}

/************************************
 * FUNCIONES SALVAR Y CARGAR PARTIDA
 ***********************************/

char **cargarPartida(char *ficheroName, int *filas, int *columnas,
                     int *conejosIniciales, int *conejosVivos, int *nivel,
                     int *puntaje, float *trampolines) {
    FILE *fp;
    char **tablero;
    char basura[NODO_NOMBRE_MAX_LENGTH + 1];
    int i, j;
    fp = fopen(ficheroName, "r");
    if (fp == NULL) return NULL;
    fgets(basura, NODO_NOMBRE_MAX_LENGTH, fp);
    fscanf(fp, "%i\n", conejosIniciales);
    fscanf(fp, "%i\n", conejosVivos);
    fscanf(fp, "%i\n", nivel);
    fscanf(fp, "%i\n", puntaje);
    fscanf(fp, "%f\n", trampolines);
    fscanf(fp, "%i\n", filas);
    fscanf(fp, "%i\n", columnas);
    // Solicito Memoria para el tablero
    tablero = (char **)pedirMemoriaMatriz(*filas, *columnas, 'c');
    if (tablero == NULL) return NULL;
    // Pueblo el tablero con los datos guardados
    for (i = 0; i < *filas; i++) {
        for (j = 0; j < (*columnas) - 1; j++) {
            fscanf(fp, "%c", &tablero[i][j]);
            tablero[i][j] = tablero[i][j] == '_' ? CELDA_VACIA : tablero[i][j];
        }
        fscanf(fp, "%c\n", &tablero[i][j]);
        tablero[i][j] = tablero[i][j] == '_' ? CELDA_VACIA : tablero[i][j];
    }
    fclose(fp);
    return tablero;
}

int guardarPartida(char *ficheroName, char **tablero, const int filas,
                   const int columnas, char *partida_nombre,
                   const int conejosIniciales, const int conejosVivos,
                   const int nivel, const int puntaje,
                   const float trampolines) {
    FILE *fp;
    int i, j;
    char guardar;
    fp = fopen(ficheroName, "w");
    if (fp == NULL) return 0;
    fprintf(fp, "%s\n", partida_nombre);
    fprintf(fp, "%i\n", conejosIniciales);
    fprintf(fp, "%i\n", conejosVivos);
    fprintf(fp, "%i\n", nivel);
    fprintf(fp, "%i\n", puntaje);
    fprintf(fp, "%f\n", trampolines);
    fprintf(fp, "%i\n", filas);
    fprintf(fp, "%i\n", columnas);
    for (i = 0; i < filas; i++) {
        for (j = 0; j < columnas; j++) {
            guardar = tablero[i][j] == CELDA_VACIA ? '_' : tablero[i][j];
            fprintf(fp, "%c", guardar);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return 1;
}

TipoNodoNombre *generar_lista_partidas() {
    TipoNodoNombre *lista;
    FILE *fp = NULL;
    char ruta_archivo[50];
    char nombre[NODO_NOMBRE_MAX_LENGTH + 1];
    int i, x;

    lista = lista_vacia();

    for (i = 0; True; i++) {
        sprintf(ruta_archivo, "%s%s%i%s", FOLDER_PARTIDAS, FILE_PARTIDA_PREFIX,
                i, FILE_PARTIDA_EXT);
        // printf("%s", ruta_archivo);break;
        fp = fopen(ruta_archivo, "r");
        if (fp == NULL) {
            break;
        } else {
            // Leo el nombre de la partida
            fgets(nombre, NODO_NOMBRE_MAX_LENGTH, fp);
            // Le quito el caracter salto de carro
            for (x = 0; nombre[x] != '\n'; x++)
                ;
            nombre[x] = '\0';
            // Lo inserto en la lista
            lista = insertar_por_cola(lista, nombre);
            // Cierro el archivo y dirigo el puntero a null
            fclose(fp);
            fp = NULL;
        }
    }
    return lista;
}

/*****************************************
 * FUNCIONES PARA ADMINISTRAR EL RANKING
 ****************************************/

void mostrarRanking(ItemRanking *ranking, const int n) {
    int i;
    // El Titulo
    printLuminoso("RANKING");
    printf("\n");
    // El Ranking
    for (i = n - 1; i >= 0; i--) {
        if (i % 2)
            fijarColorTexto(COLOR_CYAN);
        else
            fijarColorTexto(COLOR_VERDE);
        printf("%2i) Puntaje: %5i * Por: %s\n", n - i, ranking[i].puntaje,
               ranking[i].nombre);
    }
    fijarColorNormal();
}

void mostrarRankingDestacado(ItemRanking *ranking, const int n, const int pos) {
    int i, j;
    // El Titulo
    printLuminoso("RANKING");
    printf("\n");

    // Muestro el encabezado de las columnas
    fijarColorTexto(COLOR_PURPURA);
    for (j = 0; j < 40; j++) putchar('-');
    printf("\n|%4s |%20s |%9s |\n", "Pos.", "Nombre", "Puntaje");
    for (j = 0; j < 40; j++) putchar('-');
    putchar('\n');
    fijarColorNormal();

    // Imprimo el ranking
    for (i = n - 1; i >= 0; i--) {
        if (i == (n - pos)) fijarColorTextoEstilo(COLOR_MARRON, ESTILO_INVERSO);
        printf("|%4i |%20s |%9i |\n", n - i, ranking[i].nombre,
               ranking[i].puntaje);
        fijarColorNormal();
    }
    for (j = 0; j < 40; j++) putchar('-');
    putchar('\n');
}

int ingresarRanking(ItemRanking *ranking, const int n, ItemRanking *elemento) {
    int i;
    if (elemento->puntaje > ranking[0].puntaje) {
        for (i = 0; i < n; i++) {
            if (elemento->puntaje > ranking[i].puntaje) {
                if ((i + 1) < n) {
                    ranking[i].puntaje = ranking[i + 1].puntaje;
                    strcpy(ranking[i].nombre, ranking[i + 1].nombre);
                } else {
                    ranking[i].puntaje = elemento->puntaje;
                    strcpy(ranking[i].nombre, elemento->nombre);
                }
            } else {
                if (i - 1 >= 0) {
                    ranking[i - 1].puntaje = elemento->puntaje;
                    strcpy(ranking[i - 1].nombre, elemento->nombre);
                } else {
                    ranking[i].puntaje = elemento->puntaje;
                    strcpy(ranking[i].nombre, elemento->nombre);
                }
                break;
            }
        }
    } else
        return 0;  // No ingresa al Ranking
    // Retorno la posicion en el Ranking
    return n - i + 1;
}

int guardarRanking(ItemRanking *ranking, const int n) {
    FILE *fp;
    fp = fopen(FILE_RANKING, "wb");
    if (fp == NULL) return 0;
    fwrite(ranking, sizeof(ItemRanking) * n, 1, fp);
    fclose(fp);
    return 1;
}

int cargarRanking(ItemRanking *ranking, const int n) {
    FILE *fp;
    fp = fopen(FILE_RANKING, "rb");
    if (fp == NULL) return 0;
    fread(ranking, sizeof(ItemRanking) * n, 1, fp);
    fclose(fp);
    return 1;
}

void inicializarRanking(ItemRanking *ranking, const int n) {
    int i;
    for (i = 0; i < n; i++) {
        ranking[i].puntaje = 0;
        strcpy(ranking[i].nombre, "---");
    }
}

/****************************************
 * AYUDA
 ****************************************/

void mostrarAyuda() {
    clearScr();
    println("Juego de la Zanahoria - Instrucciones");
    println("-------------------------------------");
    println(
        "\nEl juego consiste en unos %sconejos hambrientos%s que perseguiran a "
        "la %szanahoria%s",
        COLOR_MARRON_S, ESTILO_NORMAL_S, COLOR_VERDE_S, ESTILO_NORMAL_S);
    println("(osea tu) hasta alcanzarla y poder %sdevorarla%s.", COLOR_ROJO_S,
            ESTILO_NORMAL_S);
    println(
        "\nPara salvarte de la voraz hambre de los conejos debes moverte por "
        "el escenario");
    println(
        "logrando que ellos %schoquen%s entre si o con los %scadaveres%s que "
        "hayan dejado",
        COLOR_VERDE_S, ESTILO_NORMAL_S, COLOR_VERDE_S, ESTILO_NORMAL_S);
    println("choques anteriores.");

    pausaMensaje("\nSiguiente... (Presiona Enter)");

    clearScr();
    println("Juego de la Zanahoria - Movimientos");
    println("-----------------------------------");
    println(
        "\nPara moverte debes ingresar cualquiera de los siguientes comandos:");
    println(
        "\n\t%s--------------------------------------------------------------",
        COLOR_MARRON_S);
    println("\t%s| %-20s | %-35s |", COLOR_MARRON_S, "",
            "Teclas que lo Accionan");
    println(
        "\t%s|                      | ----------------------------------- |",
        COLOR_MARRON_S);
    println("\t%s| %-20s | %16s | %16s |", COLOR_MARRON_S, "Movimiento",
            "Teclado Numerico", "Teclado Normal");
    println(
        "\t%s| -------------------- | ---------------- | ---------------- |",
        COLOR_MARRON_S);
    println("\t%s| %-20s | %16s | %16s |", COLOR_VERDE_S, "Arriba", "8", "u");
    println("\t%s| %-20s | %16s | %16s |", COLOR_ROJO_S, "Arriba - Derecha",
            "9", "i");
    println("\t%s| %-20s | %16s | %16s |", COLOR_VERDE_S, "Derecha", "6", "k");
    println("\t%s| %-20s | %16s | %16s |", COLOR_ROJO_S, "Abajo - Derecha", "3",
            ",");
    println("\t%s| %-20s | %16s | %16s |", COLOR_VERDE_S, "Abajo", "2", "m");
    println("\t%s| %-20s | %16s | %16s |", COLOR_ROJO_S, "Abajo - Izquierda",
            "1", "n");
    println("\t%s| %-20s | %16s | %16s |", COLOR_VERDE_S, "Izquierda", "4",
            "h");
    println("\t%s| %-20s | %16s | %16s |", COLOR_ROJO_S, "Arriba - Izquierda",
            "7", "y");
    println("\t%s| %-20s | %16s | %16s |", COLOR_VERDE_S, "Mantener Posicion",
            "5", "j");
    println(
        "\t%s--------------------------------------------------------------%s",
        COLOR_MARRON_S, ESTILO_NORMAL_S);

    pausaMensaje("\nSiguiente... (Presiona Enter)");

    clearScr();
    println("Juego de la Zanahoria - Movimientos (Otra Vista)");
    println("------------------------------------------------");
    println(
        "\nPara entender los movimientos disponibles, debes darte cuenta que "
        "la tecla %s5%s",
        COLOR_VERDE_S, ESTILO_NORMAL_S);
    println(
        "o la tecla %sj%s equivale a quedarse en la posicion, Y los demas a "
        "moverse en la",
        COLOR_VERDE_S, ESTILO_NORMAL_S);
    println("direccion esperada a partir de la posicion central.");
    println("\n\t-------------   -------------");
    println("\t| Tec. Num. |   | Tec. Norm.|");
    println("\t-------------   -------------");
    println("\t| 7 | 8 | 9 |   | y | u | i |");
    println("\t-------------   -------------");
    println("\t| 4 | %s5%s | 6 |   | h | %sj%s | k |", COLOR_VERDE_S,
            ESTILO_NORMAL_S, COLOR_VERDE_S, ESTILO_NORMAL_S);
    println("\t-------------   -------------");
    println("\t| 1 | 2 | 3 |   | n | m | , |");
    println("\t-------------   -------------");

    pausaMensaje("\nSiguiente... (Presiona Enter)");

    clearScr();
    println("Juego de la Zanahoria - Teletransportacion");
    println("------------------------------------------");
    println(
        "\nSi te encuentras encerrado y no hay donde te puedas mover sin ser "
        "comido");
    println(
        "(No se te permitira moverte a una posicion donde puedas ser comido)");
    println("puedes teletrasportarte presionando el comando: %st%s",
            COLOR_VERDE_S, ESTILO_NORMAL_S);
    println("\nAunque debes tener cuidado, ya que nada asegura que no caeras");
    println("junto a un conejo y este te devore.");

    pausaMensaje("\nSiguiente... (Presiona Enter)");

    clearScr();
    println("Juego de la Zanahoria - Puntuacion");
    println("----------------------------------");
    println("\nConseguiras punto con cualquiera de los siguientes eventos:");
    println("\n\t  %s5 ptos.%s - Por cada movimiento correcto", COLOR_ROJO_S,
            ESTILO_NORMAL_S);
    println("\t %s50 ptos.%s - Por cada conejo que choque.", COLOR_ROJO_S,
            ESTILO_NORMAL_S);
    println("\t%s100 ptos.%s - Cuando pases de nivel.", COLOR_ROJO_S,
            ESTILO_NORMAL_S);
    println("\nPara pasar de nivel debes lograr que todos los conejos");
    println("choquen entre si o con otro cadaver en el campo.");
    println("\nSi juntas muchos puntos, puedes entrar en el top 10");
    println("de los mejores puntajes y dejar tu puntaje registrado");
    println("junto con tu nombre para competir contra tus amigos.");

    pausaMensaje("\nSiguiente... (Presiona Enter)");

    clearScr();
    println("Juego de la Zanahoria - Trampolines");
    println("-----------------------------------");
    println("\nA partir del %s3 nivel%s apareceran los trampolines",
            COLOR_ROJO_S, ESTILO_NORMAL_S);
    println("\nPermitira a los conejos moverse hasta dos espacios");
    println("para poder comerte.");

    pausaMensaje("\nSiguiente... (Presiona Enter)");

    clearScr();
    println("Juego de la Zanahoria - Elementos del Tablero");
    println("---------------------------------------------");
    println(
        "\nEstos son los posibles elementos que encontraras en el tablero:");
    println("\n\t%s%c%s: Zanahoria", COLOR_ROJO_S, ZANAHORIA, ESTILO_NORMAL_S);
    println("\t%s%c%s: Conejo", COLOR_MARRON_S, CONEJO, ESTILO_NORMAL_S);
    println("\t%s%c%s: Cadaveres", COLOR_PURPURA_S, CADAVER, ESTILO_NORMAL_S);
    println("\t%s%c%s: Trampolin", COLOR_AZUL_S, TRAMPOLIN, ESTILO_NORMAL_S);
    println("\t%s%c%s: Conejo sobre trampolin", COLOR_ROJO_S, CONEJO_TRAMPOLIN,
            ESTILO_NORMAL_S);

    println("\nSUERTE!");

    pausaMensaje("\nComenzar... (Presiona Enter)");
}

#endif  // __ZANAHORIA_C__
