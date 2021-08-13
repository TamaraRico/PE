/*Realizar una funci�n que reciba un arreglo de n�meros reales y regrese el valor
resultante del c�lculo de la desviaci�n est�ndar. Note que X barra se refiere al
promedio de los datos; y, X sub�ndice i, se refiere a los valores en el arreglo en
el �ndice i.*/

/*Rico Lopez Tamara Illian 1270673*/

#include<stdio.h>
#include<math.h>

float desviacion_estandar(int arreglo[], int);
void captura(int[], int);

int main(void)
{
    int tam;
    printf("\nCuantos numeros desea capturar : ");
    scanf("%d", &tam);
    int arreglo[tam];
    captura(arreglo, tam);
    printf("\n\nLa desviacion estandar de los numeros capturados es : %lf", desviacion_estandar(arreglo, tam));
    return 0;
}

//captura de los numeros en ell arreglo
void captura(int arreglo[], int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        printf("\nIngrese un numero : ");
        scanf("%d", &arreglo[i]);
    }
}

float desviacion_estandar(int arreglo[], int tamano)
{
    int i;
    float promedio=0;
    double desv=0;
    for(i=0; i<tamano; i++)
    {
        promedio+=arreglo[i];
    }
    promedio=promedio/tamano;
    for(i=0; i<tamano; i++)
    {
        desv+=pow((arreglo[i]-promedio),(2));
    }
    desv=sqrt(desv/tamano);
    return desv;
}
