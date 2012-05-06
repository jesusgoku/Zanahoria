/** @brief Para implementar colores en terminales ANSI.
*
* Con esta libreria se podran utilizar las caracteristicas de las terminales ANSI para
* poder dar color, fondo y estilo a la terminal y asi agregar un poco de riquesa al
* contenido mostrado.
*
* @file colores.h
* @version 0.1
* @date 22/04/2012
* @author JesusGoku
* 
*/
#ifndef __COLORES_H__
#define __COLORES_H__

#include <stdio.h>

/** @defgroup ColoresCodigos Codigos Funciones de Colores.h
*
* Constantes con los codigos disponibles para pasarle a las funciones
* definidas en colores.h que representan los diferentes colores, estilos
* y fondos que son capaces de representar.
*
* @{
*/
#define ESTILO_NORMAL 0
#define ESTILO_CLARO 1
#define ESTILO_SUBRAYADO 4
#define ESTILO_PARPADEANTE 5
#define ESTILO_INVERSO 7
#define ESTILO_OCULTO 8

#define COLOR_NEGRO 30
#define COLOR_ROJO 31
#define COLOR_VERDE 32
#define COLOR_MARRON 33
#define COLOR_AZUL 34
#define COLOR_PURPURA 35
#define COLOR_CYAN 36
#define COLOR_GRIS 37

#define FONDO_NEGRO 40
#define FONDO_ROJO 41
#define FONDO_VERDE 42
#define FONDO_MARRON 43
#define FONDO_AZUL 44
#define FONDO_PURPURA 45
#define FONDO_CYAN 46
#define FONDO_GRIS 47

/** @} */ // end of ColoresCodigos

#ifndef WINDOWS

/** @defgroup CadenasColor Cadenas De Color y Estilo
*
* Cadenas de colores, estilos y fondo para el texto en la consola
* basado, soportado por todas las consalas ANSI
*
* @{
*/
#define ESTILO_NORMAL_S "\033[0m"
#define ESTILO_CLARO_S "\033[1m"
#define ESTILO_SUBRAYADO_S "\033[4m"
#define ESTILO_PARPADEANTE_S "\033[5m"
#define ESTILO_INVERSO_S "\033[7m"
#define ESTILO_OCULTO_S "\033[8m"

#define COLOR_NEGRO_S "\033[0;30m"
#define COLOR_ROJO_S "\033[0;31m"
#define COLOR_VERDE_S "\033[0;32m"
#define COLOR_MARRON_S "\033[0;33m"
#define COLOR_AZUL_S "\033[0;34m"
#define COLOR_PURPURA_S "\033[0;35m"
#define COLOR_CYAN_S "\033[0;36m"
#define COLOR_GRIS_S "\033[0;37m"

#define COLOR_NEGRO_CLARO_S "\033[1;30m"
#define COLOR_ROJO_CLARO_S "\033[1;31m"
#define COLOR_VERDE_CLARO_S "\033[1;32m"
#define COLOR_MARRON_CLARO_S "\033[1;33m"
#define COLOR_AZUL_CLARO_S "\033[1;34m"
#define COLOR_PURPURA_CLARO_S "\033[1;35m"
#define COLOR_CYAN_CLARO_S "\033[1;36m"
#define COLOR_GRIS_CLARO_S "\033[1;37m"

#define FONDO_NEGRO_S "\033[0;40m"
#define FONDO_ROJO_S "\033[0;41m"
#define FONDO_VERDE_S "\033[0;42m"
#define FONDO_MARRON_S "\033[0;43m"
#define FONDO_AZUL_S "\033[0;44m"
#define FONDO_PURPURA_S "\033[0;45m"
#define FONDO_CYAN_S "\033[0;46m"
#define FONDO_GRIS_S "\033[0;47m"

#define FONDO_NEGRO_CLARO_S "\033[1;40m"
#define FONDO_ROJO_CLARO_S "\033[1;41m"
#define FONDO_VERDE_CLARO_S "\033[1;42m"
#define FONDO_MARRON_CLARO_S "\033[1;43m"
#define FONDO_AZUL_CLARO_S "\033[1;44m"
#define FONDO_PURPURA_CLARO_S "\033[1;45m"
#define FONDO_CYAN_CLARO_S "\033[1;46m"
#define FONDO_GRIS_CLARO_S "\033[1;47m"

/** @} */ // end of CadenasColor

#elif

/** @defgroup CadenasColorWindows Cadenas De Color y Estilo
*
* La consola de comandos por defecto no soporta el estandar ANSI
* por lo tanto las cadenas se mostrarian como caracteres extranos
* por eso para agregar compatibilidad se usan las mismas constantes
* pero como una cadena vacia.
*
* @{
*/

#define ESTILO_NORMAL_S ""
#define ESTILO_CLARO_S ""
#define ESTILO_SUBRAYADO_S ""
#define ESTILO_PARPADEANTE_S ""
#define ESTILO_INVERSO_S ""
#define ESTILO_OCULTO_S ""

#define COLOR_NEGRO_S "\033[0;30m"
#define COLOR_ROJO_S "\033[0;31m"
#define COLOR_VERDE_S "\033[0;32m"
#define COLOR_MARRON_S "\033[0;33m"
#define COLOR_AZUL_S "\033[0;34m"
#define COLOR_PURPURA_S "\033[0;35m"
#define COLOR_CYAN_S "\033[0;36m"
#define COLOR_GRIS_S "\033[0;37m"

#define COLOR_NEGRO_CLARO_S "\033[1;30m"
#define COLOR_ROJO_CLARO_S "\033[1;31m"
#define COLOR_VERDE_CLARO_S "\033[1;32m"
#define COLOR_MARRON_CLARO_S "\033[1;33m"
#define COLOR_AZUL_CLARO_S "\033[1;34m"
#define COLOR_PURPURA_CLARO_S "\033[1;35m"
#define COLOR_CYAN_CLARO_S "\033[1;36m"
#define COLOR_GRIS_CLARO_S "\033[1;37m"

#define FONDO_NEGRO_S "\033[0;40m"
#define FONDO_ROJO_S "\033[0;41m"
#define FONDO_VERDE_S "\033[0;42m"
#define FONDO_MARRON_S "\033[0;43m"
#define FONDO_AZUL_S "\033[0;44m"
#define FONDO_PURPURA_S "\033[0;45m"
#define FONDO_CYAN_S "\033[0;46m"
#define FONDO_GRIS_S "\033[0;47m"

#define FONDO_NEGRO_CLARO_S "\033[1;40m"
#define FONDO_ROJO_CLARO_S "\033[1;41m"
#define FONDO_VERDE_CLARO_S "\033[1;42m"
#define FONDO_MARRON_CLARO_S "\033[1;43m"
#define FONDO_AZUL_CLARO_S "\033[1;44m"
#define FONDO_PURPURA_CLARO_S "\033[1;45m"
#define FONDO_CYAN_CLARO_S "\033[1;46m"
#define FONDO_GRIS_CLARO_S "\033[1;47m"

/** @} */ // end of CadenasColorWindows

#endif // WINDOWS

/** @brief Resetea la terminal a sus colores originales.
*/
void fijarColorNormal();

/** @brief Fija el color del texto a color.
*
* @param color corresponde a las constantes COLOR_XXX donde XXX puede ser cualquier color de los disponibles
*/
void fijarColorTexto(const int color);

/** @brief Fija el color del fondo a fondo.
*
* @param fondo corresponde a las constantes FONDO_XXX donde XXX puede ser cualquiera de los fondos disponibles
*/
void fijarColorFondo(const int fondo);

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
