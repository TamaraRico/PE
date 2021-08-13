//ESTRUCTURA DE DATOS
    //crea nuevos tipos de datos

#include<stdio.h>
#include<string.h>

struct fecha
{
    int dia;
    int mes;
    int year;
};

//definir estructuras (despues de las liberias, y antes de los prototipos de funciones
typedef struct alumno
//tambien se puede borrar el alumno y unicamente usar el alum_t y se llama estructura anonima
{//datos dentro de la estructura=miembro
    int matricula;
    char nombre[50];
    float promedio;
    struct fecha ingreso;
}alum_t;

/*nombre alternativo para los tipos de datos
ejemplo : typedef int entero;
typedef struct alumno alum_t; FORMA LARGA*/

void mostrar_alumnno(struct alumno);

int main(void)
{
    //declaracion de variables
    alum_t alumnos[]={{2020, "Raul", 85.0, {8, 8, 2019}},
                      {2021, "Tamara", 90.5, {16, 8, 2019}}};//USANDO EL ALIAS
    //tipo de datos: struct alumno
    //nombre de la variable: a1

    //ACCESO AL ESTRUCTURAS ANIDADAS
    //a1.ingreso.year=2019; //estructuras anidadas

    printf("tamaño del arreglo: %d", sizeof(alumnos));
    //60 por el compilador

    /* FORMA LARGA, se puede declarar al principio
    a1.matricula=2020;
    strcpy(a1.nombre, "Raul");
    a1.promedio=85;*/

    printf("\n\nInformacion del alumno 1:");
    mostrar_alumnno(*alumnos);
    printf("\n\nInformacion del alumno 2:");
    mostrar_alumnno(*(alumnos+1));

    return 0;
}

//tipo de dato: struct alumno
//nombre del parametro: an
void mostrar_alumnno(struct alumno an)
{
    printf("\nMatricula del alumno : %d", an.matricula);
    printf("\nNombre del alumno : %s", an.nombre);
    printf("\nMatricula del alumno : %.2f", an.promedio);
    printf("\nFecha de ingreso : %d/%d/%d", an.ingreso.dia, an.ingreso.mes, an.ingreso.year);
}

