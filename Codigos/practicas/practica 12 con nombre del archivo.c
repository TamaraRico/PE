#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define CLEAR() system("CLS")

struct fecha{int dia; int mes; int year;};
struct anuncio{
    int num;
    char clasificacion[20];
    char responsable[50];
    int telefono;
    char contenido[200];
    struct fecha publicacion;
};

void captura_clas(char*);
struct fecha captura_fecha();
void captura_clas(char*);
void captura(struct anuncio *);
void grabar(struct anuncio);
void mostrar_todos();
int busqueda_entero (int);
void borrar();
void editar ();
void ordenar_responsable();
long int tamano(FILE *);
//void mostrar_fecha();
int numeros_diferentes(int);
void consulta_clas();
void consulta_responsable();

int main()
{
    char opc;
    struct anuncio registro;
    do
    {
        CLEAR();
        puts("\n1) Registrar anuncio");
        puts("2) Borrar (no. de anuncio)");
        puts("3) Editar (no.de anuncio)");
        puts("4) Consultar por clasificacion");
        puts("5) Consultar por responsable");
        puts("6) Ordenar");
        puts("7) Mostrar todos");
        puts("0) Salir");
        printf("Opcion:");

        setbuf(stdin, 0);
        opc=getchar();

        switch(opc)
        {
            case '1':   captura(&registro);//
                        grabar(registro);//
                        break;
            case '2': borrar(); break;
            case '3': editar(); break;
            case '4': consulta_clas(); break;//
            case '5': consulta_responsable(); break; //
            case '6': ordenar_responsable(); break;
            case '7': mostrar_todos(); break;//
        }
    }while (opc!=0);
    return 0;
}
int numeros_diferentes(int num)
{
    FILE * flujo;
    struct anuncio a;
    int i;
    flujo= fopen("clientes.dat","rb");
    if (flujo)
    {
        while(fread(&a,sizeof(struct anuncio),1,flujo)>0)
        {
            i++;
            if (a.num==num)
            {
                fclose(flujo);
                return i;
            }
            else
            {
                fclose(flujo);
                return 0;
            }
        }
    }
    else
    {
        fclose(flujo);
        printf("Error al abrir el flujo");
    }
}
void mostrar()
{
    FILE * flujo;
    struct anuncio registro;
    flujo= fopen("clientes.dat","rb");
    if (flujo)
    {
        while(fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", registro.num);
            printf("Clasificacion: %s \n", registro.clasificacion);
            printf("Responsable: %s \n", registro.responsable);
            printf("Telefono: %d \n", registro.telefono);
            printf("Contenido: %s \n", registro.contenido);
            printf("\nFecha de publicacion: %d/%d/%d", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
            setbuf(stdin,0);
            getchar();
        }
    }
    fclose(flujo);
}
int busqueda_entero(int num)
{
    FILE * flujo;
    struct anuncio registro;
    int cont=0;
    flujo= fopen("clientes.dat","rb");
    if (flujo)
    {
        while(fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (registro.num==num)
            {
            printf("\n\n  Registro No. %d\n", registro.num);
            printf("Clasificacion: %s \n", registro.clasificacion);
            printf("Responsable: %s \n", registro.responsable);
            printf("Telefono: %d \n", registro.telefono);
            printf("Contenido: %s \n", registro.contenido);
            printf("\nFecha de publicacion: %d/%d/%d", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
            setbuf(stdin,0);
            getchar();
            fclose(flujo);
            return cont;
            }
        }
        fclose(flujo);
    }
    return -1;
}
void editar()
{
    int ban, llave;
    struct anuncio registro;
    FILE * flujo;
    setbuf(stdin,0);
    printf("Numero del anuncio: "); scanf("%d", &llave);
    ban=busqueda_entero(llave);
    if (ban!=-1)
    {
        flujo= fopen("clientes.dat","rb+");
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fread(&registro,sizeof(struct anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("Clasificacion: %s \n", registro.clasificacion);
            printf("Responsable: %s \n", registro.responsable);
            printf("Telefono: %d \n", registro.telefono);
            printf("Contenido: %s \n", registro.contenido);
            printf("\nFecha de publicacion: %d/%d/%d", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
            printf("Escriba el contenido mejorado: "); gets(&registro.contenido);
            fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fwrite(&registro,sizeof(struct anuncio),1,flujo);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }
    else
            printf("No se encontro");
}
void borrar()
{
   FILE *original, *copia;
   int llave, ban;
   struct anuncio aux;
   original=fopen("clientes.dat","rb");
   copia=fopen("temporal.dat","wb");
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       printf("Numero del anuncio que desea eliminar: ");
       setbuf(stdin, 0);
       scanf("%d", &llave);
       ban=busqueda_entero(llave);
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(struct anuncio),1,original)>0)
           {    if(strcmp(aux.responsable,llave)!=0)
                   fwrite(&aux,sizeof(struct anuncio),1,copia);
           }
           fclose(original);
           fclose(copia);
           remove("clientes.dat");
           rename("temporal.dat", "clientes.dat");
           printf("\nBorrado...");getchar();
       }
       else
            printf("No se encontro");
   }
}
void ordenar_responsable()
{
   FILE *flujo;
   int i, j, n;
   struct anuncio a,b;
   flujo=fopen("clientes.dat","rb+");
   if (flujo==NULL)
      printf("No se puede realizar la operacion");
   else
   {       i=0;
           n=tamano(flujo)/sizeof(struct anuncio);
           printf("Ordenando %d registros ", n);
           getchar();
           for(i=0;i<n-1;i++)
           {
              for(j=i+1;j<n;j++)
              {
                fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
                fread(&a,sizeof(struct anuncio),1,flujo);
                fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
                fread(&b,sizeof(struct anuncio),1,flujo);
                printf("%d, %d, %s con %s \n", i,j,a.responsable, b.responsable);
                getchar();
                if( strcmp(a.responsable,b.responsable)>0)
                {
                    fseek(flujo,i*sizeof(struct anuncio),SEEK_SET);
                    fwrite(&b,sizeof(struct anuncio),1,flujo);
                    fseek(flujo,j*sizeof(struct anuncio),SEEK_SET);
                    fwrite(&a,sizeof(struct anuncio),1,flujo);
                }
              }
           }
        i=0;
        printf("\nLos anuncios ordenados según el responsable");
        fseek(flujo,0,SEEK_SET);
        while(fread(&a,sizeof(struct anuncio),1,flujo)>0)
        {
            i++;
            printf("\n No. de control: %d",a.num);
            printf("\n Clasificacion: %d",a.clasificacion);
            printf("\n Contenido: %s ", a.contenido);
            printf("\n Telefono: %d",a.telefono);
            printf("\nResponsable: %s",a.responsable);;
        }
        fclose(flujo);
        setbuf(stdin, 0);getchar();
       }
}
long int tamano(FILE *file)
{
    char buffer;
    long int size=0;
    fseek(file, 0, SEEK_SET);
    while(fread(&buffer, 1, 1, file)>0)size++;
    fseek(file, 0, SEEK_SET);
    return size;
}
void captura(struct anuncio * registro)
{   float aux;
    CLEAR();
    printf("No. de control: "); scanf("%d",&registro->num);
    setbuf(stdin,0);
    printf("Clasificacion del anuncio: ");
    captura_clas(registro->clasificacion);
    printf("Respondable: \n"); gets(registro->responsable);
    printf("Contenido: "); gets(registro->contenido);
    printf("Telefono: "); scanf("%d",&aux);
    registro->telefono=aux;
    registro->publicacion=captura_fecha();
}
void captura_clas(char * clasificacion)
{
    char opc;
    puts("\n1)Venta");
    puts("2)Autos");
    puts("3)Mascotas");
    puts("4)Empleos");
    puts("5)Renta");
    puts("6)Traspasos");
    puts("7)Otro");
    opc=getchar();
    switch(opc)
    {
        case '1': strcpy(clasificacion, "Venta"); break;
        case '2': strcpy(clasificacion, "Autos"); break;
        case '3': strcpy(clasificacion, "Mascotas"); break;
        case '4': strcpy(clasificacion, "Empleos"); break;
        case '5': strcpy(clasificacion, "Renta"); break;
        case '6': strcpy(clasificacion, "Traspasos"); break;
        case '7': strcpy(clasificacion, "Otro"); break;
    }
}
struct fecha captura_fecha()
{
    struct fecha publicacion;
    printf("Ingrese fecha (formato dd/mm/aaaa): ");
    scanf("%d/%d/%d",&publicacion.dia, &publicacion.mes, &publicacion.year);
    return publicacion;
}
void grabar(struct anuncio registro)
{
    FILE * flujo;
    int cont;
    printf("\n No. de control: %d",registro.num);
    printf("\n Clasificacion: %d",registro.clasificacion);
    printf("\n Contenido: %s ", registro.contenido);
    printf("\n Telefono: %d",registro.telefono);
    printf("\nResponsable: %s",registro.responsable);
    getchar();
    flujo= fopen("anuncios.dat","ab");
    if (flujo!=NULL)
    {
        fwrite(&registro,sizeof(struct anuncio),1,flujo);
        fclose(flujo);
    }
    else
        printf("No se pudo abrir");
}
void consulta_responsable()
{//definir variables locales
    FILE * flujo;
    struct anuncio registro;
    int ban, cont=0;;
    char llave[50];
    setbuf(stdin,0);
    printf("Ingrese el nombre del responsable: "); gets(llave);
    flujo= fopen("clientes.dat","rb");
    if (flujo)
    {//para leer el archivo con los clientes
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.responsable,llave)==0)
            {//si ambos datos son iguales sigifica que sí existe ese dato
                printf("\n No. de control: %d",registro.num);
                printf("\n Clasificacion: %d",registro.clasificacion);
                printf("\n Contenido: %s ", registro.contenido);
                printf("\n Telefono: %d",registro.telefono);
                printf("\nResponsable: %s",registro.responsable);
                getchar();
                fclose(flujo);
                ban=cont;
            }//si existe se regresa un numero
        }
        fclose(flujo);
    }
    ban=-1;
    if (ban!=-1)
    {//porque si existe el nombre en la base de datos de los clientes
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fread(&registro,sizeof(struct anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\n No. de control: %d",registro.num);
            printf("\n Clasificacion: %d",registro.clasificacion);
            printf("\n Contenido: %s ", registro.contenido);
            printf("\n Telefono: %d",registro.telefono);
            printf("\nResponsable: %s",registro.responsable);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }//por algun error con el archivo
    else//cuando no se cuentra el nombre
            printf("No se encontro");
}
void consulta_clas()
{//definir variables locales
    FILE * flujo;
    struct anuncio registro;
    int ban, cont=0;;
    char llave[50];
    setbuf(stdin,0);
    printf("Ingrese el nombre del tipo de anuncio: "); gets(llave);
    flujo= fopen("clientes.dat","rb");
    if (flujo)
    {//para leer el archivo con los clientes
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.clasificacion,llave)==0)
            {//si ambos datos son iguales sigifica que sí existe ese dato
                printf("\n No. de control: %d",registro.num);
                printf("\n Clasificacion: %d",registro.clasificacion);
                printf("\n Contenido: %s ", registro.contenido);
                printf("\n Telefono: %d",registro.telefono);
                printf("\nResponsable: %s",registro.responsable);
                getchar();
                fclose(flujo);
                ban=cont;
            }//si existe se regresa un numero
        }
        fclose(flujo);
    }
    ban=-1;
    if (ban!=-1)
    {//porque si existe el nombre en la base de datos de los clientes
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fread(&registro,sizeof(struct anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            printf("\n No. de control: %d",registro.num);
            printf("\n Clasificacion: %d",registro.clasificacion);
            printf("\n Contenido: %s ", registro.contenido);
            printf("\n Telefono: %d",registro.telefono);
            printf("\nResponsable: %s",registro.responsable);
            fclose(flujo);
        }
        else
            printf("No se pudo abrir el archivo");
    }//por algun error con el archivo
    else//cuando no se cuentra el nombre
            printf("No se encontro");
}
void mostrar_todos()
{
    time_t t;
    struct tm tm;
    FILE * file=fopen("clientes.dat","rb");
    struct anuncio registro;
    int cont=0;

    t=time(NULL);
    tm=*localtime(&t);
    CLEAR();
    setbuf(stdin,0);
    printf("\nInformacion de los anuncios prublicados hoy\n");

    if(file)
    {
        while(fread(&registro,sizeof(struct anuncio),1,file)>0)
        {
            cont++;
            if (registro.publicacion.dia==tm.tm_mday&&registro.publicacion.mes==(tm.tm_mon+1)&&registro.publicacion.year==
                (tm.tm_year+1900))
            {
                printf("\n No. de control: %d",registro.num);
                printf("\n Clasificacion: %d",registro.clasificacion);
                printf("\n Contenido: %s ", registro.contenido);
                printf("\n Telefono: %d",registro.telefono);
                printf("\nResponsable: %s",registro.responsable);
            }
        }
        fclose(file);
        setbuf(stdin,0);getchar();
    }
    else
    {
        printf("Error al abrir el archivo");
        setbuf(stdin, 0);getchar();
    }
}
