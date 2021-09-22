/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Gomez Diaz Maximiliano Ezequiel
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
	setbuf(stdout,NULL);
    int opcion;
    int primerNumero;
    int segundoNumero;
    int suma;
    int resta;
    int producto;
    float division;
    int factorial1;
    int factorial2;
    int VariableAntiBasura;

    primerNumero=-1;
    segundoNumero=-1;
    VariableAntiBasura=0;

    do
    {
        printf("\n1. Ingrese primer operador (A=%d)",primerNumero);
        printf("\n2. Ingrese segundo operador (B=%d)",segundoNumero);
        printf("\n3. Calcular: Suma, Resta, Multiplicacion, Division, Factorial(los factoriales tienen que ser positivos y enteros menores a 13)");
        printf("\n4. Mostar resultados");
        printf("\n5. Salir");
        printf("\nElija una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
            primerNumero= ObtenerEntero();
            break;
            case 2:
            segundoNumero= ObtenerEntero();
            break;
            case 3:
            if(primerNumero!=-1&&segundoNumero!=-1)
            {
                suma=Sumar(primerNumero,segundoNumero);
                resta=Restar(primerNumero,segundoNumero);
                producto=Producto(primerNumero,segundoNumero);
                division=Division(primerNumero,segundoNumero);
                factorial1=ObtenerFactorial(primerNumero);
                factorial2=ObtenerFactorial(segundoNumero);
                printf("Listo para mostrar \n");
                VariableAntiBasura=1;
            }
            break;
            case 4:
            if(VariableAntiBasura==1)
            {
                MostarResultados(suma,resta,producto,division,factorial1,factorial2);
            }else
            {
                printf("No se calcularon los datos, hagalo antes de mostrar \n");
            }
            break;
            case 5:
            printf("Adios \n");
            break;
            default:
            printf("Opcion inexistene \n");
            break;
        }
    }while(opcion!=5);

    return 0;
}
