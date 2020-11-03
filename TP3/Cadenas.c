/*
 * Cadenas.c
 *
 *  Created on: 19 sep. 2020
 *      Author: kenyn
 */

#include "Cadenas.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief imprime texto ingresado en la mascota a la función, captura lo ingresado en fgets y
 * elimina el \n
 *
 * @param pResultado
 * @param mensaje
 * @param cantidadDeLetras
 *
 * @return void
 */

void FgetsComprimido(char *pResultado, char *mensaje, int cantidadDeLetras) {

	printf("\n%s", mensaje);
	fflush(stdin);
	fgets(pResultado, cantidadDeLetras, stdin);
	pResultado[strlen(pResultado) - 1] = '\0';

}

/**
 * @brief convierte en mayusculas el string ingresado en el parametro cadena[]
 *
 * @param cadena
 * @param tam
 * @return void
 */

void ConvertirTodoMayuscula(char cadena[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		cadena[i] = toupper(cadena[i]);
	}
}

/**
 * @brief convierte en minusculas el string ingresado en el parametro cadena[]
 *
 * @param cadena
 * @param tam
 * @return void
 */

void ConvertirTodoMinuscula(char cadena[], int tam) {
	int i;

	for (i = 0; i < tam; i++) {
		cadena[i] = tolower(cadena[i]);
	}
}

/**
 * @brief Convierte en mayuscula la primera letra del parametro cadena[],
 * detecta espacios y convierte en mayusculas la siguiente letra
 *
 * @param cadena
 * @param tam
 *
 * @return void
 */

void ConvertirPrimerLetraEnMayuscula(char cadena[], int tam) {

	int i;

	ConvertirTodoMinuscula(cadena, tam);

	cadena[0] = toupper(cadena[0]);

	for (i = 0; i < tam; i++) {
		if (cadena[i] == ' ') {
			cadena[i + 1] = toupper(cadena[i + 1]);
		}
	}

}

/**
 * @brief repite la cadena del parametro mensajeParaRepetir[] la cantidad de veces
 * que diga el parametro numeroDeVecesParaRepetir[]
 *
 * @param mensajeParaRepetir
 * @param numeroDeVecesParaRepetir
 *
 * @return void
 */

void RepetirCadena(char mensajeParaRepetir[], int numeroDeVecesParaRepetir) {

	int contadorDeRepeticiones;

	contadorDeRepeticiones = 0;

	while (contadorDeRepeticiones != numeroDeVecesParaRepetir) {
		puts(mensajeParaRepetir);
		contadorDeRepeticiones++;
	}
}
