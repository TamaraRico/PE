#include<stdio.h>

//FLUJO DE ARCHIVOS
//un flujo en c es un apuntador a una estructura FILE
int main()
{
    //Tenemos acceso a los flujos
    //FILE *stdin: flujo estandar de entrada (teclado)
    //FILE *stdout : flujo estandar de salida ()
    //FILE *stderr : flujo estandar de error (monitor)
    FILE *flujo;

    //crear un nuevo flujo
    flujo=fopen("ejemplo.txt", "w");
    //Nombre del archivo: "ejemplo.txt"
    //Modo de acceso: w - Escritura

    //escribir en ese flujo
    fprintf(flujo, "hola mundo");

    //cerrar el flujo
    fclose(flujo);

    return 0;
}
