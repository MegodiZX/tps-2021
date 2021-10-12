#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BORRADO 2
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int estado;
}eEmpleado;

void InicializarEmpleados(eEmpleado lista[],int tam);
/** \brief Pone todos los estados del array de empleados en "LIBRE"
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
int BuscarLibre(eEmpleado lista[],int tam);
/** \brief Buscan en el array un espacio en LIBRE, al encontrar uno rompe y devuelve la posicion libre
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return posicionLibre int
 *
 */

eEmpleado CrearUnEmpleado(int id);
/** \brief Pide al usuario el ingreso de todos los parametros de un Empleado menos el id
 *
 * \param id int
 * \return empleadoACrear eEmpleado
 *
 */
void DarDeAltaEmpleado(eEmpleado lista[],int tam);
/** \brief Se fija si hay posiciones en "LIBRE" y llama a CrearUnEmpleado si estan todos en "OCUPADO"
 * o "BORRADO" se informa que no queda espacio
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void MostrarEmpleados(eEmpleado lista[],int tam);
/** \brief Muestra en formato matriz todos los parametros de los empleados con estado "OCUPADO"
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void MensajeError(void);
/** \brief Mensaje de error llamado al menu para informar al usuario que tiene que ingresar un Empleado
 *
 * \param void
 * \return void
 *
 */
int TomarEntero(char mensaje[]);
/** \brief Recibe un string para mostrar con un printf. Luego guarda un valor con scanf y lo retorna
 *
 * \param mensaje[] char
 * \return valor int
 *
 */
void ModificarEmpleado(eEmpleado lista[],int tam);
/** \brief Muestra los empleados cargados, le pide al usuario ingresar el Id para MODIFICAR uno de los otros
 * parametros, el usuario ingresa con lo que se reemplazara. Se pide confirmacion y de ser positiva
 * sobreescribe el parametro seleccionado
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void DarDeBajaUnEmpleado(eEmpleado lista[],int tam);
/** Muestra los empleados cargados, le pide al usuario ingresar el Id para ELIMINAR, luego pide confirmacion
 * de ser otorgada cambia el estado de ese Empleado a BORRADO
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
void OrdenarPorApellidoYSector(eEmpleado lista[],int tam);
/** Recorre el array comparando apellidos ordenando de 'a' a la 'z' y si hay 2 apellidos iguales ordena por
 * sector de menor a mayor
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
float TotalDeSalarios(eEmpleado lista[],int tam);
/** Suma todos los salarios de los Empleados cargados y devuelve el total
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return acumulador float
 *
 */
float PromedioDeSalarios(eEmpleado lista[],int tam);
/** Usando TotalDeSalarios y un for que cuenta la cantidad de Empleados con estado OCUPADO calcula el promedio
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return promedioDeSalarios float
 *
 */
int SalariosPorEncimaDelPromedio(eEmpleado lista[],int tam);
/** Con un for que recorre el array, un if y la funcion anterior calcula los salarios que estan por
 * encima del promedio
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return int
 *
 */
void PuntoCuatro(eEmpleado lista[],int tam);
/** Utilizando los valores de TotalDeSalarios, PromedioDeSalarios y SalariosPorEncimaDelPromedio muestra
 * lo pedido en el punto 4 de la consigna
 *
 * \param lista[] eEmpleado
 * \param tam int
 * \return void
 *
 */
