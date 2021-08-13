#include<stdio.h>

enum cosas{libro, libreta, lapiz, pluma};

struct materiales{
    int cantidad;
    float precio;
    enum cosas cool;
};

int main(void)
{
    enum cosas x;
    struct materiales mywork;

    printf("Capture una cantidad");
    scanf("%d", &mywork.cantidad);
    printf("Capture el precio :");
    scanf("%f", &mywork.precio);
    printf("Capture el tipo : ");
    scanf("%d", &x);
    printf("cantidad %d", mywork.cantidad);
    printf("precio %f", mywork.precio);
    printf("tipo %s", cosas.x);

    return 0;
}
