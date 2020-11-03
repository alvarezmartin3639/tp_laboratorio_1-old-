#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParametros(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);

void employee_delete();

int employee_generateId(LinkedList *pArrayListEmployee);

int employee_setId(Employee *this, int id);
int employee_getId(Employee *this, int *id);

int employee_setNombre(Employee *this, char *nombre);
int employee_getNombre(Employee *this, char *nombre);

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

int employee_setSueldo(Employee *this, int sueldo);
int employee_getSueldo(Employee *this, int *sueldo);

int employee_compareById(void*, void*);
int employee_compareByNombre(void*, void*);
int employee_compareByHorasTrabajadas(void *unEmpleado,
		void *otroEmpleado);
int employee_compareBySueldo(void *unEmpleado, void *otroEmpleado);

int employee_showHeader();
int employee_showAnEmployee(Employee *this);
int employee_showAnEmployeeByIndex(Employee *this, int index);

#endif // employee_H_INCLUDED
