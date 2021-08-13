/*Rico Lopez Tamara Illian 01270673
PRACTICA 11
Lectura de un archivo y manipulacion en consola */

#include<stdio.h>
#include<stdlib.h>

int main(/*int argc, char** argv*/)
{
    //ch almacena los caracteres que se leen del archivo para imprimirlos
    //nombre del archivo almacena el nombre del archivo para poder acceder a él
    char ch, nombre_archivo[25], entrada;
    int nlineas=0, npalabras=0, ncaracteres=0;
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

    printf("\nSeleccionar una opcion : ");
    scanf("%c", &entrada);
  /*  if(argc>4)
    {
        printf("\nError en el numero de parametros ");
        printf("\nEjemplo PE_Practica11.3_Rico_Tamara.exe l ej1.txt")
        exit(-1);
    }*/

    //entrada=argv[1];
    printf("El contenido del archivo %s es:\n", nombre_archivo);
    //imprime el contenido del archivo mientras no se llegue al final

    if(entrada=='l')
    {
        while((ch = fgetc(archivo)) != EOF)
        {
            if( ch == '\n')
                nlineas++;
            putchar(ch);
        }
        printf ("\nNúmero de líneas del archivo: %d\n",nlineas+1);
    }
    /*while((ch=fgetc(archivo))!= EOF)
        printf("%c",ch);*/
    else if(entrada=='c')
    {
        while((ch=fgetc(archivo))!= EOF)
            ncaracteres+=1;
        printf ("\nNúmero de caracteres del archivo: %d\n", ncaracteres);
    }
    else if(entrada=='w')
    {
        while (fscanf (archivo, "%s", ch) == 1)
            npalabras+=0;
        printf ("\nNúmero de palabras del archivo: %d\n", npalabras);
    }
    else
    {
        printf("\nLa opcion no es valida");
        exit(-1);
    }
    //cierra el archivo
    fclose(archivo);

    return EXIT_SUCCESS;
}
