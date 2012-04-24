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

#endif // __PRINTASCII_H__