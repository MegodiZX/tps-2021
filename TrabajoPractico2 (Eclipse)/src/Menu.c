#include "Empleados.h"
#include "Menu.h"
void menu(Employee list[],int tam)
{
	setbuf(stdout,NULL);
    int opcion;
    int nextId=1000;
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
                	addEmployees(list,tam,&nextId);
                    control=0;
                }break;
            case 2:
                {
                    if(control==0)
                    {
                        ModificarEmpleado(list, tam);
                    }else
                    {
                        MensajeError();
                    }
                }break;
            case 3:
                {
                    if(control==0)
                    {
                    	removeEmployee(list, tam);
                    }else
                    {
                        MensajeError();
                    }

                }break;
            case 4:
                {
                    if(control==0)
                    {
                        PuntoCuatro(list,tam);
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

