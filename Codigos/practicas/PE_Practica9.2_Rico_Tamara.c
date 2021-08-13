#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void captura_poli(float*, int);
float evaluarr_polinomio(float*, float, int);

int main(void)
{
    float *polinomio=NULL, x;
    int grado;

    printf("Captura el grado del polinomio : ");
    scanf("%d", &grado);

    polinomio=(float*)malloc((grado+1)*sizeof(float));
    captura_poli(&polinomio, (grado+1));

    printf("Captura el numero en el que desea evaluar al polinomio : ");
    scanf("%f", &x);
    printf("\nf(%.2f) = %.3f", x, evaluarr_polinomio(polinomio, x, grado));

    return 0;
}

//Captura de polinomios
void captura_poli(float* polinomio, int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%f", polinomio[i]);
    }

}

float evaluarr_polinomio(float* polinomio, float x, int grado)
{
    int i, j=grado;
    double a=0;
    for(i=0; i<=grado; i++)
    {
        a=a+(polinomio[i]*(pow(x,j)));//tipo de dato que recibe puede estar mal
        j-=1;
    }
    return a;
}
