#include<stdio.h>
//FUNCIONES EN C

/*declaracion de prototipo de funciones = declarar variables
antes de main

no se escribe el ;

tipo_de_dato nombre_de_la_funcion ( tipo_de_dato parametro_1, tipo_de_datos paramatro_2)*/

//PROGRAMA QUE SOLICITA AL USUARIO DOS VALORES (ANCHO Y LARGO) PARA CALCULAR EL AREA
float perimetro(float, float);

float area(float, float); //prototipo de funcion
/*sin esta parte, el programa no compila. A menos que se defina la funcion es esta parte, aunque en esa situacion no se sigue al estandar
ANSII C y asi, se puede usar en todo el programa. FACILIDAD DE LECTURA, ORGANIZACION*/

int main(void)
{
    //declarar variables ancho y largo y perdirselos al usuario
    float ancho, largo;

    printf("\nIngrese el largo del rectangulo : ");
    scanf("%f", &largo);
    printf("\nIngrese el ancho del rectangulo : ");
    scanf("%f", &ancho);

    printf("\n\nEl area calculada es : %.3fm2", area(ancho, largo));
    //estamos mandando a llamar una funcion con el area(ancho, largo)

    printf("\nEl perímetro es %.3f", perimetro(ancho, largo));
    /*Las variables ancho y largo que estan en la funcion main son locales, y solo existen dentro del bloque de instrucciones
    de esta parte, y las variables de la funcion area son diferentes. ESTO SIGNIFCA QUE PODRIA HABER NOMBRE DIFERENTES PARA LAS
    VARIABLES DEL BLOQUE DE FUNCIONES Y NO HABRIA NINGUN PROBLEMA*/
    return 0;
}

//definicion de la funcion
float area(float largo, float ancho)//parametros=variables locales(con un valor asignado)
{
    float resultado;
    resultado=ancho * largo;
    return resultado;//porque si no no regresa nada
}

//definición de la función
float perimetro(float largo, float ancho)
{
    return largo*2+2*ancho;
}
