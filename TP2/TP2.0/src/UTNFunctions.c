/*
 * UTNFunctions.c
 *
 *  Created on: 16 may. 2020
 *      Author: kenyn
 */

#include "UTNFunctions.h"

#include <stdio.h>
#include <string.h>
#include <winbase.h>
#include <wingdi.h>


#define OK 0
#define ACCEPTED -2
#define NOACCEPTED -333
/**
 * \brief Soluciona error dentro de eclipse
 *
 * \param void
 * \return void
 */

void SolucionErrorDeConsola() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

/**
 * \brief Simular una limpieza de pantalla agregando espacios en blanco.
 *
 * \param void
 * return void
 */

void limpiarPantalla() {
	printf("\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n\n \n\n \n\n \n\n");
}

/**
 * \brief Crea una validación con dos arrays uno para continuar y otro para salir.
 *
 * \param char mensaje[]				   El mensaje para imprimir al usuario.
 * \param char condicionParaContinuar[]    La condicion para confirmar el mensaje.
 * \param char condicionParaSalir[]		   La condicion para rechazar el mensaje y salir del bucle.
 * \return -2   						   Cuando el usuario aceptó(Eligio condicionParaContinuar).
 * \return -333                            Cuando el usuario rechazó(Eligio condicionParaSalir).
 */

int choseBetweenTwoOptions(char mensaje[], char condicionParaContinuar[],
		char condicionParaSalir[]) {

	int retorno;
	char respuestaUsuario[66];

	do {
		puts(mensaje);
		fflush(stdin);
		gets(respuestaUsuario);
	} while ((strcmp(condicionParaContinuar, respuestaUsuario) != 0)
			&& (strcmp(condicionParaSalir, respuestaUsuario) != 0));

	//Si ingresó correctamente la condicion para continuar retorná 1, sinó 0(si no ingresó el de continuar, ingresó el de salir).
	if (strcmp(condicionParaContinuar, respuestaUsuario) == 0) {
		retorno = ACCEPTED;
	} else {
		retorno = NOACCEPTED;
	}
	return retorno;
}

/**
 * \brief Hace esperar al usuario tres segundos
 *
 * \param char mensaje[]				   El mensaje para imprimir al usuario.
 * \return void
 */

void textAndSleep(char *mensaje, int sleepTime) {

	puts(mensaje);
	Sleep(sleepTime);

}

//Validaciones.

/**
 * \brief Valida un valor numerico.
 *
 * \param int *pResultado                  Puntero a la variable donde guardar el numero validado.
 * \param char *mensaje	                   El mensaje para imprimir al usuario.
 * \param char *mensajeError               El mensaje a mostrar si la validacion fue incorrecta.
 * \return -2                    	       Cuando la validación fue correcta.
 * \return -333                            Cuando la validación fue incorrecta.
 */
int getInt(int *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = ERROR;
	int bufferInt;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if (bufferInt >= minimo && bufferInt <= maximo) {
				*pResultado = bufferInt;
				retorno = OK;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Valida una palabra o letra.
 *
 * \param char *pResultado                 Puntero a la variable donde guardar el char validado.
 * \param char *mensaje	                   El mensaje para imprimir al usuario.
 * \param char *mensajeError               El mensaje a mostrar si la validacion fue incorrecta.
 * \return 	-2						       Cuando la validación fue correcta.
 * \return -333                             Cuando la validación fue incorrecta.
 */

int getChar(char *pResultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos) {
	int retorno = ERROR;
	char bufferChar;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);
			if (bufferChar >= minimo && bufferChar <= maximo) {
				*pResultado = bufferChar;
				retorno = OK;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		} while (reintentos >= 0);

	}
	return retorno;
}

/**
 * \brief Valida un numero decimal.
 *
 * \param float *pResultado                Puntero a la variable donde guardar el char validado.
 * \param char *mensaje	                   El mensaje para imprimir al usuario.
 * \param char *mensajeError               El mensaje a mostrar si la validacion fue incorrecta.
 * \return -2							   Cuando la validación fue correcta.
 * \return -333                            Cuando la validación fue incorrecta.
 */

int getFloat(float *pResultado, char *mensaje, char *mensajeError, int minimo,
		int maximo, int reintentos) {
	int retorno = ERROR;
	float bufferFloat;
	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {
		do {
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if (bufferFloat >= minimo && bufferFloat <= maximo) {
				*pResultado = bufferFloat;
				retorno = OK;
				break;
			} else {
				printf("%s", mensajeError);
				reintentos--;
			}
		} while (reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Valida un numero decimal.
 *
 * \param float *pResultado                Puntero a la variable donde guardar el char validado.
 * \param char *mensaje	                   El mensaje para imprimir al usuario.
 * \param char *mensajeError               El mensaje a mostrar si la validacion fue incorrecta.
 * \return -2							   Cuando la validación fue correcta.
 * \return -333                            Cuando la validación fue incorrecta.
 */
void fgetsComprimido(char *pResultado, char *mensaje, int cantidadDeLetras) {


	puts(mensaje);
	fflush(stdin);
	fgets(pResultado, cantidadDeLetras, stdin);
	pResultado[strlen(pResultado) - 1] = '\0';

}

/**
 * \brief Valida un numero decimal.
 *
 * \param float *pResultado                Puntero a la variable donde guardar el char validado.
 * \param char *mensaje	                   El mensaje para imprimir al usuario.
 * \param char *mensajeError               El mensaje a mostrar si la validacion fue incorrecta.
 * \return -2							   Cuando la validación fue correcta.
 * \return -333                            Cuando la validación fue incorrecta.
 */

int confirmacionDeCambios()
{
	int respuestaDeseaContinuar;
	int retorno;
	respuestaDeseaContinuar = choseBetweenTwoOptions(
			      "\n\n-------------------------------------------------"
					"\nESTOS CAMBIOS NO SE PUEDEN DESHACER, ESTÁ SEGURO "
					"\nQUE DESEA CONTINUAR?(si/no)"
					"\n-------------------------------------------------",
					"si","no");

	if (respuestaDeseaContinuar == ACCEPTED) {

		retorno = ACCEPTED;
	}
	if (respuestaDeseaContinuar == NOACCEPTED) {

		limpiarPantalla();
		textAndSleep(
				"\n\n -------------------------------------------------------"
				  "\n|CAMBIOS NO GUARDADOS!!!, será redirigido en 5 segundos.|"
				  "\n -------------------------------------------------------",
				  5000);
		retorno = NOACCEPTED;
	}

	return retorno;
}
