#include <stdio.h>

int main()
{
    int n;
    char inp[100];
    int trans[20];
    char temp[20];

    printf("Enter block size: ");
    scanf("%d", &n);

    printf("Enter transposition order: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &trans[i]);
    }

    getchar();  

    printf("Enter plaintext: ");
    fgets(inp, sizeof(inp), stdin);

    int len = 0;

    while (inp[len] != '\0' && inp[len] != '\n')
        len++;

    printf("\nCiphertext: ");

    for (int i = 0; i < len; i += n)
    {
        int j;

        
        for (j = 0; j < n; j++)
        {
            if (i + j < len)
                temp[j] = inp[i + j];
            else
                temp[j] = ' ';
        }

        for (j = 0; j < n; j++)
        {
            printf("%c", temp[trans[j]]);
        }
    }

    printf("\n");

    return 0;
}