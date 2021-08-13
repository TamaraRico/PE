/*Realizar una función que dada una cadena de caracteres, muestre el
número de vocales, consonantes y dígitos. Sin usar biblioteca ctype.h.
Los caracteres en minúsculas y mayúsculas deben ser indiferentes, por lo que
se recomienda convertir primero la cadena de caracteres a mayúsculas o minúsculas
antes del procesamiento.*/

#include<stdio.h>

void contar_digitos(char cadena[]);

int main(void)
{
    char palabra[]="hola como estas";
    contar_digitos(palabra);
    printf("La palabra es ");

    return 0;
}
void contar_digitos(char cadena[])
{
    int i, vocales=0, consonantes=0, digitos=0;
    for(i=0; cadena[i]; i++)
    {
        if((cadena[i]=='a')||(cadena[i]=='A'))
        {
            vocales=vocales+1;
            if(cadena[i]=='e'||cadena[i]=='E')
            {
                vocales+=1;
                if(cadena[i]=='i'||cadena[i]=='I')
                {
                    vocales+=1;
                    if(cadena[i]=='o'||cadena[i]=='O')
                    {
                        vocales+=1;//tal vez quito todas estas y dejo las ultimas
                        if(cadena[i]=='u'||cadena[i]=='U')
                        {
                            vocales+=1;
                        }
                    }
                }
            }
        }
        else;
        {
            consonantes++;
        }
        digitos++;
    }
    printf("Las vocales son :", vocales);
    printf("Las consonantes son :", consonantes);
    printf("Las digitos son :", digitos);
}
