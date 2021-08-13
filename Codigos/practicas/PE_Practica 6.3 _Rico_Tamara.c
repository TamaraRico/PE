/*Rico Lopez Tamara Illian 1270673
PRACTICA 6
Manipulacion de una cadena de caracteres */

#include<stdio.h>
#define MAX 50
//#include<ctype.h>

//Protoripos de funciones
int contar_digitos(char[]);
char espacios(char[]);
int palindromo(char[]);
char mayusculas(char[]);
char minusculas(char[]);

int main(void)
{
    int opc;
    char cadena[MAX];
    printf("Ingrese una palabra o frase: ");
    scanf("%s", cadena);

    do
    {

        printf("\n\nMENU: ");
        printf("\n1) Vocales, Consonantes y digitos ");
        printf("\n2) Eliminar espacios ");
        printf("\n3) Es palindromo? ");
        printf("\n4) Letras mayusculas");
        printf("\n5) Letras minusculas ");
        printf("\n6) Salir ");

        printf("\n\nSeleccione una opcion: ");
        scanf("%d", &opc);
        switch(opc)
        {
          case 1:
                printf("La cadena de caracteres %s, tiene %d digitos, %d consonantes y %d vocales", cadena, contar_digitos(cadena[MAX]));
                break;
            case 2:
                printf("La cadena de caracteres %s, sin espacios es %s", cadena, espacios(cadena));
                break;
            case 3:
                if(palindromo(cadena))
                    printf("La cadena de caracteres %s es palindromo", cadena);
                else
                    printf("La cadena de caracteres  %s no es palindromo", cadena);
                break;
            case 4:
                printf("La cadena de caracteres %s es %s", cadena, mayusculas(cadena));
                break;
            case 5:
                printf("La cadena de caracteres %s es %s", cadena, minusculas(cadena));
                break;
            case 6: break;
            default: printf("\nSeleccione una opc valida\n");
        }
    }while(opc!=6);

    return 0;
}

//Funcion que cuenta vocales, consonantes, y digitos
int contar_digitos(char cadena[])
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

    return digitos;
    return consonantes;
    return vocales;//tal vez son 3 return
}

//Funcion que eliminas los espacios de la cadena
char espacios(char cadena[])
{
    int i;
    //ciclo con 2 indices, i para las posiciones y  para los valores
    for(i=0; cadena[i]; i++)
    {
        if(cadena[i]==' ')
        {
            cadena[i]=cadena[i+1];//cadena[i+1]=cadena[i]
        }//recorrer el fin de cadena
    }
    return cadena;
}

int palindromo(char cadena[])
{
    int i, dig;
    char palindro[dig];
    dig=sizeof(cadena);
    for(i=0; cadena[i]; i++)
    {
        cadena[i]=palindro[dig];
        dig--;
    }
    if(cadena==palindro)
    {
        return 1;
    }
    else
        return 0;
}

//convertir toda la cadena a mayusculas
char mayusculas(char cadena[])
{
   /* int i;

   CONVERSION CON CTYPE.H
    for(i=0, cadena[i]; i++)
    {
        cadena[i]=toupper(cadena[i]);
    }
    return cadena[];

    CONVERSION CON CODIGO ASCII (DECIMALES)
    if(cadena<=122&&cadena>=97)
        cadena-=32;

    CONVERSION CON CODIGO ASCII (LETRAS)
    if(cadena<='z'&&cadena>='a')
        cadena=cadena-('a'-'A'); donde ('a'-'A'=32)

    CONVERSION UTILIZANDO LA "expresion ternearia condicional"*/
    return (cadena<='z'&&cadena>='a')?cadena-32:cadena;
    //valor = Condicion ? valor_verdadero : valor_falso;
}

//convertir toda la cadena a minusculas
char minusculas(char cadena[])
{
    /*int i;
    for(i=0, cadena[i]; i++)
    {
        cadena[i]=tolower(cadena[i]);
    }
    return cadena[];*/

    //expresion ternearia condicional
    return (cadena<='Z'&&cadena>='A')?cadena+32:cadena;
}
