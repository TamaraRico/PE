#include<stdio.h>

int main(int argc, char * argv[])
 {
  char clave[] = "mephistopheles";
  int i, suma = 0;
  if (argc != 2)
   {
    printf("\n\nUtilización: ./a.out clave\n\n");
    exit(1);
   }
  else
   {
    if (strcmp(clave, argv[1]) != 0)
     {
      printf("\n\nLa clave no es correcta.\n\n");
     }
    else
     {
      for(i=0;i<strlen(clave);i++)
       suma += clave[i];
    printf("\n\nLa clave es correcta - %d\n\n", suma);
     }
   }
  printf("\n\nTerminación normal.\n\n");
  return 0;
 }
