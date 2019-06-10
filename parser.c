#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* eEmployee=employee_new();

    char buf [1024];
    char* idStr=(char*)malloc(sizeof(char*));
    char* nombreStr=(char*)malloc(sizeof(char*));
    char* horasTrabajadasStr=(char*)malloc(sizeof(char*));
    char* sueldoStr=(char*)malloc(sizeof(char*));
    int cantidad=0;
    int ret=-1;


    ret = ll_clear(pArrayListEmployee);

    while(!feof(pFile))
    {
        fgets (buf, sizeof(buf), pFile);
        cantidad++;
        if (cantidad > 1 ) {
            idStr = strtok (buf, ",");
            nombreStr = strtok (NULL, ",");
            horasTrabajadasStr = strtok (NULL, ",");
            sueldoStr = strtok (NULL, ",");
            if (nombreStr!=NULL)
            {
                eEmployee=employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
                ret = ll_add(pArrayListEmployee, eEmployee);
            }
        }
    }
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* eEmployee=employee_new();

    char buf [1024];
    char* idStr=(char*)malloc(sizeof(char*));
    char* nombreStr=(char*)malloc(sizeof(char*));
    char* horasTrabajadasStr=(char*)malloc(sizeof(char*));
    char* sueldoStr=(char*)malloc(sizeof(char*));

    int cantidad=0;
    int ret=-1;


    ret = ll_clear(pArrayListEmployee);

    while(!feof(pFile))
    {
        fgets (buf, sizeof(buf), pFile);
        cantidad++;
        if (cantidad > 1 ) {
            idStr = strtok (buf, ",");
            nombreStr = strtok (NULL, ",");
            horasTrabajadasStr = strtok (NULL, ",");
            sueldoStr = strtok (NULL, ",");

            if (nombreStr!=NULL)
            {
                eEmployee=employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);
                ret = ll_add(pArrayListEmployee, eEmployee);
            }
        }
    }

    return ret;
}
