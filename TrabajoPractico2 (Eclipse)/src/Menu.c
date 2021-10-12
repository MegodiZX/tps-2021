/*
 * Menu.c
 *
 *  Created on: 12 oct. 2021
 *      Author: Megodi
 */

#include "Empleados.h"
#include "Menu.h"
void menu(eEmpleado lista[],int tam)
{
	setbuf(stdout,NULL);
    int opcion;
    int control;
    control=1;
    do
    {
        printf("\n1.Alta de un Empleado");
        printf("\n2.Modificar un Empleado");
        printf("\n3.Dar de Baja un Empleado");
        printf("\n4.Informar");
        printf("\n0.Salir \n");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                {
                    DarDeAltaEmpleado(lista,tam);
                    control=0;
                }break;
            case 2:
                {
                    if(control==0)
                    {
                        ModificarEmpleado(lista, tam);
                    }else
                    {
                        MensajeError();
                    }
                }break;
            case 3:
                {
                    if(control==0)
                    {
                        DarDeBajaUnEmpleado(lista, tam);
                    }else
                    {
                        MensajeError();
                    }

                }break;
            case 4:
                {
                    if(control==0)
                    {
                        PuntoCuatro(lista,tam);
                    }else
                    {
                        MensajeError();
                    }

                }break;
            case 0:
                {
                    printf("Finalizo el programa ");
                }break;
            default:
                {
                    printf("Opcion inexistente \n");
                }break;
        }

    }while(opcion!=0);

}

