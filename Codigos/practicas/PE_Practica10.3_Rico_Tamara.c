/*Rico Lopez Tamara Illian 01270673
PRACTICA 10
Estructura de vectores*/

#include<stdio.h>
#include<math.h>

//definicion de la estructura
struct  vectores{
    float i;
    float j;
    float k;
};

//prototipos de funciones
struct vectores captura();
void mostar_vectores(struct vectores);//tipo de dato: struct complejo
void modulo_vector(struct vectores);
void suma_vectores(struct vectores, struct vectores);
void resta_vectores(struct vectores, struct vectores);
void producto_vectorial(struct vectores, struct vectores);
void producto_escalar(struct vectores, struct vectores);

int main()
{
    struct vectores v1, v2;
    v1=captura();
    mostar_vectores(v1);
    modulo_vector(v1);
    printf("\n\nCaptute un segundo numero complejo\n");
    v2=captura();
    mostar_vectores(v2);
    modulo_vector(v2);

    suma_vectores(v1, v2);
    resta_vectores(v1, v2);
    producto_escalar(v1, v2);
    producto_vectorial(v1, v2);

    return 0;
}

struct vectores captura()
{
    struct vectores v;
    printf("Ingrese un vector en R3 (ej 1i+9j+5k): ");
    scanf("%fi+%fj+%fk", &v.i, &v.j, &v.k);
    return v;
}

void mostar_vectores(struct vectores v)
{
    printf("Vector en R3: %.1fi + %.1fj + %.1fk", v.i, v.j, v.k);
}

void modulo_vector(struct vectores v)
{
    float modulo;
    modulo=sqrt(v.i*v.i+v.j*v.j+v.k*v.k);
    printf("\nEl modulo del vector es: %.2f", modulo);
}

void suma_vectores(struct vectores v1, struct vectores v2)
{
    printf("\n\nLa suma de los vectores es: %.1fi + %.1fj + %.1fk", v1.i+v2.i, v1.j+v2.j, v1.k+v2.k);
}

void resta_vectores(struct vectores v1, struct vectores v2)
{
    printf("\nLa resta de los vectores es: %.1fi + %.1fj + %.1fk", v1.i-v2.i, v1.j-v2.j, v1.k-v2.k);
}

void producto_escalar(struct vectores v1, struct vectores v2)
{
    float producto;
    producto=v1.i*v2.i+v1.j*v2.j+v1.k*v2.k;
    printf("\nEl producto escalar entre los vectores es: %.2f", producto);
}

void producto_vectorial(struct vectores v1, struct vectores v2)
{
    float i, j, k;
    i=(v1.j*v2.k)-(v2.j*v1.k);
    j=(v1.k*v2.i)-(v2.k*v1.i);
    k=(v1.i*v2.j)-(v2.i*v1.j);
    printf("\nEl producto vectorial de los vectores es: %.1fi + %.1fj + %.1fk \n", i, j, k);
}
