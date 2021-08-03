#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int n, i, j, tamMaiorPal, tamPalavra, numCases = 0;
    char palavras[55][55];

    do
    {
        scanf("%u", &n);
        tamMaiorPal = 0;
        if (n == 0)
            break;
        for (i = 0; i < n; i++)
        {
            scanf("%s", &palavras[i][0]);
            if (strlen(palavras[i]) > tamMaiorPal)
            {
                tamMaiorPal = strlen(palavras[i]);
            }
        }

        if (numCases != 0)
        {
            printf("\n");
        }
        numCases++;

        for (i = 0; i < n; i++)
        {
            tamPalavra = tamMaiorPal - strlen(palavras[i]);
            for (j = 0; j < tamPalavra; j++)
            {
                printf(" ");
            }
            printf("%s\n", palavras[i]);
        }

    } while (n != 0);

    return 0;
}