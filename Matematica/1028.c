#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int MDC(int N, int D)
{
    if (D == 0)
        return N;
    else
        return MDC(D, N % D);
}

int main()
{
    int N, Cont, Fig1, Fig2, Mdc;
    scanf("%d", &N);
    for (Cont = 0; Cont < N; Cont++)
    {
        scanf("%d%d", &Fig1, &Fig2);
        Mdc = MDC(Fig1, Fig2);
        printf("%d\n", Mdc);
    }
    return 0;
}
