/*Rico Lopez Tamara Illian 01270673
PRACTICA 10
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct fecha{
    int dia;
    int mes;
    int year;
};

struct estudiante{
    int matricula;
    char nombre[35];
    char a_paterno[35];
    char a_materno[35];
    struct fecha ingreso;
    struct fecha nacimiento;
    int promedio;
};

struct estudiante captura();
void mostar_estudiante(struct estudiante);//tipo de dato: struct estudiante
void promedio_promedio(int*, int);
void mostrar_est_reprobados(struct estudiante*, int);
void mostrar_est_aprobados(struct estudiante*, int);
void busqueda_matricula(struct estudiante*, int);
void busqueda_apellido(struct estudiante*, int);

int main(void)
{
    char opc;
    int num, *promedio=NULL, i, j, opc2;
    struct estudiante est, **arrayy=NULL, *aprobados=NULL, *reprobados=NULL;
    printf("Ingrese el numero de alumnos que desea capturar: ");
    scanf("%d", &num);
    arrayy=malloc(num*sizeof(struct estudiante));
    aprobados=malloc(num*sizeof(struct estudiante));
    reprobados=malloc(num*sizeof(struct estudiante));
    promedio=(int*)malloc(num*sizeof(struct estudiante));
    for(i=0; i<num; i++)
    {
        est=arrayy[i];
        est=captura();
        mostrar_estudiante(est);
    }
    for(j=0; j<num; j++)
    {
        est=arrayy[j];
        promedio[j]+=est.promedio;
        if(est.promedio<60)
            reprobados[j]+=est;
        else
            aprobados[j]+=est;
    }
    promedio_promedio(promedio, num);
    printf("\nImpresion de alumnos aprobados :");
    mostrar_est_aprobados(aprobados, num);
    printf("\nImpresion de alumnos reprobados :");
    mostrar_est_reprobados(reprobados, num);

    do
    {
        printf("\nDesea buscar un alumno :");
        printf("\n1)Por matricula");
        printf("\n2)Por apellido");
        scanf("%d", &opc2);
        if(opc2==1)
            busqueda_matricula(arrayy, num);
        else if(opc2==2)
            busqueda_apellido(arrayy, num);
        else
            printf("\nOpcion no vaida");
        printf("\nDesea buscar otro alumno (S/N) : ");
        scanf("%c", &opc);

    }while(opc=='n'||opc=='N');

    return 0;
}

struct estudiante captura()
{
    struct estudiante e;
    printf("\nIngrese la matricula : ");
    scanf("%d", &e.matricula);
    printf("\nIngrese el nombre: ");
    scanf("%s", e.nombre);
    printf("Ingrese el apellido: ");
    scanf("%s %s", e.a_paterno, e.a_materno);
    printf("Ingrese la fecha de ingreso: ");
    e.ingreso=captura_fecha();
    printf("Ingrese la fecha de nacimiento : ");
    e.nacimiento=captura_fecha();
    e.promedio=rand()%100+1;
    printf("El promedio del alumno es : %d", e.promedio);
    //e*.= (int*)malloc(n*sizeof(int));
}

struct fecha captura_fecha()
{
    struct fecha f;
    printf("\nIngrese fecha (formato dd/mm/aaaa): ");
    scanf("%d/%d/%d",&f.dia, &f.mes, &f.year);
}

void mostrar_estudiante(struct estudiante e)
{
    printf("\nNombre del alumno: %s %s %s", e.nombre, e.a_paterno, e.a_materno);
    printf("\nMatricula del alumno: %d", e.matricula);
    printf("\nPromedio del alumno: %d", e.promedio);
    printf("\nFecha de ingreso %d/%d/%d", e.ingreso.dia, e.ingreso.mes, e.ingreso.year);
    printf("\nFecha de nacimiento %d/%d/%d", e.nacimiento.dia, e.nacimiento.mes, e.nacimiento.year);
}

void promedio_promedio(int* promedio, int num)
{
    int i, s=0;
    float p;
    for(i=0; i<num; i++)
    {
        s+=promedio[i];
    }
    p=s/num;
    printf("\nEl promedio de todos los alumnos capturados es de %.1f", p);
}

void mostrar_est_reprobados(struct estudiante* e, int num)
{
    struct estudiante est;
    int i;
    for(i=0; i<num; i++)
    {
        est=e[i];
        printf("\nEl alumno %s %s %s reprobó con un promedio de %d", est.nombre, est.a_paterno, est.a_materno, est.promedio);
    }
}

void mostrar_est_aprobados(struct estudiante* e, int num)
{
    struct estudiante est;
    int i;
    for(i=0; i<num; i++)
    {
        est=e[i];
        printf("\nEl alumno %s %s %s aprobó con un promedio de %d", est.nombre, est.a_paterno, est.a_materno, est.promedio);
    }
}

void busqueda_matricula(struct estudiante* arreglo, int num)
{
    struct estudiante est;
    int matricula, i, no=0;
    printf("\nIngrese el numero de la matricula que desea buscar : ");
    scanf("%d", &matricula);
    for(i=0; i<num; i++)
    {
        est=arreglo[i];
        if(est.matricula==matricula)
            printf("\nAl alumno %s %s %s se le corresponde la matricula %d", est.nombre, est.a_paterno, est.a_materno, est.matricula);
        else
            no++;
    }
    if(no==num)
        printf("\nLa matricula %d no se encuentra dentro del registro de alumnos", matricula);
}

void busqueda_apellido(struct estudiante* arreglo, int num)
{
    struct estudiante est;
    int i, no=0;
    char apellido;
    printf("\nIngrese el apellido paterno del alumno que desea buscar : ");
    scanf("%s", apellido);
    for(i=0; i<num; i++)
    {
        est=arreglo[i];
        if(est.a_paterno==apellido)
            printf("\nAl alumno %s %s %s se le corresponde la apellido %s", est.nombre, est.a_paterno, est.a_materno, est.a_paterno);
        else
            no++;
    }
    if(no==num)
        printf("\nEl apellido %s no se encuentra dentro del registro de alumnos", apellido);
}
