
/*el compilador necesita saber cuantos bytes de memoria guardar para cada variable
asi que si se inicializa el arreglo ya no es necesario delcarar el espacio
con arreglos bidimensionales (matrices) siempre se tiene que llenar 1 [row][]
y si fuera en 3 dimensiones seria lenar los 2 primero [row][col][]
*/

//MEMORIA DINAMICA

//define tambien puede definir macros
#include<stdio.h>
#define MAX 10

//segundo parametro : TAMAÑO (tam) Y SE DECLARÓ DENTRO DE LA FUNCION
float promedio(float[], int);

void captura(float[], int);

int main(void)
{
    //aqui llegan las copias de las capturas de la funcion void
    float calificacione[MAX]

    captura(calificacione, MAX)

    return 0;
}

/*float promedio(float arreglo[], int tam)//declaracion de variables locales (tam, arreglo)
{
    float prom=0;

    for(i=0; i<tam; i++)
        prom+=arreglo[i;]

    return prom/tam;
}*/


//void no regresa nada, variable vacia
void captura(float arreglo[],int tam)//el nombre del arregl es la direccion
{
    int i;
    for(i=0; i<tam, i++)
    {
        printf("Ingrese un valor : ");
        scanf("%f", &arreglo[i]);
    }
}
