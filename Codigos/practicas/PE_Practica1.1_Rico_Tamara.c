/* Rico Lopez Tamara Illian 1270673
Programa para convertir  unidades de pulgadas a milímetros*/
#include <stdio.h>

/*función principal*/
int main(void)
{
    float pulgadas, milimetros;

    printf("\tPrograma para convertir  unidades de pulgadas a milimetros");
    printf("\nCantidad de lluvia que se ha presentado este año");
    printf("\n\nIntroduzca el valor en pulgas: ");

    //funcion de captura
    scanf("%f", &pulgadas);

    // 1in = 25.4 milimetros
    milimetros = pulgadas * 25.4;

    //función de salida
    printf("La cantidad de pulgadas equivalentes a %fin son %fmm\n", pulgadas, milimetros);
    printf("\n\n PRESIONE ENTER PARA SALIR...");

    return 0;
}

