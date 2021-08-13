/*Realizar una función que calcule el valor de coseno de un ángulo
mediante la serie de taylor, como se describe en la siguiente imagen.
El prototipo de la función debe ser el siguiente: float cos(float x, int n).
Donde x es el ángulo y n el número de iteraciones.*/

#include<stdio.h>
#include<math.h>

#define PI 3.1416

float funcion_cos(float, int);

int main(void)
{
    float angulox;
    int num;
    printf("\nSERIES DE TAYLOR");
    printf("\nEvaluar el coseno en grados x = ");
    scanf("%f", &angulox);
    angulox=angulox*PI/180;
    printf("\nIngrese el numero de iteraciones ");
    scanf("%d", &num);
    printf("\nEl coseno de %f = %f", angulox, funcion_cos(angulox, num));
    return 0;
}

float funcion_cos(float x, int n)
{
    int i;
    float acumulador=1, iteracion=1;
    for(i=1; i<=2*n; i+=2)//donde n es el numero de repeticiones
    {
        iteracion=(-1)*iteracion*x*x/(i*(i+1));
        acumulador+=iteracion;
    }
    return acumulador;
}

