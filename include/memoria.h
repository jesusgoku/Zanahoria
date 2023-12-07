/** @brief Libreria para solicitar y Liberar Memoria.
 *
 * Hay funciones para pedir memoria facilmente para una matriz en una sola
 * llamada y liberarla tambien.
 *
 * Para solicitar la memoria se utiliza un metodo para reducir el numero de
 * llamadas a malloc solo a dos Lo cual lo hace eficiente en tiempo de
 * procesador, pero como la memoria solicitada debe ser continua se corre el
 * riesgo de no encontrar el suficiente espacio para la matriz, este riesgo se
 * reduce al pedir la memoria de cada fila por separado, pero considerando que
 * los computadores actuales tienen suficiente memoria opte por utilizar este
 * metodo.
 *
 * @file memoria.h
 * @version 0.1
 * @date 22/04/2012
 * @author JesusGoku
 *
 */
#ifndef __MEMORIA_H__
#define __MEMORIA_H__

#include <stdio.h>
#include <stdlib.h>

/** @brief Pedir memoria para una matriz de enteros.
 *
 * @param filas Filas de la matriz a solicitar
 * @param columnas Columnas de la matriz a solicitar
 *
 * @return Puntero a la matriz solicitada
 */
int **pedirMemoriaMatrizEntera(const int filas, const int columnas);

/** @brief Liberar memoria de una matriz entera.
 *
 * @param pm Puntero a la memoria que se desea liberar
 */
void liberarMemoriaMatrizEntera(int **pm);

/** @brief Pedir memoria para una matriz de caracteres.
 *
 * @param filas Filas de la matriz a solicitar
 * @param columnas Columnas de la matriz a solicitar
 *
 * @return Puntero a la matriz solicitada
 */
char **pedirMemoriaMatrizCaracter(const int filas, const int columnas);

/** @brief Liberar memoria de una matriz de caracteres.
 *
 * @param pm Puntero a la memoria que se desea liberar
 */
void liberarMemoriaMatrizCaracter(char **pm);

/** @brief Pedir memoria para una matriz.
 *
 * Te permite pedir memoria para una matriz de entre 3 tipos (Enteros,
 *Caracteres, Flotantes) especificandolo en el tercer parametro
 *
 * @param filas Filas de la matriz a solicitar
 * @param columnas Columnas de la matriz a solicitar
 * @param tipo Cacter que representa al tipo de la matriz
 *			c -> char
 *			i -> int
 *			f -> float
 *
 * @return Puntero a la matriz solicitad, se debe hacer un casting al tipo
 *pedido
 */
void **pedirMemoriaMatriz(const int filas, const int columnas, const char tipo);

/** @brief Liberar memoria de una matriz.
 *
 * @param pm Puntero a la memoria que se desea liberar
 */
void liberarMemoriaMatriz(void **pm);

/** @brief Pedir memoria para una matriz (Metodo por Filas).
 *
 * Te permite pedir memoria para una matriz de entre 3 tipos (Enteros,
 *Caracteres, Flotantes) especificandolo en el tercer parametro.
 *
 * Esta pide la memoria fila por fila, para ser utilizada en maquinas con poca
 *memoria continua
 *
 * @param filas Filas de la matriz a solicitar
 * @param columnas Columnas de la matriz a solicitar
 * @param tipo Cacter que representa al tipo de la matriz
 *			c -> char
 *			i -> int
 *			f -> float
 *
 * @return Puntero a la matriz solicitad, se debe hacer un casting al tipo
 *pedido
 */
void **pedirMemoriaMatrizDos(const int filas, const int columnas,
                             const char tipo);

/** @brief Liberar memoria pedida por filas
 *
 * @param pm Puntero a la memoria que se desea liberar
 * @param filas Cantidad de filas que seran liberadas
 */
void liberarMemoriaMatrizDos(void **pm, const int filas);

#endif  // __MEMORIA_H__
