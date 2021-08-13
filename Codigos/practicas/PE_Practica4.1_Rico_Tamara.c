/*Rico Lopez Tamara Illian 1270673
Practica 4
DETERMINAR SI UN NUMERO CAPTURADO ES PRIMO*/
#include<stdio.h>

int main()
{
    int num, i, a=0;
    char opcion='s';

    while(opcion=='s')//se repetirá hasta que el usuario lo decida (ciclo por centinela)
    {
        printf("Capture un numero : ");
        scanf("%d", &num);
        /*for(i=1; i<=num; i++)
            {
                if(num%i==0)
                {
                    a++;
                }
            }
        if(a==2||num==1||num==0)
        {
            printf("\nEl numero %d es primo", num);
        }
        else
        {
            printf(\nEl numero %d no es primo", num);
        }*/
        for(i=2; i<num; i++)
        {
            if(num%i!=0)
            {
                a=a+0;
            }
            else
            {
                a=a+1;
            }
        }
        if(a!=0)
        {
            printf("El numero %d no es un numero primo", num);
        }
        else
        {
            printf("El numero %d es un numero primo", num);

        }
        printf("\n¿Capturar otro numero?(s/n) : ");
        scanf("%c", opcion);
    }

    return 0;
}
