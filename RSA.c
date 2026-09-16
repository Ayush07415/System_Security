#include <stdio.h>
#include <stdlib.h>

int powerMod(int base, int exp, int mod)
{
    int result = 1;

    while (exp > 0)
    {
        result = (result * base) % mod;
        exp--;
    }

    return result;
}

int main()
{
    int p, q;
    int d;

    printf("\nEnter the value of p: ");
    scanf("%d", &p);

    printf("\nEnter the value of q: ");
    scanf("%d", &q);

    int n = p * q;

    int funcn = (p - 1) * (q - 1);

    int publickey;

    printf("\nEnter the value of public key: ");
    scanf("%d", &publickey);

    for (int i = 0; i < 100; i++)
    {
        if (((funcn * i) + 1) % publickey == 0)
        {
            d = ((funcn * i) + 1) / publickey;
            break;
        }
    }

    printf("\nPrivate key (%d,%d)", d, n);
    printf("\nPublic key (%d,%d)", publickey, n);

    int pt;

    printf("\nEnter plain text: ");
    scanf("%d", &pt);

    int ct = powerMod(pt, publickey, n);

    printf("\nCipher text: %d", ct);

    return 0;
}