/*Rico Lopez Tamara Illian 1270673
PRACTICA 9*/

#include<stdio.h>
#include<stdlib.h>

int calcular_num_primos(int);
void arreglo_num_primos(int*, int*, int);

int main(void)
{
    int lim_inferior, lim_superior;
    printf("Ingrese el rango del arreglo (ejemplo 9,10): ");
    scanf("%d,%d", &lim_inferior, &lim_superior);

    arreglo_num_primos(&lim_inferior, &lim_superior, lim_superior);

    return 0;
}

int calcular_num_primos(int num)
{
    int a=0, i;
    for(i=1; i<=inferior; i++)
    {
        if(inferior%i==0)
                a++;
    }
    if(a==2||inferior==1||inferior==0)
        return 1;
    else
        return 0;
}

void arreglo_num_primos(int *inferior, int *super, int superior)
{
    int i, j, c=0;
    int *ptr;
    ptr=(int*)malloc(superior*sizeof(int));
    for(i=*inferior; i<=*super; i++)
    {
        if(calcular_num_primos(i))
        {
            if(ptr==NULL)
                printf("\nNo se pudo reservar memoria");
            else
            {
                for(j=0; j<superior; j++)
                    *(ptr+1)=i;
                c+=1;
                printf("\n[%d]", i);
            }
        }
    }
    printf("\nSe guardaron %i numeros primos en el arreglo", c);
    free(ptr);
}
