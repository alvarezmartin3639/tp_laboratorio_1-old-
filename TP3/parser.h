/*
 * parser.h
 *
 *  Created on: 30 oct. 2020
 *      Author: kenyn
 */

#ifndef DEBUG_PARSER_H_
#define DEBUG_PARSER_H_

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

#endif /* DEBUG_PARSER_H_ */
