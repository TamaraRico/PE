/*Rico Lopez Tamara Illian 127067
PRACTICA 5
Promedio de numeros e identificar cual es el mayor y el menor*/
#include<stdio.h>

//prototipo de la funcion
float promedio(int, int);

int main(void)
{
    int num, i=1, mayor=0, menor, a=0;
    do
    {
        printf("\nIngrese un numero entero : ");
        scanf("%d", &num);
        a+=num;
        if(num>mayor)
            mayor=num;
        if(num<menor&&i>1)
            menor=num;
        i++;
    }while(num!=-1);

    printf("\nEl numero mayor es %d y el menor es %d", mayor, menor);
    printf("\nEl promedio de los numeros capturas es %.3f", promedio(a, i));

    return 0;
}
//definicion de la funcion premedio
float promedio(int a, int i)
{
    return a/i;
}
