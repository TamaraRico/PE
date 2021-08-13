#include<stdio.h>
//FLUJOS DE ARCHIVOS

int main(void)
{
    int num;
    fprintf(stdout, "Ingrese un numero : ");
    //flujo de entrada
    fscanf(stdin, "%d", &num);
    //equivalente a scanf, la única diferencia es el stdin

    fprintf(stdout, "El numero capturado es : %d\n", num);
    //ligado al flujo estandar de Salida
    return 0;
}
