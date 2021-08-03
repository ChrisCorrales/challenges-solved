#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char Num[7];
    int TotCasos, i, TamStr, Cont1, Cont2;
    scanf("%d", &TotCasos);
    for (i = 0; i < TotCasos; i++)
    {
        scanf("%s", Num);
        TamStr = strlen(Num);
        Cont1 = 0;
        Cont2 = 0;
        if (TamStr == 5)
            puts("3");
        if (TamStr == 3)
        {
            if (Num[0] == 't')
                Cont2 = Cont2 + 1;
            else if (Num[0] == 'o')
                Cont1 = Cont1 + 1;
            if (Num[1] == 'w')
                Cont2 = Cont2 + 1;
            else if (Num[1] == 'n')
                Cont1 = Cont1 + 1;
            if (Num[2] == 'o')
                Cont2 = Cont2 + 1;
            else if (Num[2] == 'e')
                Cont1 = Cont1 + 1;
            if (Cont1 == 2 || Cont1 == 3)
                puts("1");
            else if (Cont2 == 2 || Cont2 == 3)
                puts("2");
        }
    }

    return 0;
}
