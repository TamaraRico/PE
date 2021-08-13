/*Rico Lopez Tamara Illian 1270673
PRACTICA 7*/
//JUEGO DEL GATO

/*Funciones dentro del juego
    1. Limpiar el tabero
    2. Establecer el turno
    3. Movimiento
    4. Ganador
    5. Revisar si hay espaios vacios
    6. Cambiar de turno
    7. Mostrar tablero*/

#include<stdio.h>
#include<stdlib.h>//para que el primer turno sea aleatorio, es decir, si empieza x ó o
#include<time.h>

//Usar caracteres para ahorrar memoria (32 bytes)
#define CRUZ 'X'
#define CERO 'O'
#define VACIO 0
//Para que sea mas entendible

#define FIL 3 //FILAS
#define COL 3 //COLUMNAS

/*1. Abstraccion de identidades, estructuras de datos
  2. Funciones que operen sobre las estructuras de datos
  3.  */

#define CAMBIOT(X) (X==CRUZ? CERO : CRUZ) //cambio turno (para que sea mas facil)
//turno=turno==CRUZ? CERO: CRUZ; esto es lo queremos que haga


//PROTOTIPO DE FUNCIONES
void limpiar_tablero(char[FIL][COL], int, int);//vacio porque solo modifica el arreglo, no necesitamos usarlo, y por eso no regresa nada
char turno_inicial();//tablero y posicion del movimiento
int movimiento(char[FIL][COL], int, int, char);//regresa 1 (movimiento valido) y 0 (si es movimiento no es realizable)
char ganador(char[FIL][COL], int, int);
//X: Si gano X
//O: Si gano O
//0 (falso): si nadie gana
int vacios(char [FIL][COL], int, int);//todavia hay espacio vacios???
void mostrar_tablero(char [FIL][COL], int, int);//void porque solo necesitamos que lo haga, sin que regrese nada
//porque no se puede regresar un arreglo


//FUNCION PRINCIPAL
int main(void)
{
    int x, y, empate;
    char tablero[FIL][COL], opc='S', turno, ganador[10];

    printf("\nJUEGO DEL GATO\n\n");

    do
    {
        limpiar_tablero(tablero[FIL][COL], FIL, COL);
        turno=turno_inicial();

        if(turno==CRUZ)
        {
            printf("Jugador X ingrese una coordenada x, y entre el 0 y el 2 = ");
            scanf("%d,%d", &x, &y);
        }
        else
        {
            printf("Jugador O ingrese una coordenada x, y entre el 0 y el 2 = ");
            scanf("%d,%d", &x, &y);
        }

        do
        {
            turno=CAMBIOT(turno_inicial);
            printf("Jugador %c ingrese una coordenada x, y entre el 0 y el 2 = ", turno);
            scanf("%d,%d", &x, &y);
            movimiento(tablero[FIL][COL], x, y, turno);
            ganador(tablero[FIL][COL], FIL, COL);
            empate=vacios(tablero[FIL][COL], FIL, COL);
            system("cls");

        }while(ganador==VACIO||empate==0);//no hay ganador ni empate

    if(ganador==CRUZ)
    {
        printf("\n\nEl ganador es el jugador %c!!!", CRUZ);
    }
    else if(ganador==CERO)
    {
        printf("\n\nEl ganador es el jugador %c!!!", CERO);
    }
    else if (empate==1)
    {
        printf("\n\nAl parecer hubo un empate!!");
    }
    printf("\n\n¿Quieres volver a jugar (S/N)? = ");
    scanf("%c", opc);

    }while(opc!='N');

    return 0;
}

//cuando se quiere volver a jugar y para empezar el juego.
//cuando veriicamos si las celdas estan "VACIO"
void limpiar_tablero(char tablero[FIL][COL], int fila, int col)
{
    int i, j;
    for(i=0; i<fila; i++)//para accesar a las posiciones
    {
        for(j=0; j<col; j++)
            tablero[i][j]=VACIO;
    }
}

//QUIEN INICIA EL JUEGO
char turno_inicial()
{
    return rand()%2 ? CRUZ : CERO;
    //rand()%2 significa que solo puede escoger cero (CERO) y uno (CRUZ) para generar un numero aleatorio
    //? CRUZ siendo el primero cruz
    //: CERO y de lo contrario, cero
}

int movimiento(char tablero[FIL][COL], int x, int y, char turno)//el usuario ingresa la coordnada del tablero
{//tablero= matriz, x y y a lo que ingresa el usuario, turno=si es CRUZ o  CERO
    if(x>=0 && x<=FIL && y>=0 && y<=COL)//que la coordenada este dentro del tablero
    {
        if(tablero[x][y] == VACIO)
        {//Si es espacio es vacio, se puede poner CRUZ  o CERO
            tablero[x][y]=turno;
            return 1;
        }
    }
    return 0;// Si no es valida o esta ocupada, generar un mensaje en main
}

char ganador(char tablero[FIL][COL], int fila, int col)
{
    int i, j, diagonal1=0, diagonal2=0, acruz=0, acero=0;
    //PARA SABER SI HAY TRES EN LAS FILAS
    for(i=0; i<=fila; i++)
    {
        acero=0;
        acruz=0;
        for(j=0; j<=col; j++)
        {
            if(tablero[i][j]==CRUZ)
                acruz+=1;
            else if(tablero[i][j]==CERO)
                acero+=1;
        }
    }
    if(acruz==3)
        return CRUZ;
    if(acero==3)
        return CERO;

    //PARA SABER SI HAY TRES EN LAS COLUMNAS
    for(j=0; j<=col; j++)
    {
        acero=0;
        acruz=0;
        for(i=0; i<=fila; i++)
        {
            if(tablero[i][j]==CRUZ)
                acruz+=1;
            else if(tablero[i][j]==CERO)
                acero+=1;
        }
    }
    if(acruz==3)
        return CRUZ;
    if(acero==3)
        return CERO;

    //PARA SABER SI HAY TRES EN RAYA EN LAS DIAGONALES
    if(tablero[0][0]==tablero[1][1] && tablero[0][0]==tablero[2][2])
    {
        if(tablero[0][0]==CRUZ)
            return CRUZ;
        if(tablero[0][0]==CERO)
            return CERO;
    }
    if(tablero[0][2]==tablero[1][1] && tablero[0][2]==tablero[2][0])
    {
        if(tablero[0][2]==CRUZ)
            return CRUZ;
        if(tablero[0][2]==CERO)
            return CERO;
    }
    return VACIO;

}

//
int vacios(char tablero[FIL][COL], int fila, int col)
{
    int i, j;
    for(i=0; i<fila; i++)//para acceder a las posiciones
    {
        for(j=0; j<col; j++)
        {
            if(tablero[i][j]==VACIO)//si no se cumple es que ya hay CRUZ O CERO
            {
                return 1; //si todavia hay espacios

            }
        }
    }

    return 0; //si ya no hay espacios vacios y mostrar que se termino el juego
}

//IMPRIME LA MATRIZ DEL JUEGO
void mostrar_tablero(char tablero[FIL][COL], int fila, int col)
{
    int i, j;
    printf("\nTablero\n\n");
	printf("\n   C0 C1 C2\n");
	for(i=0; i<FIL; i++)//impresión del molde de la matriz
    {
        printf("F%d", i);
		for(j=0; j<COL; j++)
		{
			tablero[i][j]=VACIO;
			printf("[%c]", tablero[i][j]);
		}
        printf("\n");
	}
}
