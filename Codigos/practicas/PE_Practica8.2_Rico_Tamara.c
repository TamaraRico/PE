#include<stdio.h>
#define MAX 50

//void contar_digitos(char* cadena[], int[]);
void vocales_consonantes(char* cadena[]);
int espacios(char* cadena[], char* cadena1[]);

int main()
{
    char *cadena[MAX], *cadena1[MAX];
    //int *consonantes=0, *vocales=0, *digitos=0;
    printf("Ingrese una palabra : ");
    //scanf("%s", *cadena);
    fgets(*cadena, MAX, stdin);
    printf("El numero de digitos de la cadena es : %d", strlen(*cadena));
    //contar_digitos(cadena);
    vocales_consonantes(cadena);
    espacios(cadena, cadena1);
    printf("\nLa cadena sin espacios es : %s", *cadena1);
    return 0;
}

int espacios(char* cadena[], char* cadena1[])
{
    //int i, j=0;
    //char* cadena1[MAX];
    while(*cadena)
    {
        if(*cadena!=' ')
        {
            *cadena1=*cadena;
            cadena1++;
        }
    cadena++;
    }
    //printf(cadena1)
    return 0;
}

void vocales_consonantes(char* cadena[])
{
    int i, vocales=0, consonantes=0;
    while(*cadena)
    {
        if(*cadena=='a'|| *cadena=='e' || *cadena=='i' || *cadena=='o' || *cadena=='u')
        {
            vocales++;
        }
        else
        {
            consonantes++;
        }
    cadena++;
    }
    printf("\nEl numero de vocales es : %d", vocales);
    printf("\nEl numero de consonantes es : %d", consonantes);
}
