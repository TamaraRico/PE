/*Rico Lopez Tamara Illian 1270673
EXAMEN 2 EJERCICIO 2
Realizar un programa para administrar información de los clientes de una empresa. Se debe almacenar en un archivo la siguiente
información de cada cliente: ID, nombre, apellido, fecha de nacimiento, género, correo, número de teléfono y sueldo mensual.
Realizar las siguientes funciones: 1) capturar datos por teclado al archivo, 2) búsqueda por apellido, 3) búsqueda por ID. 4)
Mostrar todos. 5) Baja por ID. 6) Aplicar bono: las personas que tengan más de 60 años se les ingrementa el sueldo en 10%
(Mostrar información en consola sin modificar el archivo).
*/

//incluir liberia
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR() system("CLS")

//definicion de las estructuras con el tipo de dato cliente
struct fecha{int dia; int mes; int year;};
struct cliente{
    int id;
    char nombre[20];
    char apellido[20];
    struct fecha n;
    int genero;
    char correo[20];
    int telefono;
    float sueldo;
};
//prototipos de funciones
struct fecha captura_fecha();
void captura(struct cliente * c);
void grabar(struct cliente cl);
void borrar();
void busqueda_ID();
void busqueda_cliente();
void mostrar();
void aplicar_bono();
//funcion main con menu
int main(void)
{//declarar dato tipo struct cliente para las funciones que lo ocupan
    struct cliente c;
    char opc;
//impresion del menu para el usuario
    puts("\nMENU ACERCA DE LOS CLIENTES\n");
    do{
        //CLEAR();//para que se limpie la consola, agregado al final
        puts("\n1) Captura de datos");
        puts("2) Busqueda por apellido");
        puts("3) Busqueda por ID");
        puts("4) Mostrar todos");
        puts("5) Baja por ID");
        puts("6) Aplicar bono");

        printf("Elija una opcion: ");
        setbuf(stdin, 0);
        opc=getchar();
        //para acceder facilmente al menu
        switch(opc)
        {//llamadas a cada funcion segun la opcion del usuario
            case '1': captura(&c);
                      grabar(c); break;
            case '2': busqueda_cliente(); break;
            case '3': busqueda_ID(); break;
            case '4': mostrar(); break;
            case '5': borrar(); break;
            case '6': aplicar_bono(); break;
        }
    }while(opc!=48);//para que no sea un ciclo infinito
    return 0;
}
//funcion para capturar cliente en un tipo de dato cliente
void captura(struct cliente * c)
{   float x;
    printf("ID del cliente: "); scanf("%d",&c->id);
    setbuf(stdin,0);
    printf("Nombre: "); gets(c->nombre);
    printf("Apellido: "); gets(c->apellido);
    printf("Correo: "); gets(c->correo);
    printf("Genero:"); scanf("%d",&c->genero);
    printf("Sueldo: "); scanf("%f",&x);
    c->sueldo=x;
    printf("Telefono:"); scanf("%d",&c->telefono);
    c->n=captura_fecha();
}
//se captura la fecha aparte porque es mas facil, porque es otra estructuura
struct fecha captura_fecha()
{//declarar el tipo de dato fecha
    struct fecha n;
    printf("Ingrese fecha de nacimiento(formato dd/mm/aaaa): ");
    scanf("%d/%d/%d",&n.dia, &n.mes, &n.year);
    return n;
}
//escribir los datos en el archivo registro
void grabar(struct cliente cl)
{//impresion de datos a grabar en el archivo
    FILE * archivo;
    printf("\n ID: %d",cl.id);
    printf("\n Nombre: %s ", cl.nombre);
    printf("\n Apellido: %s ", cl.apellido);
    printf("\n Genero: %d ", cl.genero);
    printf("\n Correo: %s ", cl.correo);
    printf("\n Fecha de nacimiento: %d/%d/%d", cl.n.dia, cl.n.mes, cl.n.year);
    printf("\n Sueldo: %f",cl.sueldo);
    printf("\n Telefono: %d",cl.telefono);
    getchar();
    archivo= fopen("registro.dat","ab");
    if (archivo!=NULL)
    {//escribir en el archivo los datos impresos
        fwrite(&cl,sizeof(struct cliente),1,archivo);
        fclose(archivo);
    }
    else
        printf("No se pudo abrir");
}
//para borrar a los clientes que ya no sean necesarios
void borrar()
{//declaracion de variables locales
   FILE *flujo, *copia;
   int num, resultado, cont;
   struct cliente cl, aux;
   flujo=fopen("registro.dat","rb");
   copia=fopen("backup.dat","wb");
   if (!flujo || !copia)
      printf("No se puede realizar la operacion");
   else
   {//se eliminan a partir del ID
       printf("ID del cliente que desea eliminar: ");
       setbuf(stdin, 0);
       scanf("%d", &num);
       if (flujo)
        {//se lee el archivo
            while(fread(&cl,sizeof(struct cliente),1,flujo)>0)
            {//contador para encontrar el numero de registro
                cont++;
                if (cl.id==num)
                {//se busca el numero del ID del cliente
                    fclose(flujo);
                    resultado=cont;
                }
                else
                {//si no se encuentra se cierra el archivo y se regresa cero
                    fclose(flujo);
                    resultado=0;
                }
            }
        }
        else
        {//en caso de no poder abrir el archivo
            fclose(flujo);
            printf("Error al abrir el flujo");
        }
    //si el resultado es diferente de cero significa que se encontro el numero de ID en el aechivo
        if (resultado!=0)
       {
           while(fread(&aux,sizeof(struct cliente),1,flujo)>0)
           {    if(aux.id==num)
                   fwrite(&aux,sizeof(struct cliente),1,copia);
           }//para eliminar al cliente del archivo pero tenerlo en un respaldo
           fclose(flujo);
           fclose(copia);
           remove("registro.dat");
           rename("backup.dat", "registro.dat");
           printf("\nBorrado...");getchar();
       }
       else//no se encuentra el dato del cliente para borrarlo
            printf("No se encontro");
   }
}
//funcion para buscar a un cliente en base a su ID
void busqueda_ID()
{
    FILE * flujo;
    struct cliente cl;
    int ban, id_usuario, cont=0;
    setbuf(stdin,0);
    //datos para poder buscarlo en el archivo
    printf("Ingrese el no. de ID: ");
    scanf("%d", &id_usuario);
    flujo= fopen("registro.dat","rb");
    if (flujo)
    {//para poder leer el archivo con los clientes
        while( fread(&cl,sizeof(struct cliente),1,flujo)>0)
        {
            cont++;
            if (cl.id==id_usuario)
            {//para imprimir al usuario con el numero de ID si se encuetra
                printf("\nID: %d \n", cl.id);
                printf("Nombre: %s \n", cl.nombre);
                printf("Apellido: %s \n", cl.apellido);
                printf("Genero: %d \n", cl.genero);
                printf("Correo: %s \n", cl.correo);
                printf("Fecha de nacimiento: %d/%d/%d\n", cl.n.dia, cl.n.mes, cl.n.year);
                printf("Telefono: %d \n", cl.telefono);
                printf("Sueldo: %f \n", cl.sueldo);
                getchar();
                fclose(flujo);
                ban=cont;
            }
        }
        fclose(flujo);
    }
    ban=-1;
    if (ban!=-1)
    {//si la variable es diferente de -1 significa que si se encontro el dato
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct cliente),SEEK_SET);
            fread(&cl,sizeof(struct cliente),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\nID: %d \n", cl.id);
            printf("Nombre: %s \n", cl.nombre);
            printf("Apellido: %s \n", cl.apellido);
            printf("Genero: %d \n", cl.genero);
            printf("Correo: %s \n", cl.correo);
            printf("Fecha de nacimiento: %d/%d/%d\n", cl.n.dia, cl.n.mes, cl.n.year);
            printf("Telefono: %d \n", cl.telefono);
            printf("Sueldo: %f \n", cl.sueldo);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }
    else
            printf("No se encontro");
}
//para mostrar todos los datos de todos los clientes
void mostrar()
{
    FILE * flujo;
    struct cliente cl;
    int cont=1;
    flujo= fopen("registro.dat","rb");
    if (flujo)
    {//para acceder al archivo en modo lectura
        while( fread(&cl,sizeof(struct cliente),1,flujo)>0)
        {//para imprimir a los clientes
            printf("\n\n  Registro No. %d\n", cont);
            printf("ID: %d \n", cl.id);
            printf("Nombre: %s \n", cl.nombre);
            printf("Apellido: %s \n", cl.apellido);
            printf("Genero: %d \n", cl.genero);
            printf("Correo: %s \n", cl.correo);
            printf("Fecha de nacimiento: %d/%d/%d\n", cl.n.dia, cl.n.mes, cl.n.year);
            printf("Sueldo: %f \n", cl.sueldo);
            printf("Telefono: %d \n", cl.telefono);
            setbuf(stdin,0);
            getchar();
            cont++;
        }
    }
    fclose(flujo);
}
//para un aumento de sueldo a mayores de 60
void aplicar_bono()
{//declarar variables
    struct cliente cl;
    FILE *file=fopen("registro.dat", "rb");
//para leer el archivo sin cambiarlo
    while(!feof(file))
    {
        fread(&cl, sizeof(struct cliente), 1, file);
        if(2020-cl.n.year>=60)
        {//para confirmar que son mayores de 60
            printf("\nID: %d \n", cl.id);
            printf("Nombre: %s \n", cl.nombre);
            printf("Apellido: %s \n", cl.apellido);
            printf("Genero: %d \n", cl.genero);
            printf("Correo: %s \n", cl.correo);
            printf("Fecha de nacimiento: %d/%d/%d\n", cl.n.dia, cl.n.mes, cl.n.year);
            printf("Telefono: %d \n", cl.telefono);
            printf("Sueldo: %f \n", cl.sueldo);
            cl.sueldo+=cl.sueldo*0.1;
            printf("\nSueldo con bono= %d", cl.sueldo);
        }
        else
        {//en caso de que no encuentre ningun cliente mayor a 60
            printf("\nNo hay clientes mayores de 60 años");
        }
    }//para cerrar el archivo porque ya no se necesita
    fclose(file);
}
//para encontrar a los cliente a traves de su apellido
void busqueda_cliente()
{//definir variables locales
    FILE * flujo;
    struct cliente cl;
    int ban;
    char llave[50];
    setbuf(stdin,0);
//para btener un dato que buscar dentro del archivo
    printf("Apellido del cliente: "); gets(llave);
    int cont=0;
    flujo= fopen("registro.dat","rb");
    if (flujo)
    {//para leer el archivo con los clientes
        while( fread(&cl,sizeof(struct cliente),1,flujo)>0)
        {
            cont++;
            if (strcmp(cl.apellido,llave)==0)
            {//si ambos datos son iguales sigifica que sí existe ese dato
                printf("\nID: %d \n", cl.id);
                printf("Nombre: %s \n", cl.nombre);
                printf("Apellido: %s \n", cl.apellido);
                printf("Genero: %d \n", cl.genero);
                printf("Correo: %s \n", cl.correo);
                printf("Fecha de nacimiento: %d/%d/%d\n", cl.n.dia, cl.n.mes, cl.n.year);
                printf("Telefono: %d \n", cl.telefono);
                printf("Sueldo: %f \n", cl.sueldo);
                getchar();
                fclose(flujo);
                ban=cont;
            }//si existe se regresa un numero
        }
        fclose(flujo);
    }
    ban=-1;
//si no existe ese nombre se regresa -
    if (ban!=-1)
    {//porque si existe el nombre en la base de datos de los clientes
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct cliente),SEEK_SET);
            fread(&cl,sizeof(struct cliente),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\nID: %d \n", cl.id);
            printf("Nombre: %s \n", cl.nombre);
            printf("Apellido: %s \n", cl.apellido);
            printf("Genero: %d \n", cl.genero);
            printf("Correo: %s \n", cl.correo);
            printf("Fecha de nacimiento: %d/%d/%d\n", cl.n.dia, cl.n.mes, cl.n.year);
            printf("Telefono: %d \n", cl.telefono);
            printf("Sueldo: %f \n", cl.sueldo);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }//por algun error con el archivo
    else//cuando no se cuentra el nombre
            printf("No se encontro");
}
