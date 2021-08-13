#include<stdio.h>
#include<stdlib.h>

int main()
{
    //ch almacena los caracteres que se leen del archivo para imprimirlos
    //nombre del archivo almacena el nombre del archivo para poder acceder a él
    char *arreglo, nombre_archivo[25];
    FILE *archivo;
    int tam, i, k, j;
    //representa el flujo del archivo

    printf("Ingrese el nombre del archivo que desea leer : ");
    gets(nombre_archivo);

    //abre el archivo en modo lectura
    archivo=fopen(nombre_archivo, "rb");

    //si no se puede leer del archivo, se sale del programa
    if (!archivo)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }
//imprime el contenido del archivo seleccionado
    printf("El contenido del archivo %s es:\n", nombre_archivo);
//funcion que mueve el cursor del archivo
    fseek(archivo, 0L, SEEK_END);
    tam=ftell(archivo);//para saber la posicion actual
    rewind(archivo);//para que comience a leer el archivo desde el comienzo
//para ir almacenando las lineas de cada archivo
    arreglo=(char*)malloc(tam*sizeof(char));
//funcion que permite leer el archivo desde el comienzo
    fread(arreglo, tam, 1, archivo);
    for(i=0; i<(tam/16); i++)
    {//contador para acceder a cada seccion del archivo
        printf(" | ");
        for(j=0; j<16; j++)
        {//contador para acceder a cada caracter de forma hexadecimal
            printf("%02X ", *(arreglo+i*16+j));
        }//para imprimir las lineas del ejemplo
        printf(" | ");
        for(k=0; k<16; k++)
        {/*para acceder a las mismas posiciones que con el contador anterior
            con la diferencia que se van a imprimir los caracteres en sus formato
            convencional. No funciona usar la misma variable de contador en ambos*/
            printf("%c", *(arreglo+i*16+k));
        }
    }//sale del archivo
    fclose(archivo);
    return EXIT_SUCCESS;
}
