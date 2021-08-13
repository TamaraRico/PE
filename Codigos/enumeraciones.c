#include<stdio.h>

enum casa{
    hogar,
    home,
    perro
};

struct cosas{
    int num;
    enum casa jojo;
};

int main()
{
    //enum casa h
    struct cosas h;
    int x=2;
    printf("Esto es : %d", x);
    return 0;
}
