/*Rico Lopez Tamara Illian 1270673
PRACTICA 8
Programa que calcula las raíces de una ecuación de segundo grado con funciones y apuntadores*/

#include<stdio.h>
#include<math.h>

//prototipo de la funcion con apuntadores
void raices_fg(float, float, float, float*, float*);

int main(void)
{
    //declaracion de apuntadores
    float *raiz1, *raiz2;
    int a, b, c;

    //captura de datos
    printf("Introduzca el valor de a : ");
    scanf("%d", &a);
    if (a==0)//validar que sea una ecuación de segundo grado
    {
        printf("\nEl valor de a debe ser diferente de cero");
        printf("Introduzca el valor de a : ");
        scanf("%d", &a);
    }
    printf("Introduzca el valor de b : ");
    scanf("%d", &b);
    printf("Introduzca el valor de c : ");
    scanf("%d", &c);
    printf("La ecuación de segundo grado queda como : %dx2 + %dx + %d", a, b, c);

    //llamada a la función
    raices_fg(a, b, c, raiz1, raiz2);
   /* printf("\nEl valor de la raiz1 es de %f\n", *raiz1);
    printf("\nEl valor de la raiz2 es de %f\n", *raiz2);*/

    printf("\nFin");
    return 0;
}

//función para obtener las raíces de la ecuación
void raices_fg(float a, float b, float c, float *raiz1, float *raiz2)
{
    float discriminante, r, img, raiz;
    discriminante=(b*b)-(4*a*c);
    if (discriminante<0)
    {
        raiz=sqrt(-discriminante); //sqrt((
        r=(-b)/(2*a);
        printf("\n\nr=%.2f\n", r);
        img=raiz/(2*a);
        printf("\nEl valor de la raiz1 es de %.2f + %.2fi", r, img);
        printf("\nEl valor de la raiz2 es de %.2f - %.2fi", r, img);
    }
    else
    {
        raiz=sqrt(discriminante);
        printf("\nraiz=%.1f", raiz);
        *raiz1=(-b+raiz)/(2*a);
        //printf("\nraiz1=%f", *raiz1);
        *raiz2=(-b+raiz)/(2*a);
        printf("\nEl valor de la raiz1 es de %f\n", raiz1);
        printf("\nEl valor de la raiz2 es de %f\n", raiz2);
    }
}
