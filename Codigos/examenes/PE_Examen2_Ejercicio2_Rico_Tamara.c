/*Rico Lopez Tamara Illian 1270673
EXAMEN 2
Ejercicio 1*/

#include<stdlib.h>
#include<stdio.h>
//recibe los parametros por consola
int main(int argc, char* argv[])
{//declaracion de las 2 variables de archivp
    FILE* archivo=fopen(argv[1], "r");
    FILE* nuevo=fopen("respaldo.txt", "w");
    char caracter;
    int mayuscula, espacios, enter;
//comprobar que se recibieron bien los parametros
    if(!(argc>1))
    {
        printf("\nError al recibir los parametros por consola");
        exit(-1);//si no es asi se termina el programa
    }
    if(!archivo)
    {//se asegura de que el archivo es accesible
        printf("\nError al abrir le flujo del archivo");
        exit(-1);
    }//para accer a cada caracter del archivo antes del final
    while(!((caracter=fgetc(archivo))==EOF))
    {
        caracter=fgetc(archivo);
        caracter=tolower(caracter);//convierte las letras mayusculas a minusculas
        if(mayuscula&&caracter!=' '&&caracter!=NULL)
        {
            caracter=toupper(caracter);
            mayuscula=0;//convierte las letras minusculas a mayusculas
            //printf("%c", caracter);
        }
        else if(caracter=='.'||caracter=='\n')
        {//si hay un punto no hace nada
            mayuscula=1;
        }//para saber si es un espacio o un salto de linea
        else if(caracter==' '||caracter=='\n')
            espacios=1;
        else if(caracter==' '||caracter=='\n'&&espacios)
        {//para combrar el valor de las variables, y que se guarden en el nuevo archivo o no
            caracter=NULL;
            enter=0;
        }
        else
        {
            espacios=0;
            enter=1;
        }
        fprintf(nuevo, "%c", caracter);
        printf("%c",caracter);
    }
    fclose(archivo);
    return EXIT_SUCCESS;
}
