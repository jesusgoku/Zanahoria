#ifndef __COLORES_C__
#define __COLORES_C__

#include <stdio.h>

#if !defined(WINDOWS) || defined(ANSICON)

void fijarColorNormal(){
	printf("\033[0m");
}

void fijarColorTexto(const int color){
	printf("\033[0;%im", color);
}

void fijarColorFondo(const int fondo){
	printf("\033[0;%im", fondo);
}

void fijarColorEstilo(const int estilo){
	printf("\033[%im", estilo);
}

void fijarColorTextoFondo(const int texto, const int fondo){
	printf("\033[0;%i;%im", texto, fondo);
}

void fijarColorTextoFondoEstilo(const int texto, const int fondo, const int estilo){
	printf("\033[%i;%i;%im", estilo, texto, fondo);
}

void fijarColorTextoEstilo(const int texto, const int estilo){
	printf("\033[%i;%im", estilo, texto);
}

#else

void fijarColorNormal(){}

void fijarColorTexto(const int color){}

void fijarColorFondo(const int fondo){}

void fijarColorEstilo(const int estilo){}

void fijarColorTextoFondo(const int texto, const int fondo){}

void fijarColorTextoFondoEstilo(const int texto, const int fondo, const int estilo){}

void fijarColorTextoEstilo(const int texto, const int estilo){}

#endif

#endif // __COLORES_C__
