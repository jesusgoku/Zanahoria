#ifndef __MEMORIA_H__
#define __MEMORIA_H__

#include <stdio.h>
#include <stdlib.h>

int ** pedirMemoriaMatrizEntera(const int filas, const int columnas);
void liberarMemoriaMatrizEntera(int **pm);
char ** pedirMemoriaMatrizCaracter(const int filas, const int columnas);
void liberarMemoriaMatrizCaracter(char **pm);
void ** pedirMemoriaMatriz(const int filas, const int columnas, const char tipo);
void liberarMemoriaMatriz(void **pm);
void ** pedirMemoriaMatrizDos(const int filas, const int columnas, const char tipo);
void liberarMemoriaMatrizDos(void **pm, const int filas);

#endif // __MEMORIA_H__