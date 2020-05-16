/*
 * ArrayEmployees.h
 *
 *  Created on: 3 may. 2020
 *      Author: kenyn
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpity;
}typedef Employee;


void harcodeoEmployee(Employee listEmployee[]);

int initEmployees(Employee* list, int len);

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

void auxiliarDefine(char auxName[], char auxLastName[], float *auxSalary, int *auxSector);

void showAuxiliars(char auxName[], char auxLastName[], int id, float auxSalary,
		int auxSector);

int searchFreeSpace(Employee* list, int len, int freeValue);

int generateEmployeeId();

int findEmpitySpace(Employee *list, int len);

int findEmployeeById(Employee *list, int len, int id);

int sortEmployees(Employee* list, int len, int order);

int removeEmployee(Employee *list, int len, int id);

int sortEmployeesDescending(Employee *list, int len);

int sortEmployeesAscending(Employee *list, int len);

int printEmployees(Employee *list, int length);

int modifyEmployee(Employee *list, int len, int id, int indexEmployee);

int modifyName(Employee *list, int indexEmployee, char *name);

int modifyLastName(Employee *list, int indexEmployee, char *lastName);

int modifySalary(Employee *list, int indexEmployee, float *salary);


int modifySector(Employee *list, int indexEmployee, int *sector);

int showOneEmployee(Employee *list, int indexEmployee);

int salaryTotal(Employee *list, int len);

int exceedSalaryAverage (Employee *list, int len, int salaryAverage);



#endif /* ARRAYEMPLOYEES_H_ */
