#include<stdio.h>
#include<math.h>
int main ()
{
    //DECIMAL A OCTAL
    int decimal=5, octal=0, i=1;
    while (decimal!=0)
    {
        octal+=(decimal%8)*i;
        decimal/=8;
        i*=10;
    }
    printf("decimal : %d a octal : %d", decimal, octal);

    //OCTAL A DECIMAL

    int octal2=116, decimal2=0, j=0;
    while (octal2!=0)
    {
        decimal2+=(octal2%10)*pow(8,1);
        j++;
        octal2/=10;
    }
    printf("octal : %d a decimal : %d", octal2, decimal2);

    int rem, n=45, bin=0, k=0, x=1;
    while(n!=0)
    {
        rem=n%2;
        n/=2;
        bin+=rem*k;
        k*=10;
    }
    printf("decimal : %d a binario : %d", n, bin);

    char hexaDeciNum[100];
    int l=0;
    while(n!=0)
    {
        int temp=0;
        temp=n%16;
        if(temp<10)
        {
            hexaDeciNum[l]=temp+48;
            l++;
        }
        else
        {
            hexaDeciNum[i]=temp+55;
            l++;
        }
        n=n/16;
        printf("%d a %s", n, hexaDeciNum);
    }

    long long n=110110111;
    int dec=0, i=0, rem;
    while(n!=0)
    {
        rem=n%10;
        n/=10;
        dec+=rem*pow(2,i)
    }
    printf("%lld a %d", n, dec);

    return 0;
}
