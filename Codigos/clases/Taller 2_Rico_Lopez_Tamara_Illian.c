/*Rico L�pez Tamara Illian 1270673
Taller 2 - Covid 19*/

#include<stdio.h>

int main(void)
{
    float temp, peso;//PARA DECIMALES
    int edad;
    char nombre[50], apellidop[50], apellidom[20], genero, en_cronica, embarazo, resp, vulnerable, pecho, conf, despierto, azul, otros;//PARA CADENAS DE CARACTERES
        const char recomendaciones_no_covid[] = "\n\nBienvenid%c %s %s, seg�n la informaci�n \
ingresada se considera que no presenta un cuadro compatible con covid19.\
\n\nSe recomienda que realice las siguientes medidas de prevenci�n :\
\n\n\t-Use un tapaboca de tela cuando est� con otras personas. \
\n\t-Evite el contacto innecesario con las dem�s personas.\n ";

    const char recomendaciones_caso_grave[] = "\n\nBienvenid%c %s %s, seg�n la informaci�n \
ingresada se considera como un posible caso grave, por lo que se recomienda asistir \
al m�dico de manera inmediata. Se recomienda primero llamar a un proveedor de atenci�n \
m�dica.\n\nSe recomienda que realice las siguientes medidas de prevenci�n :\
\n\n\t-Use un tapaboca de tela cuando est� con otras personas. \
\n\t-Evite el contacto innecesario con las dem�s personas.\n";

    const char recomendaciones_caso_vul[] = "\n\nBienvenid%c %s %s, seg�n la informaci�n \
ingresada se considera que pertenece al grupo vulnerable, por lo que se recomienda asistir al \
m�dico, favor de llamar previamente a un proveedor de atenci�n m�dica.\
\n\nSe recomienda que realice las siguientes medidas de prevenci�n :\
\n\n\t-Use un tapaboca de tela cuando est� con otras personas. \
\n\t-Evite el contacto innecesario con las dem�s personas.\n ";

    const char recomendaciones_caso_leve[] = "\n\nBienvenid%c %s %s, seg�n la informaci�n \
ingresada se considera que usted pordr�a presentar un cuadro de covid19 leve.\
\n\nSe recomienda que realice las siguientes medidas de prevenci�n :\
\n\n\t-Use un tapaboca de tela cuando est� con otras personas. \
\n\n\t-Qu�dese en su casa y llame al m�dico para asesoramiento m�dico y antes de ir al consultorio.\
\n\t-Separarse de las dem�s personas de su hogar .\n ";

    const char saludo_terminacion1[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA M�DICA\
*****************************************************\
** %s %s %s\
** G�nero: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** No sufre de enfermedades cr�nicas.\
**** No presenta s�ntoma.\
******************************************************\n\n";

    const char saludo_terminacion2[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA M�DICA\
*****************************************************\
** %s %s %s\
** G�nero: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** No sufre de enfermedades cr�nicas.\
**** Presenta s�ntomas leves.\
******************************************************\n\n";

    const char saludo_terminacion3[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA M�DICA\
*****************************************************\
** %s %s %s\
** G�nero: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** sufre de enfermedades cr�nicas.\
**** Poblaci�n vulnerable\
**** Presenta s�ntomas.\
******************************************************\n\n";

    const char saludo_terminacion4[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA M�DICA\
*****************************************************\
** %s %s %s\
** G�nero: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** No sufre de enfermedades cr�nicas.\
**** Presenta s�ntomas leves.\
******************************************************\n\n";

    printf("Hospital Angeles, Tijuana, BC \n\n");
    printf("Introduzca su nombre : ");
    scanf("%s", nombre);
    printf("Introduzca su apellido paterno : ");
    scanf("%s", apellidop);
    printf("Introduzca su apellido materno : ");
    scanf("%s", apellidom);
    printf("Introduzca su edad : ");
    scanf("%d", &edad);
    printf("Introduzca su peso (en kg) : ");
    scanf("%f", &peso);
    printf("Introduzca su temperatura : ");
    scanf("%.2f", &temp);
    printf("Introduzca su genero F o M: ");
    scanf("%c", genero);
    printf("\n\n CUESTIONARIO DE ENFERMEDADES CR�NICAS \n\n");
    printf("�Sufre de hipertensi�n o diabetes? :");
    scanf("%s", en_cronica);
    if (genero == 'F')
    {
        printf("�Esta usted embarazada?");
        scanf("%s", embarazo);

    }
    printf("\n\n CUESTIONARIO DE S�NTOMAS\n\n");
    printf("�Siente dificultad para respirar? : ");
    scanf("%s", resp);
    printf("�Presenta alg�n dolor o presi�n persistente en el pecho?: ");
    scanf("%d", pecho);
    printf("�Ha sentido confusi�n repentina? : ");
    scanf("%s", conf);
    printf("�Ha sentido incapacidad de despertarse o permanecer despierto? : ");
    scanf("%s", despierto);
    printf("�Ha tenido los labios o cara azulados? : ");
    scanf("%s", azul);
    printf("Tiene alguno de los siguientes s�ntomas: Fiebre o escalofr�os, Tos, Fatiga, Dolores musculares y corporales, Dolor de cabeza, P�rdida reciente del olfato o el gusto, Dolor de garganta, Congesti�n o moqueo, N�useas o v�mitos, Diarrea : ");
    scanf("%s", otros);


    if (edad>60||embarazo=="si"||en_cronica=="si"||peso>100)
    {
        vulnerable = "si";
    }
    if (resp=="si"&&pecho=="si"&&(conf=="si"||despierto=="si"||azul=="si"))
    {
        printf("\n\n***CASO DE COVID GRAVE***\n\n");
        printf(recomendaciones_caso_grave, nombre, apellidop, apellidom);
        printf(saludo_terminacion2, nombre, apellidop, apellidom, genero, edad, peso, temp);
    }
    if ((vulnerable=="si"||otros=="si")&&temp>=37.5)
    {
        printf("\n\n***CASO DE COVID CON COMPLICACIONES***\n\n");
        printf(recomendaciones_caso_vul, nombre, apellidop, apellidom);
        printf(saludo_terminacion3, nombre, apellidop, apellidom, genero, edad, peso, temp);
    }
    if (temp>=37.5&&otros=="si")
    {
        printf("\n\n***CASO DE COVID LEVE***\n\n");
        printf(recomendaciones_caso_leve, nombre, apellidop, apellidom);
        printf(saludo_terminacion4, nombre, apellidop, apellidom, genero, edad, peso, temp);
    }
    if (temp<37.5&&en_cronica!="si"&&otros=="no")
    {
        printf("\n\n***CASO NO COVID***\n\n");
        printf(recomendaciones_no_covid, nombre, apellidop, apellidom);
        printf(saludo_terminacion1, nombre, apellidop, apellidom, genero, edad, peso, temp);
    }

    printf("\n\nPresione ENTER para salir...\n\n");

    return 0;
}

