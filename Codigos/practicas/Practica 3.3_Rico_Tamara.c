/*Rico Lopez Tamara Illian 1270673
Triangulos*/

#include<stdio.h>
#include<math.h>


int main(void)
{
    float s1, s2, s3, p, s, a;
    int r;

    printf("Introduzca el primer lado del triangulo : ");
    scanf("%f", &s1);
    printf("Introduzca el segundo lado del triangulo : ");
    scanf("%f", &s2);
    printf("Introduzca el tercer lado del triangulo : ");
    scanf("%f", &s3);

    if (s1<s2&&s1<s3)
    {
        printf("\nEl primer lado debe ser mayor al resto\n");
        printf("Introduzca el primer lado del triangulo : \n");
        scanf("%f", &s1);
    }

    if (s1>=!(s2+s3))
    {
        if ((s1*s1)==(s2*s2 + s3*s3))
        {
            printf("\nSe forma un triangulo rectangulo\n");
            printf("los lados son : %f, %f, %f\n", s1, s2, s3);
        }
        if (s1*s1>(s2*s2 + s3*s3))
        {
            printf("\nSe forma un triangulo obtuso\n");
            printf("los lados son : %f, %f, %f\n", s1, s2, s3);
        }

        if (s1*s1<(s2*s2 + s3*s3))
        {
            printf("\nSe forma un triangulo agudo\n");
            printf("los lados son : %f, %f, %f\n", s1, s2, s3);
        }

        if (s1==s2&&s2==s3)
        {
            printf("\nSe forma un triangulo equilatero\n");
            printf("los lados son : %f, %f, %f\n", s1, s2, s3);
        }
    }
    else
    {
        printf("\nNo se forma ningun triangulo\n");
        printf("los lados son : %f, %f, %f\n", s1, s2, s3);
    }

    p=s1+s2+s3;
    printf("%f\n", p);

    s=p/2;
    printf("%f\n", s);

    r=s*(s-s1)*(s-s2)*(s-s3);
    printf("%d\n", r);

    if (r<0)
    {
        a=sqrt(-r);
        printf("%f", a);
        printf("\nEl área del triangulo es %fi y el perímetro es %f\n", a, p);
    }
    else
    {
        a=sqrt(r);
        printf("%f", a);
        printf("\nEl área del triangulo es %.3f y el perímetro es %f\n", a, p);
    }

    return 0;
}
