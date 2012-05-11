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
	TipoNodoNombre *aux, *prev;
	for(prev = NULL, aux = lista; aux != NULL; prev = aux, aux = aux->sig)
	{
		if(!strcmp(aux->nombre, cadena))
		{
			if(prev == NULL)
			{
				lista = aux->sig;
			}
			else
			{
				prev->sig = aux->sig;
			}
			free(aux);
			return(lista);
		}
	}
	return lista;
}

TipoNodoNombre * borrar_valor(TipoNodoNombre *lista, char *cadena)
{
	TipoNodoNombre *aux, *prev;
	prev = NULL;
	aux = lista;
	while(aux != NULL)
	{
		if(!strcmp(aux->nombre, cadena))
		{
			if(prev == NULL) lista = aux->sig;
			else prev->sig = aux->sig;

			free(aux);
			
			if(prev == NULL) aux = lista;
			else aux = prev->sig;
		}
		else
		{
			prev = aux;
			aux = aux->sig;
		}
	}
	return lista;
}

TipoNodoNombre * insertar_en_posicion(TipoNodoNombre *lista, int pos, char *cadena)
{
	TipoNodoNombre *aux, *prev, *nuevo;
	int i;

	nuevo = (TipoNodoNombre *)malloc(sizeof(TipoNodoNombre));
	strcpy(nuevo->nombre, cadena);

	for(i = 0, prev = NULL, aux = lista; i < pos && aux != NULL; i++, prev = NULL, aux = aux->sig);
	nuevo->sig = NULL;
	if(prev == NULL) lista = nuevo;
	else prev->sig = nuevo;
	return lista;
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

/*TipoNodoNombre * insertar_en_orden(TipoNodoNombre *lista, char *cadena)
{

}*/

TipoNodoNombre * concatenar_listas(TipoNodoNombre *a, TipoNodoNombre *b)
{
	TipoNodoNombre *c, *aux, *nuevo, *prev;
	c = NULL;
	prev = NULL;

	for(aux = a; aux != NULL; aux = aux->sig)
	{
		nuevo = (TipoNodoNombre *)malloc(sizeof(TipoNodoNombre));
		strcpy(nuevo->nombre, aux->nombre);
		if(prev != NULL) prev->sig = nuevo;
		else c = nuevo;
		prev = nuevo;
	}

	for(aux = b; aux != NULL; aux = aux->sig)
	{
		nuevo = (TipoNodoNombre *)malloc(sizeof(TipoNodoNombre));
		strcpy(nuevo->nombre, aux->nombre);
		if(prev != NULL) prev->sig = nuevo;
		else c = nuevo;
		prev = nuevo;
	}

	if(prev != NULL) prev->sig = NULL;
	return c;
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
