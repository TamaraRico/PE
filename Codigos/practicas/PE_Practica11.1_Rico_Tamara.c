/*Rico Lopez Tamara Illian 01270673
PRACTICA 11
Lectura de un archivo*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    //ch almacena los caracteres que se leen del archivo para imprimirlos
    //nombre del archivo almacena el nombre del archivo para poder acceder a él
    char ch, nombre_archivo[25];
    FILE *archivo;
    //representa el flujo del archivo

    printf("Ingrese el nombre del archivo que desea leer : ");
    gets(nombre_archivo);

    //abre el archivo en modo lectura
    archivo=fopen(nombre_archivo, "r");

    //si no se puede leer del archivo, se sale del programa
    if (!archivo)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    printf("El contenido del archivo %s es:\n", nombre_archivo);
    //imprime el contenido del archivo mientras no se llegue al final
    while((ch=fgetc(archivo))!= EOF)
        printf("%c",ch);

    //cierra el archivo
    fclose(archivo);

    return 0;
}
