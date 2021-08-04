#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int ehprimo(int n)
{
    int i;
    if (n == 2)
        return TRUE;
    if (n <= 1 || n % 2 == 0)
        return FALSE;

    for (i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return FALSE;
    }
    return TRUE;
}

int main()
{
    int TotCasos, Caso, Num, bolean;
    scanf("%d", &TotCasos);
    for (Caso = 0; Caso < TotCasos; Caso++)
    {
        scanf("%d", &Num);
        bolean = ehprimo(Num);
        if (bolean == TRUE)
            printf("Prime\n");
        else
            printf("Not Prime\n");
    }
}