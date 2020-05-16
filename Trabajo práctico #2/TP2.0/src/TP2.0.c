/*
 ============================================================================
 Name        : 0.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>

#include "ArrayEmployees.h"
#include "Menu.h"
#include "UTNFunctions.h"

#define ELEMENTS 5
#define ERROR -1

int main(void) {

	SolucionErrorDeConsola();

	Employee arrayEmployees[ELEMENTS];
	int chosenOption;
	int id=ERROR;
	int indexEmployee;
	char name[50];
	char lastName[50];
	float salary;
	int sector;

	initEmployees(arrayEmployees, ELEMENTS);

	harcodeoEmployee(arrayEmployees);

	do {
		chosenOption = menuText();

		switch (chosenOption) {
		case 1:
			limpiarPantalla();
			auxiliarDefine(name, lastName, &salary, &sector);
			addEmployee(arrayEmployees, ELEMENTS, id, name, lastName, salary,
					sector);

			break;
		case 2:
			limpiarPantalla();
			getInt(&id, "\nIngrese id del empleado a buscar.",
					"\nError eso no es una id valida...", 0, 1000, 111);
			indexEmployee = findEmployeeById(arrayEmployees, ELEMENTS, id);
			modifyEmployee(arrayEmployees, ELEMENTS, id, indexEmployee);
			break;
		case 3:
			removeEmployee(arrayEmployees, ELEMENTS, id);
			break;
		case 4:
			suMenuReport(arrayEmployees, ELEMENTS);
			break;
		}
	} while (chosenOption != 5);
	return EXIT_SUCCESS;
}
