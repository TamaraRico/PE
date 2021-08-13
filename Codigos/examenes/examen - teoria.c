#include<stdio.h>

int main()
{
    int v=1, y=3;
    void *ptr=&v;
    void *ptr2=&y;
    printf("Resultado : %d", (ptr2-ptr));
    printf("Resultado ptr : %d", ptr);
    printf("Resultado ptr2 : %d", ptr2);
    return 0;
}
