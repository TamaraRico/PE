/*Rico Lopez Tamara Illian 1270673
PRACTICA 5
Programa que calcula la diferencia entre dos horas en segundos*/
#include<stdio.h>

//prototipo de funcion
int difseg(int, int, int, int, int, int);

int main(void)
{
    int h1, m1, s1, h2, m2, s2;
    char opc;

    do
    {
        printf("\nIngrese la hora inicial (HH:MM:SS) = ");
        scanf("%d:%d:%d", &h1, &m1, &s1);
        printf("\nIngrese la hora final (HH:MM:SS) = ");
        scanf("%d:%d:%d", &h2, &m2, &s2);
        if(h1<0||h2<0||m1<0||m2<0||s1<0||s2<0)
            printf("\nLa hora se mide en numeros positivos, intentalo otra vez");
    }while(h1<0||h2<0||m1<0||m2<0||s1<0||s2<0);//para no capturar numeros negativos

    printf("\n\nSeleccione el formato de salida : ");
    printf("\nH : Horas ");
    printf("\nM : Minutos ");
    printf("\nS : Segundos ");

    printf("\n\nSeleccione una opcion: ");
    scanf("%d", &opc);
    //el formato del resultado
    if(opc=='S'||opc=='s')
        printf("\nLa diferencia entre %d:%d:%d y %d:%d:%d es de %d segundos", h1, m1, s1, h2, m2, s2, difseg(h1, h2, m1, m2, s1, s2));
    else if(opc=='m'||opc=='M')
            printf("\nLa diferencia entre %d:%d:%d y %d:%d:%d es de %d minutos", h1, m1, s1, h2, m2, s2, difseg(h1, h2, m1, m2, s1, s2)*60);
    else if(opc=='H'||opc=='h')
        printf("\nLa diferencia entre %d:%d:%d y %d:%d:%d es de %d horas", h1, m1, s1, h2, m2, s2, difseg(h1, h2, m1, m2, s1, s2)*3600);

    return 0;
}

//funcion
int difseg(int h1, int h2, int m1, int m2, int s1, int s2)
{
    int s;
    s=((3600*(h1-h2))+(60*(m1-m2))+(s1-s2));
    if(s<0)//en caso de que el resultado de la resta sea negativo
        s=-s;
    return s;
}
