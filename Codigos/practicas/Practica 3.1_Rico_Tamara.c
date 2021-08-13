/*Rico Lopez Tamara Illian 1270673
Leer la hora */

#include<stdio.h>

int main(void)
{
    int hora, minutos, segundos, dia=0;


    printf("Escribe la hora : ");
    scanf("%d", &hora);
    if (hora<0)
    {
        printf("\nHora no válida, debe ser un número mayor a cero");
        printf("Escribe la hora : ");
        scanf("%d", &hora);
    }
    printf("Escribe los minutos : ");
    scanf("%d", &minutos);
    if (minutos<0)
    {
        printf("\nMinutos no válidos, debe ser un número mayor a cero");
        printf("Escribe los minutos : ");
        scanf("%d", &minutos);
    }
    printf("Escribe los segundos : ");
    scanf("%d", &segundos);
    if (segundos<0)
    {
        printf("\nSegundos no válidos, debe ser un número mayor a cero");
        printf("Escribe los segundos : ");
        scanf("%d", &segundos);
    }
    printf("La hora que ingresaste fue : %d : %d : %d ", hora, minutos, segundos);
    segundos=segundos+1;
    printf("\n\n%d", segundos);

    if (segundos>=60)
    {
        segundos=segundos-61;
        minutos+=1;
    }
        if (minutos>=60)
        {
            minutos=minutos-60;
            hora+=1;
        }
            if (hora>=24)
            {
                hora=hora-24;
                dia=dia+1;
                printf("\n\nLa hora más 1 segundo es: %d : %d : %d : %d \n\n", dia, hora, minutos, segundos);

            }
            else
            {
                printf("\n\nLa hora más 1 segundo es: %d : %d : %d : %d \n\n", dia, hora, minutos, segundos);
            }


    return 0;
}
