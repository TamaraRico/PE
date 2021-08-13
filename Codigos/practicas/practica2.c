#include<stdio.h> //instruccion con caracter numeral, stdio es una archivo de cabecera ANSI C: EN ESO NOS VAMOS A ENFORCAR
//con include se le dice al compilador que vamos a usar esta biblioteca studio.h
//ANSI C crea estandares para programas
//descargar un comilador que cumla las reglas de ansi c
//biblioteca=colección de funciones y en c se llama paquete y terminan en .h por eso la vamos a usar en todos los ejercicios
int main()
//en otros lenguajes la funcion es Main
{
    //en esta sección se deben declarar variables
    //int num=4, num2=3, res; //COMPLETAMENTE VÁLIDO Y MAS FACIL //se va almacenar en la variable res
    //en c , las comillas simples representan un solo caracter 'h'
    //int num; //declaracion de variables para numeros enteros
    //int num2=3;
    //float var; //numero decimal=float
    //int=entero y variable=num
    //declarar variables mucho antes que en python
    //también puede ser int num=4;
    // y apara otra variables, se tiene que volver a declarar
    //variables: almacenan datos y establecer qué tipo de dato
    //printf("Contenido de num: %d",num); //especificardos de formato (checar la tabla de datos) para funciones de entrada y de salida
    //printf("Contenido de num y num2: %d,%d",num, num2);//parametros se separan por ,
    //ES IMPORTANTE NO OLVIDAR EL IDENTIFICADOR DE FORMATO

    int num, num2, res;

    printf("Introduzca un valor entero: ");
    scanf("%d", &num);//funcion scanf: capturar informacion del teclado, sintaxis similar a printf
    //para scanf, se debe anteponer un operador a la variable almacenadora
    //&=direccion, en este caso, a num. ANTES DEL NOMBRE DE LA VARIABLE. no en cadennas de caracteres

    printf("\nEl capturado es : %d", num);
    printf("\nIntroduzca otro valor entero: ");
    scanf("%d", &num2);

    printf("\nLos valores capturados son: \ %d y %d", num, num2);

    res = num + num2;

    printf("\n%d + %d = %d", num, num2, res);



    //printf requiere de un primer parametro que ONLIGATORIAMENTE DEBE SER UNA CADENA DE CARACTERES
    //la biblioteca stdio.h nos permite usar estas funciones y muchas más, sobre la entrda y salida
    //printf("Hola mundo\n");//no olvidar en ;, porque indica el fin de la instruccion
    //en python: identaciones y en c: {}
    //printf("bienvenido");
    //num=4;
    //res = num + num2; //flotantes+enteros=flotantes IMPORTANTE AL DECLARAR
    //4+3=7 siempre se pone pprimera la varable ue va a almacenar el resultado
    //printf("\n%d + %d: %d", num, num2, res); //el orden importa
    //c no puede imprimir print(num+num2=res)


    return 0; //agregarlo
}

// en c, la primera funcion es main porque es el punto de partida
//en el parentesis se ueden definir ls entrads de la funcion
//NO OLVIDAR CERRAR LA CONSOLA
//division es diferente con flotants y con enteros, checar la presentacion
//si el tipo de dato es flotante, los datos deben ser flotantes como 9.00 PRACTICA
