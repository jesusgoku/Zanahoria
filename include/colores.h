#ifndef __COLORES_H__
#define __COLORES_H__

#include <stdio.h>

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

void fijarColorNormal();
void fijarColorTexto(const int color);
void fijarColorFondo(const int color);
void fijarColorEstilo(const int estilo);
void fijarColorTextoFondo(const int texto, const int fondo);
void fijarColorTextoFondoEstilo(const int texto, const int fondo, const int estilo);
void fijarColorTextoEstilo(const int texto, const int estilo);

#endif // __COLORES_H__
