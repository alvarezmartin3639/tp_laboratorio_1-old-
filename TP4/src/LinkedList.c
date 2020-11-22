#include "../inc/LinkedList.h"

#include <stdio.h>
#include <stdlib.h>

static Node* getNode(LinkedList *this, int nodeIndex);
static int addNode(LinkedList *this, int nodeIndex, void *pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void) {
	LinkedList *this = NULL;

	this = (LinkedList*) malloc(sizeof(LinkedList));
	if (this != NULL) { //SI EL PUNTERO NO ES NULL CREO UN LINKEDLIST SIN INICIALIZAR
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		returnAux = this->size;
	}
	return returnAux;
}

/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList *this, int nodeIndex) {

	Node *auxNodo = NULL;
	int i;

	if (this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this)) { //VERIFICO ERRORES, DESPUES COPIO DONDE APUNTA LA LOCOMOTORA(EL PRIMER NODO) AL AUXILIAR
		auxNodo = this->pFirstNode;

		for (i = 0; i < nodeIndex; i++) { //CON LA DIRECCION DE MEMORIA DEL PRIMER NODO PUEDO IR RECORRIENDOLOS HASTA LLEGAR AL INDICE DEL NODO PEDIDO
			auxNodo = auxNodo->pNextNode;

		}
	}

	return auxNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList *this, int nodeIndex) {
	return getNode(this, nodeIndex);
}

