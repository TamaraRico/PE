/*Rico Lopez Tamara Illian 1270673
PRCATICA 6
Captura de polinimios en un menu con funciones*/

#include<stdio.h>
#include<math.h>

//matriz para almacenar el polinomio (coeficiente, exponente), filas columas
void captura_polinomio(float[], int);

//arreglo para almacenar el polinomio resultado
float evaluar_polinomio(float [],float, int);

int main(void)
{
    int i, j, opc, grado;
    float polinomio[6], num;

    printf("Captura el grado del polinomio (1 al 5) : ");
    scanf("%d", &grado);

    captura_polinomio(polinomio, (grado+1));
    /*for(i=0; i<=grado; i++)
        printf("%f", polinomio[i]);*/
    j=grado;
    do
    {

        printf("\n\nMENU: ");
        printf("\n1) Modificar el polinomio ");
        printf("\n2) Imprimir el polinomio ");
        printf("\n3) Evaluar el polinomio ");
        printf("\n4) Salir ");

        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc)
        {
            case 1:
                printf("Vuelva a capturar el polinomio ");
                captura_polinomio(polinomio, grado);
                break;
            case 2:
                printf("El polinomio capturado es : \n");
                    for(i=0; i<=grado; i++)
                    {
                        printf("+%.1fx^%d", polinomio[i], j);
                        j-=1;
                        //printf("%d", sizeof(polinomio)/sizeof(float));
                    }
                break;
            case 3:
                printf("Capture el numero : ");
                scanf("%f", &num);
                printf("El polinomio evaluado en %.2f es igual a %.2lf ", num, evaluar_polinomio(polinomio, num, grado));
                break;
            case 4: break;
            default: printf("\nSeleccione una opc valida\n");
        }
    }while(opc!=4);

    return 0;
}

//Captura de polinomios
void captura_polinomio(float arreglo[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("Ingrese un valor: ");
        scanf("%f", &arreglo[i]);
    }

}

//evaluacion de los polinomios
float evaluar_polinomio(float arreglo[], float num, int grad)
{
    int i, j=grad;
    double a=0;
    for(i=0; i<=grad; i++)
    {
        a=a+(arreglo[i]*(pow(num,j)));//tipo de dato que recibe puede estar mal
        j-=1;
    }
    return a;
}
