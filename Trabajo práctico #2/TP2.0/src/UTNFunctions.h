/*
 * FuncionesGenerales.h
 *
 *  Created on: 28 abr. 2020
 *      Author: kenyn
 */

#ifndef UTN_FUNCIONESPROPIAS_H_
#define UTN_FUNCIONESPROPIAS_H_

int choseBetweenTwoOptions(char mensaje[], char condicionParaContinuar[],
		char condicionParaSalir[]);

void textAndSleep(char *mensaje, int sleepTime);

void SolucionErrorDeConsola();

void limpiarPantalla();

int getChar(char *pResultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos);

int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

int getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos);

void fgetsComprimido(char *pResultado, char *mensaje, int cantidadDeLetras);

int confirmacionDeCambios();


#endif /* UTN_FUNCIONESPROPIAS_H_ */
