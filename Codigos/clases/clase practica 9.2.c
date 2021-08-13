#include<stdio.h>

int maxx(int, int);
int minn(int, int);

int main(void)
{
    int (*ptr)(int, int)

    ptr=minn;
    printf("%d", ptr(5,8));

    return 0;
}


