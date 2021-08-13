//escribir un numero entero en un archivo

#include<stdio.h>

int main(void)
{
    int num = 5; //en binario es 101
    FILE *archivo; //para poder manipular el archivo, es su direccion

    archivo=fopen("ejemplo1.bin", "wb");
    //fopen regresa una direccion de memoria, o cero si no se pudo abrir
    //wb porque queremos escribir en el archivo

    //validacion - para malloc y archivos
    if(archivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(-1); //se sale del programa
    }

    //escribir el numero en el archivo
    fwrite(&num, sizeof(int), 1, archivo);
    //1. direccion de memoria de lo que queremos escrbir
    //2. tamaño del bloque de memoria sizeof(tipo de dato)
    //3.cuantos bloques (1)
    //4. El archivo

    //se debe cerrar el archivo ya que no lo usamos
    fclose(archivo);
    //archivo es un apuntador a un archivo


    //se creó el archivo en mi carpeta de PE pero no se puede abrir porque
    //no tengo el programa

    return 0;
}
