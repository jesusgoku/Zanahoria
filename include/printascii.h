/** @brief Libreria para la impresion de Arte ASCII
*
* Colecciones de logos para impresion de arte ascii en la consola
*
* @file printascii.h
* @author JesusGoku
* @version 0.1
* @date 22/04/2012
* 
*/
#ifndef __PRINTASCII_H__
#define __PRINTASCII_H__

#include <stdio.h>
#include <my_function.h>
#include <string.h>
#include <colores.h>

/** @brief Imprime el logo de bienvenida al juego de la zanahoria.
*/
void printZanahoria();

/** @brief Imprime el logo de un conejo comiendo una zanahoria.
*/
void printConejoZanahoria();

/** @brief Imprime un conejo con el texto de GAME OVER!.
*/
void printConejoGameOver();

/** @brief Imprime gracias por jugar.
*/
void printGraciasPorJugar();

/** Imprime un letrro con letras parpadeantes con el string apuntado por cadena.
*
* @param cadena puntero al string que se quiere mostrar en el mensaje
*/
void printLuminoso(char *cadena);

/** @brief Imprime un letrero con letras parpadeantes encerrado por signos + y -
*
* @param cadena puntero al string que se quiere mostrar en el mensaje
*/
void printMasMenos(char *cadena);

/** @brief Imprime un mensaje de error en color rojo
*
* @param msj puntero a cadena con el mensaje que se desea mostrar
*/
void printMsjError(const char *msj);

/** @brief Imprimir un mesaje de error en color rojo e introducir una pausa en la ejecucion
*
* @param msj puntero a cadena con el mensaje a mostrar
*/
void printMsjErrorPausa(const char *msj);

/** @brief Imprime un mensaje de error en color verde
*
* @param msj puntero a cadena con el mensaje que se desea mostrar
*/
void printMsjOk(const char *msj);

/** @brief Imprimir un mesaje de confirmacion en color verde e introducir una pausa en la ejecucion
*
* @param msj puntero a cadena con el mensaje a mostrar
*/
void printMsjOkPausa(const char *msj);

/** @brief Imprime un mensaje de error en color marron
*
* @param msj puntero a cadena con el mensaje que se desea mostrar
*/
void printMsjInfo(const char *msj);

/** @brief Imprimir un mesaje de informacion en color marron e introducir una pausa en la ejecucion
*
* @param msj puntero a cadena con el mensaje a mostrar
*/
void printMsjInfoPausa(const char *msj);

#endif // __PRINTASCII_H__
