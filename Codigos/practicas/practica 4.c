/*ESTRUCTUAS DE CONTROL ITERATIVAS

for()
do
while
while

variable de control=las variables dentro de la condicion

centinela=no se detiene por un contador, sino por factores externos, como al pedirle al usuario si quiere volver a jugar*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    //int i=0; //contador
    //char opt = 's';

    /*while (i<10)
    {
        printf("Hola\n");
        i++; //i=i+1
    }

    do //hacer algo al menos una vez, menu, juego
    {
        printf("mundo\n");

    }while(i<10);*/
    int num=0, c=0;
    float prom=0;

    /*for (i=0; num!=-1; i++)
    {
        printf("Introduzca un numero : ");
        scanf("%d", &num);
    }
    printf("%d Numeros diferentes de -1", i); //cuantos numeros se ingresan contando el -1*/

   /* while(num!=-1)
    {
        printf("Introduzca un numero : ");
        scanf("%d", &num);
        if (num!=-1)//diferentes formas de resolverse
        {
            c++;
            prom+=num;
        }
    }
    prom=prom/c;
    printf("%d contador y el promedio %f", c, prom);*/

    int a, b;

    for(a=0; a<10; a++)
    {
        for(b=0; b<10; b++)
        {
            if (a==b)
                printf("%d%d\n", a, b);
                printf("Valor : %d\n", a*10+b);
        }
    }

    int num2;
    do
    {
        printf("\nIntroduzca un número entre 0 - 100 : ");
        scanf("%d", &num2);
    }while(num2<0||num2>100);
    printf("\nValor capturado : %d \n", num2);

    int n, i;

    //Se ejecuta una vez la principio del programa
    srand(time(NULL));

    for(i=0; i<10; i++)
    {
        //esto nos da entre 0-99 y se sumamos 1 para que alcance el 1 y 100
        n=rand()%100 + 1;//no existen los parametros como en python
        printf("\n%d", n);
    }

    return 0;


    //ctrol+c=cierre de ciclo infinito
}
