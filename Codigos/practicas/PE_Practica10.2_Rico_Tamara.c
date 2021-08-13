/*Rico Lopez Tamara Illian 01270673
PRACTICA 10
Estructura de numeros racionales*/

#include<stdio.h>

//definicion de la estructura
struct racional{
    int num;//numerador
    int den;//denominador
};

//prototipos de funciones
struct racional captura();
void mostar_racional(struct racional);//tipo de dato: struct racional
void suma_racionales(struct racional, struct racional);
void resta_racionales(struct racional, struct racional);
void mult_racionales(struct racional, struct racional);
void div_racionales(struct racional, struct racional);


int main()
{
    //declarar variables con el nuevo tipo de dato
    struct racional r1, r2;
    r1=captura();
    mostar_racional(r1);
    printf("\n\nCaptute un segundo numero racional\n");
    r2=captura();
    mostar_racional(r2);

    suma_racionales(r1, r2);
    resta_racionales(r1, r2);
    mult_racionales(r1, r2);
    div_racionales(r1, r2);

    return 0;
}

struct racional captura()
{
    struct racional r;
    printf("Ingrese un numero racional (ej 1/2): ");
    scanf("%d/%d", &r.num, &r.den);
    return r;
}

void mostar_racional(struct racional r)
{
    printf("Numero racional: %d/%d ", r.num, r.den);
}

void suma_racionales(struct racional r1, struct racional r2)
{
    int suma, suma_den;
    if(r1.den==r2.den)
    {//fracciones con comun denominador
        suma=r1.num+r2.num;
        printf("\n\nLa suma de los numeros racionales es : %d/%d ", suma, r1.den);
    }
    else
    {
        suma_den=r1.den*r2.den;
        suma=(r1.num*r2.den)+(r2.num*r1.den);
        printf("\n\nLa suma de los numeros racionales es : %d/%d ", suma, suma_den);
    }
}

void resta_racionales(struct racional r1, struct racional r2)
{
    int resta, resta_den;
    if(r1.den==r2.den)
    {//fracciones con comun denominador
        resta=r1.num-r2.num;
        printf("\nLa resta de los numeros racionales es : %d/%d ", resta, r1.den);
    }
    else
    {
        resta_den=r1.den*r2.den;
        resta=(r1.num*r2.den)-(r2.num*r1.den);
        printf("\nLa resta de los numeros racionales es : %d/%d ", resta, resta_den);
    }
}

void mult_racionales(struct racional r1, struct racional r2)
{
    printf("\nLa multiplicacion de los numeros racionales es : %d/%d ",r1.num*r2.num, r1.den*r2.den);
}

void div_racionales(struct racional r1, struct racional r2)
{
    printf("\nLa division de los numeros racionales es : %d/%d \n\n",r1.num*r2.den, r1.den*r2.num);
}

