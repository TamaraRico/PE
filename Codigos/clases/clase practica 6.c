//ARREGLOS (LISTAS) EN C

#include<stdio.h>
//replazo, no variable
#define TAM 10 //tam de tamaño y se va a reemplazar en el código, antes de la compilacion
/*los datos dentro de un arreglo deben ser del mismo tipo de dato
ARREGLOS = direcciones de memoria

nombre del arreglo y {} la posicion para acceder a ese dato especifico

******************************************************************************************************************************

int numeros[8]; declaracion de una lista, donde todos son numeros enteros

*******************************************************************************************************************************

siempre que se declara una cadena de caracteres, se especifica el tamaño [6], pero, en este caso al ser 6, solo se puede escribir
una cadena de 5 caracteres, porque el 6to se reserva para un caracter especial que indica el fin de la cadena,
el simbolo es '0', '\0'(caracter que representa al 0 en octal), '\x0'(caracter que representa al 0 en hexadecimal)

\n = secuencia de escape

ACCESO
nombre_del_arreglo[índice] = dato; para incluir un numero

INICIALIZACION
int números[8]={23,56,5,-89,98,13,45,89};
*/

//IMPRIME PARAMETRO A UN ARREGLO
void suma(int [, int]); //prototipo de la funcion suma, que sera un arreglo
/* El void es para que el usuario capture los numeros de una funcion
el int[] es para que se almacene en un arreglo
y el ultimo int es porque todo lo que ingrese el usuario es entero (int)*/

int main(void)
{
    char letra = 'A';

    printf("\nletra = %c", letra);
    printf("\nletra = %d", letra);
    printf("\nletra = %x", letra);

    char ciudad1[]="tijuana";
    char ciudad2[8]={'t','i','j','u','a','n','a'};
    int i, j;

    ciudad1[0]='T';
    ciudad2[0]='T';

    printf("\n%s - tamaño = %d bytes \n", ciudad1, sizeof(ciudad1));
    printf("\n%s - tamaño = %d bytes \n", ciudad2, sizeof(ciudad2));

    for(i=0; ciudad1[i]; i++) /*porque cuando i==0 el resultado sera falso sin que nosotros lo tengamos que indicar, porque el cero es
        el unico considerado como falso*/
        printf("\n%c", ciudad1[i]);
        //ciudad[i]!=0 es otra condicion del ciclo
        //ciudad[i]!='\x0'
        //ciudad[i]
        //i<sizeof(ciudad1) sizeof imprime 8, asi que esos son los valores que cumplen con la condicion, porque NULL no es valido

    for(i=0; i<5; i++)
        printf("Ingrese un numero entero (pos %d)");

    return 0;
}

//void = tipo de dato vacio, no regresa nada (?)
/* el caso de los arreglos no es como las variables en cuanto a memoria stack



