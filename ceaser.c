#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char str[50];

    printf("Enter your string: ");
    scanf("%s", &str);

    int key, i;

    printf("\nEnter your key: ");
    scanf("%d", &key);

    for (int i = 0; str[i] != '\0'; ++i)
    {
        char ch = str[i];

        if (isalnum(ch))
        {
            if (islower(ch))
            {
                ch = (ch - 'a' + key) % 26 + 'a';
            }

            if (isupper(ch))
            {
                ch = (ch - 'A' + key) % 26 + 'A';
            }

            if (isdigit(ch))
            {
                ch = (ch - '0' + key) % 10 + '0';
            }

            str[i] = ch;
        }
        else
        {
            printf("\nInvalid message");
        }
    }

    printf("%s", str);

    return 0;
}