/*Realizar una función que dada una cadena de caracteres, muestre el
número de vocales, consonantes y dígitos. Sin usar biblioteca ctype.h.
Los caracteres en minúsculas y mayúsculas deben ser indiferentes, por lo que
se recomienda convertir primero la cadena de caracteres a mayúsculas o minúsculas
antes del procesamiento.*/

#include<stdio.h>
#include<string.h>

void contar_digitos(char[], int[]);
void voc_cons(char[]);
void minusculas(char[]);

int main()
{
    char cadena[100];
    int cuenta[26]={0}, i;
    printf("Captura una palabra o sentencia : ");
    scanf("%s", cadena);
    minusculas(cadena);

    printf("El numero de digitos de la cadena es : %d", strlen(cadena));
    contar_digitos(cadena, cuenta);
    printf("\nCada digito de la cadena\n");
    for(i=0; i<26; i++)
    {
      printf("%c \t  %d\n", i + 'a', cuenta[i]);
    }
    return 0;
}

void contar_digitos(char cadena[], int cuenta[])
{
    int i=0;
    while(cadena[i]!='\0')
    {
        if(cadena[i]>='a' && cadena[i]<='z')
        {
            cuenta[cadena[i]-'a']++;
            i++;
        }
    }
}

void voc_cons(char cadena[])
{
    int i, vocales=0, consonantes=0;
    for(i=0; cadena[i]; i++)
    {
        if(cadena[i]=='a'|| cadena[i]=='e' || cadena[i]=='i' || cadena[i]=='o' || cadena[i]=='u')
        {
            vocales++;
        }
        else
        {
            consonantes++;
        }
    }
    printf("\nEl numero de vocales es : %d", vocales);
    printf("\nEl numero de consonantes es %d: ", consonantes);
}

void minusculas(char cadena[])
{
    int i;
	for (i=0; cadena[i]!='\0'; ++i)
    {
        cadena[i]=tolower(cadena[i]);
    }
    printf("\nCadena resultante: %s\n", cadena);
}
