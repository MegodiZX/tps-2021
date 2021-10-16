#include <stdio.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BORRADO 2
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void InitEmployees(Employee list[],int tam);
/** \brief Pone todos los estados del array de empleados en "LIBRE"
 *
 * \param list[] Employee
 * \param tam int
 * \return void
 *
 */
int BuscarLibre(Employee list[],int tam);
/** \brief Buscan en el array un espacio en LIBRE, al encontrar uno rompe y devuelve la posicion libre
 *
 * \param list[] Employee
 * \param tam int
 * \return posicionLibre int
 *
 */

Employee makeEmployee(int id);
/** \brief Pide al usuario el ingreso de todos los parametros de un Empleado menos el id y los cargar y devuelve un Employee
 *
 * \param id int
 * \return empleadoACrear Employee
 *
 */
void addEmployees(Employee list[],int tam);
/** \brief Se fija si hay posiciones en "LIBRE" y llama a CrearUnEmpleado si estan todos en "OCUPADO"
 * o "BORRADO" se informa que no queda espacio
 *
 * \param list[] Employee
 * \param tam int
 * \return void
 *
 */
void MostrarEmpleados(Employee list[],int tam);
/** \brief Muestra en formato matriz todos los parametros de los empleados con estado "OCUPADO"
 *
 * \param list[] Employee
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
void ModificarEmpleado(Employee list[],int tam);
/** \brief Muestra los empleados cargados, le pide al usuario ingresar el Id para MODIFICAR uno de los otros
 * parametros, el usuario ingresa con lo que se reemplazara. Se pide confirmacion y de ser positiva
 * sobreescribe el parametro seleccionado
 *
 * \param list[] Employee
 * \param tam int
 * \return void
 *
 */
void DarDeBajaUnEmpleado(Employee list[],int tam);
/** Muestra los empleados cargados, le pide al usuario ingresar el Id para ELIMINAR, luego pide confirmacion
 * de ser otorgada cambia el estado de ese Empleado a BORRADO
 *
 * \param list[] Employee
 * \param tam int
 * \return void
 *
 */
void OrdenarPorApellidoYSector(Employee list[],int tam);
/** Recorre el array comparando apellidos ordenando de 'a' a la 'z' y si hay 2 apellidos iguales ordena por
 * sector de menor a mayor
 *
 * \param list[] Employee
 * \param tam int
 * \return void
 *
 */
float TotalDeSalarios(Employee list[],int tam);
/** Suma todos los salarios de los Empleados cargados y devuelve el total
 *
 * \param list[] Employee
 * \param tam int
 * \return acumulador float
 *
 */
float PromedioDeSalarios(Employee list[],int tam);
/** Usando TotalDeSalarios y un for que cuenta la cantidad de Empleados con estado OCUPADO calcula el promedio
 *
 * \param list[] Employee
 * \param tam int
 * \return promedioDeSalarios float
 *
 */
int SalariosPorEncimaDelPromedio(Employee list[],int tam);
/** Con un for que recorre el array, un if y la funcion anterior calcula los salarios que estan por
 * encima del promedio
 *
 * \param list[] Employee
 * \param tam int
 * \return int
 *
 */
void PuntoCuatro(Employee list[],int tam);
/** Utilizando los valores de TotalDeSalarios, PromedioDeSalarios y SalariosPorEncimaDelPromedio muestra
 * lo pedido en el punto 4 de la consigna
 *
 * \param list[] Employee
 * \param tam int
 * \return void
 *
 */
