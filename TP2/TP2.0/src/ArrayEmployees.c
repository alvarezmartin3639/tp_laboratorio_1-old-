/*
 * ArrayEmployees.c
 *
 *  Created on: 3 may. 2020
 *      Author: kenyn
 */

#include "ArrayEmployees.h"

#include <stdio.h>
#include <string.h>

#include "UTNFunctions.h"

#define TRUE 1
#define FALSE 0
#define FREESPACE -3
#define ELEMENTS 5
#define FREEVALUE -4
#define ERROR -1
#define OK 0
#define ACCEPTED -2
#define NOACCEPTED -333

/** \brief  loads employees with predefined values ​​for testing
 *
 * \param list Employee* Pointer to array of employees
 * \return void
 *
 */

void harcodeoEmployee(Employee listEmployee[]) {

	int i;
	int id[ELEMENTS] = { 100, 101, 102, 103, 104 };
	int isEmpity[ELEMENTS] = { 1, 1, 1, 1, 1 };
	float salary[ELEMENTS] = { 250, 320, 179, 192, 120 };
	int sector[ELEMENTS] = { 2, 3, 5, 0, 8 };
	char name[ELEMENTS][20] = { "zAndres", "AHector", "Roberto", "Luis",
			"Hernan" };
	char lastName[ELEMENTS][20] = { "Zapato", "Alvarez", "Zapato", "Villegas",
			"Lopez" };

	for (i = 0; i < ELEMENTS; i++) {
		listEmployee[i].id = id[i];
		listEmployee[i].isEmpity = isEmpity[i];
		listEmployee[i].salary = salary[i];
		listEmployee[i].sector = sector[i];
		strcpy(listEmployee[i].name, name[i]);
		strcpy(listEmployee[i].lastName, lastName[i]);

	}
}

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee *list, int len) {
	int retorno = ERROR;
	int i;

	if (len > 1 && list != NULL) {
		retorno = OK;
		for (i = 0; i < len; i++) {
			list[i].isEmpity = TRUE;
		}
	}

	return retorno;
}

/**\brief add in existing list of employees the value received as parameters
 * in the first empity position
 *
 * \param list employee*       Pointer to array of employees.
 * \param len int              array length.
 * \param id int               id of Employee.
 * \param name[] char          name of Employeee.
 * \param lastName[] char      last name of Employee.
 * \param salary float         salary of Employee.
 * \param sector int           sector of Employee.
 * \return int return (-1) if Error [Invalid length or NULL pointer or without
 * free space] - (0) if Ok
 */

int addEmployee(Employee *list, int len, int id, char name[], char lastName[],
		float salary, int sector) {
	int freeSpaceIndex;
	int retorno = ERROR;

	freeSpaceIndex = findEmpitySpace(list, len);

	if (freeSpaceIndex != ERROR && len > 1 && list != NULL) {
		limpiarPantalla();

		list[freeSpaceIndex].isEmpity = FALSE;

		list[freeSpaceIndex].id = generateEmployeeId();

		id = list[freeSpaceIndex].id;

		showAuxiliars(name, lastName, id, salary, sector);

		retorno = OK;
	} else {
		printf(
				"\nError: Longitud del array inválida, puntero NULL o sin espacio libre");
	}
	return retorno;
}

/**\brief defines the auxiliaries to be able to replace the variables if the user confirms.
 *
 * \param auxName char         Pointer to array auxName
 * \param auxLastName char     Pointer to array auxLastName
 * \param *auxSalary float     Pointer to auxSalary
 * \param *auxSector int       Pointer to auxSector
 * \return void
 */

void auxiliarDefine(char auxName[], char auxLastName[], float *auxSalary,
		int *auxSector) {

	fgetsComprimido(auxName, "\n--------------------------------"
			"\nIngrese el nombre del empleado."
			"\n-------------------------------\n", 111);

	fgetsComprimido(auxLastName, "\n--------------------------------"
			"\nIngrese el apellido del empleado."
			"\n-------------------------------\n", 111);

	getFloat(auxSalary, "\n-------------------------------"
			"\nIngrese el salario del empleado."
			"\n-------------------------------\n", "\nError salario invalido.",
			1, 100000, 111);

	getInt(auxSector, "\n-----------------------------"
			"\nIngrese el sector."
			"\n-----------------------------\n", "\nError sector invalido", 0,
			100, 111);

}

/**\brief displays the auxiliaries in a table.
 *
 * \param name char              Name of new Employee
 * \param lastName[] char        Last name of new Employee
 * \param id int 				 Id of new Employee
 * \param salary float			 salary of new Employee
 * \param sector int 			 sector of new Employee
 *
 * \return void
 */

