#include <stdio.h>
#include <stdlib.h>

#include "Employee.h"
#include "LinkedList.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*								Puntero a pFile
 * \param pArrayListEmployee LinkedList*			La lista
 * \return int -1									Error el archivo no existe
 * \return int -2									Error la lista no apunta a nada
 * \return int contador								La cantidad de empleados parseados con exito
 */

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {

	Employee *employee;
	int contador;
	char id[21];
	char nombre[21];
	char horas[21];
	char salario[21];

	contador = 0;

	if (pFile == NULL) {
		printf("\n****El archivo no existe****");
		return -1;
	}
	if (pArrayListEmployee == NULL) {
		return -2;
	}

	fseek(pFile, 32, SEEK_SET); //PARSEO Y AGREGO A LA LISTA
	while (!feof(pFile)) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horas, salario);
		employee = employee_newParametros(id, nombre, horas, salario);
		ll_add(pArrayListEmployee, employee);
		contador++;
	}

	return contador;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*								Puntero a pFile
 * \param pArrayListEmployee LinkedList*			La lista
 * \return int -1									Error el archivo no existe
 * \return int -2									Error la lista no apunta a nada
 * \return int -3									Error no se pudo parsear
 * \return int EXIT_SUCCESS							Si se parseo correctamente
 */

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {

	Employee *employee;
	int freadReturn = -1;

	if (pFile == NULL) {
		printf("\n****El archivo no existe****");
		return -1;
	}
	if (pArrayListEmployee == NULL) {
		return -2;
	}

	fseek(pFile, 33, SEEK_SET); //PARSEO EL ARCHIVO CREANDO EMPLOYEES
	while (!feof(pFile)) {
		employee = employee_new();
		freadReturn = fread(employee, sizeof(Employee), 1, pFile);

		if (freadReturn != 1) {
			return -3;
		}

		ll_add(pArrayListEmployee, employee);
	}

	return EXIT_SUCCESS;
}

