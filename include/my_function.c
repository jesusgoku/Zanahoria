#ifndef __MY_FUNCTION_C__
#define __MY_FUNCTION_C__

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

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

void pausa(){
    clearStdin();
    getc(stdin);
}

void pausaMensaje(const char *mensaje){
    println(mensaje);
    pausa();
}

int preguntayn(const char *pregunta){
    char respuesta;
    do{
        printf(pregunta);
        clearStdin();
        scanf("%c", &respuesta);
        if(respuesta != 'y' && respuesta != 'n')
            println("Respuesta no valida!");
    }while(respuesta != 'y' && respuesta != 'n');
    return respuesta == 'y' ? 1 : 0;
}

#endif // __MY_FUNCTION_C__
