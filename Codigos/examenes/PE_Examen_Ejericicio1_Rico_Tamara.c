/*Realizar una función que dado un rango de números, imprima todos los números
primos que se encuentren dentro del mismo. Por ejemplo, en el rango 1 al 5,
debería imprimir 2, 3 y 5.*/

#include<stdio.h>

int main (void)
{
    int rangox, rangoy, i, j, a;
    printf("\nNUMEROS PRIMOS EN UN RANGO DE NUMEROS\n\n");
    do
    {
        printf("Escriba un rango de numeros (x,y): ");
        scanf("%d,%d", &rangox, &rangoy);
        if(rangoy<=rangox)
        {
            printf("\nEl primer numero debe ser menor que el segundo");
            printf("\nIntentalo otra vez");
        }
    }while(rangoy<=rangox);

    for(j=rangox; j<=rangoy; j++)
    {
        a=0;
        //printf("\nj=%d", j);
        for(i=1; i<=j; i++)
        {
            //printf("\ni=%d", i);
            if(j%i==0)
            {
                a++;
                //printf("\na=%d", a);
            }
        }
        if(a==2||j==1||j==0)
        {
            printf("\nEl numero %d es primo", j);
        }
        else
        {
            printf("\nEl numero %d no es primo", j);
        }
    }

    return 0;
}

