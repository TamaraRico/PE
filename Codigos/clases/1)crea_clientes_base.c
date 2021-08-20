#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int cuenta;
    char nombre[20];
    char apellido[20];
    float fondos;
} cliente;

int main(void)
{
    FILE *file;
    cliente c = {0, "", "", 0};
    int i;


    //Capturar informacion de clientes en un banco

    //regresa una direccion si fue exitoso el acceso
    //regresa 0 si hubo algun problema
    file = fopen("clientes.dat", "wb");

    //Validando que file contenga una direccion
    if (!file)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    for(i=0; i<100; i++)
    {
        fwrite(&c, sizeof(cliente), 1, file);
    }


    fclose(file);



    return EXIT_SUCCESS;
}
