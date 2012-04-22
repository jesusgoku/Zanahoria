#ifndef __COLORES_C__
#define __COLORES_C__

#include <stdio.h>

void fijarColorNormal(){
	printf("\033[0m");
}

void fijarColorTexto(const int color){
	printf("\033[0;%im", color);
}

void fijarColorFondo(const int color){
	printf("\033[0;%im", color);
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

#endif // __COLORES_C__
