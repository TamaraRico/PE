#include<stdio.h>
 //AÑO BISIESTO
 /* Seguir las siguientes instrucciones
    1. Si el año no es divisible entre 4,
        no es año bisiesto
    2. Si es divisible entre 4 pero no es divisible
        entre 100, el año es bisiesto
    3. */

  int main(void)
  {
      int year;
      printf("Introduzca el año (ej. 2020): ");
      scanf("%d", &year);

      //expresion redundante
      //año modulo de 4, o year multiplo de 4
      if(year%4 != 0)
      {
          printf("El año no es bisiesto");
      }
      else //year es divisible entre 4
      {
        if(year%100 != 0)
        {//year no es divisible por 100
            printf("El año si es bisiesto");
        }
        else
        {//year es divisible por 4
            //year es divisible por 100
            if(year%400 == 0)
            {
                printf("El año es bisiesto");
            }
            else
            {
                printf("El año no es bisiesto");
            }
        }
      }
  }


