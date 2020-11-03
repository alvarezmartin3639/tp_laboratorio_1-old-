/*
 utest example : Unit test examples.
 Copyright (C) <2018>  <Mauricio Davila>

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node {
	void *pElement;
	struct Node *pNextNode;
}typedef Node;

struct LinkedList {
	Node *pFirstNode;
	int size;
}typedef LinkedList;
#endif


//Publicas
LinkedList* ll_newLinkedList(void);
//CUENTA LA CANTIDAD DE EMPLYOEE
int ll_len(LinkedList *this);
Node* test_getNode(LinkedList *this, int nodeIndex);
int test_addNode(LinkedList *this, int nodeIndex, void *pElement);
//AGREGA ELEMENTO A LA LISTA
int ll_add(LinkedList *this, void *pElement);
void* ll_get(LinkedList *this, int index);
//REMPLAZA UN ELEMENTO DE LA LISTA
int ll_set(LinkedList *this, int index, void *pElement);
//BORRA UN ELEMENTO DE LA LISTA
int ll_remove(LinkedList *this, int index);
//LIMPIA LA LISTA (NO BORRA EL ARCHIVO)
int ll_clear(LinkedList *this);
//BORRA EL ARCHIVO
int ll_deleteLinkedList(LinkedList *this);
//DEVUELVE EL INDICE DE UN ELEMENTO DETERMINADO
int ll_indexOf(LinkedList *this, void *pElement);
//SE FIJA SI LA LISTA ESTÁ VACIA
int ll_isEmpty(LinkedList *this);
//METE UN ELEMENTO ENTRE OTROS DOS
int ll_push(LinkedList *this, int index, void *pElement);
//ELIMINA UN DATO Y LO DEVUELVE (HAY QUE CASTEARLO PARA DARLE FORMA AL VOLVER)
void* ll_pop(LinkedList *this, int index);
//DICE SI EL ELEMENTO QUE LE PASO ESTÁ CONTENIDO (SI TIENE ESE ELEMENTO)
int ll_contains(LinkedList *this, void *pElement);
//DICE SI LA LISTA QUE PASO COMO SEGUNDO PARAMETRO ESTÁ CONTENIDA EN LA PRIMERA(SI TIENE TODOS LOS ELEMENTOS DE LA SEGUNDA LISTA)
int ll_containsAll(LinkedList *this, LinkedList *this2);
//DEVUELVE LA PORCION DE LISTA QUE YO LE DIGA DESDE (FROM) Y HASTA (TO)
LinkedList* ll_subList(LinkedList *this, int from, int to);
//DEVUELVE UNA NUEVA LISTA QUE ES UNA COPIA DE OTRA (THIS)
LinkedList* ll_clone(LinkedList *this);
//ORDENA LOS EMPLEADOS DE LA LISTA
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order);
