
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

#include "FuncionesCalculadora.h"

int main(void) {

	//Solción a un error de mi consola de eclipse, no se si es problema de mi pc con eclipse o de los proyectos que se crean, por las dudas lo pongo.
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char opcionElegidaDelMenu;
	float operandoA;
	float operandoB;
	float resultadoDeLaFuncionSuma;
	float resultadoDeLaFuncionResta;
	float resultadoDeLaFuncionDivision;
	float resultadoDeLaFuncionMultiplicacion;
	float resultadoFactorialA;
	float resultadoFactorialB;

	operandoA=0;
	operandoB=0;

	//Muestra menú hasta que se ingrese salir.
	do {
		limpiarPantalla();
		opcionElegidaDelMenu = verTextoDelMenu(operandoA, operandoB);

		//Menú opciones
		switch (opcionElegidaDelMenu) {

		//1)Pedir y guardar operandoA.
		case '1':

			limpiarPantalla();
			printf("1. Ingresar 1er operando (A=%.2f)\n", operandoA);
			scanf("%f", &operandoA);
			break;

			//2)Pedir y guardar operandoB.
		case '2':

			limpiarPantalla();

			printf("2. Ingresar 2do operando (B=%.2f)\n", operandoB);
			scanf("%f", &operandoB);
			break;

			//3)Calcular resultados fuera del main.
		case '3':

			resultadoDeLaFuncionSuma = sumar(operandoA, operandoB);

			resultadoDeLaFuncionResta = restar(operandoA, operandoB);

			resultadoDeLaFuncionDivision = dividir(operandoA, operandoB);

			resultadoDeLaFuncionMultiplicacion = multiplicar(operandoA,
					operandoB);

			resultadoFactorialA = factorizar(operandoA);

			resultadoFactorialB = factorizar(operandoB);

			break;

			//4)Envia los calculos a la funcion ImprimirResultados y verifica si son o no correctos.
		case '4':
			verResultados(operandoA, operandoB, resultadoDeLaFuncionSuma,
					resultadoDeLaFuncionResta, resultadoDeLaFuncionDivision,
					resultadoDeLaFuncionMultiplicacion, resultadoFactorialA,
					resultadoFactorialB);

			deseaContinuar("Presione 'enter' para continuar...","","");

			break;
		}

	} while (opcionElegidaDelMenu != '5'); //5)Verifica, si es un 5 sale.


}
