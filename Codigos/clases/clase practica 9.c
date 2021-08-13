//APUNTADORES A FUNCIONES

#include<stdio.h>

void saluda();
void despedida();

int main(void)
{
    void (*ptr)(void)=saluda;
    //ESTRUCTURA DE APUNTADORES A FUNCIONES
    //el tipo de dato es en base al prototipo de la función
    //es un apuntador porque lleva *
    //lleva () porque es hacia una función
    //el primer void es del tipo de dato de retorno
    //y el segundo void es del parámetro
    //no lleva & porque el nombre de la funcion es una dirección de memoria

    printf("\n%p", saluda);

    //INDIRECCIÓN
    ptr();//aquí se almacena la dirección de la función

    //cambiar la dirección del apuntador
    ptr=despedida;
    ptr();

    return 0;
}

void saluda()
{
    printf("\nHola mundo");
}

void despedida()
{
    printf("\nHasta luego");
}
