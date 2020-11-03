#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "String.h"
#include "FuncionesGenerales.h"

/****************************************************
 Menu:
 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
 4. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
 3. Alta de empleado
 4. Modificar datos de empleado
 4. Baja de empleado
 6. Listar empleados
 7. Ordenar empleados
 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
 9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
 10. Salir
 *****************************************************/

/*
 *Nombre: Álvarez Martín Andrés
 *Division: 1F
 *Legajo: 110077
 *
 */

int main() {

	SolucionErrorDeConsola();
	LinkedList *lista;
	int opcionElejida;

	lista = ll_newLinkedList();
	ll_clear(lista);

	do {
		LimpiarPantalla();
		printf(
				"\nMenu:"
						"\n 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)."
						"\n 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
						"\n 3. Alta de empleado."
						"\n 4. Modificar datos de empleado"
						"\n 5. Baja de empleado"
						"\n 6. Listar empleados"
						"\n 7. Ordenar empleados"
						"\n 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
						"\n 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
						"\n 10. Salir");

		GetInt(&opcionElejida, "\n\nElija una opcion: ",
				"****Opcion invalida****", 1, 10, 2);

		switch (opcionElejida) {

		case 1:
			controller_loadFromText("data.csv", lista);
			break;
		case 2:
			controller_loadFromBinary("data.csv", lista);
			break;
		case 3:
			controller_addEmployee(lista);
			break;
		case 4:
			controller_editEmployee(lista);
			break;
		case 5:
			controller_removeEmployee(lista);
			break;
		case 6:
			controller_listEmployee(lista);
			PresionarEnterParaContinuar();
			break;
		case 7:
			controller_sortEmployee(lista);
			break;
		case 8:
			controller_saveAsText("data.csv", lista);
			break;
		case 9:
			controller_saveAsBinary("data.csv", lista);
			break;
		}
	} while (opcionElejida != 10);

	ll_deleteLinkedList(lista);
	return 0;

}

