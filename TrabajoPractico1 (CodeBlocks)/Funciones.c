#include <stdio.h>
int ObtenerEntero(void)
{
    int valor;
    printf("\nIngrese numero: ");
    scanf("%d",&valor);
    return valor;
}
int Suma(int a, int b)
{
    int resultado;

    resultado=a+b;

    return resultado;
}

int Resta(int a, int b)
{
    int resultado;

    resultado=a-(b);

    return resultado;
}

int Producto(int a, int b)
{
    int resultado;

    resultado=a*b;

    return resultado;
}

float Division(int a, int b)
{
    float resultado;
    if(b==0)
    {
        resultado=0;
    }else
    {
        resultado= (float)a/b;
    }

    return resultado;
}

int ObtenerFactorial(int numeroIngresado)
{
    int resultado;
    int i;
    resultado=0;
    if(numeroIngresado>-1)
    {
        for(i=numeroIngresado-1;i>1;i--)
        {
            numeroIngresado=numeroIngresado*i;
        }
        resultado=numeroIngresado;
        if(resultado==0)
        {
            resultado=1;
        }
    }else
    {
        resultado=-1;
    }

    return resultado;

}

void MostarResultados(int suma,int resta,int producto,float division,int factorial1,int factorial2)
{
    printf("La suma es: %d\n",suma);
    printf("La resta es: %d\n",resta);
    printf("La multiplicacion es: %d\n",producto);
    if(division==0)
    {
        printf("No se puede dividir por 0\n");

    }else
    {
       printf("La divicion es: %.2f\n",division);
    }
    if(factorial1==-1)
    {
        printf("No existe factorial de numeros negativos\n");
    }else
    {
        printf("El Factorial del primer numero es: %d \n",factorial1);
    }
    if(factorial2==-1)
    {
        printf("No existe factorial de numeros negativos\n");
    }else
    {
        printf("El Factorial del segundo numero es: %d \n",factorial2);
    }

}
