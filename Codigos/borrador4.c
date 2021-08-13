#include<stdio.h>

int main()
{
    int i, j, k, l, a, b;

    for(i=1; i<=9; i++)
    {
        a=0;
        b=0;
        if(i%2==0)
        {
            a=a+i;
            //printf("\ni=%d  y  a=%d", i, a);
        }
        else
        {
            b=b+i;
            //printf("\ni=%d  y  b=%d", i, b);
        }
        for (j=0; j<=9; j++)
        {
            if(j%2==0)
            {
                a=a+j;
                //printf("\nj=%d  y  a=%d", j, a);
            }
            else
            {
                b=b+j;
                //printf("\nj=%d  y  b=%d", j, b);
            }
            for(k=0; k<=9; k++)
            {
                if(k%2==0)
                {
                    a=a+k;
                    //printf("\nk=%d  y  a=%d", k, a);
                }
                else
                {
                    b=b+k;
                    //printf("\nk=%d  y  b=%d", k, b);
                }
                for(l=0; l<=9; l++)
                {
                    if(l%2==0)
                    {
                        a=a+l;
                        //printf("\nl=%d  y  a=%d", l, a);
                    }
                    else
                    {
                        b=b+l;
                        //printf("\nl=%d  y  b=%d", l, b);
                    }
                    if(a==b)
                    {
                        printf("\n%d%d%d%d", i, j, k, l);
                    }
                }
            }
        }
    }

    return 0;
}
