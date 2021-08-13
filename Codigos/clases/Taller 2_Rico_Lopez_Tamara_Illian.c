/*Rico López Tamara Illian 1270673
Taller 2 - Covid 19*/

#include<stdio.h>

int main(void)
{
    float temp, peso;//PARA DECIMALES
    int edad;
    char nombre[50], apellidop[50], apellidom[20], genero, en_cronica, embarazo, resp, vulnerable, pecho, conf, despierto, azul, otros;//PARA CADENAS DE CARACTERES
        const char recomendaciones_no_covid[] = "\n\nBienvenid%c %s %s, según la información \
ingresada se considera que no presenta un cuadro compatible con covid19.\
\n\nSe recomienda que realice las siguientes medidas de prevención :\
\n\n\t-Use un tapaboca de tela cuando esté con otras personas. \
\n\t-Evite el contacto innecesario con las demás personas.\n ";

    const char recomendaciones_caso_grave[] = "\n\nBienvenid%c %s %s, según la información \
ingresada se considera como un posible caso grave, por lo que se recomienda asistir \
al médico de manera inmediata. Se recomienda primero llamar a un proveedor de atención \
médica.\n\nSe recomienda que realice las siguientes medidas de prevención :\
\n\n\t-Use un tapaboca de tela cuando esté con otras personas. \
\n\t-Evite el contacto innecesario con las demás personas.\n";

    const char recomendaciones_caso_vul[] = "\n\nBienvenid%c %s %s, según la información \
ingresada se considera que pertenece al grupo vulnerable, por lo que se recomienda asistir al \
médico, favor de llamar previamente a un proveedor de atención médica.\
\n\nSe recomienda que realice las siguientes medidas de prevención :\
\n\n\t-Use un tapaboca de tela cuando esté con otras personas. \
\n\t-Evite el contacto innecesario con las demás personas.\n ";

    const char recomendaciones_caso_leve[] = "\n\nBienvenid%c %s %s, según la información \
ingresada se considera que usted pordría presentar un cuadro de covid19 leve.\
\n\nSe recomienda que realice las siguientes medidas de prevención :\
\n\n\t-Use un tapaboca de tela cuando esté con otras personas. \
\n\n\t-Quédese en su casa y llame al médico para asesoramiento médico y antes de ir al consultorio.\
\n\t-Separarse de las demás personas de su hogar .\n ";

    const char saludo_terminacion1[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA MÉDICA\
*****************************************************\
** %s %s %s\
** Género: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** No sufre de enfermedades crónicas.\
**** No presenta síntoma.\
******************************************************\n\n";

    const char saludo_terminacion2[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA MÉDICA\
*****************************************************\
** %s %s %s\
** Género: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** No sufre de enfermedades crónicas.\
**** Presenta síntomas leves.\
******************************************************\n\n";

    const char saludo_terminacion3[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA MÉDICA\
*****************************************************\
** %s %s %s\
** Género: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** sufre de enfermedades crónicas.\
**** Población vulnerable\
**** Presenta síntomas.\
******************************************************\n\n";

    const char saludo_terminacion4[]="\n\nDATOS A CONSIDERAR CUANDO REALICE LA CONSULTA MÉDICA\
*****************************************************\
** %s %s %s\
** Género: %c Edad: %d\
** Peso: %fkg Temperatura: %f C\
**** No sufre de enfermedades crónicas.\
**** Presenta síntomas leves.\
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
    printf("\n\n CUESTIONARIO DE ENFERMEDADES CRÓNICAS \n\n");
    printf("¿Sufre de hipertensión o diabetes? :");
    scanf("%s", en_cronica);
    if (genero == 'F')
    {
        printf("¿Esta usted embarazada?");
        scanf("%s", embarazo);

    }
    printf("\n\n CUESTIONARIO DE SÍNTOMAS\n\n");
    printf("¿Siente dificultad para respirar? : ");
    scanf("%s", resp);
    printf("¿Presenta algún dolor o presión persistente en el pecho?: ");
    scanf("%d", pecho);
    printf("¿Ha sentido confusión repentina? : ");
    scanf("%s", conf);
    printf("¿Ha sentido incapacidad de despertarse o permanecer despierto? : ");
    scanf("%s", despierto);
    printf("¿Ha tenido los labios o cara azulados? : ");
    scanf("%s", azul);
    printf("Tiene alguno de los siguientes síntomas: Fiebre o escalofríos, Tos, Fatiga, Dolores musculares y corporales, Dolor de cabeza, Pérdida reciente del olfato o el gusto, Dolor de garganta, Congestión o moqueo, Náuseas o vómitos, Diarrea : ");
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

