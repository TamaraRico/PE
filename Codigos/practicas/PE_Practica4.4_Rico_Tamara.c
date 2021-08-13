/*Rico López Tamara Illian 1270673
Practica 4 Juego Adivinar el numero*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(void)
{
    int r, intento, i;//declaracion de variables
    char opcion='y';
    do
    {//para que se ejecute el programa, al menos una vez
        srand(time(NULL));//numeros al azar
        r=rand()%1000+1;//El numero generado seria hasta el 999, pero como queremos que cuente el 1000, sumamos 1
        //printf("\n%d", r);//para probar el codigo
        int i=0;//reinicio el contador
        while(intento!=r)//el ususario adivina hasta que acierta el numero
        {
            printf("\nTengo un numero entre 1 y 100");
            printf("¿Puedes adivinar mi numero? : ");
            scanf("%d", &intento);
            i++;//contador
            if(intento<r)
            {
                printf("\nMuy bajo, intentalo nuevamente");
            }
            else
            {//condiciones aninidadas, porque sino se cuenta el intento==r
                if(intento>r)
                {
                    printf("\nMuy alto, intentalo nuevamente");
                }
            }
        }
        if(i<10)
        {
            printf("\nFelicidades!! Has adivinado en pocos intentos");
            if(i==10)//if aninado
            {
                printf("\nYa conoces el numero secreto!!");
            }
        }
        else
        {
            printf("\nBien hecho!Lo puedes hacer mejor");
        }

        printf("\nExcelente!!! Has adivinado el numero");
        printf("\n***************El numero de intentos fue %d ***************************", i);
        printf("\nQuieres jugar otra vez?(y/n) : ");
        scanf("%s", opcion);

    //el programa seguirá corriendo hasta que se introduza una n
    }while(opcion=='y');

    return 0;
}
