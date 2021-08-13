//no son instrucciones de C, las realiza el preprocesador
//no es practico, porquecada vez que cambien el define, se tiene que volver a compilar
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//constantes simbolicas
#define MAX 20
#define CALIF 6

void crea_calificaciones(int[], int);
void muestra_arreglo(int[], int);
void calcula_frecuencias(int[], int[], int);

int main(void)
{
    int calificaciones[MAX], frecuencias[CALIF] = {0};
    srand(time(NULL));

    crea_calificaciones(calificaciones, MAX);
    printf("\n\nArreglo de calificaciones:\n\n");
    muestra_arreglo(calificaciones, MAX);

    calcula_frecuencias(calificaciones, frecuencias, MAX);
    printf("\n\nArreglo de frecuencias:\n\n");
    muestra_arreglo(frecuencias, CALIF);


    return 0;
}


void crea_calificaciones(int calificaciones[], int tam)
{
    while(tam>0)
    {
        calificaciones[tam-1] = rand()%CALIF;
        tam--;
    }
}

void muestra_arreglo (int array[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        printf("Elemento %d: %d\n",i, array[i]);


}

void calcula_frecuencias(int calificaciones[], int frecuencias[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
        frecuencias[ calificaciones[i] ]++;
}
