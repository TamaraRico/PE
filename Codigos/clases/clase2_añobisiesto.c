#include<stdio.h>
 //A�O BISIESTO
 /* Seguir las siguientes instrucciones
    1. Si el a�o no es divisible entre 4,
        no es a�o bisiesto
    2. Si es divisible entre 4 pero no es divisible
        entre 100, el a�o es bisiesto
    3. */

  int main(void)
  {
      int year;
      printf("Introduzca el a�o (ej. 2020): ");
      scanf("%d", &year);

      //expresion redundante
      //a�o modulo de 4, o year multiplo de 4
      if(year%4 != 0)
      {
          printf("El a�o no es bisiesto");
      }
      else //year es divisible entre 4
      {
        if(year%100 != 0)
        {//year no es divisible por 100
            printf("El a�o si es bisiesto");
        }
        else
        {//year es divisible por 4
            //year es divisible por 100
            if(year%400 == 0)
            {
                printf("El a�o es bisiesto");
            }
            else
            {
                printf("El a�o no es bisiesto");
            }
        }
      }
  }


