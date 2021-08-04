#include <stdio.h>

int main()
{
    int HorI, MinI, HorF, MinF, TotM, TotH, Total;
    scanf("%i%i%i%i", &HorI, &MinI, &HorF, &MinF);
    while (HorI != 0 || HorF != 0 || MinI != 0 || MinF != 0)
    {
        if (HorI < HorF)
        {
            if (MinI > MinF)
            {
                TotH = ((HorF - HorI) - 1) * 60;
                TotM = (60 - MinI) + MinF;
            }
            if (MinI <= MinF)
            {
                TotH = (HorF - HorI) * 60;
                TotM = (MinF - MinI);
            }
        }
        else if (HorI == HorF)
        {
            if (MinI > MinF)
            {
                TotH = (((24 - HorI) + HorF) - 1) * 60;
                TotM = (60 - MinI) + MinF;
            }
            if (MinI < MinF)
            {
                TotH = 0;
                TotM = MinF - MinI;
            }
            if (MinI == MinF)
            {
                TotH = 0;
                TotM = 0;
            }
        }
        else if (HorI > HorF)
        {
            TotH = (((24 - HorI) - 1) + HorF) * 60;
            TotM = (60 - MinI) + MinF;
        }

        Total = TotM + TotH;
        printf("%i\n", Total);
        scanf("%i%i%i%i", &HorI, &MinI, &HorF, &MinF);
    }

    return 0;
}