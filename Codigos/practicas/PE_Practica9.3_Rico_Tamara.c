#include <stdio.h>
#include<stdlib.h>

void mult_matriz(int**ptr, int**ptr2, int fil, int col, int col2);

int main(void)
{
    int col, fil, **matriz, i, a, b;
    int col2, fil2, **matriz2, j;

    printf("Capture las dimensiones de la matriz (ej. 3,3) : ");
    scanf("%d,%d", &col, &fil);
    printf("Capture las dimensiones de la segunda matriz (3,3) : ");
    scanf("%d,%d", &col2, &fil2);

    if(col!=fil2)
        printf("\nEl producto de las matrices no esta definido");

    matriz=(int**)malloc(fil*sizeof(int*));

    for(i=0; i<col; i++)
        matriz[i]=(int*)malloc(col*sizeof(int));

    for(a=0; a<fil; a++)
    {
        for(b=0; b<col; b++)
            matriz[i][j]=rand() % 10 + 1;
    }

    matriz2=(int**)malloc(fil2*sizeof(int*));
    for(i=0; i<col2; i++)
        matriz2[i]=(int*)malloc(col2*sizeof(int));
    //ya se pueden manipular los apuntadores como arreglos de arreglos, es decir, matrices

    for(a=0; a<fil2; a++)
    {
        for(b=0; b<col2; b++)
            matriz2[i][j]=rand() % 10 + 1;
    }

    mult_matriz(matriz, matriz2, fil, col, col2);

    return 0;
}

void mult_matriz(int**ptr, int**ptr2, int fil, int col, int col2)
{
    int resultado[0][0], i, j, k, multiplicacion=0;
    for (i=0; i<fil; i++)
    {
      for (j=0; j<col; j++)
      {
        for (k=0; k<col2; k++)
        {
          multiplicacion+=(ptr[i][k]*ptr2[k][j]);
        }
        resultado[i][j] = multiplicacion;
        multiplicacion=0;
      }
    }
    printf("El producto de las matrices es :\n");
    for (i=0; i<fil; i++)
    {
      for (j=0; j<col2; j++)
        printf("\n%d\t", resultado[i][j]);
    }
}
