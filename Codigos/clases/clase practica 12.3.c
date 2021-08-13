//Leer una estructuera en un archivo

#include<stdio.h>

struct persona{
    char nombre[19];
    char genero;
    int edad;
    float peso;
};

void imprimir_persona(struct persona);

int main(void)
{
    struct persona p;
    FILE* archivo;

    archivo=fopen("ejemplo1.bin", "rb");


    //validacion - para malloc y archivos
    if(archivo==NULL)
    {
        printf("Error al abrir el archivo");
        exit(-1); //se sale del programa
    }

//mueve el indicador de posicion
//1. es del archivo que se va a leer
//2. desde donde va a empezar a leer, en este caso, 28
//3. funcion para que empiece a leer desde el principio
    fseek(archivo, sizeof(p),SEEK_SET);
    //sizeof(p)*0 - primera estructura
    //sizeof(p)*1 - segunda estructura
    //sizeof(p)*2 - tercea estructura
    //sizeof(p)*3 - cuarta estructura
    //leemos a partir de la poscision del cursor, en este caso, 28 bytes
    fread(&p, sizeof(p), 1, archivo);

    imprimir_persona(p);

    return 0;
}

void imprimir_persona(struct persona p)
{
    printf("Nombre: %s", p.nombre);
    printf("Genero: %c", p.genero);
    printf("Edad: %d", p.edad);
    printf("PEso: %f", p.peso);
}
