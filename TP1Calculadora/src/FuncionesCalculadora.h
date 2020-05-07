/*
 * FuncionesCalculadora.h
 *
 *  Created on: Apr 14, 2020
 *      Author: martin
 */
#include <stdio.h>

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

char verTextoDelMenu(float operandoA, float operandoB);

void verResultados(float operandoA, float operandoB, float resultadoDeLaFuncionSuma, float resultadoDeLaFuncionResta, float resultadoDeLaFuncionDivision, float resultadoDeLaFuncionMultiplicacion, float resultadoFactorialA, float resultadoFactorialB);

float sumar(float operandoA, float operandoB);

float restar(float operandoA, float operandoB);

float dividir(float operandoA, float operandoB);

float multiplicar(float operandoA, float operandoB);

float factorizar(float NumeroParaFactorizar);

void limpiarPantalla();

int deseaContinuar(char mensaje[60], char condicionParaContinuar[60],
		char condicionParaSalir[60]);

#endif /* FUNCIONES_H_ */
