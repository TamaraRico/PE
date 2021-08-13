#include<stdio.h>

int main(void)
{
    /*char hola[]="hola";
    int array[3][3] = {{1}, {2,2,2}, {3,3,3}};
    printf("%d", array[0][2]);
    printf("%s", hola);
    printf("\nbytes reservados: %d", sizeof(hola));*/
    int i, arreglo[]={1,2,3,4,5,6}, tamano=6;
    float promedio=0;
    double desv=0;
    for(i=0; i<tamano; i++)
    {
        promedio+=arreglo[i];
    }
    promedio=promedio/tamano;
    for(i=0; i<tamano; i++)
    {
        desv+=pow((arreglo[i]-promedio),(2));
    }
    desv=sqrt(desv/tamano);
    printf("\ndesviacion = %lf", desv);
    return 0;
}
