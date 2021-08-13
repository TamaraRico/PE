/*Rico Lopez Tamara Illian 01270673
PRACTICA 11
Leer un archivo desde la consola*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    FILE* archivo=fopen(argv[1], "r");
    char ch, entrada;
    int nlineas=0, contador=0;

    if(!(argc>1))
    {
        printf("\nError al recibir los parametros por consola");
        exit(-1);
    }
    if(!archivo)
    {
        printf("\nError al abrir le flujo del archivo");
        exit(-1);
    }
    while(!((ch=fgetc(archivo))==EOF))
    {
        if(ch==10)
            nlineas+=1;
        printf("%c", ch);
        if(contador==0)
        {
            if(nlineas==15)
            {
                contador+=1;
                printf("\nPresione ENTER");
                entrada=getchar();
                nlineas=0;
            }
        }
        if(contador!=0)
        {
            if(nlineas==15)
            {
                printf("\nPresione ENTER");
                entrada=getchar();
                nlineas=0;
            }
        }
    }
    fclose(archivo);

    return EXIT_SUCCESS;
}
