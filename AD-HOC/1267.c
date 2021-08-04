#include <stdlib.h>
#define MAX_VET 101
#define TRUE 1
#define FALSE 0

int main()
{
    unsigned short int Alunos[MAX_VET], NumJantar, NumAluno, TotJantares, TotAlunos, X, Bolean;
    scanf("%hu%hu", &TotAlunos, &TotJantares);
    while (TotAlunos != 0 || TotJantares != 0)
    {
        for (NumAluno = 0; NumAluno < TotAlunos; NumAluno++)
            Alunos[NumAluno] = 0;

        for (NumJantar = 0; NumJantar < TotJantares; NumJantar++)
            for (NumAluno = 0; NumAluno < TotAlunos; NumAluno++)
            {
                scanf("%hu", &X);
                if (X == 1)
                    Alunos[NumAluno]++;
            }
        Bolean = FALSE;
        for (NumAluno = 0; NumAluno < TotAlunos; NumAluno++)
        {
            if (Alunos[NumAluno] == TotJantares)
            {
                Bolean = TRUE;
                break;
            }
        }
        if (Bolean == TRUE)
            printf("yes\n");
        else
            printf("no\n");
        scanf("%hu%hu", &TotAlunos, &TotJantares);
    }
    return 0;
}
