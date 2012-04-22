/** @brief Para implementar colores en terminales ANSI.
*
* Con esta libreria se podran utilizar las caracteristicas de las terminales ANSI para
* poder dar color, fondo y estilo a la terminal y asi agregar un poco de riquesa al
* contenido mostrado.
*
* @file my_function.h
* @version 0.1
* @date 22/04/2012
* @author JesusGoku
* 
*/
#ifndef __COLORES_H__
#define __COLORES_H__

#include <stdio.h>

/** @brief Estilos Disponibles para pasar a las funciones
*/
#define ESTILO_NORMAL 0
#define ESTILO_CLARO 1
#define ESTILO_SUBRAYADO 4
#define ESTILO_PARPADEANTE 5
#define ESTILO_INVERSO 7
#define ESTILO_OCULTO 8

/** @brief Colores disponibles para pasar a las funciones
*/
#define COLOR_NEGRO 30
#define COLOR_ROJO 31
#define COLOR_VERDE 32
#define COLOR_MARRON 33
#define COLOR_AZUL 34
#define COLOR_PURPURA 35
#define COLOR_CYAN 36
#define COLOR_GRIS 37

/** @brief Fondos disponibles para pasar a las funciones.
*/
#define FONDO_NEGRO 40
#define FONDO_ROJO 41
#define FONDO_VERDE 42
#define FONDO_MARRON 43
#define FONDO_AZUL 44
#define FONDO_PURPURA 45
#define FONDO_CYAN 46
#define FONDO_GRIS 47

/** @brief Resetea la terminal a sus colores originales.
*/
void fijarColorNormal();

/** @brief Fija el color del texto a color.
*
* @param color corresponde a las constantes COLOR_XXX donde XXX puede ser cualquier color de los disponibles
*/
void fijarColorTexto(const int color);

/** @brief Fija el color del fondo a color.
*
* @param color corresponde a la constantes FONDO_XXX donde XXX son el color dentro de los disponibles
*/
void fijarColorFondo(const int color);

/** @brief Fija el estilo de la terminal.
*
* @param estilo corresponde a la constantes ESTILO_XXX donde XXX son los estilos dentro de los disponibles
*/
void fijarColorEstilo(const int estilo);

/** @brief Fija el color y el fondo del texto.
*
* @param texto corresponde a las constantes COLOR_XXX donde XXX puede ser cualquier color de los disponibles
* @param fondo corresponde a las constantes FONDO_XXX donde XXX puede ser cualquiera de los fondos disponibles
*/
void fijarColorTextoFondo(const int texto, const int fondo);

/** @brief Fija el color, el estilo y el fondo del texto.
*
* @param texto corresponde a las constantes COLOR_XXX donde XXX puede ser cualquier color de los disponibles
* @param fondo corresponde a las constantes FONDO_XXX donde XXX puede ser cualquiera de los fondos disponibles
* @param estilo corresponde a las constantes ESTILO_XXX donde XXX puede ser cualquier estilo de los disponibles
*/
void fijarColorTextoFondoEstilo(const int texto, const int fondo, const int estilo);

/** @brief Fija el color y el estilo del texto.
*
* @param texto corresponde a las constantes COLOR_XXX donde XXX puede ser cualquier color de los disponibles
* @param estilo corresponde a las constantes ESTILO_XXX donde XXX puede ser cualquier estilo de los disponibles
*/
void fijarColorTextoEstilo(const int texto, const int estilo);

#endif // __COLORES_H__
