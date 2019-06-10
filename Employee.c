#include "Employee.h"
#include "string.h"
#include "utn.h"

Employee* eEmployee;

Employee* employee_new()
{
  eEmployee=(Employee *)malloc(sizeof(Employee));

  return eEmployee;
}

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{

    eEmployee=(Employee *)malloc(sizeof(Employee));

    employee_setId(eEmployee, (int)atoi(idStr));
    employee_setSueldo(eEmployee, (int)atoi(sueldoStr));
    employee_setHorasTrabajadas(eEmployee, (int)atoi(horasTrabajadasStr));
    employee_setNombre(eEmployee,nombreStr);

    return eEmployee;
}

void employee_delete()
{
   // hace pelota el arraylist
    free(eEmployee);
    return 0;
}

int employee_setId(Employee* this,int id)
{
     this->id=id;
     return 0;
}


int employee_getId(Employee* this,int* id)
{
    *id=this->id;
    return 0;
}


int employee_setNombre(Employee* this,char* nombre)
{
     strcpy(this->nombre,nombre);

     return 0;
}

int employee_getNombre(Employee* this,char* nombre)
{
    strcpy(nombre, this->nombre);
    return 0;
}


int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
     this->horasTrabajadas=horasTrabajadas;
     return 0;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    *horasTrabajadas=this->horasTrabajadas;
    return 0;
}


int employee_setSueldo(Employee* this,int sueldo)
{
         this->sueldo=sueldo;
         return 0;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    *sueldo=this->sueldo;
    return 0;
}

int employee_buscarEmployee(LinkedList* pArrayListEmployee, char* idStr)
{
    Employee* eEmployee;

    int lon=0;
    int i=0;
    lon = ll_len(pArrayListEmployee);
    for(i=0; i<lon; i++)
    {
        eEmployee = (Employee*)ll_get(pArrayListEmployee,i);
        if (eEmployee->id == atoi(idStr))
        {
           return i;
        }
    }

    return -1;
}

Employee*  employee_datosEmployee(LinkedList* pArrayListEmployee, int opc, int* indice)
{

    char* idStr=(char*)malloc(sizeof(char*));
    char* nombreStr=(char*)malloc(sizeof(char*));
    char* horasTrabajadasStr=(char*)malloc(sizeof(char*));
    char* sueldoStr=(char*)malloc(sizeof(char*));

    int numero=0;
    int ret=-1;

    *indice=-1;

    if (getValidInt("Id   :","Dato ingresado erroneo\n", &numero,1,99999,1))
    {
       mensaje("Reintente");
       return NULL;
    }
    itoa(numero,idStr,10);

    *indice=employee_buscarEmployee(pArrayListEmployee,idStr);
    if ((*indice >= 0 && opc==0))    {
        mensaje("Id ingresado YA existe");
        return NULL;
    }
    if ((*indice < 0 && opc!=0))    {
        mensaje("Id ingresado NO existe");
        return NULL;
    }

    if (opc!=2) {
        if (getValidString("Nombre        :"," Dato ingresado erroneo\n","\nMaximo 50 caracteres", nombreStr,50,1))    {
           mensaje("Reintente");
           return NULL;
        }
        if (getValidInt("Horas trabajadas  :","Dato ingresado erroneo\n",&numero,1,999,1))    {
           mensaje("Reintente");
           return NULL;
        }
        if (getValidInt("Sueldo            :","Dato ingresado erroneo\n",&numero,1,9999999,1))     {
           mensaje("Reintente");
           return NULL;
        }
        itoa(numero, horasTrabajadasStr, 10);
        itoa(numero, sueldoStr, 10);
    }

    eEmployee=employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);

    return eEmployee;
}
