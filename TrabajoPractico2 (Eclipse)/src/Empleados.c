#include "Empleados.h"
void InitEmployees(Employee list[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
    	list[i].isEmpty=LIBRE;
    }
}//todos los estados a libre

int BuscarLibre(Employee list[],int tam)
{
    int i;
    int posicionLibre;
    posicionLibre=-1;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty==LIBRE)
        {
            posicionLibre=i;
            break;
        }
    }
    return posicionLibre;//si devuelve -1 no se encontro posicion libre
}

Employee makeEmployee(int id)
{
	Employee empleadoACrear;
    empleadoACrear.id=id+1;
    printf("Ingrese nombre del Empleado: ");
    fflush(stdin);
    gets(empleadoACrear.name);
    printf("Ingrese apellido del Empleado: ");
    fflush(stdin);
    gets(empleadoACrear.lastName);
    printf("Ingrese salario del Empleado: ");
    scanf("%f",&empleadoACrear.salary);
    empleadoACrear.sector=TomarEntero("Ingrese sector del Empleado: ");
    empleadoACrear.isEmpty=OCUPADO;

    return empleadoACrear;

}

void addEmployees(Employee list[],int tam)
{
    int posicion;
    posicion=BuscarLibre(list,tam);
    if(posicion!=-1)
    {
    	list[posicion]=makeEmployee(posicion);
    }else
    {
        printf("No quedan espacio libres");
    }
}

void MostrarEmpleados(Employee list[],int tam)
{
    int i;
    printf("%8s %10s %10s %10s %10s\n","ID","Nombre","Apellido","Salario","Sector");
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty==1)
        {
            printf("%8d %10s %10s %10.2f %8d\n",
            		list[i].id,
					list[i].name,
					list[i].lastName,
					list[i].salary,
					list[i].sector);
        }
    }
}
void MensajeError(void)
{
    printf("Error se debe cargar minimo un empleado para realizar esta operacion\n");
}

int TomarEntero(char mensaje[])
{
    int valor;
    printf("%s",mensaje);
    scanf("%d",&valor);
    return valor;
}

void ModificarEmpleado(Employee list[],int tam)
{
    int EmpleadoAModificar;
    int CampoAModificar;
    int i;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
    int confirmacion;
    confirmacion=0;

    MostrarEmpleados(list,tam);
    EmpleadoAModificar=TomarEntero("Ingrese el Id del empleado a Modificar ");
    CampoAModificar=TomarEntero("Que campo desea modificar?\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");

    for(i=0;i<tam;i++)
    {

        if(list[i].isEmpty==OCUPADO&&list[i].id==EmpleadoAModificar)
        {
            switch(CampoAModificar)
            {
                case 1:
                {
                    printf("Ingrese nuevo Nombre: ");
                    fflush(stdin);
                    gets(auxNombre);
                    confirmacion=TomarEntero("Esta seguro?\n1.si\n2.no\n");
                    if(confirmacion==1)
                    {
                        strcpy(list[i].name,auxNombre);
                    }
                }break;
                case 2:
                {
                    printf("Ingrese nuevo Apellido: ");
                    fflush(stdin);
                    gets(auxApellido);
                    confirmacion=TomarEntero("Esta seguro?\n1.si\n2.no\n");
                    if(confirmacion==1)
                    {
                        strcpy(list[i].lastName,auxApellido);
                    }
                }break;
                case 3:
                {
                    printf("Ingrese nuevo Salario: ");
                    scanf("%f",&auxSalario);
                    confirmacion=TomarEntero("Esta seguro?\n1.si\n2.no\n");
                    if(confirmacion==1)
                    {
                    	list[i].salary=auxSalario;
                    }
                }break;
                case 4:
                {
                    printf("Ingrese nuevo Sector: ");
                    scanf("%d",&auxSector);
                    confirmacion=TomarEntero("Esta seguro?\n1.si\n2.no\n");
                    if(confirmacion==1)
                    {
                    	list[i].sector=auxSector;
                    }
                }break;
            }
        }
    }
    if(confirmacion==0)
    {
        printf("El usuario no existe o esta dado de baja\n");
    }

}

void DarDeBajaUnEmpleado(Employee list[],int tam)
{
    int i;
    int idABorrar;
    int confirmacion;
    confirmacion=0;
    MostrarEmpleados(list,tam);
    idABorrar=TomarEntero("Ingrese el Id del empleado a Eliminar ");

    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty==OCUPADO&&list[i].id==idABorrar)
        {
            confirmacion=TomarEntero("Esta seguro de que desea Eliminarlo?\n1.si\n2.no\n");
            if(confirmacion==1)
            {
            	list[i].isEmpty=BORRADO;
            }
        }
    }

}

void OrdenarPorApellidoYSector(Employee list[],int tam)
{
	Employee auxEmpleado;
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(list[i].lastName,list[j].lastName)<0)
            {
                auxEmpleado = list[i];
                list[i] = list[j];
                list[j] = auxEmpleado;
            }else
            {
                if(strcmp(list[i].lastName,list[j].lastName)==0)
                {
                    if(list[i].sector>list[j].sector)
                    {
                        auxEmpleado = list[i];
                        list[i] = list[j];
                        list[j] = auxEmpleado;
                    }
                }
            }

        }
    }
}

float TotalDeSalarios(Employee list[],int tam)
{
    int i;
    float acumulador;
    acumulador=0;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            acumulador=acumulador+list[i].salary;
        }

    }
    return acumulador;
}

float PromedioDeSalarios(Employee list[],int tam)
{
    float total;
    int i;
    int contadorDeSalarios;
    float promedioDeSalarios;
    contadorDeSalarios=0;
    total=TotalDeSalarios(list,tam);

    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            contadorDeSalarios++;
        }
    }
    promedioDeSalarios=total/contadorDeSalarios;
    return promedioDeSalarios;
}

int SalariosPorEncimaDelPromedio(Employee list[],int tam)
{
    int i;
    int cont;
    float promedio;
    cont=0;
    promedio=PromedioDeSalarios(list,tam);

    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty==OCUPADO)
        {
            if(list[i].salary>promedio)
            {
                cont++;
            }
        }
    }
    return cont;
}

void PuntoCuatro(Employee list[],int tam)
{

    float totalDeTodosSalarios;
    float promedioDeTodosLosSalarios;
    int CantidadDeSalariosPorEncimaDelPromedio;

    OrdenarPorApellidoYSector(list,tam);
    MostrarEmpleados(list,tam);

    totalDeTodosSalarios=TotalDeSalarios(list,tam);
    promedioDeTodosLosSalarios=PromedioDeSalarios(list,tam);
    CantidadDeSalariosPorEncimaDelPromedio=SalariosPorEncimaDelPromedio(list,tam);
    printf("El Total de todos los salarios es: %.2f \n",totalDeTodosSalarios);
    printf("El Promedio entre todos los salarios es: %.2f \n",promedioDeTodosLosSalarios);
    printf("La Cantidad de salarios por encima del promedio son: %d \n",CantidadDeSalariosPorEncimaDelPromedio);

}
