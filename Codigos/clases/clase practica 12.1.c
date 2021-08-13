//leer un archivo binario

#include<stdio.h>

int main()
{
    int num;
    FILE* archivo; //porque vamos a abrir un archivo

    archivo=fopen("ejemplo1.bin", "rb");
    //rb porque es modo lectura

    //validacion
    if(archivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(-1); //se sale del programa
    }

    //funcion para leer el archivo y almacenarlo en num
    fread(&num, sizeof(int), 1, archivo);
    //1. donde lo voy a almacenar
    //2. tamaño del bloque del archivo y de la variable
    //3. las veces que se quiere escribir
    //4. de donde lo estoy leyendo

    printf("Comprobar el valor de num : %d", num);
    //imprimio 5

    return 0;
}
