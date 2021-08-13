#include<stdio.h>
#include<stdlib.h>

int main()
{
    //ch almacena los caracteres que se leen del archivo para imprimirlos
    //nombre del archivo almacena el nombre del archivo para poder acceder a él
    char ch, hex, nombre_archivo[25];
    FILE *archivo;
    int i, j, k;
    //representa el flujo del archivo

    printf("Ingrese el nombre del archivo que desea leer : ");
    gets(nombre_archivo);

    //abre el archivo en modo lectura
    archivo=fopen(nombre_archivo, "r");

    //si no se puede leer del archivo, se sale del programa
    if (!archivo)
    {
        printf("Error al abrir flujo de archivo.");
        exit(-1);
    }

    printf("El contenido del archivo %s es:\n", nombre_archivo);
    //imprime el contenido del archivo mientras no se llegue al final
    ch=fgetc(archivo);
    hex=ch;
    while((ch=fgetc(archivo))!= EOF)
    {
        ch=fgetc(archivo);
        for(i=0; i<16; i++)        {
            printf(" | ");
            for(j=0; j<16; j++)
            {
                printf("%02X ", ch+i*16+j);
            }
            printf(" | ");
            for(k=0; k<16; k++)
            {
                printf("%c", ch+i*16+k);
            }
        }
    }
        //hex=fgetc(archivo);
        printf("%02X ", ch);
        //printf("%c", ch);
    //cierra el archivo
    fclose(archivo);

    return 0;
}

/*
   char word[17], outword[33];//17:16+1, 33:16*2+1
    int i, len;

    printf("Intro word:");
    fgets(word, sizeof(word), stdin);
    len = strlen(word);
    if(word[len-1]=='\n')
        word[--len] = '\0';

    for(i = 0; i<len; i++){
        sprintf(outword+i*2, "%02X", word[i]);
    }
    printf("%*/