void showAuxiliars(char name[], char lastName[], int id, float salary,
		int sector) {

	printf(
			"\n ----------------------"
					"\n|SE AGREGÓ EL EMPLEADO:|"
					"\n ----------------------"
					"\n------------------------------------------------------------------------"
					"\n|%4s | |%18s | |%20s | %8s | %4s", "ID", "LAST NAME",
			"NAME", "SALARY",
			"SECTOR|"
					"\n------------------------------------------------------------------------");

	printf("\n|%4d | |%18s | |%20s | %8.2f | %4d  |", id, lastName, name,
			salary, sector);

	printf(
			"\n------------------------------------------------------------------------");

	textAndSleep("\n\nRedirigiendo al menu en 4 segundos...", 4000);
}

/*
 * \brief generates a unique id for an employee
 * \return generarId int    return id generated
 *
 */
int generateEmployeeId() {
	static int generarId = 0;
	generarId++;
	return generarId;
}
/* *\brief search and return an empty space in the employee index
 *
 * \param list Employee*      Pointer to array of employees.
 * \param len int             array length.
 * \return
 *
 */
int findEmpitySpace(Employee *list, int len) {

	int i;
	int index = ERROR;
	for (i = 0; i < len; i++) {
		if (list[i].isEmpity == TRUE) {
			index = i;
			break;
		}
	}

	return index;

}

/**\brief find an Employee by Id en returns the index 	position array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *  pointer received or employee not found]
 */

int findEmployeeById(Employee *list, int len, int id) {
	int i;
	int retorno = ERROR;

	if (len > 1 && list != NULL) {

		for (i = 0; i < len; i++) {
			if (list[i].id == id) {

				retorno = i;
			}

		}
	} else {
		limpiarPantalla();
		printf("\n --------------------------"
				"\n|nEmpleado no encontrado!!!|"
				"\n --------------------------");
		textAndSleep("\n\nSerá redirigido en 3 segundos", 3000);
	}
	return retorno;
}

/**\brief Remove a Employee by Id (put isEmpity flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer ir if can't
 * find a employee] - (0) if Ok.

 *
 */

int removeEmployee(Employee *list, int len, int id) {

	int indexEmployee;
	int retorno;

	limpiarPantalla();
	getInt(&id, "\nIngrese id del empleado a eliminar.",
			"\nError eso no es una id valida...", 0, 1000, 111);
	indexEmployee = findEmployeeById(list, len, id);

	if (id != ERROR && len > 1 && list != NULL && indexEmployee != ERROR) {

		showOneEmployee(list, indexEmployee);
		limpiarPantalla();
		if (confirmacionDeCambios() == ACCEPTED) {
			list[indexEmployee].isEmpity = FALSE;

			textAndSleep(
					"\nCAMBIOS GUARDADOS CON EXITO, VOLVERA AL MENU EN 3 SEGUNDOS!!!",
					3000);
			retorno = ACCEPTED;
		}

	}else {
		textAndSleep(
							"\nERROR, VOLVERA AL MENU EN 3 SEGUNDOS!!!",
							3000);
		retorno = NOACCEPTED;
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid lengtrh or NULL pointer] - (0) if Ok.
 *
 */

int sortEmployees(Employee *list, int len, int order) {

	int retorno = ERROR;

	if (len > 1 && list != NULL && (order == 1 || order == 0)) {
		retorno = OK;
		if (order == 1) {
			sortEmployeesAscending(list, len);
		}
		if (order == 0) {
			sortEmployeesDescending(list, len);

		}

	}

	return retorno;
}

/** \brief Sort the elements in the array of employees descending
 *
 * \param list Employee*	     Pointer to array Employee.
 * \param len int	             Length of array.
 * \return int Return (-1) if Error [Invalid lengtrh or NULL pointer] - (0) if Ok.
 *
 */

int sortEmployeesDescending(Employee *list, int len) {

	int i;
	int j;
	Employee auxEmployee;
	int retorno = ERROR;

	if (len > 1 && list != NULL) {
		retorno = OK;

		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				if (strcmp(list[i].lastName, list[j].lastName) > 0) {
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;
				} else {
					if (strcmp(list[i].lastName, list[j].lastName) == 0) {
						if (list[i].sector < list[j].sector) {
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
						}
					}
				}

			}
		}
	}
	return retorno;
}

/** \brief Sort the elements in the array of employees ascending
 *
 * \param list Employee*			Pointer to array Employee
 * \param len int	                Length of array
 * \return int Return (-1) if Error [Invalid lengtrh or NULL pointer] - (0) if Ok.
 *
 */

