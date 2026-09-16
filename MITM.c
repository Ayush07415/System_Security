#include <stdio.h>

int powermod(int base, int exp, int mod)
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
    int a, q, xa, xb, ya, yb, ka, kb;

    int m1, m2, ym1, ym2, km1, km2;

    printf("Enter a prime number value of a: ");
    scanf("%d", &a);

    printf("Enter value of q: ");
    scanf("%d", &q);

    printf("Enter private key of A: ");
    scanf("%d", &xa);

    printf("Enter private key of B: ");
    scanf("%d", &xb);

    ya = powermod(a, xa, q);
    yb = powermod(a, xb, q);

    ka = powermod(yb, xa, q);
    kb = powermod(ya, xb, q);

    printf("\nA's public key = %d", ya);
    printf("\nB's public key = %d", yb);

    if (ka == kb)
        printf("\nKey exchange successful");
    else
        printf("\nKey exchange failed");


    printf("\n\n--- MITM ATTACK ---");

    printf("\nEnter attacker's private key m1: ");
    scanf("%d", &m1);

    printf("Enter attacker's private key m2: ");
    scanf("%d", &m2);

    ym1 = powermod(a, m1, q);
    ym2 = powermod(a, m2, q);

    ka = powermod(ym2, xa, q);
    kb = powermod(ym1, xb, q);

    km1 = powermod(ya, m2, q);
    km2 = powermod(yb, m1, q);

    printf("\nA's key = %d", ka);
    printf("\nB's key = %d", kb);
    printf("\nAttacker's key with A = %d", km1);
    printf("\nAttacker's key with B = %d", km2);

    if (ka == km1 && kb == km2 && ka != kb)
        printf("\n\nMITM Attack Successful");
    else
        printf("\n\nMITM Attack Failed");

    return 0;
}