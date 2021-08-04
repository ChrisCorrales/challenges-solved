#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_VET 1001
int main()
{
    unsigned int Bilhetes[MAX_VET], BilhetOrig, NumPessoas, CodBilhet, Cont, QtdBilFalsos;
    scanf("%u%u", &BilhetOrig, &NumPessoas);
    while (BilhetOrig != 0 || NumPessoas != 0)
    {
        QtdBilFalsos = 0;
        memset(Bilhetes, 0, sizeof(Bilhetes));
        for (Cont = 0; Cont < NumPessoas; Cont++)
        {
            scanf("%u", &CodBilhet);
            Bilhetes[CodBilhet] = Bilhetes[CodBilhet] + 1;
            if (Bilhetes[CodBilhet] == 2)
                QtdBilFalsos++;
        }
        printf("%u\n", QtdBilFalsos);
        scanf("%u%u", &BilhetOrig, &NumPessoas);
    }
    return 0;
}
