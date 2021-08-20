/*Rico Lopez Tamara Illian 01270673
PRACTICA 11
Leer un archivo y alamcenar su contenido en un arreglo
para su manipulacion*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//float suma(int*, int);
float max(int*, int);
float min(int*, int);
float media(int*, int);
float mediana(int*, int);
float moda(int*, int);
int comparar(const void *, const void *);

int main(void)
{
    char ch, nombre_archivo[25];
    FILE *archivo;
    int *arreglo, tamn, size, i;

    //para leer el archivo
    printf("Ingrese el nombre del archivo que desea leer : ");
    gets(nombre_archivo);

    //para acceder al archivo que se establecio en el punto anterior
    archivo=fopen(nombre_archivo, "r");

    if (!archivo)
    {//para comprobar que se pudo leer el archivo
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

//para contar las líneas del archivo y la cantidad de numeros
    while((ch = fgetc(archivo)) != EOF)
    {
        if( ch == '\n')
            tamn++;
        putchar(ch);
    }
    tamn+=1;
    printf("\nEl tamaño del arreglo : %d", tamn);
    arreglo=(int*)malloc(sizeof(int)*tamn);
    //tamaño del archivo de forma dinamica

    while((ch=fgetc(archivo))!= EOF)
    {
        for(i=0; i<tamn; i++)
            arreglo[i]=atoi(ch);//para almacenar los numeros en el arreglo
    }
    fclose(archivo);

    //para imprimir el contenido del arreglo
    for(i=0; i<tamn; i++)
        printf("%d  ", arreglo[i]);

    //arreglo de apuntadores a funciones
    float (*funciones[])(int*, int) = {max, min, media, mediana, moda };
    char* nombres[] = {"maximo", "minimo", "media", "mediana", "moda"};

    size = sizeof(funciones)/sizeof(funciones[0]);
    for(i=0; i<size; i++)
        printf("%s: %.3f\n", nombres[i], funciones[i](arreglo,tamn));

    return 0;
}

//para ordenar los numeros
int comparar(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

float suma(int* array, int size)
{
    float sum = 0;
    while(size--)
    {
        sum += *array;
        array++;
    }
    /*while(size--)
        sum += *(array++);
    */
    return sum;
}

float max(int* array, int size)
{
    float maximo = *array;
    while(size--)
    {
        if(maximo < *array)
            maximo =*array;
        array++;
    }
    return maximo;
}

float min(int* array, int size)
{
    float minimo=*array;
    while(size--)
    {
        if(minimo>*array)
            minimo=*array;
        array++;
    }
    return minimo;
}

float media(int* array, int size)
{
   /* float prom, sum = 0;
    while(size--)
        sum += *(array++);
*/
    int i;
    float prom, acumulador=0;
    for(i=0; i<size; i++)
        acumulador+=array[i];
    prom=acumulador/size;
    return prom;
}

//Se requiere datos ordenados
float mediana(int* array, int size)
{
    int i;
    //usar funcion qsort se stdlib.h para ordenamiento de datos
    qsort(array, size, sizeof(int), comparar);

    //Elementos del arreglo ordenado
   /* for(i=0; i<size; i++)
        printf ("%d ",array[i]);*/

    if(size%2!=0)
        return array[size/2];
    else
    {
        return array[((size/2)+((size/2)-1))/2];
    }
    //return 1;
}

float moda(int* array, int size)
{
    int auxiliar[size], i, n, j, posicion=0;
    float maximo = auxiliar[0];
    for(i=0; i<11; i++)
        auxiliar[i]=0;
    for(i=0; i<size; i++)
    {
        n=array[i];
        for(j=i; j<size; j++)
        {
            if(array[j]==n)//tal vez lleva *
                auxiliar[i]++;
        }
    }
    for(i=0; i<size; i++)
    {
        if(auxiliar[i]>maximo)
            posicion=i;
            maximo=auxiliar[i];
    }
    return array[posicion];
}



