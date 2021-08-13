/*Rico lopez Tamara Illian 1270673
PRACTICA 6
Tabla de frecuencias */
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10

int numeros_aleatorios(int[], int);

int main(void)
{
    int i, j, calificaciones[MAX], frecuencia[MAX]={1,2,3,4,5,6,7,8,9,10};

    numeros_aleatorios(calificaciones, MAX);
    printf("\nLos resultados son : \n\n");

   /* printf("Calif.\tFrecuencia\tHistograma\n");
    printf("\n%-5d\t%-10d\t", calificaciones, frecuencia);
    for(i=0; i<10; i++) printf("*");
        printf("\n%-5d\t%-10d\t", calificaciones[i], frecuencia[i]);
        for(i=0; i<10; i++)
            printf("*");*/

    printf("Calif.\tFrecuencia\tHistograma\n");
    printf("\n%-5d\t%-10d\t", calificaciones, frecuencia);
    for(i=0; i<10; i++)
    {
        printf("\n%d",frecuencia[i]);
    }
    for(j=0; j<10; j++)
    {
        printf("\t\n*", numeros_aleatorios(calificaciones, MAX));

    }

    return 0;
}

//Generar numeros aleatorios
int numeros_aleatorios(int calificaciones[], int tam)//arreglo, tamaño del arreglo
{
    int i, acumulador;
    do
    {
        srand(time(NULL));
        for(i=0; i<tam; i++)
        {
            calificaciones[i]=rand()%50+1;//no existen los parametros como en python
            acumulador++;
        }
    }while(acumulador!=50);
    return calificaciones[tam];
}

