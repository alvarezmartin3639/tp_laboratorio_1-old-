/*
 * FuncionesGenerales.c
 *
 *  Created on: 22 sep. 2020
 *      Author: kenyn
 */

#include "FuncionesGenerales.h"

#include <conio.h>
#include <stdio.h>
#include <string.h>

/**
 * @brief Soluciona error dentro de eclipse
 *
 * @param void
 *
 * @return void
 */

void SolucionErrorDeConsola() {

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
}

/**
 * @brief simula un limpiado de la pantalla
 *
 * @param void
 *
 * @return void
 */

void LimpiarPantalla() {
	printf("\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n \n\n");
}

/**
 * @brief Crea una validación con dos arrays uno para continuar y otro para salir.
 *
 * @param char mensaje[]				   El mensaje para imprimir al usuario.
 * @param char condicionParaContinuar[]    La condicion para confirmar el mensaje.
 * @param char condicionParaSalir[]		   La condicion para rechazar el mensaje y salir del bucle.
 *
 * @return 1   						   Cuando el usuario aceptó(Eligio condicionParaContinuar).
 * @return 0                            Cuando el usuario rechazó(Eligio condicionParaSalir).
 */

int ElejirEntreDosOpciones(char mensaje[], char condicionParaContinuar[],
		char condicionParaSalir[]) {

	int retorno;
	char respuestaUsuario[66];

	do {
		FgetsComprimido(respuestaUsuario, mensaje, 55);
	} while ((strcmp(condicionParaContinuar, respuestaUsuario) != 0)
			&& (strcmp(condicionParaSalir, respuestaUsuario) != 0));

	//Si ingresó correctamente la condicion para continuar retorná 1, sinó 0(si no ingresó el de continuar, ingresó el de salir).
	if (strcmp(condicionParaContinuar, respuestaUsuario) == 0) {
		retorno = 1;
	} else {
		retorno = 2;
	}
	return retorno;
}

/**
 * @brief crea una validación con dos arrays uno para continuar y otro para salir.
 *
 * @param pResultado
 * @param mensaje
 * @param opcionUno
 * @param opcionDos
 *
 * @return
 */

int elejirEntreDosOpcionesConPuntero(char *pResultado, char *mensaje,
		char opcionUno[], char opcionDos[]) {
	int retorno = ERROR;
	char respuestaUsuario[66];

	do {
		FgetsComprimido(respuestaUsuario, mensaje, 55);
	} while ((strcmp(opcionUno, respuestaUsuario) != 0)
			&& (strcmp(opcionDos, respuestaUsuario) != 0));

	//Si ingresó correctamente la condicion para continuar retorná 1, sinó 0(si no ingresó el de continuar, ingresó el de salir).
	if (strcmp(opcionUno, respuestaUsuario) == 0) {
		retorno = 1;

	} else {
		retorno = 2;
	}

	strcpy(pResultado, respuestaUsuario);

	return retorno;
}

/**
 * @brief imprime un texto para confirmar cambios y devuelve un valor numerico
 * dependiendo si acepto o no
 *
 * @param void
 *
 * @return int retorno   La respuesta del usuario.
 */

int ConfirmacionDeCambios() {
	int respuestaDeseaContinuar;
	int retorno;
	respuestaDeseaContinuar = ElejirEntreDosOpciones(
			"\n\n-------------------------------------------------"
					"\nESTOS CAMBIOS NO SE PUEDEN DESHACER, ESTÁ SEGURO "
					"\nQUE DESEA CONTINUAR?(si/no)"
					"\n-------------------------------------------------", "si",
			"no");

	if (respuestaDeseaContinuar == ACEPTO) {

		retorno = ACEPTO;
	}
	if (respuestaDeseaContinuar == NOACEPTO) {

		LimpiarPantalla();
		ElejirEntreDosOpciones(
				"\n****Cambios no guardados, presione 'ENTER' para continuar.****",
				"", "exit");
		retorno = NOACEPTO;
	}

	return retorno;
}

/**
 * @brief cuenta la cantidad de caracteres que tiene un entero
 *
 * @return contador
 */

int ContarCaracteresDeUnEntero() {

	int num;
	int contador;

	contador = 1;
	printf(
			"Este programa te va a decir cuantos digitos tiene un numero. Introduce uno: ");
	scanf("%d", &num);

	while (num / 10 > 0) {
		num = num / 10;
		contador++;
	}
	printf("Tiene %u caracteres", contador);
	getch();
	return contador;

}

/**
 * @brief imprime un texto pidiendo que presionen 'enter' hasta que el usuario lo presione
 *
 * @return void
 */

void PresionarEnterParaContinuar() {

	char bufferUsuario[10];
	do {
		FgetsComprimido(bufferUsuario,
				"\n****Presione 'enter' para continuar*****", 10);

	} while (strcmp(bufferUsuario, "") != 0);

}

