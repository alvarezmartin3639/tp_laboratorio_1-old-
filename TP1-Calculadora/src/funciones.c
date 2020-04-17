/*
 * funciones.c
 *
 *  Created on: Apr 14, 2020
 *      Author: martin
 */
#include  <stdio_ext.h>

/**\brief Muestra el menú y scanea lo escrito
 *
 * \param float operandoA Numero ingresado en menú 1 (operandoA).
 * \param float operandoB Numero ingresado en menú 2 (operandoB).
 * \return char con la opcion elegida por el usuario

 */

char verTextoDelMenu(float operandoA, float operandoB) {

	char opcion;

	printf("1. Ingresar 1er operando (A=%.2f)\n", operandoA);
	printf("2. Ingresar 2do operando (B=%.2f)\n", operandoB);
	printf("3. Calcular todas las operaciones\n");
	printf("   a) Calcular la suma (A+B)\n");
	printf("   b) Calcular la resta (A-B)\n");
	printf("   c) Calcular la division (A/B)\n");
	printf("   d) Calcular la multiplicacion (A*B)\n");
	printf("   e) Calcular el factorial (A!)\n");
	printf("4. Informar resultados\n");
	printf("   El resultado de A+B es: r\n");
	printf("   El resultado de A-B es: r\n");
	printf("   El resultado de A/B es: r\n");
	printf("   El resultado de A*B es: r\n");
	printf("   El factorial de A es: r1 y El factorial de B es: r2\n");
	printf("5. Salir\n");
	__fpurge(stdin);
	scanf("%c", &opcion);

	return opcion;
}

/**\brief Muestra los resultados de las operaciones
 *
 * \param float operandoA Numero1
 * \param float operandoB Numero2
 * \param float resultadoDeLaFuncionSuma Resultado de Numero1 + Numero2.
 * \param float resultadoDeLaFuncionResta Resultado de Numero1 + Numero2.
 * \param float resultadoDeLaFuncionDivision Resultado de Numero1 + Numero2.
 * \param float resultadoDeLaFuncionMultiplicacion  Resultado de Numero1 + Numero2.
 * \param float resultadoFactorialA Resultado del factorial del Numero1.
 * \param float resultadoFactorialB Resultado del factorial del Numero2.
 * \return void.
 *
 */

void verResultados(float operandoA, float operandoB,
		float resultadoDeLaFuncionSuma, float resultadoDeLaFuncionResta,
		float resultadoDeLaFuncionDivision,
		float resultadoDeLaFuncionMultiplicacion, float resultadoFactorialA,
		float resultadoFactorialB) {

	limpiarPantalla();
	printf("el resultado de %.2f + %.2f es: %f \n", operandoA, operandoB,
			resultadoDeLaFuncionSuma);

	printf("el resultado de %.2f - %.2f es: %f \n", operandoA, operandoB,
			resultadoDeLaFuncionResta);

	//Error cuando al dividir operandoA o operandoB es un 0.
	if (operandoA == 0 || operandoB == 0) {
		printf("No es posible dividir por cero\n");

	} else {
		printf("el resultado de %.2f / %.2f es: %f \n", operandoA, operandoB,
				resultadoDeLaFuncionDivision);
	}

	printf("el resultado de %.2f * %.2f es: %f \n", operandoA, operandoB,
			resultadoDeLaFuncionMultiplicacion);

	//Error cuando operandoA es un decimal o menor a 1.
	if (operandoA < 1 || operandoA - (int) operandoA != 0) {
		printf(
				"No es posible hallar el factorial A, este tiene que ser mayor a 0 y sin numeros decimales (A=%f)",
				operandoA);
	} else {
		printf("el factorial de %.0f es %.0f", operandoA, resultadoFactorialA);
	}

	//Error cuando operandoB es un decimal o menor a 1.
	if (operandoB < 1 || operandoB - (int) operandoB != 0) {
		printf(
				" y No es posible hallar el factorial B, este tiene que ser mayor a 0 y sin numeros decimales (B=%f)\n",
				operandoB);
	} else {
		printf(" y el factorial de %.0f es %.0f\n", operandoB,
				resultadoFactorialB);
	}

	/**\brief  Suma el Numero1 + Numero2.
	 *
	 * \param  float operandoA Numero 1.
	 * \param  float operandoB Numero 2.
	 * \return float resultado de Numero1 + Numero2.
	 *
	 */

}

float Sumar(float operandoA, float operandoB) {

	float resultado;

	resultado = operandoA + operandoB;
	return resultado;

}

/**\brief Resta el, Numero1 - Numero2.
 *
 * \param float operandoA Numero1
 * \param float operandoB Numero2
 * \return  float resultadoDeLaResta Resultado de la resta de Numero1 - Numero2.
 *
 */

float Restar(float operandoA, float operandoB) {

	float resultadoDeLaResta;

	resultadoDeLaResta = operandoA - operandoB;
	return resultadoDeLaResta;
}

/**\brief Funcion para dividir, Numero1 / Numero2.
 *
 * \param float operandoA Numero1.
 * \param float operandoB  Numero2.
 * \return float resultado El resultado de la division de Numero1/ Numero2.
 *
 */

float Dividir(float operandoA, float operandoB) {

	float resultado;

	resultado = operandoA / operandoB;
	return resultado;

}

/**\brief Funcion para multiplicar, Numero1 * Numero2.
 *
 * \param float operandoA Numero1.
 * \param float operandoB Numero2.
 * \return float resultado El resultado de la multiplicacion de Numero1 * Numero2.
 *
 */

float Multiplicar(float operandoA, float operandoB) {

	float resultado;

	resultado = operandoA * operandoB;
	return resultado;
}

/**\brief Funcion para factorizar un numero.
 *
 * \param float NumeroParaFactorizar  Es el numero para factorizar
 * \return float resultado El resultado del factor del numero
 *
 */

float Factorizar(float NumeroParaFactorizar) {

	float resultado;
	int i;

	resultado = 1;

	for (i = 1; i <= NumeroParaFactorizar; i++) {
		resultado *= i;
	}

	return resultado;

}

/**\brief Simula un system("clear") creando espacios en blanco con enters
 *
 * \return void
 *
 */

void limpiarPantalla() {
	printf("\n\n\n\n\n\n\n\n\\n\n\n\n\n\n\n\n\n\n\n");
}

/**\brief Un printf para ver si el usuario desea continuar ingresando (Y/N).
 *
 * \return char deseaContinuar Si escribe 'y'  va a dar 8 (un valor indefinido), si escribe 'n' retorna un '5' que es el char para salir del menu.
 *

 */

void IngreseEnterParaContinuar() {
	char deseaContinuar;
	do {
		printf("Ingrese 'enter' para continuar");
		scanf("%c", deseaContinuar);

	} while (deseaContinuar != '\n');
}
