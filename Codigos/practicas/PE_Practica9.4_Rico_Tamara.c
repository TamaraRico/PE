/*en la 4, reservar espacio para un elemento arreglo, despues guardar el primer elemento en el
primer espacio de un nuevo arreglo y luego, si el sig no existe, lo agregamucho*/

#include<stdio.h>
#include<stdlib.h>

int* obtener_unicos(int *arreglo, int tam, int *new_tam);
void agregar_elemento(int *ptr, int tam, int valor);

int main(void)
{
    int *arreglo=NULL, tam=1, *unicos, tam_unicos, i, valor;
    char opcion;

    printf("Capture el tamaño del arreglo : ");
    scanf("%d", &tam);
    arreglo=(int*)malloc(tam*sizeof(int));
    for(i=0; i<tam; i++)
        arreglo[i]=rand()%100+1;

    //imprimir el arreglo
    for(i=0; i<tam; i++)
        printf("\narreglo: %d", arreglo[i]);

    unicos = obtener_unicos(arreglo, tam, &tam_unicos);
    //imprimir unicos
    for(i=0; i<tam_unicos; i++)
        printf("unicos: %d", unicos[i]);

    do
    {
        printf("\nDesea agregar otro numero al arreglo? (S/N) : ");
        scanf("%c", &opcion);
        if(opcion=='s'||opcion=='S')
        {
            printf("Capture el numero que desea agregar : ");
            scanf("%d", &valor);
            agregar_elemento(arreglo, tam, valor);
        }
    }while(opcion=='s'||opcion=='S');

    return 0;
}

int* obtener_unicos(int *arreglo, int tam, int *new_tam)
{
    int i, j, *unicos;
    unicos[0]=arreglo[0];
    for(j=0; j<tam; j++)
    {
        for(i=1; i<tam; i++)
        {
            if(arreglo[i]!=unicos[i-1])
                unicos[j]=arreglo[i];
        }
    }
    return unicos;
}

void agregar_elemento(int *ptr, int tam, int valor)
{
    tam++;
    ptr=(int*)realloc(ptr, sizeof(int)*tam);
    ptr[tam]=valor;
}