int sortEmployeesAscending(Employee *list, int len) {
	int i;
	int j;
	Employee auxEmployee;
	int retorno = ERROR;

	if (len > 1 && list != NULL) {
		retorno = OK;
		for (i = 0; i < len - 1; i++) {
			for (j = i + 1; j < len; j++) {
				if (strcmp(list[i].lastName, list[j].lastName) < 0) {
					auxEmployee = list[i];
					list[i] = list[j];
					list[j] = auxEmployee;
				} else {
					if (strcmp(list[i].lastName, list[j].lastName) == 0) {
						if (list[i].sector > list[j].sector) {
							auxEmployee = list[i];
							list[i] = list[j];
							list[j] = auxEmployee;
						}
					}
				}

			}
		}

	}

	return retorno;
}

//

int mostrarMensajito() {
	printf("fgunca");
	return 1;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int printEmployees(Employee *list, int length) {
	int i;
	printf(
			"\n\n------------------------------------------------------------------------"
					"\n|%4s | |%18s | |%20s | %8s | %4s", "ID", "LAST NAME",
			"NAME", "SALARY",
			"SECTOR|"
					"\n------------------------------------------------------------------------");

	for (i = 0; i < length; i++) {

		printf("\n|%4d | |%18s | |%20s | %8.2f | %4d  |", list[i].id,
				list[i].lastName, list[i].name, list[i].salary, list[i].sector);
	}
	printf(
			"\n------------------------------------------------------------------------");

	return 0;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

int modifyEmployee(Employee *list, int len, int id, int indexEmployee) {

	int retorno = ERROR;
	int chosenOption;
	char name[50];
	char lastName[50];
	float salary;
	int sector;

	if (id != ERROR && len > 1 && list != NULL && indexEmployee > -1) {
		do {
			limpiarPantalla();
			printf("\n -------------------------------------------"
					"\n|QUE DESEA MODIFICAR DEL EMPLEADO CON ID: %d|"
					"\n -------------------------------------------"
					"\n1- Modificar apellido."
					"\n2- Modificar nombre."
					"\n3- Modificar salario."
					"\n4- Modificar sector."
					"\n5- Ver información del empleado."
					"\n6- Salir.", id);

			getInt(&chosenOption, "\n-------------------"
					"\nElija una opcion..."
					"\n-------------------",
					"\nERROR ESO NO ES UNA OPCION VALIDA", 1, 6, 1);

			switch (chosenOption) {

			case 1:
				modifyName(list, indexEmployee, name);
				break;
			case 2:
				modifyLastName(list, indexEmployee, lastName);
				break;
			case 3:
				modifySalary(list, indexEmployee, &salary);
				break;
			case 4:
				modifySector(list, indexEmployee, &sector);
				break;
			case 5:
				showOneEmployee(list, indexEmployee);
				break;

			}
		} while (chosenOption != 6);

	}
	return retorno;
}
/** \brief Modifies the name of the employee
 *
 * \param list Employee*	   Pointer to array Employee
 * \param indexEmployee int    Index of employee to modify
 * \param name *char           Name of the employee
 * \return retorno int         return ERROR(-1) if has error, ACCEPTED(-2)
 * if the user accepted and NOACCEPTED(-333) if the user no accepted
 *
 */
int modifyName(Employee *list, int indexEmployee, char *name) {

	int retorno = ERROR;
	fgetsComprimido(name, "\nElija el nuevo nombre", 50);

	if (confirmacionDeCambios() == ACCEPTED) {
		strcpy(list[indexEmployee].name, name);
		textAndSleep(
				"\nCAMBIOS GUARDADOS CON EXITO, VOLVERA AL MENU EN 3 SEGUNDOS!!!",
				3000);
		retorno = ACCEPTED;
	} else {

		retorno = NOACCEPTED;
	}

	return retorno;

}

/** \brief Modifies the name of the employee
 *
 * \param list Employee*	  Pointer to array Employee
 * \param indexEmployee int   Index of employee to modify
 * \param lastName *char      last name of the employee
 * \return retorno int        return ERROR(-1) if has error, ACCEPTED(-2)
 * if the user accepted and NOACCEPTED(-333) if the user no accepted
 */

int modifyLastName(Employee *list, int indexEmployee, char *lastName) {
	int retorno = ERROR;
	fgetsComprimido(lastName, "\nElija el nuevo nombre", 50);

	if (confirmacionDeCambios() == ACCEPTED) {
		strcpy(list[indexEmployee].name, lastName);
		textAndSleep(
				"\nCAMBIOS GUARDADOS CON EXITO, VOLVERA AL MENU EN 3 SEGUNDOS!!!",
				3000);
		retorno = ACCEPTED;
	} else {

		retorno = NOACCEPTED;
	}

	return retorno;
}

/** \brief Modifies the salary of the employee
 *
 * \param list Employee*	   Pointer to array Employee
 * \param indexEmployee int    Index of employee to modify
 * \param salary *float	       the salary of the employee
 * \return int                 return ERROR(-1) if has error, ACCEPTED(-2)
 * if the user accepted and NOACCEPTED(-333) if the user no accepted.
 */

int modifySalary(Employee *list, int indexEmployee, float *salary) {
	int retorno = ERROR;
	getFloat(salary, "\nElija el nuevo salario", "Error.. salario invalido",
			250, 50000, 111);

	if (confirmacionDeCambios() == ACCEPTED) {
		list[indexEmployee].salary = *salary;
		textAndSleep(
				"\nCAMBIOS GUARDADOS CON EXITO, VOLVERA AL MENU EN 3 SEGUNDOS!!!",
				3000);
		retorno = ACCEPTED;
	} else {

		retorno = NOACCEPTED;
	}

	return retorno;
}

/** \brief Modifies the sector of the employee
 *
 * \param list Employee*	 Pointer to array Emplyoee
 * \param indexEmployee int  Index of Employee to modify
 * \param sector *int        work sector
 * \return int				 return ERROR(-1) if has error, ACCEPTED(-2)
 * if the user accepted and NOACCEPTED(-333) if the user no accepted.
 *
 */

int modifySector(Employee *list, int indexEmployee, int *sector) {
	int retorno = ERROR;
	getInt(sector, "\nElija el nuevo sector", "Error.. sector invalido", 0, 22,
			111);

	if (confirmacionDeCambios() == ACCEPTED) {
		list[indexEmployee].sector = *sector;
		textAndSleep(
				"\nCAMBIOS GUARDADOS CON EXITO, VOLVERA AL MENU EN 3 SEGUNDOS!!!",
				3000);
		retorno = ACCEPTED;
	} else {

		retorno = NOACCEPTED;
	}

	return retorno;
}

/** \brief print the content of employees array
 *
 * \param list Employee*	Pointer to array Employee
 * \param length int	    Array length
 * \return int	            return OK if no error(0) and ERROR(-1) if error.
 *
 */

int showOneEmployee(Employee *list, int indexEmployee) {

	int retorno = ERROR;
	if (indexEmployee > -1 && list != NULL) {

		printf(
				"\n\n------------------------------------------------------------------------"
						"\n|%4s | |%18s | |%20s | %8s | %4s", "ID", "LAST NAME",
				"NAME", "SALARY",
				"SECTOR|"
						"\n------------------------------------------------------------------------");

		printf("\n|%4d | |%18s | |%20s | %8.2f | %4d  |",
				list[indexEmployee].id, list[indexEmployee].lastName,
				list[indexEmployee].name, list[indexEmployee].salary,
				list[indexEmployee].sector);

		choseBetweenTwoOptions("\nPulse 'enter' para continuar...", "", "");
		retorno=OK;
	}

	return retorno;
}

/** \brief returns the sum of all salarys
 *
 * \param list Employee*	Pointer to array Employee
 * \param leng int          Array length
 * \return retorno int      ERROR(-1) and different from error
 * if the accumulator worked
 */

int salaryTotal(Employee *list, int len) {
	int i;
	int retorno = ERROR;
	float salaryAccumulator = 0;
	if (len > 1 && list != NULL) {
		for (i = 0; i < len; i++) {

			if (list[i].isEmpity == TRUE) {
				salaryAccumulator = salaryAccumulator + list[i].salary;
			}
		}
		retorno = salaryAccumulator;
	}
	return retorno;
}

/** \brief returns the sum of all salarys
 *
 * \param list Employee*	Pointer to array Employee
 * \param leng int          Array length
 * \return retorno int      ERROR(-1) and different from error
 * if the accumulator worked
 */

int exceedSalaryAverage(Employee *list, int len, int salaryAverage) {
	int i;
	int retorno = ERROR;
	int counterSalaryAverage = 0;

	if (len > 1 && list != NULL) {

		for (i = 0; i < len; i++) {
			if (list[i].isEmpity == TRUE) {

				if (list[i].salary > salaryAverage) {
					counterSalaryAverage++;
				}

			}
		}

		retorno = counterSalaryAverage;
	}
	return retorno;
}
