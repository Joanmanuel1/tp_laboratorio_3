#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int ret=0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        option=menu();
        switch(option)
        {
          // si ret < 0 es error
            case 1:
                ret=controller_loadFromText("data.csv", listaEmpleados);
                break;

            case 2:
                ret=controller_loadFromBinary("data.csv", listaEmpleados);
                break;

            case 3:
                ret=controller_addEmployee(listaEmpleados);
                if (ret < 0) {
                    mensaje("Error al dar de alta");
                } else {
                    mensaje("Alta realizada");
                }
                break;

            case 4:
                if (!isVacia(listaEmpleados)) {
                    ret=controller_editEmployee(listaEmpleados);
                    if (ret < 0) {
                        mensaje("Error al modificar");
                    } else {
                        mensaje("Modicacion realizada");
                    }
                }
                break;

            case 5:
                if (!isVacia(listaEmpleados)) {
                    ret=controller_removeEmployee(listaEmpleados);
                    if (ret < 0) {
                        mensaje("Error al eliminar");
                    } else {
                        mensaje("Eliminacion realizada");
                    }
                }
                break;

            case 6:
                if (!isVacia(listaEmpleados)) {
                    ret=controller_ListEmployee(listaEmpleados);
                    if (ret < 0) {
                        mensaje("Error al listar");
                    } else {
                        mensaje("Operacion realizada");
                    }
                }
                break;

            case 7:
                if (!isVacia(listaEmpleados)) {
                    ret=controller_sortEmployee(listaEmpleados);
                    if (ret < 0) {
                        mensaje("Error al ordenar");
                    } else {
                        mensaje("Operacion realizada");
                    }
                }
                break;

            case 8:
                if (!isVacia(listaEmpleados)) {
                    ret=controller_saveAsText("data_out.csv" , listaEmpleados);
                    if (ret < 0) {
                        mensaje("Error al grabar");
                    } else {
                        mensaje("Operacion realizada");
                    }
                }
                break;

            case 9:
                if (!isVacia(listaEmpleados)) {
                    ret=controller_saveAsBinary("data_out.bin" , listaEmpleados);
                    if (ret < 0) {
                        mensaje("Error al listar binario");
                    } else {
                        mensaje("Operacion realizada");
                    }

                }
                break;

        }
    }while(option != 10);
    ret = ll_deleteLinkedList(listaEmpleados);

    return ret;
}

int menu()
{
    int option;

    system("cls");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).   \n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario). \n");
    printf(" 3. Alta de empleado                                                            \n");
    printf(" 4. Modificar datos de empleado                                                 \n");
    printf(" 5. Baja de empleado                                                            \n");
    printf(" 6. Listar empleados                                                            \n");
    printf(" 7. Ordenar empleados                                                           \n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).     \n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).   \n");
    printf("10. Salir                                                                       \n");
    scanf("%d", &option);
    return option;
}

int isVacia(LinkedList* listaEmpleados)
{
    if (ll_isEmpty(listaEmpleados)) {
        mensaje("No hay empleados cargados\n");
        return 1;
    }

    return 0;

}
