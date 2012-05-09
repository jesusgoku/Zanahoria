#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lista.h>

TipoNodoNombre * lista_vacia(){
	return NULL;
}

int es_lista_vacia(TipoNodoNombre *lista)
{
	return lista == NULL;
}

TipoNodoNombre * insertar_por_cabeza(TipoNodoNombre *lista, char *cadena)
{
	TipoNodoNombre *nuevo;
	nuevo = (TipoNodoNombre *)malloc(sizeof(TipoNodoNombre));
	strcpy(nuevo->nombre, cadena);
	nuevo->sig = lista;
	lista = nuevo;
	return lista;
}

int longitud_lista(TipoNodoNombre *lista)
{
	int contador = 0;
	TipoNodoNombre *aux;
	for(aux = lista; aux != NULL; aux = aux->sig)
		contador++;
	return contador;
}

void mostrar_lista(TipoNodoNombre *lista){
	TipoNodoNombre *aux;
	int i = 0;
	for(aux = lista; aux != NULL; aux = aux->sig, i++)
		printf("%i) %s\n", i + 1, aux->nombre);
}

TipoNodoNombre * insertar_por_cola(TipoNodoNombre *lista, char *cadena)
{
	TipoNodoNombre *nuevo, *aux;
	nuevo = (TipoNodoNombre *)malloc(sizeof(TipoNodoNombre));
	strcpy(nuevo->nombre, cadena);
	nuevo->sig = NULL;
	if(lista == NULL)
	{
		lista = nuevo;
	}
	else
	{
		for(aux = lista; aux->sig != NULL; aux = aux->sig);
		aux->sig = nuevo;	
	}
	return lista;
}

TipoNodoNombre * borar_cabeza(TipoNodoNombre *lista)
{
	TipoNodoNombre *aux;
	if(lista == NULL) return NULL;
	aux = lista->sig;
	free(lista);
	lista = aux;
	return lista;
}

TipoNodoNombre * borrar_cola(TipoNodoNombre *lista)
{
	TipoNodoNombre *prev, *aux;
	if(lista == NULL) return NULL;
	for(prev = NULL, aux = lista; aux->sig != NULL; prev = aux, aux = aux->sig);
	free(aux);
	if(prev == NULL) lista = NULL;
	else prev->sig = NULL;
	return lista;
}

int pertenece(TipoNodoNombre *lista, char *cadena)
{
	TipoNodoNombre *aux;
	for(aux = lista; aux != NULL; aux = aux->sig)
		if(!strcmp(aux->nombre, cadena))
			return 1;
	return 0;
}

TipoNodoNombre * borrar_primera_ocurrencia(TipoNodoNombre *lista, char *cadena)
{

}

TipoNodoNombre * borrar_valor(TipoNodoNombre *lista, char *cadena)
{

}

TipoNodoNombre * insertar_en_posicion(TipoNodoNombre *lista, int pos, char *cadena)
{

}

void modificar_valor_posicion(TipoNodoNombre *lista, int pos, char *cadena)
{
	TipoNodoNombre *aux;
	int i = 0;
	if(pos >= 0 && pos < longitud_lista(lista))
	{
		for(i = 0, aux = lista; i < pos;i++, aux = aux->sig);
		strcpy(aux->nombre, cadena);
	}
}

TipoNodoNombre * insertar_en_orden(TipoNodoNombre *lista, char *cadena)
{

}

TipoNodoNombre * concatenar_listas(TipoNodoNombre *a, TipoNodoNombre *b)
{

}

TipoNodoNombre * liberar_lista(TipoNodoNombre *lista)
{
	TipoNodoNombre *aux, *otroaux;
	aux = lista;
	while(aux != NULL){
		otroaux = aux->sig;
		free(aux);
		aux = otroaux;
	}
	return NULL;
}