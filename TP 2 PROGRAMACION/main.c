#include <stdio.h>
#include <stdlib.h>
#define CANT_EMPLEADOS 10
#include <string.h>
#include "persona.h"





int main()
{     char seguir = 's';

    eEmpleado lista[CANT_EMPLEADOS];

    eSector sectores[] = {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
        };





  inicializarEmpleados(lista,CANT_EMPLEADOS);
  harcodearEmpleados(lista);

do{
        switch(menu()){

        case 1://ALTA DE EMPLEADO.
            agregarEmpleado(lista,CANT_EMPLEADOS,sectores,5);
            system("pause");                                                //ARREGLAR EL LEGAJO AUTOAMTICO!!!!
            break;
        case 2://MODIFICAR EMPLEADO.
            modificarEmpleado(lista,CANT_EMPLEADOS,sectores,5);
            system("pause");
            break;
        case 3://ELIMINAR EMPLEADO.
            eliminarEmpleado(lista,CANT_EMPLEADOS,sectores,5);
            system("pause");
            break;
        case 5://ORDENAR POR SECTOR Y APELLIDO ALFABETICAMENTE
            ordenarXSectorYApellido(lista,4,sectores,5);
            system("pause");
            break;
        case 6://MOSTRAR EMPLEADOS CON SUELDO MAYOR AL PROMEDIO.
            promedioYTotal(lista,CANT_EMPLEADOS,sectores,5);                          //ARREGLAR CASE 6!!!!!
            system("pause");
            break;
        case 4://LISTADO DE EMPLEADOS.
            mostrarEmpleados(lista,CANT_EMPLEADOS,sectores,5);
            system("pause");
            break;
        case 0:
            seguir = 'n';
            break;
        default:
            printf("OPCION INCORRECTA!");
            system("pause\n");
            break;

        }

    }while(seguir!='n');

    return 0;
}





























