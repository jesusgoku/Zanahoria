/** @brief Mis Funciones Reutilizables
*
* En esta libreria se encuentras funciones de uso general
*/
#ifndef __MY_FUNCTION_C__
#define __MY_FUNCTION_C__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <my_function.h>

/** @brief Como el print de python da un salto de carro luego de imprimir
* @param formato cadena de formato
* @param ... los distintos atributos especificados en formato
*
* @return cantidad de parametros imprimidos
*/
int println(const char *formato, ...)
{
	char mi_formato[255] = "";
    strcat(mi_formato, formato);
    strcat(mi_formato, "\n");

    va_list listaPtr;
    int resultado = 0;

    va_start( listaPtr, formato );
    resultado = vprintf( mi_formato, listaPtr );
    va_end( listaPtr );

    return resultado;
}

/** Redondea un flotante a entero
*
* @param num numero que desea ser redondeado
*
* @return numero redondeado
*/
int redondeoEntero(float num){
    int num10 = num * 10;
    int num10mod10 = num10 % 10;
    int redondeo = 0;
    if(num10mod10 >= 5){
        redondeo = (num10 + 10 - num10mod10);
    }else{
        redondeo = num10 - num10mod10;
    }
    return redondeo / 10;
}

/** Limpiar Buffer de Entrada
*/
/** Limpiar Pantalla
*/
#if defined(MAC)
    void clearStdin(){ fpurge(stdin); }
    void clearScr(){ system("clear"); }
#elif defined(LINUX)
    void clearStdin(){ __fpurge(stdin); }
    void clearScr(){ system("clear"); }
#elif defined(WINDOWS)
    void clearStdin(){ fflush(stdin); }
    void clearScr(){ system("cls"); }
#elif defined(CYGWIN)
    void clearStdin(){ fpurge(stdin); }
    void clearScr(){ int i; for(i = 0; i < 100; i++) printf("\n"); }
#else
	#error "Sistema Operativo Incorrecto"
#endif // Definicion clearStdin();

/** Introducir una pausa en la ejecucion
*/
void pausa(){
    clearStdin();
    getc(stdin);
}

/** Muestra un mensaje e introduce una pausa
*
* @param mensaje mensaje que se desea mostrar antes de introducir la pausa
*/
void pausaMensaje(const char *mensaje){
    fputs(mensaje, stdout);
    pausa();
}

/** Pregunta al usuario dando la posibilidad de responder y/n
*
* @param pregunta pregunta a mostrar al usuario
*
* @return respuesta del usuario, 1 para y 0 para n
*/
int preguntayn(const char *pregunta){
    char respuesta = 0;
    do {
        fputs(pregunta, stdout);
        clearStdin();
        scanf("%c", &respuesta);
        if(respuesta != 'y' && respuesta != 'n')
            println("Respuesta no valida!");
    } while (respuesta != 'y' && respuesta != 'n');
    return respuesta == 'y' ? 1 : 0;
}

/** Captura una cadena desde la entrada estadar
*
* Mas segura que gets ya que se debe especificar el limite a capturar
* y se elimina el "ENTER" dejado por fgets
*
* @param cadena indica donde se guardara la cadena capturada
* @param max langitud maxima de caracteres a capturar
*/
void mygets(char *cadena, const int max){
    int i = 0;
    clearStdin();
    fgets(cadena, max, stdin);
    for(i = 0; cadena[i] != '\n'; i++);
    cadena[i] = '\0';
}

/** Pide una cadena al usuario de forma segura
*
* Para su utilizacion utiliza la funcion mygets de esta misma libreria
*
* @param mensaje indicacion de la cadena a ingresar
* @param destino cadena donde se guardara la cadena ingresada por el usuario
* @param max longitud maxima de caracteres a capturar
*/
void pedirCadena(const char *mensaje, char *destino, const int max){
    fputs(mensaje, stdout);
    mygets(destino, max);
}

#endif // __MY_FUNCTION_C__
