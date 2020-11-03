#include "controller.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cadenas.h"
#include "Employee.h"
#include "FuncionesGenerales.h"
#include "parser.h"
#include "Validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*							 La ruta del archivo
 * \param pArrayListEmployee LinkedList*		 Puntero a la lista
 * \return int cantEmplyoyee					 La cantidad de Employees parseados
 * \return int -2								 Si el archivo o la lista apunta a NULL
 * \return int -1								 Si hubo error en el parseo de Employee
 */

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {

	FILE *pFile;
	int cantEmployee;

	ll_clear(pArrayListEmployee);

	pFile = fopen(path, "r"); //ABRO EL ARCHIVO Y ME ASEGURO QUE NO SEA NULL
	if (pFile == NULL || pArrayListEmployee == NULL) {
		printf("\n****Error****");
		fclose(pFile);
		return -2;
	}

	cantEmployee = parser_EmployeeFromText(pFile, pArrayListEmployee); //PARSEO Y ASEGURO QUE NO TENGA ERRORES
	if (cantEmployee == -1) {
		printf("\n****Error****");
		fclose(pFile);
		return -1;
	}

	fclose(pFile);
	return cantEmployee;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*							La ruta del archivo
 * \param pArrayListEmployee LinkedList*		Puntero a la lista
 * \return int EXIT_SUCCES(0)					Si no hubo fallos
 * \return int -1								Si hubo *path o *pArrayListEmployee apunta a NULL
 * \return int -2								Si parser_EmployeeFromBinary tuvo error
 */

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {

	FILE *pFile;

	ll_clear(pArrayListEmployee); //LIMPIO LA LISTA

	pFile = fopen(path, "rb"); //ABRO EL ARCHIVO Y ME ASEGURO QUE NO SEA NULL
	if (pFile == NULL || pArrayListEmployee == NULL) {
		printf("\n****Error****");
		fclose(pFile);
		return -1;
	}
	if (parser_EmployeeFromBinary(pFile, pArrayListEmployee) == EXIT_FAILURE) { //PARSEO Y ASEGURO QUE NO TENGA ERRORES
		printf("\n****Error****");
		fclose(pFile);
		return -2;
	}

	fclose(pFile);
	return EXIT_SUCCESS;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList*		Puntero a la lista
 * \return int EXIT_SUCCESS						Si se cargó el empleado correctamente
 * \return int EXIT_FAILURE						Si no se pudo cargar
 */

int controller_addEmployee(LinkedList *pArrayListEmployee) {
	Employee *auxEmployee;
	char continuar;
	char usuarioAceptoBorrarLista[22];
	char nombre[88];
	char horasTrabajadas[88];
	char sueldo[88];
	char id[88];

	LimpiarPantalla();
	printf("--------============== AGREGAR EMPLEADO ==============--------");

	auxEmployee = employee_new(); //RESERVO MEMORIA E INICIALIZO VARIABLE DE CONTROL
	strcpy(usuarioAceptoBorrarLista, "si");

	if (ll_isEmpty(pArrayListEmployee) == 1) { //SI LA LISTA ESTA VACIA SE LO HAGO SABER AL USUARIO QUE CONTINUA PERO BAJO SU RESPONSABILIDAD
		elejirEntreDosOpcionesConPuntero(usuarioAceptoBorrarLista,
				"\nEstá utilizando una lista vacia, carge la lista con la opcion 1 u 2 para evitar perdida de datos, "
						"puede continuar bajo su responsabilidad...\n Desea continuar? (si/no): ",
				"si", "no");
	}
	if (strcmp(usuarioAceptoBorrarLista, "si") == 0) {
		continuar = 'n';

		do {
			FgetsComprimido(nombre, "\nIngrese un nombre: ", 88); //CREO LOS DATOS EN AUXILIARES
			FgetsComprimido(horasTrabajadas, "\nIngrese las horas trabajadas: ",
					88);
			FgetsComprimido(sueldo, "\nIngrese un sueldo: ", 88);

			LimpiarPantalla(); //MUESTRO EL EMPLEADO Y PIDO QUE EL USUARIO CONFIRME QUE SEA CORRECTO
			printf("\nEMPLEADO:");
			employee_showHeader();
			printf("\n       %-8s %-33s %-20s %-14s", id, nombre,
					horasTrabajadas, sueldo);
			if (elejirEntreDosOpcionesConPuntero(&continuar,
					"\nLos datos ingresados son correctos?(si,no): ", "si",
					"no") == 1) {
				continuar = 's';
			}

		} while (continuar != 's');

		sprintf(id, "%d", employee_generateId(pArrayListEmployee)); //SI CONFIRMA SE GENERA ID Y SE CREA EL EMPLEADO AGREGANDOLO A LA LISTA
		auxEmployee = employee_newParametros(id, nombre, horasTrabajadas,
				sueldo);
		ll_add(pArrayListEmployee, auxEmployee);

		LimpiarPantalla(); //MENSAJE DE EXITO
		printf("\n\nEmpleado creado con exito!!!");
		PresionarEnterParaContinuar();

		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList*			Puntero a la lista
 * \return int -1									Si la lista apunta a NULL
 * \return int -2									Si la lista no tiene nada cargado
 * \return int -3									Si hubo un error inesperado
 * \return int EXIT_SUCCESS							Si se modificó un Employee y el usuario aceptó remplazarlo
 */

int controller_editEmployee(LinkedList *pArrayListEmployee) {
	Employee *auxEmployee;
	int indiceEmpleado;
	int opcionElejida;
	int horas;
	int sueldo;
	char nombre[99];

	LimpiarPantalla();
	printf("--------============== EDITAR EMPLEADO ==============--------");

	if (pArrayListEmployee == NULL) { //VERIFICACIONES DE ERRORES
		printf("\n****Error****");
		return -1;
	}
	if (ll_isEmpty(pArrayListEmployee) == 1) {
		printf("\nLista vacia, llenela lista para poder modificar empleado");
		PresionarEnterParaContinuar();
		return -2;
	}

	controller_listEmployee(pArrayListEmployee); //MUESTRO LISTA DE EMPLEADOS
	GetInt(&indiceEmpleado, "\nIngrese el indice del empleado ",
			"No es un numero valido", 0, 1000, 2);

	indiceEmpleado--; //LE RESTO UNO AL INDICE PORQUE EL INDICE DEL MENU ES UNO MAYOR AL ARRAY
	auxEmployee = ll_get(pArrayListEmployee, indiceEmpleado);

	do {

		employee_showHeader(); //MUESTRO EMPLEADO Y LO HAGO ELEJIR QUE MODIFICAR
		employee_showAnEmployee(auxEmployee);
		printf("\n\nQue desea cambiar?\n"
				"\n1) Nombre"
				"\n2) Horas trabajadas"
				"\n3) Sueldo"
				"\n4) Guardar y salir.");
		GetInt(&opcionElejida, "\n\nElija una opcion: ",
				"Error opcion no valida", 1, 4, 5);

		switch (opcionElejida) { //LOGICA DE MENU
		case 1:
			employee_getNombre(auxEmployee, nombre);
			GetString(nombre, "\nIngrese el nuevo nombre: ",
					"Error nombre invalido", 'a', 'z', 2);
			employee_setNombre(auxEmployee, nombre);
			break;
		case 2:
			employee_getHorasTrabajadas(auxEmployee, &horas);
			GetInt(&horas, "\nIngrese las nuevas horas trabajadas: ",
					"Error horas trabajadas invalidas", 0, 10000, 2);
			employee_setHorasTrabajadas(auxEmployee, horas);
			break;
		case 3:
			employee_getSueldo(auxEmployee, &sueldo);
			GetInt(&sueldo, "\nIngrese el nuevo sueldo: ",
					"Error sueldo invalido", 0, 5000000, 2);
			employee_setSueldo(auxEmployee, sueldo);
			break;
		}
	} while (opcionElejida != 4);

	if (ConfirmacionDeCambios() == ACEPTO) { //SI EL USUARIO ACEPTA SE SOBREESCRIBE EL EMPLOYEE
		ll_set(pArrayListEmployee, indiceEmpleado, auxEmployee);
		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList*				Puntero a la lista
 * \return int	EXIT_SUCCESS(0)							Si no hay errores
 * \return int EXIT_FAILURE(1)							Si hay errores
 *
 */

int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int indiceEmpleado;
	Employee *auxEmployee;

	LimpiarPantalla();
	printf("--------============== BORRAR EMPLEADO ==============--------");

	if (ll_isEmpty(pArrayListEmployee) == 1) {
		printf("\nLista vacia llenela  para poder borrar empleado");
		PresionarEnterParaContinuar();
	} else {

		controller_listEmployee(pArrayListEmployee);
		GetInt(&indiceEmpleado, "\n\nIngrese el indice del empleado ",
				"No es un numero valido", 0, 1000, 2);

		indiceEmpleado--;
		auxEmployee = ll_get(pArrayListEmployee, indiceEmpleado);

		employee_showHeader();
		employee_showAnEmployeeByIndex(auxEmployee, indiceEmpleado);

		if (ConfirmacionDeCambios() == 1) {
			ll_remove(pArrayListEmployee, indiceEmpleado);
			return EXIT_SUCCESS;
		}

	}

	return EXIT_FAILURE;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*				Puntero a la lista
 * \return int -1										Si la lista está llena
 * \return int-2										Si algun empleado apunta a NULL
 * \return EXIT_SUCCES(0)								Si se cargaron todos los empleados con exito
 *
 */

int controller_listEmployee(LinkedList *pArrayListEmployee) {
	Employee *auxEmployee;
	int len;
	int i;
	int id;
	char nombre[55];
	int horas;
	int sueldo;

	if (ll_isEmpty(pArrayListEmployee) == 1) { //VERIFICACIONES DE ERRORES
		printf("\nLista vacia llenela  para poder mostrarla");
		PresionarEnterParaContinuar();
		return -1;
	}

	len = ll_len(pArrayListEmployee); //RECORRO LA LISTA Y COPIO LOS CAMPOS DE LOS EMPLEADOS
	for (i = 0; i < len; i++) {

		auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		if (auxEmployee == NULL) {
			printf("\nRetorno -2");
			return -2;
		}

		employee_getId(auxEmployee, &id);
		employee_getNombre(auxEmployee, nombre);
		employee_getHorasTrabajadas(auxEmployee, &horas);
		employee_getSueldo(auxEmployee, &sueldo);

		if (i == 0) { //ANTES DE IMPRIMIRLOS IMPRIMO LA CABEZERA Y DESPUES LOS EMPLEADOS
			employee_showHeader();
		}
		printf("\n%5d) %-8d %-33s %-20d %-14d", i + 1, id, nombre, horas,
				sueldo);
	}

	return EXIT_SUCCESS;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*			  Puntero a la lista
 * \return int -1									  Si la lista está llena
 * \return int EXIT_FAILURE							  Si se acabaron los reintentos y no eligio la opcion correcta
 * \return int EXIT_SUCCESS							  Si se termino sin ningun error
 */

int controller_sortEmployee(LinkedList *pArrayListEmployee) {
	int opcionElejida;
	int tipoOrdenamiento;

	if (ll_isEmpty(pArrayListEmployee) == 1) {
		printf("\nLista vacia llenela  para poder borrar empleado");
		PresionarEnterParaContinuar();
		return -1;
	}

	do {
		LimpiarPantalla();
		printf(
				"--------============== ORDENAR EMPLEADO ==============--------");

		printf("\n\nComo desea ordenar los empleados?"); //MENU TIPO ORDENAMIENTO
		printf("\n\n1) Por id");
		printf("\n2) Por nombre");
		printf("\n3) Por horas");
		printf("\n4) Por sueldo");
		printf("\n5) Salir");
		if (GetInt(&opcionElejida, "\n\nElija una opcion: ", //SI SE ESCRIBIO UNA OPCION CORRECTA SE EJECUTA EL RESTO
				"Error opcion no valida", 1, 5, 5) != 0) {

			printf("\n\nElija el orden"); //MENU SENTIDO DEL ORDENAMIENTO
			printf("\n1) Ascendiente");
			printf("\n2) Descendiente");
			GetInt(&tipoOrdenamiento, "\n\nElija una opcion: ",
					"Error opcion no valida", 1, 2, 2);

			if (tipoOrdenamiento == 2) { //CAMBIO EL VALOR PARA QUE SEA ACORDE A LA FUNCION DE ORDENAMIENTO
				tipoOrdenamiento = 0;
			}
			if (tipoOrdenamiento == 1 || tipoOrdenamiento == 0) { //SI EL VALOR DEL ORDEN ES UNO CORRECTO CONTINUO CON LA LOGICA
				switch (opcionElejida) {
				case 1:
					printf(
							"\nIniciando ordenamiento, este proceso tardará algún tiempo ,sea paciente.");
					printf("\nORDENADOS POR ID: ");
					ll_sort(pArrayListEmployee, employee_compareById,
							tipoOrdenamiento);
					controller_listEmployee(pArrayListEmployee);
					PresionarEnterParaContinuar();
					break;

				case 2:
					printf(
							"\nIniciando ordenamiento, este proceso tardará algún tiempo ,sea paciente.");
					printf("\nORDENADOS POR NOMBRE: ");
					ll_sort(pArrayListEmployee, employee_compareByNombre,
							tipoOrdenamiento);
					controller_listEmployee(pArrayListEmployee);
					PresionarEnterParaContinuar();
					break;

				case 3:
					printf(
							"\nIniciando ordenamiento, este proceso tardará algún tiempo ,sea paciente.");
					printf("\nORDENADOS POR HORAS TRABAJADAS: ");
					ll_sort(pArrayListEmployee,
							employee_compareByHorasTrabajadas,
							tipoOrdenamiento);
					controller_listEmployee(pArrayListEmployee);
					PresionarEnterParaContinuar();
					break;

				case 4:
					printf(
							"\nIniciando ordenamiento, este proceso tardará algún tiempo ,sea paciente.");
					printf("\nORDENADOS POR SUELDO: ");
					ll_sort(pArrayListEmployee, employee_compareBySueldo,
							tipoOrdenamiento);
					controller_listEmployee(pArrayListEmployee);
					PresionarEnterParaContinuar();
					break;
				}
			}
		}

	} while (opcionElejida != 5);

	if (opcionElejida == 5
			&& (tipoOrdenamiento == 1 || tipoOrdenamiento == 0)) { //VERFICIACION DE ERRORES
		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*									La ruta de el archivo
 * \param pArrayListEmployee LinkedList*				Puntero a la lista
 * \return int -1										Si path o pArrayListEmployee apuntan a NULL
 * \return int -2										Si el usuario no acepta formatear el archivo
 * \return int EXIT_SUCCESS(0)							Si se guardo correctamente
 */

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
	FILE *pFile;
	Employee *auxEmployee;
	int i;
	int len;
	int id;
	int horas;
	int sueldo;
	char nombre[99];

	LimpiarPantalla();
	if (pArrayListEmployee == NULL || path == NULL) { //VERIFICACIONES DE ERRORES
		printf("\n****Error****");
		return -1;
	}
	if (ElejirEntreDosOpciones(
			"\nEsta acción va a remplazar los datos en 'data.csv', asegurese de haber cargado la lista en la opcion 1 o 2 para no perder información\nDesea contiunuar?(si/no): ",
			"si", "no") == 2) {
		return -2;
	}

	pFile = fopen("data.csv", "w"); //FORMATEO EL ARCHIVO PARA EVITAR DUPLICADOS, AGREGO CABEZERA Y CIERRO
	fprintf(pFile, "id,nombre,horasTrabajadas,sueldo");
	fclose(pFile);

	pFile = fopen(path, "a"); //ABRO EL ARCHIVO,RECORRO LOS EMPLEADOS DE LA LISTA Y COPIO SUS CAMPOS
	len = ll_len(pArrayListEmployee);
	for (i = 0; i < len; i++) {
		auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		employee_getId(auxEmployee, &id);
		employee_getNombre(auxEmployee, nombre);
		employee_getHorasTrabajadas(auxEmployee, &horas);
		employee_getSueldo(auxEmployee, &sueldo);

		if (auxEmployee != NULL) {	//SI NO APUNTA A NULL LOS ESCRIBO AL ARCHIVO
			fseek(pFile, 0L, SEEK_END);
			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
		}

	}

	fclose(pFile);
	return EXIT_SUCCESS;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*									Puntero a la ruta de el archivo
 * \param pArrayListEmployee LinkedList*				Puntero a la lista
 * \return int -1										Si path o pArrayListEmployee apuntan a NULL
 * \return int -2										Si el usuario no acepta formatear el archivo
 * \return int EXIT_SUCCESS(0)							Si se guardo correctamente
 */

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {

	FILE *pFile;
	Employee *auxEmployee;
	int i;
	int len;
	char cabezera[34];

	LimpiarPantalla();
	if (pArrayListEmployee == NULL || path == NULL) {//VERIFICACIONES DE ERRORES
		printf("\n****Error****");
		return -1;
	}
	if (ElejirEntreDosOpciones(
			"\nEsta acción va a remplazar los datos en 'data.csv', asegurese de haber cargado la lista en la opcion 1 o 2 para no perder información\nDesea contiunuar?(si/no): ",
			"si", "no") == 2) {
		return -2;
	}

	strcpy(cabezera, "id,nombre,horasTrabajadas,sueldo\n"); //CREO CABEZERA,FORMATEO EL ARCHIVO Y LA ESCRIBO
	pFile = fopen("data.csv", "wb");
	fwrite(cabezera, sizeof(cabezera), 1, pFile);
	fclose(pFile);

	pFile = fopen(path, "wb"); //ABRO EL ARCHIVO ,RECORRO MEDIANTE INDICE Y LO COPIO
	len = ll_len(pArrayListEmployee);
	for (i = 0; i < len; i++) {
		auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		fseek(pFile, 0L, SEEK_END);

		if (i == 0) {	//ESCRIBO LA CABEZERA Y EL EMPLEADO EN EL ARCHIVO
			fwrite(cabezera, sizeof(char[34]), 1, pFile);
		}
		fwrite(auxEmployee, sizeof(Employee), 1, pFile);

	}

	fclose(pFile);
	return EXIT_SUCCESS;
}

