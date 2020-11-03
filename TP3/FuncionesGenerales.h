/*
 * FuncionesGenerales.h
 *
 *  Created on: 22 sep. 2020
 *      Author: kenyn
 */

#ifndef FUNCIONESGENERALES_H_
#define FUNCIONESGENERALES_H_

#include "Cadenas.h"
#include "Validaciones.h"

#define TMASCOTAS 10
#define TRAZAS 10
#define TPAISES 10
#define OK 1
#define ACEPTO 1
#define NOACEPTO 0
#define OPCIONUNO 1
#define OPCIONDOS 0
#define LIBRE 0
#define BAD 0
#define OCUPADO 1
#define ERROR -666
#define INDIFERENTE -1


int ElejirEntreDosOpciones(char mensaje[], char condicionParaContinuar[],
		char condicionParaSalir[]);

int elejirEntreDosOpcionesConPuntero(char *pResultado, char *mensaje,
		char opcionUno[], char opcionDos[]);

//void textAndSleep(char *mensaje, int sleepTime);

void SolucionErrorDeConsola();

void LimpiarPantalla();

int ConfirmacionDeCambios();

int ContarCaracteresDeUnEntero();

int ContarCaracteresDeUnFlotante(float num);

void PresionarEnterParaContinuar();

#endif /* FUNCIONESGENERALES_H_ */
