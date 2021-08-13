/*Rico Lopez Tamara Illian 1270673
PRACTICA 7*/
//JUEGO DEL GATO

#include<stdio.h>
#include<stdlib.h>//para que el primer turno sea aleatorio, es decir, si empieza x ó o

#define FIL 3 //FILAS
#define COL 3 //COLUMNAS

#define CRUZ 'X'
#define CERO 'O'
#define VACIO 0

int main(void)
{
	char tablero[FIL][COL], opc='S';
	int i, j;

    printf("\nJUEGO DEL GATO\n\n");
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

    printf("\n%c=Primer jugador %c= Segundo jugador", CRUZ, CERO);
	int x, y, ganador=0, turno=1;
	int vacios=0; //Ocupo una variable que me indique que la tabla esta llena.

	if(opc == 'S' || opc == 's')
    {
		do
		{
			if(turno%2==1)
			{
				do
				{
					printf("\nJugador 1. \n");
					printf("Ingrese las coordenadas de su ficha (x,y): ");
					scanf("%d,%d", &x, &y);
                    //Verificar que las coordenadas sean correctas.
					if(tablero[x][y] == CRUZ || tablero[x][y] == CERO || x > 2 || y > 2)
                    {
						printf("\nIngrese coordenadas validas.\n");
					}
                //Hasta que se ingresen valores correctos, se seguira repitiendo.
				}while(tablero[x][y] == CRUZ || tablero[x][y] == CERO || x > 2 || y > 2);

				tablero[x][y]=CRUZ;

				//Limpiar la pantalla y que se quiten los codigos que vayan quedando por cada turno.
				system("cls");

				//Imprime la matriz con los cambios de la matriz.
				printf("\n   C0 C1 C2\n");
				for(i=0; i<FIL; i++)
                {
                    printf("F%d", i);
					for(j=0; j<COL; j++)
					{
						printf("[%c]", tablero[i][j]);
					}
					printf("\n");
				}
				//Aumenta el turno para que cambie despues de jugador.
				turno++;

            //Turno del jugador 2.
			} else if(turno%2==0)
			{
				do
                {
					printf("\nJugador 2: \n");
					printf("Ingrese las coordenadas de su ficha (x,y): ");
					scanf("%d,%d", &x, &y);

					if(tablero[x][y] == CRUZ || tablero[x][y] == CERO || x > 2 || y > 2)
                    {
						printf("\nCoordenadas invalidas, pruebe otra vez.\n");
					}
				} while(tablero[x][y] == CRUZ || tablero[x][y] == CERO || x > 2 || y > 2);

				tablero[x][y]=CERO;
				system("cls");
				printf("\n   C0 C1 C2\n");

				for(i=0; i<FIL; i++)
                {
                    printf("F%d", i);
					for(j=0; j<COL; j++)
					{
						printf("[%c]", tablero[i][j]);
					}
					printf("\n");
				}
				//Aumenta el turno para que cambie despues de jugador.
				turno++;
			}

            //Las condiciones de victoria.

			if(tablero[0][0] == CRUZ && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]
			|| tablero[1][0] == CRUZ && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]
			|| tablero[2][0] == CRUZ && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]

			|| tablero[0][0] == CRUZ && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]
			|| tablero[0][1] == CRUZ && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]
			|| tablero[0][2] == CRUZ && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]

			|| tablero[0][0] == CRUZ && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]
			|| tablero[0][2] == CRUZ && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
			{
				ganador=1;
				printf("\nGANA EL JUGADOR 1!\n");
			}

			if(tablero[0][0] == CERO && tablero[0][0] == tablero[0][1] && tablero[0][0] == tablero[0][2]
			|| tablero[1][0] == CERO && tablero[1][0] == tablero[1][1] && tablero[1][0] == tablero[1][2]
			|| tablero[2][0] == CERO && tablero[2][0] == tablero[2][1] && tablero[2][0] == tablero[2][2]

			|| tablero[0][0] == CERO && tablero[0][0] == tablero[1][0] && tablero[0][0] == tablero[2][0]
			|| tablero[0][1] == CERO && tablero[0][1] == tablero[1][1] && tablero[0][1] == tablero[2][1]
			|| tablero[0][2] == CERO && tablero[0][2] == tablero[1][2] && tablero[0][2] == tablero[2][2]

			|| tablero[0][0] == CERO && tablero[0][0] == tablero[1][1] && tablero[0][0] == tablero[2][2]
			|| tablero[0][2] == CERO && tablero[0][2] == tablero[1][1] && tablero[0][2] == tablero[2][0])
			{
				ganador=1;
				printf("\nGANA EL JUGADOR 2!!.\n");
			}

			detector ++;
			if (detector==9)
            {
                ganador=1;
                printf("\nEMPATE!!!\n");
            }


		} while(ganador != 1);
	}
	printf("\n\n\tFIN DEL JUEGO");

	return 0;
}

