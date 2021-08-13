/*Rico Lopez Tamara 1270673
PRACTICA 5
Programa que calcula el factorial de un numero*/
#include<stdio.h>

long int factorial(int);//prototipo de funcion

int main(void)//funcion main
{
    int num;

    printf("\nIngrese un numero entero : ");
    scanf("%d", &num);

    printf("\nEl factorial del numero %d es : %ld", num, factorial(num));

    return 0;
}

//siempre declarar e inicializar acumuladores
long int factorial(int num)
{
    long int fact=1;//acumulador
    int i;//contador
    for(i=1; i<=num; i++)
        fact=fact*i;
    //while(num)=fact*num--; (fact=fact*num; num=num-1
    return fact;

}
