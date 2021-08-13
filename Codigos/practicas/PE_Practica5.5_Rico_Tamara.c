/*Rico lopez Tamara Illian 1270673
PRACTICA 5
Realizar un menu con funciones*/

#include<stdio.h>

//Prototipos de las funciones
int reversa(int);
int digitos(int);
int suma_cifras(int);
int primo(int);

int main(void)
{
    int opc, num;

    printf("Ingrese el valor: ");
    scanf("%d", &num);

    do
    {

        printf("\n\nMENU: ");
        printf("\n1) Reversa de un numero ");
        printf("\n2) Cantidad de digitos ");
        printf("\n3) Suma de sus cifras ");
        printf("\n4) Es primo? ");
        printf("\n5) Salir ");

        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc)
        {
            case 1:
                printf("El numero %d, al reves es %d", num, reversa(num));
                break;
            case 2:
                printf("El numero %d, tiene %d digitos", num, digitos(num));
                break;
            case 3:
                printf("La suma de las cifras de %d es %d", num, suma_cifras(num));
                break;
            case 4:
                if(primo(num))
                    printf("El numero %d es primo", num);
                else
                    printf("El numero %d no es primo", num);
                break;
            case 5: break;
            default: printf("\nSeleccione una opc valida\n");
        }
    }while(opc!=5);

    return 0;
}

//NUMERO EN REVERSA
int reversa(int num)
{
    int i, m=0;
    while(num)
    {
        i=num%10;
        num=num/10;
        m=m*10+i;
    }
    return m;
}
//CANTIDAD DE DIGITOS DEL NUMERO
int digitos(int num)
{
    int i=0;
    while(num)
    {
        num=num/10;
        i++;
    }
    return i;
}
//SUMA DE CADA UNA DE SUS CIFRAS
int suma_cifras(int num)
{
    int suma = 0;
    while(num)
    {
        suma += num%10;
        num = num / 10;
    }

    return suma;
}
//SI EL NUMERO ES PRIMO O NO
int primo(int num)
{
    int i, a;
    for(i=1; i<=num; i++)
    {
        if(num%i==0)
            a++;
    }
    if(a==2||num==1||num==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
