#ifndef __MEMORIA_C__
#define __MEMORIA_C__

#include <stdio.h>
#include <stdlib.h>

int **pedirMemoriaMatrizEntera(const int filas, const int columnas) {
    int **pm = NULL;
    int i = 1;
    pm = (int **)malloc(filas * sizeof(int *));
    pm[0] = (int *)malloc(filas * columnas * sizeof(int));
    for (i = 1; i < filas; i++) pm[i] = pm[i - 1] + columnas;
    return pm;
}

void liberarMemoriaMatrizEntera(int **pm) {
    free(pm[0]);
    free(pm);
}

char **pedirMemoriaMatrizCaracter(const int filas, const int columnas) {
    char **pm = NULL;
    int i = 1;
    pm = (char **)malloc(filas * sizeof(char *));
    pm[0] = (char *)malloc(filas * columnas * sizeof(char));
    for (i = 1; i < filas; i++) pm[i] = pm[i - 1] + columnas;
    return pm;
}

void liberarMemoriaMatrizCaracter(char **pm) {
    free(pm[0]);
    free(pm);
}

void **pedirMemoriaMatriz(const int filas, const int columnas,
                          const char tipo) {
    void **pm = NULL;
    int i = 1;
    pm = (void **)malloc(filas * sizeof(void *));
    if (pm == NULL) return NULL;
    switch (tipo) {
        case 'i':
            pm[0] = (int *)malloc(filas * columnas * sizeof(int));
            break;
        case 'c':
            pm[0] = (char *)malloc(filas * columnas * sizeof(char));
            break;
        case 'f':
            pm[0] = (float *)malloc(filas * columnas * sizeof(float));
            break;
        default:
            pm[0] = NULL;
    }
    /*
     * Si no se logro pedir memoria por el metodo anterior
     * Si aun asi no s puede liberamos la memoria pedia hasta ahora
     */
    if (pm[0] == NULL) {
        free(pm);
        return NULL;
    }
    for (i = 1; i < filas; i++) pm[i] = pm[i - 1] + columnas;
    return pm;
}

void liberarMemoriaMatriz(void **pm) {
    free(pm[0]);
    free(pm);
}

void **pedirMemoriaMatrizDos(const int filas, const int columnas, char tipo) {
    void **pm;
    int i, j;
    pm = (void **)malloc(filas * sizeof(void *));
    if (pm == NULL) return NULL;
    switch (tipo) {
        case 'i':
            for (i = 0; i < filas; i++) {
                pm[i] = (int *)malloc(columnas * sizeof(int));
                if (pm[i] == NULL) {
                    for (j = 0; j < i; j++) {
                        free(pm[j]);
                        pm[j] = NULL;
                    }
                }
            }
            break;
        case 'c':
            for (i = 0; i < filas; i++) {
                pm[i] = (char *)malloc(columnas * sizeof(char));
                if (pm[i] == NULL) {
                    for (j = 0; j < i; j++) {
                        free(pm[j]);
                        pm[j] = NULL;
                    }
                }
            }
            break;
        case 'f':
            for (i = 0; i < filas; i++) {
                pm[i] = (float *)malloc(columnas * sizeof(float));
                if (pm[i] == NULL) {
                    for (j = 0; j < i; j++) {
                        free(pm[j]);
                        pm[j] = NULL;
                    }
                }
            }
            break;
        default:
            pm[0] = NULL;
    }
    if (pm[0] == NULL) {
        free(pm);
        return NULL;
    }
    return pm;
}

void liberarMemoriaMatrizDos(void **pm, const int filas) {
    int i;
    for (i = 0; i < filas; i++) free(pm[i]);
    free(pm);
}

#endif  // __MEMORIA_C_
