#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"



//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTRA EL MENU Y PIDE INGRESAR UNA OPCION.
int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Modificar\n");
    printf("3- Baja\n");
    printf("4- Listar\n");
    printf("5- Listar empleados por apellido y sector\n");
    printf("6- Listar empleados con mayor salario al promedio\n");
    printf("0- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//SETEA AL ARRAY IsEmpty EN 0 INDICANDO QUE ESTAN TODOS LOS ESPACIOS DISPONIBLES.
void inicializarEmpleados( eEmpleado x[], int tam)
{
    for(int i=0; i < tam; i++)
    {
        x[i].isEmpty = 0;
        x[i].sueldo = 0;
    }
}


//-------------------------------------------------------------
//-------------------------------------------------------------
//AGREGA LOS DATOS DE UN NUEVO EMPLEADO.
void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{
    eEmpleado nuevoEmpleado;
    int indice;
    char seguir='s';

    do{

    indice = buscarLibre(empleados, tam);   //BUSCA UN INDICE PARA EL NUVO EMPLEADO.

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
        seguir = 'n';
    }else{                                  //INGRESO DE DATOS DEL EMPLEADO.

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado.nombre);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(nuevoEmpleado.apellido);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado.sueldo);

            nuevoEmpleado.idSector = elegirSector(sectores, 5);

            nuevoEmpleado.legajo = 1000+indice;

            nuevoEmpleado.isEmpty = 1;

            empleados[indice] = nuevoEmpleado;

          //  printf("\nDesea agregar otro empleado?(s/n)\n");
          //  fflush(stdin);
          //  scanf("%c",&seguir);
          seguir = 'n';


            }
       }while(seguir != 'n');
}