/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList *this, int nodeIndex, void *pElement) {
	int returnAux = -1;

	Node *nodeAnterior;
	Node *nodeNuevo = NULL;
	Node *nodeSiguiente;

	if (this == NULL || nodeIndex < 0 //VERIFICO ERRORES
	|| nodeIndex > ll_len(this)) {
		return -1;
	} else { //VERIFICO LOS ESCENARIOS POSIBLES

		nodeNuevo = (Node*) malloc(sizeof(Node)); //CREO EL NUEVO NODE, SUMO UNO AL SIZE DE LA LOCOMOTORA Y CAMBIO EL RETURN
		nodeNuevo->pElement = pElement;
		this->size++;
		returnAux = 0;

		if (nodeIndex == 0) { //CUANDO EL INDICE ES EL PRIMER NODO,
			nodeNuevo->pNextNode = this->pFirstNode;
			this->pFirstNode = nodeNuevo;

		} else {
			nodeAnterior = getNode(this, nodeIndex - 1); //CREO EL NODE ANTERIOR Y LO ENGANCHO AL NUEVO
			nodeAnterior->pNextNode = nodeNuevo;

			if (nodeIndex == ll_len(this)) { //SI EL USUARIO QUIERE AGREGAR EL NUEVO NODE A LA ULTIMA POSICION
				nodeNuevo->pNextNode = NULL;

			} else { // ESTO SERIA PUSH?
				nodeSiguiente = getNode(this, nodeIndex + 1);
				nodeNuevo->pNextNode = nodeSiguiente; //ENGANCHO EL NUEVO AL SIGUIENTE
			}
		}
	}

	return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList *this, int nodeIndex, void *pElement) {
	return addNode(this, nodeIndex, pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this == NULL) {
		return -1;
	}

	if (addNode(this, ll_len(this), pElement) == 0) {
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Retorna un puntero al elemento que se encuentra en el indice especificiado
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList *this, int index) {
	void *returnAux = NULL;
	Node *auxNode = NULL;

	if (index >= 0 && this != NULL && index < ll_len(this)) {
		auxNode = (Node*) getNode(this, index);

		if (auxNode != NULL) {
			returnAux = (void*) auxNode->pElement;
		}
	}

	return returnAux;
}

/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;
	Node *nodeParaModificar;

	if (this == NULL || index < 0 //VERIFICO ERRORES
	|| index > ll_len(this)) {
		return -1;
	}

	nodeParaModificar = getNode(this, index); //TRAIGO EL NODE
	if (nodeParaModificar == NULL) {
		return -1;
	}

	nodeParaModificar->pElement = pElement; //LO MODIFICO
	returnAux = 0;

	return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList *this, int index) {
	int returnAux = -1;
	int lenNodeAntes;
	Node *nodeParaEliminar;
	Node *nodeAnterior;
	Node *nodePosterior;

	if (this == NULL || index < 0 //VERIFICO ERRORES
	|| index > ll_len(this)) {
		return -1;
	}

	lenNodeAntes = ll_len(this); //CUENTO Y TRAIGO EL NODE
	nodeParaEliminar = getNode(this, index);

	if (nodeParaEliminar != NULL) {
		if (index == 0) { //SI ES EL PRIMERO
			nodePosterior = getNode(this, index + 1);
			this->pFirstNode = nodePosterior; // PONER NULL LO BORRA?
			this->size--;

		} else {

			if (lenNodeAntes == index) { //SI ES EL ULTIMO
				nodeAnterior = getNode(this, index - 1);
				nodeAnterior->pNextNode = NULL;

			} else { //SI ES UNO DEL MEDIO
				nodeAnterior = getNode(this, index - 1);
				nodePosterior = getNode(this, index + 1);
				nodeAnterior->pNextNode = nodePosterior;
			}

			free(nodeParaEliminar);
			this->size--;
		}

		if (lenNodeAntes > ll_len(this)) { //SI SE ACHICO LA LISTA CAMBIO EL RETURN
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList *this) {
	int returnAux = -1;

	int i;

	if (this != NULL) {

		for (i = 0; i < ll_len(this); i++) { //RECORRO Y BORRO LA LISTA MEDIANDE INDICE
			ll_remove(this, i);
		}
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {
		ll_clear(this); //BORRO LA LISTA
		free(this); //BORRO LINKEDLIST
		returnAux = 0;
	}

	return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList *this, void *pElement) {
	int returnAux = -1;
	int i;
	int len;
	void *auxpElement;

	if (this != NULL) {
		len = ll_len(this);

		if (len > 0) {
			for (i = 0; i < len; i++) { //RECORRO LA LINKEDLIST
				auxpElement = ll_get(this, i);
				if (auxpElement == pElement) { //COMPARO EL NODO EN I CON pElement
					returnAux = i;
					break; //POR SI EXISTEN MAS DE UNA OCURRENCIA
				}
			}
		}
	}
	return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 0) Si la lista NO esta vacia
 ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList *this) {
	int returnAux = -1;

	if (this != NULL) {

		if (ll_len(this) == 0) { //SI NO EXISTEN NODOS
			returnAux = 1;
		} else {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList *this, int index, void *pElement) {
	int returnAux = -1;

	if (index >= 0 && index <= ll_len(this) && this != NULL) { //PENSAR PORQUE IMPORTA EL =

		returnAux = addNode(this, index, pElement);

		if (returnAux != -1) {
			returnAux = 0;
		}
	}

	return returnAux;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
 (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList *this, int index) {
	void *returnAux = NULL;

	if (this != NULL && index >= 0 && index < ll_len(this)) {
		returnAux = ll_get(this, index);
		ll_remove(this, index);

	}

	return returnAux;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
 ( 1) Si contiene el elemento
 ( 0) si No contiene el elemento
 */
int ll_contains(LinkedList *this, void *pElement) {
	int returnAux = -1;

	if (this != NULL) {
		if (ll_indexOf(this, pElement) != -1) { //SI INDEXOF NO DA ERROR ES QUE EXISTE
			returnAux = 1;

		} else {
			returnAux = 0;

		}
	}

	return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
 estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
 ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
 ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
 */
int ll_containsAll(LinkedList *this, LinkedList *this2) {
	int returnAux = -1;
	void *auxpElementDos;
	int i;
	int retornoContain;

	if (this == NULL || this2 == NULL) {
		return returnAux;
	}

	returnAux = 1; //SETTEO QUE ESTÁ CONTENIDO

	for (i = 0; i < ll_len(this2); i++) { //BUSCO LOS ELEMENTOS DE LA LISTA 2(THIS2) EN LA LISTA 1(THIS)
		auxpElementDos = ll_get(this2, i);
		retornoContain = ll_contains(this, auxpElementDos);

		if (retornoContain == 0) {	//SI NO ESTÁ CONTENIDO
			returnAux = 0;
			break;
		}
	}

	return returnAux;
}
/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 o (si el indice from es menor a 0 o mayor al len de la lista)
 o (si el indice to es menor o igual a from o mayor al len de la lista)
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_subList(LinkedList *this, int from, int to) {
	LinkedList *cloneArray = NULL;
	Node *auxNode = NULL;
	int i;

	if (this != NULL && from >= 0 && from <= ll_len(this) && to >= 0
			&& to <= ll_len(this)) {

		cloneArray = ll_newLinkedList(); //CREO LA LISTA
		for (i = from; i < to; i++) { // RECORRO LO QUE LA LLAMADA DICE,LO COPIO EN UN AUXILIAR Y LO AGREGO A LA LISTA CREADA
			auxNode = getNode(this, i);
			if (auxNode != NULL) {
				ll_add(cloneArray, auxNode->pElement);
			}
		}
	}

	return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
 (puntero a la nueva lista) Si ok
 */
LinkedList* ll_clone(LinkedList *this) {
	LinkedList *cloneArray = NULL;

	if (this != NULL) {
		cloneArray = ll_newLinkedList(); //CREO LA LISTA
		cloneArray = this; //PEGO LA LISTA EN LA NUEVA LISTA (COMO ES UN PUNTERO SE COPIA LA DIRECCION)
	}

	return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
 ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	int i;
	int j;
	int len;
	void *auxpElementI = NULL;
	void *auxpElementJ = NULL;

	if (this != NULL && (order == 1 || order == 0) && pFunc != NULL) {
		len = ll_len(this);

		if (order == 1) {
			for (i = 0; i < len - 1; i++) { //RECORRO LA LISTA BUSCANDO NODOS
				for (j = i + 1; j < len; j++) {

					auxpElementI = ll_get(this, i); //GUARDO LOS VALORES DE LOS NODOS PARA COMPARAR
					auxpElementJ = ll_get(this, j);

					if (pFunc(auxpElementI, auxpElementJ) > 0) { //LOS COMPARO Y SI ES MAYOR LOS ORDENO
						ll_set(this, i, auxpElementJ);
						ll_set(this, j, auxpElementI);
					}
				}
			}
			returnAux = 0;
		}

		if (order == 0) {
			for (i = 0; i < len - 1; i++) { //RECORRO LA LISTA BUSCANDO NODOS
				for (j = i + 1; j < len; j++) {

					auxpElementI = ll_get(this, i); //GUARDO LOS VALORES DE LOS NODOS PARA COMPARAR
					auxpElementJ = ll_get(this, j);

					if (pFunc(auxpElementI, auxpElementJ) < 0) { //LOS COMPARO Y SI ES M LOS ORDENO
						ll_set(this, i, auxpElementJ);
						ll_set(this, j, auxpElementI);
					}
				}
			}

			returnAux = 0;
		}
	}

	return returnAux;

}

