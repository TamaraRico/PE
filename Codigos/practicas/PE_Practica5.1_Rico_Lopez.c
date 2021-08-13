#include<stdio.h>
#include<math.h>

float pendiente(float, float, float, float);
float rad2grad(float);
float angulo(float);

int main(void)
{
    float x1, x2, y1, y2, b, p;

    printf("\nIngrese las coordenadas del primer punto (x,y) : ");
    scanf("%d,%d", &x1, &y1);
    printf("\nIngrese las coordenadas del segundo punto (x,y) : ");
    scanf("%d,%d", &x2, &y2);

    p=pendiente(x1, y1, x2, y2);
    b=-p+y1;

    printf("\n\nLa ecuacion de la recta que formas los puntos es : y=%.2fx+%.2f", pendiente(x1, y1, x2, y2), b);
    printf("\nEl angulo de inclinacion de la recta es : %f", angulo(rad2grad( pendiente(x1, y1, x2, y2))));

    return 0;
}

float pendiente(float x1, float y1, float x2, float y2)
{
    float p;
    p=(y2-y1)/(x2-x1);
    return p;
}

float angulo(float pendiente)
{
    return atan(pendiente);
}

float rad2grad(float angulo)
{
    return angulo*3.1416/180;
}
