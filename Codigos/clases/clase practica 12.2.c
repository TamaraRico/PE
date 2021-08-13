//escribir una estructuera en un archivo

#include<stdio.h>

struct persona{
    char nombre[19];
    char genero;
    int edad;
    float peso;
};

int main(void)
{
    struct persona p={"homero Simpson", 'M', 59, 160};
    FILE* archivo;

    archivo=fopen("ejemplo1.bin", "wb");


    //validacion - para malloc y archivos
    if(archivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(-1); //se sale del programa
    }

    fwrite(&p, sizeof(p), 1, archivo);
    //escribir en el archivo

    fclose(archivo);

    //al escribir un archivo, se borra lo que tenia

    return 0;
}
