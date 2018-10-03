
typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct{
    int id;
    char descripcion[20];
}eSector;

/** \brief Setea el array isEmpty y Sueldos en 0 marcando que los espacios estan vacios.
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \return -
 *
 */

void inicializarEmpleados( eEmpleado x[], int tam);

/** \brief Muestra el menu de opciones
 *
 * \param -
 * \param -
 * \return devuelve el nuemero de opcion elegido
 *
 */

int menu();

/** \brief da de alta un nuevo empleado
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void agregarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

/** \brief Busca el primer indice del array isEmpty que este vacio(o en 0)
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \return devuelve el numero de ubicacion del primer lugar vacio
 *
 */

int buscarLibre( eEmpleado x[], int tam);

/** \brief Da a elegir una opcion de los sectores cargados en el array de la estructura eSector
 *
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return devuelve el numero de la opcion elegida.
 *
 */

int elegirSector(eSector sectores[], int tam);

/** \brief muestra en consola los datos de un empleado dado de alta
 *
 * \param array de estructura eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void mostrarEmpleado(eEmpleado emp, eSector sectores[], int tamSector);

/** \brief Carga el nombre de cada sector a su id correspondiente
 *
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \param el entero que respresenta a cada id de cada sector
 * \param la cadena de caracteres donde guardar el nombre de cada sector
 * \return -
 *
 */

void cargarDescripcion(eSector sectores[], int tamSector, int idSector, char cadena[]);

/** \brief modifica la informacion de un empleado dado de alta
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

/** \brief elimina logicamente a un empleado dado de alta
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void eliminarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tamSector);

/** \brief ordena a los empleados por sectores de forma alfabetica y por apellido de forma alfabetica
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void ordenarXSectorYApellido(eEmpleado x[],int tam, eSector sectores[], int tamSector);

/** \brief Calcula la cantidad de empleados dados de alta
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \return devuelve la cantidad total de empleados cargados.
 *
 */

int cantidadDeEmpleadosCargados(eEmpleado x[],int tam);

/** \brief calcula el promedio y la suma total de los sueldos de todos los empleados dados de alta
 *          y muestra por consola los empleados que su sueldo supere al promedio.
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void promedioYTotal(eEmpleado x[], int tam,eSector sectores[], int tamSectores);

/** \brief Busca un empleado cuyo legajo sea igual al legajo ingresado
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param numero de legajo a buscar entre los empleados cargados
 * \return devuelve la cantidad total de empleados cargados.
 *
 */

int buscarEmpleado(eEmpleado x[], int tam, int legajo);

/** \brief Muestra en forma de lista todos los empleados dados de alta con todos sus datos
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \param array de estructura eSector
 * \param tamaño del array eSector
 * \return -
 *
 */

void mostrarEmpleados(eEmpleado nomina[], int tam, eSector sectores[], int tamSector);

/** \brief Verifica que haya algun empleado cargado recorriendo el arary isEmpty.
 *
 * \param array de estructura eEmpleado
 * \param tamaño del array eEmpleado
 * \return devuelve 1 si hay algun empleado dado de alta y -1 si el vector esta vacio por completo
 *
 */

int recorrerIsEmpty( eEmpleado x[], int tam);

/** \brief Da de alta un array de 4 empleados pre seteados con todos sus datos.
 *
 * \param array de estructura eEmpleado
 * \return -
 *
 */

void harcodearEmpleados(eEmpleado y[]);
