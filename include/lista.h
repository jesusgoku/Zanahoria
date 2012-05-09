#ifndef __LISTA_H__
#define __LISTA_H__

#define NODO_NOMBRE_MAX_LENGTH 50

typedef struct NodoNombre
{
	char nombre[NODO_NOMBRE_MAX_LENGTH + 1];
	struct NodoNombre *sig;
} TipoNodoNombre;

TipoNodoNombre * lista_vacia();

int es_lista_vacia(TipoNodoNombre *lista);

TipoNodoNombre * insertar_por_cabeza(TipoNodoNombre *lista, char *cadena);

int longitud_lista(TipoNodoNombre *lista);

TipoNodoNombre * insertar_por_cola(TipoNodoNombre *lista, char *cadena);

TipoNodoNombre * borar_cabeza(TipoNodoNombre *lista);

TipoNodoNombre * borrar_cola(TipoNodoNombre *lista);

int pertenece(TipoNodoNombre *lista, char *cadena);

TipoNodoNombre * borrar_primera_ocurrencia(TipoNodoNombre *lista, char *cadena);

TipoNodoNombre * borrar_valor(TipoNodoNombre *lista, char *cadena);

TipoNodoNombre * insertar_en_posicion(TipoNodoNombre *lista, int pos, char *cadena);

void modificar_valor_posicion(TipoNodoNombre *lista, int pos, char *cadena);

TipoNodoNombre * insertar_en_orden(TipoNodoNombre *lista, char *cadena);

TipoNodoNombre * concatenar_listas(TipoNodoNombre *a, TipoNodoNombre *b);

TipoNodoNombre * liberar_lista(TipoNodoNombre *lista);

#endif // __LISTA_H__