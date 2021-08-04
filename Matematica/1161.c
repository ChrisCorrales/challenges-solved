#include <stdio.h>
#include <math.h>
#include <stdlib.h>
unsigned long long int Fatorial(unsigned long long int num)
{
    int cont;
    unsigned long long int total = num;
    if (num == 0 || num == 1)
        return 1;
    for (cont = num - 1; cont != 1; cont--)
        total = total * cont;
    return total;
}
int main()
{
    unsigned short int Num1, Num2;
    unsigned long long int Result, TotFat1, TotFat2;
    while (scanf("%hu%hu", &Num1, &Num2) != EOF)
    {
        TotFat1 = Fatorial(Num1);
        TotFat2 = Fatorial(Num2);
        Result = TotFat1 + TotFat2;
        printf("%llu\n", Result);
    }
    return 0;
}