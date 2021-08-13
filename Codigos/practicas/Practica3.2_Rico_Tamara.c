/*Rico López Tamara Illian 1270673
Ecuaciones de segundo grado*/

#include<stdio.h>
#include<math.h>

int main(void)
{
    int a, b, c;
    float x1, x2, discriminante, r, img, raiz;
    printf("Introduzca el valor de a : ");
    scanf("%d", &a);
    if (a==0)
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

    discriminante=(b*b)-(4*a*c);
    printf("\n%d\n", discriminante);
    if (discriminante<0)
    {
        raiz=sqrt(-discriminante); //sqrt((
        r=(-b)/(2*a);
        printf("%f\n", r);
        img=raiz/(2*a);
        printf("\nEl valor de x1 es de %.2f + %.2fi", r, img);
        printf("\nEl valor de x2 es de %.2f - %.2fi", r, img);
    }
    else
    {
        raiz=sqrt(discriminante);
        x1=(-b+raiz)/2*a;
        x2=(-b+raiz)/2*a;
        printf("\nEl valor de x1 es de %f\n", x1);
        printf("\nEl valor de x2 es de %f\n", x2);
    }

    return 0;

}
