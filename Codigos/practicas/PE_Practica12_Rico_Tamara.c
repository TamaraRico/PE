/*Rico Lopez Tamara Illian 01270673
PRACTICA 12
Sistema de control de un periodico*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CLEAR() system("CLS")

struct fecha{int dia; int mes; int year;};

struct anuncio{
    int num;
    char clasificacion[15];//int clasificacion; //hacer un menu captura profe
    char responsable[50];
    int telefono;
    char contenido[60];
    struct fecha publicacion;
};

struct fecha captura_fecha();
void clasificacion(char*);
void captura(struct anuncio * , int);
void grabar(struct anuncio, char);
void mostrar(char);
int busqueda (char llave[], char);
void borrar(char);
void editar (char);
void ordenar_responsable(char);
long int tamano(FILE *);
void mostrar_fecha();

int main()
{
    char opc, nombre_archivo[25];
    struct anuncio registro;
    int cont=0;

    printf("Ingrese el nombre del archivo que desea leer : ");
    gets(nombre_archivo);

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
            case '1':   cont+=1;
                        captura(&registro, cont);
                        grabar(registro, nombre_archivo);
                        break;
            case '2': borrar(nombre_archivo); break;
            case '3': editar(nombre_archivo); break;
            //case '4': busqueda(); break;
            //case '5': busqueda(); break;
            case '6': ordenar_responsable(nombre_archivo); break;
            case '7': mostrar(nombre_archivo); break;

        }
    }while (opc!=48);

    return 0;
}

void mostrar(char nombre)
{
    FILE * flujo;
    struct anuncio registro;
    //int cont=1;
    flujo= fopen(nombre,"rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            printf("\n\n  Registro No. %d\n", registro.num);
            //printf("Clasificacion: %s \n", registro.clasificacion);
            printf("Responsable: %s \n", registro.responsable);
            printf("Telefono: %d \n", registro.telefono);
            printf("Contenido: %s \n", registro.contenido);
            printf("\nFecha de publicacion: %d/%d/%d", registro.publicacion.dia, registro.publicacion.mes, registro.publicacion.year);
            setbuf(stdin,0);
            getchar();
            //cont++;
        }
    }
    fclose(flujo);
}
int busqueda (char llave[], char nombre)
{
    FILE * flujo;
    struct anuncio registro;
    int cont=0;
    flujo= fopen(nombre,"rb");
    if (flujo)
    {
        while( fread(&registro,sizeof(struct anuncio),1,flujo)>0)
        {
            cont++;
            if (strcmp(registro.num,llave)==0)
            {
            printf("\n\n  Registro No. %d\n", registro.num);
            //printf("Clasificacion: %s \n", registro.clasificacion);
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
void editar(char nombre)
{
    int ban;
    char llave[50];
    struct anuncio registro;

    FILE * flujo;
    setbuf(stdin,0);
    printf("Descripción del articulo: "); gets(llave);
    ban=busqueda(llave, nombre);

    if (ban!=-1)
    {
        flujo= fopen(nombre,"rb+");
        if (flujo!=NULL)
        {   fseek(flujo,(ban-1)*sizeof(struct anuncio),SEEK_SET);
            fread(&registro,sizeof(struct anuncio),1,flujo);
            printf("\n Encontrado en el Registro No. %d \n", ban);
            //printf("Clasificacion: %s \n", registro.clasificacion);
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
void borrar(char nombre)
{
   FILE *original, *copia;
   char llave[50];
   int ban;
   struct anuncio aux;
   original=fopen(nombre,"rb");
   copia=fopen("temporal.dat","wb");
   if (!original || !copia)
      printf("No se puede realizar la operacion");
   else
   {
       printf("Numero el articulo que desea eliminar: ");
       setbuf(stdin, 0);
       gets(llave);
       ban=busqueda(llave, nombre);
       if (ban!=-1)
       {
           while(fread(&aux,sizeof(struct anuncio),1,original)>0)
           {    if(strcmp(aux.responsable,llave)!=0)
                   fwrite(&aux,sizeof(struct anuncio),1,copia);
           }
           fclose(original);
           fclose(copia);
           remove(nombre);
           rename("temporal.dat", nombre);
           printf("\nBorrado...");getchar();
       }
       else
            printf("No se encontro");
   }
}

void ordenar_responsable(char nombre)
{
   FILE *flujo;
   int i, j;

   int n;
   struct anuncio a,b;

   flujo=fopen(nombre,"rb+");

   if (flujo==NULL)
      printf("No se puede realizar la operacion");
   else
   {       i=0;
           //fseek(flujo,0,SEEK_END);
           //n=ftell(flujo)/sizeof(struct articulo);
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
           fclose(flujo);
       }

   /* while(n> 0){
    for(int i = n; i < tam; i++){
        int j = i - n;

        while(j >= 0){
            int k = j + n;

            if(strcmp(e[j].apellido, e[k].apellido) < 0){
                j = -1;
            }else{
                swap(e[j],e[k]);
            }
        }
    }
    salto /= 2;
}*/
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
