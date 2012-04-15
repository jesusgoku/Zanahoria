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
    void clearScr(){ system("clear"); }
#else
	#error "Sistema Operativo Incorrecto"
#endif // Definicion clearStdin();

#endif // __MY_FUNCTION_C__