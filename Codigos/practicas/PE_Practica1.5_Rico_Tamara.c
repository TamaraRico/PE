/* Rico Lopez Tamara Illian 1270673
Programa para calcular el area y el perimetro de un terreno*/
#include <stdio.h>

/*función principal*/
int main(void)
{
    float ancho, largo, p, a;

    printf("\tPrograma para calcular el area y el perimetro de un terreno");
    printf("\n\nIntroduzca el ancho del terreno (en m) : ");
    //funcion de captura
    scanf("%f", &ancho);
    // largo = 3 * ancho
    largo = 3 * ancho;
    //función de salida
    printf("El largo del terreno es %fm y el ancho es  %fm\n", largo, ancho);
    p = (2 * ancho) + (2 * largo);
    a = ancho * largo;
    printf("\n\nEl perimetro del terreno es %fm y el area es %fm2\n\n", p, a);

    return 0;
}
