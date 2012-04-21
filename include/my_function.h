#ifndef __MY_FUNCTION_H__
#define __MY_FUNCTION_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef enum {False, True} Bool;

int println(const char *formato, ...);
int redondeoEntero(float num);
void clearScr();
void clearStdin();
void pausa();
void pausaMensaje(const char *mensaje);
int preguntayn(const char *pregunta);

#endif // __MY_FUNCTION_H__
