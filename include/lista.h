/** @brief Funciones para la implementacion de una lista simplemente enlazada
*
* Funciones para trabajar con una lista enlazada simple de un campo de texto
* de tamano NODO_NOMBRE_MAX_LENGTH
*
* @file zanahoria.h
* @version 0.1
* @date 22/04/2012
* @author JesusGoku
* 
*/
#ifndef __LISTA_H__
#define __LISTA_H__

#define NODO_NOMBRE_MAX_LENGTH 50

/** @brief Estructura Nodo para almacenar un campo de texto */
typedef struct NodoNombre
{
	char nombre[NODO_NOMBRE_MAX_LENGTH + 1];
	struct NodoNombre *sig;
} TipoNodoNombre;

/** @brief Inicializa la lista a NULL */
TipoNodoNombre * lista_vacia();

/** @brief Verifica si la lista esta vacia
*
* @param lista puntero al primer nodo de la lista
*
* @return Retorna 1 para vacia y 0 para almenos un elemento
*/
int es_lista_vacia(TipoNodoNombre *lista);

/** @brief Inserta un nodo a la cabeza
*
* @param lista puntero al primer nodo de la lista
* @param cadena puntero a la cadena con la que se creara el nuevo nodo
*
* @return Retorna un puntero a la nueva cabeza de la lista
*/
TipoNodoNombre * insertar_por_cabeza(TipoNodoNombre *lista, char *cadena);

/** @brief Devuelve la cantidad de nodos de la lista
*
* @param lista puntero al primer nodo de la lista
*
* @return entero que representa al numero de nodos de la lista 
*/
int longitud_lista(TipoNodoNombre *lista);

/** @brief Inserta un nodo a la cola de la lista
*
* @param lista puntero al primer nodo de la lista
* @param cadena puntero a la cadena con la que se creara el nuevo nodo
*
* @return Retorna el mismo puntero lista o un puntero al nuevo elemento creada en caso de estar vacia
*/
TipoNodoNombre * insertar_por_cola(TipoNodoNombre *lista, char *cadena);

/** @brief Borra el primer nodo de la lista
*
* @param lista puntero al primer nodo de la lista
*
* @return puntero al nuevo primer elemento de la lista
*/
TipoNodoNombre * borar_cabeza(TipoNodoNombre *lista);

/** @brief Borra el ultimo elemento de la lista
*
* @param lista puntero al primer elemento de la lista
*
* @return Retorna el puntero lista o NULL en caso de haber un solo nodo
*/
TipoNodoNombre * borrar_cola(TipoNodoNombre *lista);

/** @brief Verifica si un valor pertenece a la lista
*
* @param lista puntero al primer nodo de la lista
* @param cadena puntero a la cadena que se desea verificar si es parte de algun nodo
*
* @return 1 si la cadena pertenece a algun nodo, 0 no pertenece
*/
int pertenece(TipoNodoNombre *lista, char *cadena);

/** @brief Borra la primera ocurrencia que coincida con cadena
*
* @param lista puntero al primer nodo de la lista
* @param cadena puntero a la cadena que se desea eliminar
*
* @return Devuelve un puntero al primer nodo de la lista
*/
TipoNodoNombre * borrar_primera_ocurrencia(TipoNodoNombre *lista, char *cadena);

/** @brief Borra todos los nodos que contengan cadena
*
* @param lista puntero al primer nodo de la lista
* @param cadena puntero a cadena con la cadena a buscar para eliminar nodo
*
* @return Retorno un puntero al primer nodo de la lista
*/
TipoNodoNombre * borrar_valor(TipoNodoNombre *lista, char *cadena);

/** @brief Inserta un nodo en una posicion especificada
*
* @param lista puntero al primer nodo de la lista
* @param pos entero que indica la posicion en la que se desea ingresar el elemento (0 es antes del primer elemento)
* @param cadena puntero a la cadena para crear el nuevo nodo
*
* @return Puntero al primer elemento de la lista
*/
TipoNodoNombre * insertar_en_posicion(TipoNodoNombre *lista, int pos, char *cadena);

/** @brief Modifica el valor de una posicion
*
* @param lista puntero al primer nodo de la lista
* @param pos entero a la posicion que se desea modifica (primer nodo posicion 0)
* @param cadena puntero a cadena con el valor nuevo para la posicion
*
*/
void modificar_valor_posicion(TipoNodoNombre *lista, int pos, char *cadena);

// TipoNodoNombre * insertar_en_orden(TipoNodoNombre *lista, char *cadena);

/** @brief Concatena dos listas en la primera
*
* @param a puntero a una lista de nodos
* @param b puntero a una lista de nodos
*
* @return retorna el puntero a ahora con b apuntado por el fin de el ultimo nodo de a
*/
TipoNodoNombre * concatenar_listas(TipoNodoNombre *a, TipoNodoNombre *b);

/** @brief Elimina todos los nodos de la lista
*
* @param lista puntero al primer nodo de la lista
*
* @return La funcion retorna NULL
*/
TipoNodoNombre * liberar_lista(TipoNodoNombre *lista);

#endif // __LISTA_H__