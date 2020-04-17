/*
 * funciones.h
 *
 *  Created on: Apr 14, 2020
 *      Author: martin
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int verTextoDelMenu(float operandoA, float operandoB);

void verResultados(float operandoA, float operandoB, float resultadoDeLaFuncionSuma, float resultadoDeLaFuncionResta, float resultadoDeLaFuncionDivision, float resultadoDeLaFuncionMultiplicacion, float resultadoFactorialA, float resultadoFactorialB);

float Sumar(float operandoA, float operandoB);

float Restar(float operandoA, float operandoB);

float Dividir(float operandoA, float operandoB);

float Multiplicar(float operandoA, float operandoB);

float Factorizar(float NumeroParaFactorizar);

void limpiarPantalla();

void IngreseEnterParaContinuar();

#endif /* FUNCIONES_H_ */
