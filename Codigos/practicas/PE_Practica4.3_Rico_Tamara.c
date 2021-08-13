/* Rico López Tamara Illian 127063
Practica 4
Programa que imprime todos los números de 4 cifras que la suma de las cifras impares es igual a las pares*/

#include<stdio.h>
//creo que lo hice al principio esta bien
int main()
{
    //Declaración de variables
    int i, j, k, l;

    //for(a=0; a%2==0; a)
    //ciclo for
    for(i=1; i<=9; i++)
        {
            //printf("\na=%d", a);
            for(j=0; j<=9; j++) //ciclo for aninado
            {
                //printf("\nb=%d", b);
                for(k=0; k<=9; k++)
                {
                    //printf("\nc=%d", c);
                    for(l=0; l<=9; l++)
                    {
                        //printf("\nb=%d", b);
                        if(i+k==j+l)
                        {
                            printf("\n%d%d%d%d\n", i, j, k, l);
                        }/*if(i+k == j+l)*/
                    }
                }
            }
        }

    return 0;
}

