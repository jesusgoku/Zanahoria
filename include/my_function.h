/** @brief Mis Funciones Reutilizables.
*
* En esta libreria se encuentras funciones de uso general
*
* @file my_function.h
* @version 0.1
* @date 22/04/2012
* @author JesusGoku
* 
*/
#ifndef __MY_FUNCTION_H__
#define __MY_FUNCTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/** @brief Emulacion del tipo Booleano
*
*/
typedef enum {False, True} Bool;

/** @brief Como el print de python.
*
* Da un salto de carro luego de imprimir, por lo demas se comporta igual que printf
*
* @param formato cadena de formato
* @param ... los distintos atributos especificados en formato
*
* @return cantidad de parametros imprimidos
*/
int println(const char *formato, ...);

/** @brief: Redondea un flotante a entero
*
* @param num numero que desea ser redondeado
*
* @return numero redondeado
*/
int redondeoEntero(float num);

/** @brief Limpiar Buffer de Entrada
*/
void clearScr();

/** @brief Limpiar Pantalla
*/
void clearStdin();

/** @brief Introducir una pausa en la ejecucion
*/
void pausa();

/** @brief Muestra un mensaje e introduce una pausa
*
* @param mensaje mensaje que se desea mostrar antes de introducir la pausa
*/
void pausaMensaje(const char *mensaje);

/** @brief Pregunta al usuario dando la posibilidad de responder y/n
*
* @param pregunta pregunta a mostrar al usuario
*
* @return respuesta del usuario, 1 para y 0 para n
*/
int preguntayn(const char *pregunta);

/** @brief Captura una cadena desde la entrada estadar.
*
* Mas segura que gets ya que se debe especificar el limite a capturar
* y se elimina el "ENTER" dejado por fgets
*
* @param cadena indica donde se guardara la cadena capturada
* @param max langitud maxima de caracteres a capturar
*/
void mygets(char *cadena, const int max);

/** @brief Pide una cadena al usuario de forma segura.
*
* Para su utilizacion utiliza la funcion mygets de esta misma libreria
*
* @param mensaje indicacion de la cadena a ingresar
* @param destino cadena donde se guardara la cadena ingresada por el usuario
* @param max longitud maxima de caracteres a capturar
*/
void pedirCadena(const char *mensaje, char *destino, const int max);

#endif // __MY_FUNCTION_H__
