#include "Employee.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Validaciones.h"

/**
 *@brief Reserva memoria y crea un Employee.
 *
 * @return pEmployee	    	El puntero al employee creado
 */

Employee* employee_new() {
	Employee *pEmployee;

	pEmployee = (Employee*) malloc(sizeof(Employee));
	if (pEmployee == NULL) {
		exit(0);
	}
	return pEmployee;
}

/**
 *@brief Reserva memoria creando un Employee y les escribe los valores pasados en la llamda a la función.
 *
 * @param idStr					Puntero al valor del id
 * @param nombreStr				Puntero al valor del nombre
 * @param horasTrabajadasStr	Puntero al valor de las horas trabajadas
 * @param sueldoStr				Puntero al valor del sueldo
 * @return pEmployee			Puntero al Employee creado y cargado con valores
 */

Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *pEmployee;
	int idCasteado;
	int horasCasteado;
	int sueldoCasteado;

	pEmployee = employee_new(); //LLAMO A LA FUNCION QUE RESERVA MEMORIA
	if (pEmployee != NULL) {

		idCasteado = atoi(idStr); //CONVIERTO STRING A INT
		horasCasteado = atoi(horasTrabajadasStr);
		sueldoCasteado = atoi(sueldoStr);

		if (employee_setSueldo(pEmployee, sueldoCasteado)) { //REMPLAZO LOS VALORES DE LA LLAMADA A LA ESTRUCTURA
			if (employee_setNombre(pEmployee, nombreStr)) {
				if (employee_setHorasTrabajadas(pEmployee, horasCasteado)) {
					if (employee_setId(pEmployee, idCasteado)) {
						return pEmployee; //SI SALE TODO BIEN RETORNA EL EMPLOYEE

					}
				}
			}
		}
	}
	free(pEmployee);
	return 0;
}

/**
 * @brief Genera el id de un empleado, sumandole uno al id mas alto de la lista.
 *
 * @param pArrayListEmployee	El puntero a la lista
 * @return idMaximo 			El nuevo id del empleado
 * @return -1					Error el puntero a la lista es NULL
 * @return -2					Error no se pudo gettear
 * @return 0					Error no existen Employees en la lista
 */

int employee_generateId(LinkedList *pArrayListEmployee) {
	Employee *auxEmployee;
	int idMaximo;
	int len;
	int i;
	int id;

	if (pArrayListEmployee == NULL) { //VERIFICO ERRORES
		return -1;
	}

	len = ll_len(pArrayListEmployee); //CUENTO LOS EMPLEADOS
	if (len == 0) {
		return len;
	}

	for (i = 0; i < len; i++) {	//RECORRO LA LISTA CALCULANDO LOS ID MAXIMO
		id = -1;
		auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);

		if (employee_getId(auxEmployee, &id) == 0) {
			return -2;
		}

		if (id > idMaximo || i == 0) {
			idMaximo = id;
		}
	}

	idMaximo = idMaximo + 1; //CALCULO EL NUEVO ID Y LO DEVUELVO
	return idMaximo;
}

/**
 *@brief Remplaza el valor de Employee->id por el id pasado en la llamada.
 *
 * @param this 			La estructura Employee
 * @param id 			El valor del nuevo id a remplazar en Employee
 * @return setteo=1	    Si pudo remplazar
 * @return setteo=2		Si no pudo remplazar
 */

int employee_setId(Employee *this, int id) {
	int setteo = 0;

	if (this != NULL && id > 0) {
		this->id = id;
		setteo = 1;
	}

	return setteo;
}

/**
 *@brief Remplaza el valor del id por el valor del Employee->id
 *
 * @param this 			 La estructura Employee
 * @param id 			 El valor del nuevo id a remplazar en Employee
 * @return getteo=1		 Si se pudo remplazar
 * @return getteo=0		 Si no se pudo remplazar
 */

int employee_getId(Employee *this, int *id) {
	int getteo = 0;

	if (this != NULL && id != NULL) {
		*id = this->id;
		getteo = 1;

	}
	return getteo;
}

/**
 *@brief Remplaza el valor de Employee->nombre por el nombre pasado en la llamada.
 *
 * @param this			  Puntero al Employee
 * @param nombre		  Puntero al valor del nombre
 * @return setteo=1		  Si pudo remplazar
 * @return setteo=0		  Si no pudo remplazar
 */

int employee_setNombre(Employee *this, char *nombre) {
	int setteo = 0;

	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		setteo = 1;
	}

	return setteo;
}

/**
 *@brief Remplaza el valor del nombre por el valor del Employee->nombre
 *
 * @param this		     Puntero al Employee
 * @param nombre		 Puntero al valor del nombre
 * @return getteo=1		 Si se pudo remplazar
 * @return getteo=0 	 Si no se pudo remplaza
 */

