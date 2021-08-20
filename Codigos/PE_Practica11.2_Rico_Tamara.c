/*Rico Lopez Tamara Illian 01270673
PRACTICA 11
Lectura de un archivo y manipulacion en consola */

#include<stdio.h>
#include<stdlib.h>

//argc cuantos parametros enviamos por consola (2) - NUMERO DE PARAMATROS
//argv almacenar una matriz de caracteres  - LISTA DE PARAMETROS
int main(int argc, char** argv)
{
    //ch almacena los caracteres que se leen del archivo para imprimirlos
    //nombre del archivo almacena el nombre del archivo para poder acceder a él
    char ch, nombre_archivo[25];
    int opc;
    FILE *archivo;
    //representa el flujo del archivo

    printf("Ingrese el nombre del archivo que desea leer : ");
    gets(nombre_archivo);

    opc=atoi(argv[1]);
    /*printf("\nElija 1 o 2 :");
    scanf("%d", &opc);*/

    //abre el archivo en modo lectura
    archivo=fopen(nombre_archivo, "r");

    //si no se puede leer del archivo, se sale del programa
    /*if (argc!=2)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }*/

    archivo=fopen(argv[1], "r");
    if(!archivo)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    printf("El contenido del archivo %s es:\n", nombre_archivo);
        //imprime el contenido del archivo mientras no se llegue al final
    while((ch=fgetc(archivo))!= EOF)
    {
        if(opc==1)
            ch=toupper(ch);//convierte las letras mayusculas a minusculas
        printf("%c",ch);
    }

    //cierra el archivo
    fclose(archivo);

    return 0;
}
