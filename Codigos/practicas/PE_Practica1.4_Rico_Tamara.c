/* Rico Lopez Tamara Illian 1270673
Programa que calcule la cantidad de antibiotico para un perro*/
#include <stdio.h>

/*función principal*/
int main(void)
{
    float peso, mm;
    printf("\tPrograma para calcular la cantidad de antibiotico de un perro");
    printf("\n\nIntroduzca el peso del perro (en kg): ");
    //funcion de captura
    scanf("%f", &peso);
    // 2kg = 25 mm
    mm = (25 * peso)/2;
    //función de salida
    printf("La cantidad de antibiotico para el perro que pesa %fkg es %fmm\n", peso, mm);

    return 0;
}
