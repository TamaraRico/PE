//APUNTADORES A FUNCIONES

#include<stdio.h>

void saluda();
void despedida();

int main(void)
{
    void (*ptr)(void)=saluda;
    //ESTRUCTURA DE APUNTADORES A FUNCIONES
    //el tipo de dato es en base al prototipo de la funci�n
    //es un apuntador porque lleva *
    //lleva () porque es hacia una funci�n
    //el primer void es del tipo de dato de retorno
    //y el segundo void es del par�metro
    //no lleva & porque el nombre de la funcion es una direcci�n de memoria

    printf("\n%p", saluda);

    //INDIRECCI�N
    ptr();//aqu� se almacena la direcci�n de la funci�n

    //cambiar la direcci�n del apuntador
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
