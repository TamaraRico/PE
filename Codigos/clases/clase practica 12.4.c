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
    struct persona p={"Tamara Rico", 'F', 19, 60};
    FILE* archivo;

    archivo=fopen("ejemplo1.bin", "ab");
    //ab no se borra lo que tenia

    //validacion - para malloc y archivos
    if(archivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(-1); //se sale del programa
    }

    fwrite(&p, sizeof(p), 1, archivo);
    //escribir en el archivo
    fclose(archivo);

    return 0;

}