int employee_getNombre(Employee *this, char *nombre) {
	int getteo = 0;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		getteo = 1;
	}

	return getteo;
}

/**
 *@brief Remplaza el valor de Employee->horasTrabajadas por el horasTrabajadas pasado en la llamada.
 *
 * @param this			  Puntero al Employee
 * @param horasTrabajadas Puntero al valor de horasTrabajadas
 * @return setteo=1		  Si pudo remplazar
 * @return setteo=0		  Si no pudo remplazar
 */

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int setteo = 0;

	if (this != NULL && horasTrabajadas > 0) {
		this->horasTrabajadas = horasTrabajadas;
		setteo = 1;
	}

	return setteo;
}

/**
 *@brief Remplaza el valor del horasTrabajadas por el valor del Employee->horasTrabajadas
 *
 * @param this			  Puntero al Employee
 * @param horasTrabajadas Puntero al valor de horasTrabajdas
 * @return getteo=1		  Si pudo remplazar
 * @return getteo=0		  Si no pudo remplazar
 */

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int getteo = 0;

	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		getteo = 1;
	}
	return getteo;
}

/**
 *@brief Remplaza el valor de Employee->sueldo por el sueldo pasado en la llamada.
 *
 * @param this			  Puntero al Employee
 * @param sueldo		  Puntero al valor del sueldo
 * @return setteo=1		  Si pudo remplazar
 * @return setteo=0		  Si no pudo remplazar
 */

int employee_setSueldo(Employee *this, int sueldo) {
	int setteo = 0;

	if (this != NULL && sueldo > 0) {
		this->sueldo = sueldo;
		setteo = 1;
	}

	return setteo;
}

/**
 *@brief Remplaza el valor del sueldo por el valor del Employee->sueldo
 *
 * @param  this			  Puntero al Employee
 * @param  sueldo		  Puntero al valor de sueldo
 * @return getteo=1		  Si pudo remplazar
 * @return getteo=0		  Si no pudo remplazar
 */

int employee_getSueldo(Employee *this, int *sueldo) {
	int getteo = 0;

	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		getteo = 1;
	}
	return getteo;
}

/**
 *@brief Compara dos empleados por id y devuelve dicha comparacion expresada en un int
 *
 * @param  unEmpleado				Primer empleado a comprarar
 * @param  otroEmpleado				Segundo empleado a comparar
 * @return comparacion=-1			Si unEmpleado es menor a otroEmpleado
 * @return comparacion=1			Si unEmpleado es mayor a otroEmpleado
 * @return comparacion=0			Si unEmpleado es igual a otroEmpleado
 */

int employee_compareById(void *unEmpleado, void *otroEmpleado) {
	int comparacion;
	int idUnEmpleado;
	int idOtroEmpleado;
	Employee *uno;
	Employee *dos;

	uno = (Employee*) unEmpleado;
	dos = (Employee*) otroEmpleado;
	idUnEmpleado = -1;
	idOtroEmpleado = -1;
	comparacion = 0; //PREDEFINO QUE SON IGUALES

	employee_getId(uno, &idUnEmpleado);
	employee_getId(dos, &idOtroEmpleado);

	if (idUnEmpleado > idOtroEmpleado) { //COMPARO
		comparacion = 1;

	} else {
		if (idUnEmpleado < idOtroEmpleado) {
			comparacion = -1;
		}
	}

	return comparacion;
}

/**
 *@brief Compara dos empleados por nombre y devuelve dicha comparacion expresada en un int
 *
 * @param unEmpleado				Primer empleado a comprarar
 * @param otroEmpleado				Segundo empleado a comparar
 * @return comparacion=-1			Si unEmpleado es menor a otroEmpleado
 * @return comparacion=1			Si unEmpleado es mayor a otroEmpleado
 * @return comparacion=0			Si unEmpleado es igual a otroEmpleado
 */

int employee_compareByNombre(void *unEmpleado, void *otroEmpleado) {
	int comparacion;
	char nombreUnEmpleado[55];
	char nombreOtroEmpleado[55];
	Employee *uno;
	Employee *dos;

	uno = (Employee*) unEmpleado;
	dos = (Employee*) otroEmpleado;
	comparacion = 0; //SON IGUALES

	employee_getNombre(uno, nombreUnEmpleado);
	employee_getNombre(dos, nombreOtroEmpleado);

	if (strcmp(nombreUnEmpleado, nombreOtroEmpleado) > 0) { //LOGICA DE COMPARACION
		comparacion = 1;

	} else {
		if (strcmp(nombreUnEmpleado, nombreOtroEmpleado) < 0) {
			comparacion = -1;
		}
	}

	return comparacion;
}

