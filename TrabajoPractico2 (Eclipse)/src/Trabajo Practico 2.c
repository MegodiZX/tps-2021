/*
 ============================================================================
 Name        : Trabajo.c
 Author      : Gomez Diaz Maximiliano Ezequiel
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico N°2
 ============================================================================
 */

#include "Empleados.h"
#include "Menu.h"
#define T 1000
int main()
{
	Employee list[T];

	InitEmployees(list,T);

    menu(list,T);

    return 0;
}
