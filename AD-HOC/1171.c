#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int Casos, Indic, Cont, Num[2003];
    for (Cont = 0; Cont < 2003; Cont++)
        Num[Cont] = 0;
    scanf("%d", &Casos);
    for (Cont = 0; Cont < Casos; Cont++)
    {
        scanf("%d", &Indic);
        Num[Indic] = Num[Indic] + 1;
    }
    Cont = 0;
    while (Cont < 2003)
    {
        if (Num[Cont] > 0)
        {
            printf("%d aparece %d vez(es)\n", Cont, Num[Cont]);
        }
        Cont++;
    }
    return 0;
}
