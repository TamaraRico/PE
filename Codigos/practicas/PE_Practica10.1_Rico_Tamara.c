/*Rico Lopez Tamara Illian 01270673
PRACTICA 10
Estructura de un numero complejo*/

#include<stdio.h>
#include<math.h>

//estructura del numero complejo
struct complejo{
    float real;//parte real
    float img;//parte imaginaria
};

//prototipo de funciones
struct complejo captura();
void mostar(struct complejo);//tipo de dato: struct complejo
void mostar_polar(struct complejo);
void suma_complejos(struct complejo, struct complejo);
void resta_complejos(struct complejo, struct complejo);
void mult_complejos(struct complejo, struct complejo);
void div_complejos(struct complejo, struct complejo);

int main()
{
    //definicion de variables con el nuevo tipo de dato
     struct complejo c1, c2;
     c1=captura();
     mostar(c1);
     mostar_polar(c1);
     printf("\n\nCaptute un segundo numero complejo\n");
     c2=captura();
     mostar(c2);
     mostar_polar(c2);

     //operaciones aritmeticas con numeros complejos
     suma_complejos(c1, c2);
     resta_complejos(c1, c2);
     mult_complejos(c1, c2);
     div_complejos(c1, c2);

    return 0;
}

struct complejo captura()
{
    struct complejo c;
    printf("Ingrese numero complejo (ej 1+2i): ");
    scanf("%f+%fi", &c.real, &c.img);
    return c;
}

void mostar(struct complejo c)
{
    printf("Numero complejo: %.1f + %.1fi ", c.real, c.img);
}

void mostar_polar(struct complejo c)
{
    float z, angulo;
    //el modulo de los numeros en su parte real
    z=sqrt((pow(c.real,2))+(pow(c.img,2)));
    //el angulo que forma en su parte imaginaria en radianes
    //la funcion atan2 realiza la division de ambos parametros
    angulo=atan2(c.img,c.real);
    if(angulo<-3.1416)//validar que el angulo que se toma sea el real de acuerdo al cuadrante
        angulo+=3.1416;
    else if(angulo>-3.1416 && angulo<-4.7123)
        angulo=-(angulo)+6.2831;
    else if(angulo>-4.7123 && angulo<-6.2831)
        angulo=6.2831-angulo;
    printf("\nNumero complejo en forma polar: %.1f(cos %.1f + sen %.1f)", z, angulo, angulo);
}

void suma_complejos(struct complejo c1, struct complejo c2)
{
    float sum1, sum2;
    //sumas por separados
    sum1=c1.real + c2.real;
    sum2=c1.img + c2.img;
    printf("\n\nLa suma de los numeros complejos es: %.1f + %.1fi", sum1, sum2);
}

void resta_complejos(struct complejo c1, struct complejo c2)
{
    float resta_real, resta_img;
    //restas por separado
    resta_real= c1.real - c2.real;
    resta_img = c1.img - c2.img;
    printf("\nLa resta de los numeros complejos es: %.1f + %.1fi", resta_real, resta_img);
}

void mult_complejos(struct complejo c1, struct complejo c2)
{
    float m_real, m_img;
    //multiplicaciones por la ley distributiva, en su parte real e imaginaria por la impresion
    m_real=(c1.real*c2.real)+((c1.img*c2.img)*-1);
    m_img=(c1.real*c2.img) + (c2.real*c1.img);
    printf("\nLa multiplicacion de los numeros complejos es: %.1f + %.1fi", m_real, m_img);
}

void div_complejos(struct complejo c1, struct complejo c2)
{
    float numerador_real, numerador_img, denominador;
    /*if(c2.img<0)
    {
        numerador_real=(c1.real*c2.real)+(-1)*(c1.img*(-c2.img));
        numerador_img=(c1.real*(-c2.img))+(c1.img*c2.real);
        denominador=c2.real*c2.real+((-c2.img)*c2.img)*(-1);
    }
    else
    {
        numerador_real=(c1.real*c2.real)+(-1)*(c1.img*(-c2.img));
        numerador_img=(c1.real*(-c2.img))+(c1.img*c2.real);
        denominador=c2.real*c2.real+((-c2.img)*c2.img)*(-1);
    }*/
    numerador_real=(c1.real*c2.real)+(-1)*(c1.img*(-c2.img));
    numerador_img=(c1.real*(-c2.img))+(c1.img*c2.real);
    denominador=c2.real*c2.real+((-c2.img)*c2.img)*(-1);
    printf("\nLa division de los numeros complejos es: %.1f + %.1fi\n", numerador_real/denominador, numerador_img/denominador);
}

