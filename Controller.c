#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Parser.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int ret=-1;

    pFile = fopen(path,"r");
    ret=parser_EmployeeFromText(pFile , pArrayListEmployee);
    fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE *pFile;
    int ret=-1;

    pFile = fopen(path,"rb");
    ret=parser_EmployeeFromBinary(pFile , pArrayListEmployee);
    fclose(pFile);
    return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

  Employee* eEmployee;
  int* indice=(int*)malloc(sizeof(int*));

  int ret=-1;
  eEmployee=employee_datosEmployee(pArrayListEmployee, 0, indice);
  if (eEmployee != NULL)
  {
    ret = ll_add(pArrayListEmployee, eEmployee);
  }

  return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

  Employee* eEmployee;

  int ret=-1;
  char* idStr=(char*)malloc(sizeof(char*));
  int* indice=(int*)malloc(sizeof(int*));

  eEmployee=employee_datosEmployee(pArrayListEmployee, 1, indice);
  if (eEmployee != NULL) {
     ret = ll_set(pArrayListEmployee, *indice, eEmployee);
  }

  return ret;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    Employee* eEmployee;

    int ret=-1;
    char* idStr=(char*)malloc(sizeof(char*));
    int* indice=(int*)malloc(sizeof(int*));

    eEmployee=employee_datosEmployee(pArrayListEmployee, 2, indice);
    if (eEmployee != NULL) {
        ret = ll_remove(pArrayListEmployee, *indice);
    }
    return ret;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* eEmployee;

    FILE *pFile;

    int ret=-1;
    int indice=-1;
    int lon=0;
    int i=0;

    pFile = fopen("data_out.lst","w");
    lon = ll_len(pArrayListEmployee);
    fprintf(pFile, "Id         Nombre                              Horas         Sueldo             \n");
    for(i=0; i<lon; i++)
    {
        eEmployee = (Employee*)ll_get(pArrayListEmployee,i);
        fprintf(pFile, "%10d %-30s %10d %10d\n",  eEmployee->id, eEmployee->nombre, eEmployee->horasTrabajadas, eEmployee->sueldo);
    }
    fclose(pFile);
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int ret=0;

    ret = ll_sort(pArrayListEmployee, comparaEmployee, 1);
    return 1;
}

int comparaEmployee(void* eEmployeeA, void* eEmployeeB)
{
    if(((Employee*)eEmployeeA)->sueldo > ((Employee*)eEmployeeB)->sueldo)
    {
        return 1;
    }

     if(((Employee*)eEmployeeA)->sueldo < ((Employee*)eEmployeeB)->sueldo)
    {
        return -1;
    }

    return 0;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* eEmployee;

    FILE *pFile;

    int lon=0;
    int i=0;
    int ret=-1;

    pFile = fopen(path,"w");

    ret=fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    lon = ll_len(pArrayListEmployee);
    for(i=0; i<lon; i++)
    {
        eEmployee = (Employee*)ll_get(pArrayListEmployee,i);
        ret=fprintf(pFile, "%d,%s,%d,%d\n", eEmployee->id, eEmployee->nombre, eEmployee->horasTrabajadas, eEmployee->sueldo);
    }
    fclose(pFile);

    return ret;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    Employee* eEmployee;


    FILE *pFile;
    int lon=0;
    int i=0;
    int ret=-1;

    pFile = fopen(path,"wb");


    ret=fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
    lon = ll_len(pArrayListEmployee);
    for(i=0; i<lon; i++)
    {
        eEmployee = (Employee*)ll_get(pArrayListEmployee,i);
        ret=fprintf(pFile, "%d,%s,%d,%d\n", eEmployee->id, eEmployee->nombre, eEmployee->horasTrabajadas, eEmployee->sueldo);
    }
    fclose(pFile);
    return ret;
}

