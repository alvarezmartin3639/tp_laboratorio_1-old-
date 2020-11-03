/*
 * Validaciones.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cadenas.h"
#include "FuncionesGenerales.h"

int GetChar(char *pResultado, char *mensaje, char *mensajeError,
		char condicionUno, char condicionDos, int reintentos) {

	do {
		char auxPresultado;
		int retorno = ERROR;

		printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &auxPresultado);

		if (auxPresultado == condicionUno || auxPresultado == condicionDos) {
			*pResultado = auxPresultado;
			retorno = 0;
			return retorno;
		} else {

			printf("\n\n****%s, quedan %d reintentos****\n", mensajeError,
					reintentos);
			reintentos--;
		}
	} while (reintentos >= 0);

	printf(
			"\n\n****Se acabaron los reintentos vuelva a intentarlo mas tarde.****");
	return reintentos;
}

/**
 * @brief muestra un mensaje ingresado en *mensaje, lo valida por int y si no hay errores
 * lo remplaza a la variable ingresada en el puntero *pResultado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 *
 * @return retorno
 *
 */

int GetInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {

	int auxPresultado;
	int retorno = ERROR;
	char deseaContinuar = 'y';

	do {

		printf("%s", mensaje);

		if (scanf("%d", &auxPresultado) == 1) {

			*pResultado = auxPresultado;

			retorno = OK;
			return retorno;

		} else {

			printf(
					"\n****%s, tiene que ser un numero mayor que %d y menor que %d, quedan %d reintentos****",
					mensajeError, minimo, maximo, reintentos);
			GetChar(&deseaContinuar, "\nDesea continuar?(y/n): ",
					"Error las opciones validas son 'y' 'n'", 'y', 'n', 2);
			reintentos--;
		}

	} while (deseaContinuar == 'y' && reintentos != 0);

	printf("****Se acabaron los reintentos, vuelva a intentarlo mas tarde****");

	return reintentos;
}

/**
 * @brief muestra un mensaje ingresado en *mensaje, lo valida por char y si no hay errores
 * lo remplaza a la variable ingresada en el puntero *pResultado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 *
 * @return retorno
 */

int GetString(char *pResultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos) {

	do {
		int contadorDeCharsValidados;
		int i;
		char auxPresultado[40];
		int cantidadChars;
		int retorno = ERROR;

		contadorDeCharsValidados = 0;

		FgetsComprimido(auxPresultado, mensaje, 100);
		cantidadChars = strlen(auxPresultado);

		for (i = 0; i < cantidadChars; i++) {
			if (((auxPresultado[i] >= 65 && auxPresultado[i] <= 90)
					|| (auxPresultado[i] >= 97 && auxPresultado[i] <= 122))
					&& pResultado != NULL && mensaje != NULL
					&& mensajeError != NULL && reintentos >= 0) {

				contadorDeCharsValidados++;
			}
		}
		if (cantidadChars == contadorDeCharsValidados) {
			strcpy(pResultado, auxPresultado);
			retorno = 0;
			return retorno;
		} else {

			printf(
					"\n\n****%s solo letras entre la '%c' a la '%c', quedan %d reintentos****\n",
					mensajeError, minimo, maximo, reintentos);
			reintentos--;
		}
	} while (reintentos >= 0);

	printf(
			"\n\n****Se acabaron los reintentos vuelva a intentarlo mas tarde.****");
	return reintentos;
}

/**
 * @brief muestra un mensaje ingresado en *mensaje, lo valida por flotante y si no hay errores
 * lo remplaza a la variable ingresada en el puntero *pResultado
 *
 * @param pResultado
 * @param mensaje
 * @param mensajeError
 * @param minimo
 * @param maximo
 * @param reintentos
 *
 * @return retorno
 */

int GetFloat(float *pResultado, char *mensaje, char *mensajeError, float minimo,
		float maximo, int reintentos) {

	char buffer[100];
	double value;
	char *endptr;
	int retorno = ERROR;

	fgets(buffer, sizeof(buffer), stdin);

	do {
		printf("\n%s", mensaje);
		fgets(buffer, sizeof(buffer), stdin);

		if (buffer == NULL) {
			return retorno; /* Unexpected error */
		}

		value = strtod(buffer, &endptr);
		if (((*endptr == '\0') || (isspace(*endptr) != 0))
				&& (value - (int) value != 0) && minimo <= maximo
				&& reintentos >= 0) {
			*pResultado = value;

			retorno = ERROR;
			return retorno;

		} else {
			printf(
					"\n\n****%s, elija un numero decimal con un '.', entre %f y %f, quedan %d reintentos****\n",
					mensajeError, minimo, maximo, reintentos);
			reintentos--;
		}

	} while (reintentos >= 0);

	printf(
			"\n\n****Se acabaron los reintentos vuelva a intentarlo mas tarde.****");
	return ERROR;

}

/**
 *
 * @param variable
 * @return
 */

int ValidarInt(int variable) {

	if (variable > 0 && !isalpha(variable)) {
		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

/**
 *
 * @param variable
 * @return
 */

int ValidarFloat(float variable) {

	if (variable > 0 && !isalpha(variable)) {

		if (variable - (int) variable != 0) {
			return EXIT_SUCCESS;
		}

	}

	return EXIT_FAILURE;
}

/**
 *
 * @param variable
 * @param cantChars
 * @return
 */

int ValidarString(char variable[], int cantChars) {

	int contadorDeCharsValidados;
	int i;
	int cantidadChars;

	contadorDeCharsValidados = 0;

	cantidadChars = strlen(variable);

	for (i = 0; i < cantidadChars; i++) {
		if ((variable[i] >= 65 && variable[i] <= 90)
				|| ((variable[i] >= 97 && variable[i] <= 122)
						&& variable != NULL)) {
			contadorDeCharsValidados++;
		}
	}

	if (cantidadChars == contadorDeCharsValidados) {
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
