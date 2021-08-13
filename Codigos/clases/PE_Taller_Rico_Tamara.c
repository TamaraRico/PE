/*Rico Lopez Tamara Illian 1270673
Impresión de datos de un hospital*/
#include<stdio.h>

int main()
{
    float estatura, peso;//PARA DECIMALES
    int dia, mes, ano;
    char nombre[15], apellidop[20], apellidom[20], sangre[2], genero[1];//PARA CADENAS DE CARACTERES
    printf("Hospital Angeles, Tijuana, BC \n\n");
    printf("Introduzca su primer nombre (max 15 caracteres) : ");
    scanf("%s", nombre);
    printf("Introduzca su apellido paterno (max 20 caracteres) : ");
    scanf("%s", apellidop);
    printf("Introduzca su apellido materno (max 20 caracteres) : ");
    scanf("%s", apellidom);
    printf("Introduzca su estatura (en m) : ");
    scanf("%f",&estatura);
    printf("Introduzca su peso (en kg) : ");
    scanf("%f",&peso);
    printf("Introduzca su tipo de sangre : ");
    scanf("%s", sangre);
    printf("Introduzca su genero : ");
    scanf("%s", genero);
    printf("Introduzca su día de nacimiento : ");
    scanf("%d",&dia);
    printf("Introduzca su mes de nacimiento : ");
    scanf("%d",&mes);
    printf("Introduzca su ano de nacimiento : ");
    scanf("%d",&ano);
    printf("\n\n ***************************************************************");
    printf("\n *******************DATOS DEL PACIENTE**************************");
    printf("\nNombre : %s %s %s", nombre, apellidop, apellidom);//POR ALGUNA RAZON, NO IMPRIME EL 2DO APELLIDO
    printf("\n*Peso : %f kilogramos", peso);//NO IMPRIME KILOGRAMOS
    printf("\n*Estatura : %f metros", estatura);//NO IMPRIME METROS
    printf("\n*Tipo de sangre : %s", sangre);//POR ALGUNA RAZON NO LO IMPRIME
    printf("\n*Genero : %s", genero);
    printf("\n*Fecha de nacimiento : %d/%d/%d", dia, mes, ano);
    printf("\n **************************************************************");
    printf("\n\nPresione ENTER para salir...\n\n");

    return 0;
}
