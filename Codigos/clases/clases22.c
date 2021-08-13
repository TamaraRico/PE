//Estructuras de control selectivas
/* evaluar condiciones y en base a eso realizar una acción o otra

IF, WHILE, FOR cambiar el flujo del programa, no hay cambios (decisión)

¿qué camino tomar?*/

//EXPRESION : conjunto de elemetos, como variables, operadores, funciones. Respetando la sintaxis de c. Se evalua para obtener un unico resultado

/*if (expresion)
    instruccion; //se ejecuta si es verdadero*/

/*if (expresion)
{
    bloque de instrucciones
}*/

#include<stdio.h>

int main(void)
{
    float temp;

    printf("Iintroduzca su temperatura en C: ");
    scanf("%f", &temp);

    //se evalua la expresion y si es verdadera se ejecuta el bloque de instrucciones

    /*Valores de verdad
        Falso: 0 se interpreta como falso
        Verdadero: cualquier otro caso (otro valor)
    */

    printf("\nDEBUG : valor de la expresion condicional %d", temp>37.7); //para obtener verdadero o falso

    //una sola expresion a evaluar

    if (temp>37.7)/*instruccion vacia ; */ //estructura de control selectiva NO LLEVA ;
        //expresion condicional () operadpr relacional <>
    {
        //bloque de instrucciones dentro de un bloque de instrucciones
        printf("\nLa temperatura %.2f indica que usted tiene fiebre\n", temp);
        //%.2f esto significa que solo va a imprimir 2 decimales
    }

    else //no se pone expresion, no es necesario y es lógicamente incorrecto
    {
        printf("\nLa temperatura %.2f indica que no usted no tiene fiebre\n", temp);
    }
    printf("\nFin del programa\n");

    return 0;
}




