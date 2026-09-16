#include <stdio.h>

int powermod(int base,int exp,int mod)
{
    int result=1;

    while(exp>0)
        {
            result=(result*base)%mod;
            exp--;
        }
    return result;
}

int main() {
    int a,q,xa,xb,ya,yb,ka,kb;

    printf("Enter a prime number value of a: ");
    scanf("%d",&a);

    printf("Enter value of q: ");
    scanf("%d",&q);

    printf("Enter private key of A: ");
    scanf("%d",&xa);

     printf("Enter private key of B: ");
    scanf("%d",&xb);

    ya=powermod(a,xa,q);
    yb=powermod(a,xb,q);

    ka=powermod(yb,xa,q);
    kb=powermod(ya,xb,q);

    if(ka==kb)
        printf("Successful");
    else
        printf("Failed");

    return 0;
}