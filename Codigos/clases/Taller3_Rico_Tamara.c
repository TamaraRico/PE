/*Taller 3
Juego de multiplicar.

Completar los siguientes requerimientos:
1. Solicitar al usuario el número de preguntas
2. Al finalizar el juego, se debe mostrar:
    2.1 Número de aciertos y porcentaje (50% 2/4)
    2.2 Total de tiempo que tardó en contestar
    2.3 Mostrar puntos

Ejemplo:

    ***** Resultado *****
    Aciertos: 2/4 (50%)
    Tiempo total: 4s
    Puntos: 4000
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

double difftime(time_t, time_t);
float porcentaje_aciertos(int, int);
int tiempo_mayor(int[], int);
int tiempo_menor(int[], int);
void imprime_menu();

int main(void)
{
    int preguntas, aciertos=0, p;
    time_t inicio, fin, start, end;
    int a, b, x, respuesta;
    int puntuacion=0, tiempo_total=0, opc;
    double tiempo_transcurrido;

    /*time(time*) devuelve la hora actual*/
    /*srand(long int) establece una semilla para generar números
        aleatorios*/
    //Esta instrucción se ejecuta solo una vez en el programa
    srand(time(NULL));

    time(&start);
    printf("Ingrese el numero de preguntas que desea responder : ");
    scanf("%d", &p);
    preguntas=p;
    printf("\n\nContesta tan rapido como puedas!!!\n");
    int arreglo[preguntas];

    imprime_menu();
    printf("\nNivel de dificultad : ");
    scanf("%d", &opc);
    do
    {
        if(opc==1)
        {
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
        }
        else if(opc==2)
        {
            a = rand() % 14 + 2;
            b = rand() % 14 + 2;
        }
        else if(opc==3||opc==4)
        {
            a = rand() % 25 + 6;
            b = rand() % 25 + 6;
        }
        //rand() genera un número aleatorio entero
        if(opc!=4)
        {
            printf("\n%d X %d = ", a, b);

            /*clock() regresa el número de pulsos de reloj
            desde el inicio del proceso*/
            time(&inicio);//epieza a correr el tiemo para er cuanto va a tardar

            scanf("%d", &respuesta);

            time(&fin);
            //Restando fin e inicio sabremos cuanto tardó en responder

            if (respuesta == a * b)
            {
                printf("\tCorrecto! (");
                aciertos+=1;
                puntuacion+=1000;
            }
            else
            {
                printf("\tIncorrecto (");
                puntuacion-=100;
            }
        }
    else
    {
        x = rand() % 4 + 1;
        if(x==1)
        {
            printf("\n%d + %d = ", a, b);
            time(&inicio);
            scanf("%d", &respuesta);
            time(&fin);
            if(respuesta==a+b)
            {
                printf("\tCorrecto! (");
                aciertos+=1;
                puntuacion+=1000;
            }
            else
            {
                printf("\tIncorrecto (");
                puntuacion-=100;
            }
        }
        else if(x==2)
        {
            printf("\n%d - %d = ", a, b);
            time(&inicio);
            scanf("%d", &respuesta);
            time(&fin);
            if(respuesta==a-b)
            {
                printf("\tCorrecto! (");
                aciertos+=1;
                puntuacion+=1000;
            }
            else
            {
                printf("\tIncorrecto (");
                puntuacion-=100;
            }
        }
        else if(x==3)
        {
            printf("\n%d X %d = ", a, b);
            time(&inicio);
            scanf("%d", &respuesta);
            time(&fin);
            if(respuesta==a*b)
            {
                printf("\tCorrecto! (");
                aciertos+=1;
                puntuacion+=(1000*5);
            }
            else
            {
                printf("\tIncorrecto (");
                puntuacion-=(100*5);
            }
        }
        else if(x==4)
        {
            while(a%b!=0)
            {
                a = rand() % 25 + 6;
                b = rand() % 25 + 6;
            }
            printf("\n%d / %d = ", a, b);
            time(&inicio);
            scanf("%d", &respuesta);
            time(&fin);
            if(respuesta==a/b)
            {
                printf("\tCorrecto! (");
                aciertos+=1;
                puntuacion+=(1000*10);
            }
            else
            {
                printf("\tIncorrecto (");
                puntuacion-=(100*10);
            }
        }
    }
    tiempo_transcurrido = difftime(fin, inicio);
    printf("%.1f s)\n", tiempo_transcurrido);
    arreglo[preguntas]=tiempo_transcurrido;

    if(tiempo_transcurrido==2||tiempo_transcurrido==3)
    {
        puntuacion-=50;
    }
        else if(tiempo_transcurrido>=4&&tiempo_transcurrido<=8)
    {
        puntuacion-=(tiempo_transcurrido-3)*100;
    }
    else if(tiempo_transcurrido>8&&(respuesta==a*b))
    {
        puntuacion-=1000;
    }

    } while (--preguntas > 0);

    time(&end);

    //porcentaje_aciertos(preguntas, aciertos);
    printf(" \n\n***** Resultado ***** ");
    printf("\nAciertos: %d/%d %.2f", aciertos, p, porcentaje_aciertos(p, aciertos));
    printf("\nTiempo transcurrido: %.2f", difftime(end, start));
    printf("\nPuntuación : %d", puntuacion);
    printf("\nTiempo mayor : %d", tiempo_mayor(arreglo, p));
    printf("\nTiempo menor : %d", tiempo_menor(arreglo, p));

    return 0;
}

float porcentaje_aciertos(int preg, int a)
{
    return (a/preg*100);
}

int tiempo_mayor(int arreglo[], int tam)
{
    int i, mayor=0;
    for(i=0; i<tam; i++)
    {
        if(arreglo[i]>arreglo[mayor])
            mayor=i;
    }
    return mayor;
}

int tiempo_menor(int arreglo[], int tam)
{
    int i, menor=0;
    for(i=0; i<tam; i++)
    {
        if(arreglo[i]<menor)
            menor=i;
    }
    return menor;
}

void imprime_menu()
{
    printf("\n\nElige el nivel de dificultad");
    printf("\n1)Facil ");
    printf("\n2)Medio ");
    printf("\n3)Alto ");
    printf("\n4)PRO ");
}