/**
 *@brief Compara dos empleados por horas trabajadas y devuelve dicha comparacion expresada en un int
 *
 * @param unEmpleado				Primer empleado a comprarar
 * @param otroEmpleado				Segundo empleado a comparar
 * @return comparacion=-1			Si unEmpleado es menor a otroEmpleado
 * @return comparacion=1			Si unEmpleado es mayor a otroEmpleado
 * @return comparacion=0			Si unEmpleado es igual a otroEmpleado
 */

int employee_compareByHorasTrabajadas(void *unEmpleado, void *otroEmpleado) {
	int comparacion;
	int HorasUnEmpleado;
	int HorasOtroEmpleado;
	Employee *uno;
	Employee *dos;

	uno = (Employee*) unEmpleado;
	dos = (Employee*) otroEmpleado;
	HorasUnEmpleado = -1;
	HorasOtroEmpleado = -1;
	comparacion = 0; //PREDEFINO QUE SON IGUALES

	employee_getHorasTrabajadas(uno, &HorasUnEmpleado);
	employee_getHorasTrabajadas(dos, &HorasOtroEmpleado);

	if (HorasUnEmpleado > HorasOtroEmpleado) { //LOGICA DE COMPARACION
		comparacion = 1;

	} else {
		if (HorasUnEmpleado < HorasOtroEmpleado) {

			comparacion = -1;
		}
	}

	return comparacion;
}

/**
 *@brief Compara dos empleados por nombre y devuelve dicha comparacion expresada en un int
 *
 * @param unEmpleado				Primer empleado a comprarar
 * @param otroEmpleado				Segundo empleado a comparar
 * @return comparacion=-1			Si unEmpleado es menor a otroEmpleado
 * @return comparacion=1			Si unEmpleado es mayor a otroEmpleado
 * @return comparacion=0			Si unEmpleado es igual a otroEmpleado
 */

int employee_compareBySueldo(void *unEmpleado, void *otroEmpleado) {
	int comparacion;
	int SueldoUnEmpleado;
	int SueldoOtroEmpleado;
	Employee *uno;
	Employee *dos;

	uno = (Employee*) unEmpleado;
	dos = (Employee*) otroEmpleado;
	SueldoUnEmpleado = -1;
	SueldoOtroEmpleado = -1;
	comparacion = 0; //PREDEFINO QUE SON IGUALES

	employee_getSueldo(uno, &SueldoUnEmpleado);
	employee_getSueldo(dos, &SueldoOtroEmpleado);

	if (SueldoUnEmpleado > SueldoOtroEmpleado) { //LOGICA DE COMPARACION
		comparacion = 1;
	} else {

		if (SueldoUnEmpleado < SueldoOtroEmpleado) {
			comparacion = -1;
		}
	}

	return comparacion;
}

/**
 *@brief La cabezera de un empleado (ID,NOMBRE,HORAS TRABAJADAS,SUELDO)
 *
 * @return printf				La cantidad de caracteres impresos
 */

int employee_showHeader() {

	return printf("\n\n       %-8s %-33s %-20s %-14s", "ID", "NOMBRE",
			"HORAS TRABAJADAS", "SUELDO");
}

/**
 *@brief Muestra un solo Employee pasado dentro del argumento de la funcion
 *
 * @param this					El puntero a Employee a mostrar
 * @return printf 				Si el puntero no es NULL devuelve la cantidad de caracteres impresos
 * @return EXIT_FAILURE 		Si el puntero es NULL devuelve 1
 */

int employee_showAnEmployee(Employee *this) {
	int id;
	char nombre[55];
	int horas;
	int sueldo;

	if (this != NULL) {
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);
		return printf("\n       %-8d %-33s %-20d %-14d", id, nombre, horas,
				sueldo);
	}

	return EXIT_FAILURE;
}

/**
 *@brief Muestra un solo Employee mediante su id, pasado dentro del argumento de la funcion
 *
 * @param this					El Employee a mostrar
 * @return printf 				Si el puntero no es NULL devuelve la cantidad de caracteres impresos
 * @return EXIT_FAILURE	   	    Si el puntero es NULL devuelve 1
 */

int employee_showAnEmployeeByIndex(Employee *this, int index) {
	int id;
	char nombre[55];
	int horas;
	int sueldo;

	if (this != NULL) {
		employee_getId(this, &id);
		employee_getNombre(this, nombre);
		employee_getHorasTrabajadas(this, &horas);
		employee_getSueldo(this, &sueldo);
		return printf("\n       %-8d %-33s %-20d %-14d", id, nombre, horas,
				sueldo);
	}

	return EXIT_FAILURE;
}
