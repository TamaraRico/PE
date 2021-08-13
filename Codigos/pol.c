#include<stdio.h>

int main()
{
    int i, j, k, a, b, l;

    if(i%2==0)
    {
        a=a+i
    }
    else
    {
        b=b+i
        if(j%2==0)
        {
            a=a+j
        }
        else
        {
            b=b+j
            if(k%2==0)
            {
                a=a+k
            }
            else
            {
                b=b+k
                if(l%2==0)
                {
                    a=a+l
                }
                else
                {
                    b=b+l
                    if(a==b)
                    {
                        printf("%d%d%d%d", i, j, k, l)
                    }
                }
            }
        }
    }

    return 0;
}