//-------------------------------------------------------------
//-------------------------------------------------------------
//BUSCA EL PRIMER INDICE DISPONIBLE PARA DAR DE ALTA UN NUEVO EMPLEADO.
int buscarLibre( eEmpleado x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//DA A ELEGIR UNO DE LOS SECTORES DISPONIBLES PARA VINCULARLO CON UN MEPLEADO.
int elegirSector(eSector sectores[], int tam)
{
    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++){
        printf("%d %s\n", sectores[i].id, sectores[i].descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}


//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTA LOS DATOS DE UN EMPLEADO.
void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp.idSector, descripcion);

    printf("%d %s %s %.2f %s \n\n", emp.legajo, emp.nombre, emp.apellido, emp.sueldo, descripcion);

}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MUESTRA EL LISTADO DE EMPLEADOS DADOS DE ALTA.
void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector)
{
    if(recorrerIsEmpty(nomina,tam)==-1)
    {
        printf("No hay empleados cargados aun.");
    }else{
    for(int i=0; i< tam; i++)
    {
        if( nomina[i].isEmpty == 1)
        {
            mostrarEmpleado(nomina[i], sectores, tamSector);
        }
    }
}
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//CARGA EL NOMBRE DE LOS SECTORES DISPONIBLES.
void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[])
{

    for(int i=0; i < tamSector; i++){
        if( sectores[i].id == idSector){

            strcpy(cadena, sectores[i].descripcion);
            break;
        }
    }
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//MODIFICA UN ATRIBUTO ESPECIFICO DEL EMPLEADO QUE COINCIDA EL LEGAJO INGRESADO.
void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

int legajo;
int indice;
char modificar = 's';
int opcion;

mostrarEmpleados(empleados,tam,sectores,tamSector);

if(recorrerIsEmpty(empleados,tam)==-1){     //VERIFICA QUE HAYA ALGUN EMPLEADO CARGADO PARA MODIFICARLO.

    printf("No hay empleados cargados.");

}else{

printf("Ingrese legajo: ");     //VERIFICA QUE EL LEGAJO EXISTA.
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);   //MUESTRA EL EMPLEADO INGRESADO Y
                                                                //PIDE SELECCIONAR QUE ATRIBUTO MODIFICAR


    printf("\n\n ***QUE DESEA MODIFICAR?***\n");
    printf("1-NOMBRE\n");
    printf("2-APELLIDO\n");
    printf("3-SUELDO\n");
    printf("4-SECTOR\n");
    printf("0-CANCELAR\n");

    scanf("%d",&opcion);

        switch(opcion){
        case 1:
            printf("Ingrese nuevo Nombre: ");
            scanf("%s", empleados[indice].nombre);
            break;
        case 2:
            printf("Ingrese nuevo Apellido: ");
            scanf("%s", empleados[indice].apellido);
            break;
        case 3:
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &empleados[indice].sueldo);
            break;
        case 4:
           empleados[indice].idSector = elegirSector(sectores,5);
           break;
        case 0:
            modificar = 'n';
            break;
        }


    fflush(stdin);

    if(modificar != 's'){
        printf("Modificacion cancelada\n\n");
        }
    }
}
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//ELIMINA LOGICAMENTE AL EMPLEADO QUE COINCIDA EL LEGAJO INGRESADO.
void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector)
{

int legajo;
int indice;
char borrar;

mostrarEmpleados(empleados,tam,sectores,tamSector);

if(recorrerIsEmpty(empleados,tam)==-1){         //VERIFICA QUE EXISTA UN EMPLEADO CARGADO

        printf("No hay empleados cargados aun.");

}else{


printf("Ingrese legajo: ");                     //BUSCA AL EMPLEADO POR EL LEGAJO
scanf("%d", &legajo);

indice = buscarEmpleado(empleados, tam, legajo);

if( indice == -1){
    printf("No hay ningun empleado con el legajo %d\n", legajo);
}
else{
    mostrarEmpleado( empleados[indice], sectores, tamSector);

    printf("\nConfirma borrado?: ");
    fflush(stdin);
    scanf("%c", &borrar);
    if(borrar != 's'){
        printf("Borrado cancelado\n\n");
    }
    else{
        empleados[indice].isEmpty = 0;              //ELIMINA AL EMPLEADO SETEANDO EL ARRAY IsEmpty EN 0.
        printf("Se ha eliminado el empleado\n\n");
        }
    }
}
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//ORDENA A LOS EMPLEADOS POR SECTOR Y POR APELLIDO.
void ordenarXSectorYApellido(eEmpleado x[],int tam, eSector sectores[], int tamSector)
{

    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado auxEmpleado;

    for(int i=0; i<tam -1; i++)                         //RECORRE LOS ARRAY
    {
        for(int j = i +1; j < tam; j++)
        {
            cargarDescripcion(sectores, tamSector, x[i].idSector, descripcionI);        //SWAPEA A LOS EMPLEADOS POR SECTORES ALFABETICAMENTE.
            cargarDescripcion(sectores, tamSector, x[j].idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp(x[i].apellido, x[j].apellido) > 0)   //SWAPEA LOS EMPLEADOS POR SECTOR Y APELLIDO ALFABETICAMENTE.
            {
                auxEmpleado = x[i];
                x[i] = x[j];
                x[j] = auxEmpleado;
            }
        }
    }

}

//-------------------------------------------------------------
//-------------------------------------------------------------
//SUMA LA CANTIDAD DE EMPLEADOS DADOS DE ALTA.
int cantidadDeEmpleadosCargados(eEmpleado x[],int tam)
{
    float cantidad = 0;

    for(int i = 0; i<tam ; i++){

        if(x[i].isEmpty == 1){
            cantidad++;
        }
    }
    return cantidad;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//SACA EL TOTAL Y EL PROMEDIO DE TODOS LOS SUELDOS INGRESADOS Y MUESTRA LOS EMPLEADOS CON SUELDO MAYOR AL PROMEDIO.
void promedioYTotal(eEmpleado x[], int tam,eSector sectores[], int tamSectores){

    float total=0;
    float promedio = 0;
    float cantidadEmpleados = 0;

    if(recorrerIsEmpty(x,tam)==-1){     //VERIFICA QUE HAYA ALGUN EMPLEADO CARGADO PARA MODIFICARLO.

        printf("No hay empleados cargados.");
    }else{
        for(int i=0; i<tam; i++){                   //SUMA EL TOTAL DE TODOS LOS SUELDOS RECORRIENDO EL ARRAY DE EMPLEADOS.SUELDO.

        total += x[i].sueldo;

    }

        promedio = total/cantidadDeEmpleadosCargados(x,tam);        //SE CALCULA EL PROMEDIO

        printf("EL TOTAL DEL SUELDO ES DE: %f \n\n",total);       //MUESTRA EL TOTAL
        printf("EL PROMEDIO ES DE: %f \n\n",promedio);            //MUESTRA EL PROMEDIO

        for(int j = 0; j<tam ; j++){                    //BUSCA LOS EMPLEADOS QUE TENGAN UN MAYOR SUELDO AL PROMEDIO PARA MOSTRARLOS.

            if(x[j].sueldo > promedio){
                mostrarEmpleado(x[j],sectores,tamSectores);
                cantidadEmpleados++;
            }
        }
            printf("Cantidad de empleados con sueldo mayor al promedio: %f\n",cantidadEmpleados);
    }
}

//-------------------------------------------------------------
//-------------------------------------------------------------

//BUSCA EL INDICE DEL EMPLEADO QUE COINCIDA EL LEGAJO INGRESADO
int buscarEmpleado(eEmpleado x[], int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if( x[i].legajo == legajo && x[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//-------------------------------------------------------------
//-------------------------------------------------------------
//VERIFICAR QUE HAYA ALGUN EMPLEADO CARGADO.
int recorrerIsEmpty( eEmpleado x[], int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( x[i].isEmpty == 1)
        {
            indice = 1;
            break;
        }
    }
    return indice;
}
//-------------------------------------------------------------
//-------------------------------------------------------------

void harcodearEmpleados(eEmpleado y[])
{
eEmpleado x[4] = {
      {1111,"Gonzalo","Mey",1000,1,1},
      {2222,"Franco","Gonzales",2000,2,1},
      {3333,"Juan","Perez",1500,3,1},
      {4444,"Maria","Juana",2300,1,1}
      };


      for(int i=0;i<5;i++){
        y[i] = x[i];
      }
}

//-------------------------------------------------------------
//-------------------------------------------------------------
