/*
 * Menu.c
 *
 *  Created on: 3 may. 2020
 *      Author: kenyn
 */

#include <stdio.h>

#include "ArrayEmployees.h"
#include "UTNFunctions.h"

int menuText() {
	int chosenOption;

	limpiarPantalla();
	printf("\n1. ALTAS.");
	printf("\n2. MODIFICAR.");
	printf("\n3. BAJA.");
	printf("\n4. INFORMAR.");
	printf("\n5. SALIR.");
	printf("\nElija una opcion porfavor.\n");
	scanf("%d", &chosenOption);

	return chosenOption;
}

int suMenuReport(Employee *list, int len) {

	int chosenOption;
	float returnSalaryTotal;
	float salaryAverage;
	int averageWageCounter;

	do {

		limpiarPantalla();
		printf(
				"\n------------"
						"\nINFORMAR:"
						"\n1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector."
						"\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio."
						"\n3. Volver al menu.");
		scanf("%d", &chosenOption);

		switch (chosenOption) {
		case 1:
			sortEmployees(list, len, 0);
			printEmployees(list, len);
			choseBetweenTwoOptions("\n\nPresione 'enter' para continuar....",
					"", "");
			break;
		case 2:
			//falta este
			returnSalaryTotal = salaryTotal(list, len);
			salaryAverage = returnSalaryTotal / len;
			averageWageCounter = exceedSalaryAverage(list, len, salaryAverage);
			printf("\nEl salario total es: |%.3f|"
					"\nEl promedio de salario es: |%.3f|"
					"\nLa cantidad de empleados que superan la media es: |%d|",
					returnSalaryTotal, salaryAverage, averageWageCounter);
			choseBetweenTwoOptions("\n\nPulse 'enter' para continuar....", "",
					"");

			break;
		}
	} while (chosenOption != 3);

	return 1;
}

