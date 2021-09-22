#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

int ObtenerEntero(void);
/**
 * @brief Permite ingresar un valor entero y lo asigna con el retorno
 * @param ---
 * @return Valor numerico ingresado
 */

int Suma(int a, int b);
/**
 * @brief Recibe 2 parametros y los SUMA
 * @param primer numero
 * @param segundo numero
 * @return Resultado de la operacion
 */

int Resta(int a, int b);
/**
 * @brief Recibe 2 parametros y los RESTA
 * @param primer numero
 * @param segundo numero
 * @return Resultado de la operacion
 */

int Producto(int a, int b);
/**
 * @brief Recibe 2 parametros y los MULTIPLICA
 * @param primer numero
 * @param segundo numero
 * @return Resultado de la operacion
 */

float Division(int a, int b);
/**
 * @brief Recibe 2 parametros y los DIVIDE
 * @param primer numero
 * @param segundo numero
 * @return Resultado de la operacion
 */

int ObtenerFactorial(int numeroingresado);
/**
 * @brief Recibe 1 numero y mediente un for multiplica por todos los que lo preceden hasta el 1 para sacar el FACTORIAL
 * @param Numero
 * @return Factorial
 */

void MostarResultados(int suma,int resta,int producto,float division,int factorial1,int factorial2);
/**
 * @brief Recibe los resultados de Suma, Resta, Division, Producto, factorial de A y de B, y los muestra
 * @param Suma
 * @param Resta
 * @param Division
 * @param Producto
 * @param Factorial de A
 * @param Factorial de B
 * @return ---
 */

#endif // FUNCIONES_H_INCLUDED
