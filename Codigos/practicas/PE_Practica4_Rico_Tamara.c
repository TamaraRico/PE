/* Rico López Tamara Illian 127063
Practica 4
Programa que imprime todos los números de tres cifras que al elevar al cubo es el mismo número de 3 cifras*/

#include<stdio.h>

int main()
{
    //Declaración de variables
    int i, j, k, a, b, c;

    //ciclo for
    for(i=1; i<=9; i++)
        {
            a=i*i*i;
            //printf("\na=%d", a);
            for(j=0; j<=9; j++) //ciclo for aninado
            {
                b=j*j*j;
                //printf("\nb=%d", b);
                for(k=0; k<=9; k++)
                {
                    c=k*k*k;
                    //printf("\nc=%d", c);
                    if((a+b+c)==(i*100+j*10+k))
                        printf("\n%d%d%d", i, j, k);
                }
            }
        }

    return 0;
}
