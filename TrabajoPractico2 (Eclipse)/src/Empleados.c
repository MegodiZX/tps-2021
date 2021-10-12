#include "Empleados.h"
void InicializarEmpleados(eEmpleado lista[],int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado=LIBRE;
    }
}//todos los estados a libre

int BuscarLibre(eEmpleado lista[],int tam)
{
    int i;
    int posicionLibre;
    posicionLibre=-1;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==LIBRE)
        {
            posicionLibre=i;
            break;
        }
    }
    return posicionLibre;//si devuelve -1 no se encontro posicion libre
}

eEmpleado CrearUnEmpleado(int id)
{
    eEmpleado empleadoACrear;
    empleadoACrear.id=id+1;
    printf("Ingrese nombre del Empleado: ");
    fflush(stdin);
    gets(empleadoACrear.nombre);
    printf("Ingrese apellido del Empleado: ");
    fflush(stdin);
    gets(empleadoACrear.apellido);
    printf("Ingrese salario del Empleado: ");
    scanf("%f",&empleadoACrear.salario);
    empleadoACrear.sector=TomarEntero("Ingrese sector del Empleado: ");
    empleadoACrear.estado=OCUPADO;

    return empleadoACrear;

}

void DarDeAltaEmpleado(eEmpleado lista[],int tam)
{
    int posicion;
    posicion=BuscarLibre(lista,tam);
    if(posicion!=-1)
    {
        lista[posicion]=CrearUnEmpleado(posicion);
    }else
    {
        printf("No quedan espacio libres");
    }
}

void MostrarEmpleados(eEmpleado lista[],int tam)
{
    int i;
    printf("%8s %10s %10s %10s %10s\n","ID","Nombre","Apellido","Salario","Sector");
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==1)
        {
            printf("%8d %10s %10s %10.2f %8d\n",
                   lista[i].id,
                   lista[i].nombre,
                   lista[i].apellido,
                   lista[i].salario,
                   lista[i].sector);
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

void ModificarEmpleado(eEmpleado lista[],int tam)
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

    MostrarEmpleados(lista,tam);
    EmpleadoAModificar=TomarEntero("Ingrese el Id del empleado a Modificar ");
    CampoAModificar=TomarEntero("Que campo desea modificar?\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n");

    for(i=0;i<tam;i++)
    {

        if(lista[i].estado==OCUPADO&&lista[i].id==EmpleadoAModificar)
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
                        strcpy(lista[i].nombre,auxNombre);
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
                        strcpy(lista[i].apellido,auxApellido);
                    }
                }break;
                case 3:
                {
                    printf("Ingrese nuevo Salario: ");
                    scanf("%f",&auxSalario);
                    confirmacion=TomarEntero("Esta seguro?\n1.si\n2.no\n");
                    if(confirmacion==1)
                    {
                        lista[i].salario=auxSalario;
                    }
                }break;
                case 4:
                {
                    printf("Ingrese nuevo Sector: ");
                    scanf("%d",&auxSector);
                    confirmacion=TomarEntero("Esta seguro?\n1.si\n2.no\n");
                    if(confirmacion==1)
                    {
                        lista[i].sector=auxSector;
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

void DarDeBajaUnEmpleado(eEmpleado lista[],int tam)
{
    int i;
    int idABorrar;
    int confirmacion;
    confirmacion=0;
    MostrarEmpleados(lista,tam);
    idABorrar=TomarEntero("Ingrese el Id del empleado a Eliminar ");

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO&&lista[i].id==idABorrar)
        {
            confirmacion=TomarEntero("Esta seguro de que desea Eliminarlo?\n1.si\n2.no\n");
            if(confirmacion==1)
            {
                lista[i].estado=BORRADO;
            }
        }
    }

}

void OrdenarPorApellidoYSector(eEmpleado lista[],int tam)
{
    eEmpleado auxEmpleado;
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(lista[i].apellido,lista[j].apellido)<0)
            {
                auxEmpleado = lista[i];
                lista[i] = lista[j];
                lista[j] = auxEmpleado;
            }else
            {
                if(strcmp(lista[i].apellido,lista[j].apellido)==0)
                {
                    if(lista[i].sector>lista[j].sector)
                    {
                        auxEmpleado = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxEmpleado;
                    }
                }
            }

        }
    }
}

float TotalDeSalarios(eEmpleado lista[],int tam)
{
    int i;
    float acumulador;
    acumulador=0;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            acumulador=acumulador+lista[i].salario;
        }

    }
    return acumulador;
}

float PromedioDeSalarios(eEmpleado lista[],int tam)
{
    float total;
    int i;
    int contadorDeSalarios;
    float promedioDeSalarios;
    contadorDeSalarios=0;
    total=TotalDeSalarios(lista,tam);

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            contadorDeSalarios++;
        }
    }
    promedioDeSalarios=total/contadorDeSalarios;
    return promedioDeSalarios;
}

int SalariosPorEncimaDelPromedio(eEmpleado lista[],int tam)
{
    int i;
    int cont;
    float promedio;
    cont=0;
    promedio=PromedioDeSalarios(lista,tam);

    for(i=0;i<tam;i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(lista[i].salario>promedio)
            {
                cont++;
            }
        }
    }
    return cont;
}

void PuntoCuatro(eEmpleado lista[],int tam)
{

    float totalDeTodosSalarios;
    float promedioDeTodosLosSalarios;
    int CantidadDeSalariosPorEncimaDelPromedio;

    OrdenarPorApellidoYSector(lista,tam);
    MostrarEmpleados(lista,tam);

    totalDeTodosSalarios=TotalDeSalarios(lista,tam);
    promedioDeTodosLosSalarios=PromedioDeSalarios(lista,tam);
    CantidadDeSalariosPorEncimaDelPromedio=SalariosPorEncimaDelPromedio(lista,tam);
    printf("El Total de todos los salarios es: %.2f \n",totalDeTodosSalarios);
    printf("El Promedio entre todos los salarios es: %.2f \n",promedioDeTodosLosSalarios);
    printf("La Cantidad de salarios por encima del promedio son: %d \n",CantidadDeSalariosPorEncimaDelPromedio);

}
