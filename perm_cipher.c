#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    char trans[] = {1, 0, 2, 5, 4, 3};
    char inp[] = "Techno";

    int len = sizeof(trans);
    char ch, temp[len];

    int i, j, k;

    j = i = 0;

    do
    {
        for (; '\0' != (ch = inp[i]) && ch != '\n'; ++i)
        {
            temp[j++] = ch;

            if (j == len)
            {
                j = 0;
                ++i;
                break;
            }
        }

        while (j != 0)
        {
            temp[j++] = ' ';

            if (j == len)
                j = 0;
        }

        for (k = 0; i && k < len; ++k)
            printf("%c", temp[trans[k]]);

    } while (ch != '\0' && ch != '\n' && ch != ' ');

    printf("\n");

    return 0;
}