/* Rico Lopez Tamara Illian 1270673
Programa para convertir  unidades de tiempo a segundos*/
#include <stdio.h>

/*función principal*/
int main(void)
{
    int dias, horas, minutos, segundos, total;

    printf("\tPrograma para convertir  unidades de tiempo a segundos");
    printf("\n\nIntroduzca la cantidad de dias : ");
    //funcion de captura
    scanf("%d", &dias);
    printf("\n\nIntroduzca la cantidad de horas : ");
    //funcion de captura
    scanf("%d", &horas);
    printf("\n\nIntroduzca la cantidad de minutos : ");
    //funcion de captura
    scanf("%d", &minutos);
    printf("\n\nIntroduzca la cantidad de segundos : ");
    scanf("%d", &segundos);
    total = dias * 86400 + horas * 3600 + minutos * 60 + segundos;
    //función de salida
    printf("\n\nLa cantidad %ddias, %dhoras, %dminutos y %d seguntos son en total %dsegundos\n", dias, horas, minutos, segundos, total);

    return 0;
}
