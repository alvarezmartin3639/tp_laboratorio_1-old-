/*
 ============================================================================
 Name        : TesteoCalculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int main(void) {

	char opcionElegidaDelMenu;
	float operandoA;
	float operandoB;
	float resultadoDeLaFuncionSuma;
	float resultadoDeLaFuncionResta;
	float resultadoDeLaFuncionDivision;
	float resultadoDeLaFuncionMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;

	//Muestra menú hasta que se ingrese salir.
	do {
		limpiarPantalla();
		opcionElegidaDelMenu = verTextoDelMenu(operandoA, operandoB);

		//Menú opciones
		switch (opcionElegidaDelMenu) {

		//1)Pedir y guardar operandoA.
		case '1':

			limpiarPantalla();
			printf("1. Ingresar 1er operando (A=%f)\n", operandoA);
			scanf("%f", &operandoA);
			break;

			//2)Pedir y guardar operandoB.
		case '2':

			limpiarPantalla();

			printf("2. Ingresar 2do operando (B=%f)\n", operandoB);
			scanf("%f", &operandoB);
			break;

			//3)Calcular resultados fuera del main.
		case '3':

			resultadoDeLaFuncionSuma = Sumar(operandoA, operandoB);

			resultadoDeLaFuncionResta = Restar(operandoA, operandoB);

			resultadoDeLaFuncionDivision = Dividir(operandoA, operandoB);

			resultadoDeLaFuncionMultiplicacion = Multiplicar(operandoA,
					operandoB);

			resultadoFactorialA = Factorizar(operandoA);

			resultadoFactorialB = Factorizar(operandoB);

			break;

			//4)Envia los calculos a la funcion ImprimirResultados y verifica si son o no correctos.
		case '4':
			verResultados(operandoA, operandoB, resultadoDeLaFuncionSuma,
					resultadoDeLaFuncionResta, resultadoDeLaFuncionDivision,
					resultadoDeLaFuncionMultiplicacion, resultadoFactorialA,
					resultadoFactorialB);

			IngreseEnterParaContinuar();

			break;
		}

	} while (opcionElegidaDelMenu != '5'); //5)Verifica, si es un 5 sale.

	return EXIT_SUCCESS;
}
