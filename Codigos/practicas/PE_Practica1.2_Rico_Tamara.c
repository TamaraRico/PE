/* Rico López Tamara Illian 1270673
Programa para convertir grados centígrados a fahrenheit*/
#include <stdio.h>

/*función principal*/
int main(void)
{
    float centigrados, fahrenheit;

    printf("\tPrograma para convertir  grados centigrados a fahrenheit");
    printf("\n\nIntroduzca los grados en centigrados : ");

    //funcion de captura
    scanf("%f", &centigrados);

    // F = 9/5C + 32
    fahrenheit = ((9 * centigrados)/5) + 32;

    //función de salida
    printf("La cantidad de grados centigrados es %fC y en Fahrenheit es %fF\n", centigrados, fahrenheit);
    printf("\n\nPRESIONE ENTER PARA SALIR...");

    return 0;
}

