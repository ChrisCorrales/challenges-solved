#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void PosFixa(char *, char *, int, int);
int SeachPosit(char, char *);

int g;
int main()
{
    char Infixa[54], PreFixa[54];
    int Caso, TotCasos, Tam;
    scanf("%d", &TotCasos);
    for (Caso = 0; Caso < TotCasos; Caso++)
    {
        scanf("%d%s%s", &Tam, PreFixa, Infixa);
        g = -1;
        PosFixa(PreFixa, Infixa, 0, Tam - 1);
        puts("");
    }

    return 0;
}

void PosFixa(char *pre, char *inf, int i, int tam)
{
    int pos;
    if (i <= tam)
    {
        g++;
        pos = SeachPosit(pre[g], inf);
        PosFixa(pre, inf, i, pos - 1);
        PosFixa(pre, inf, pos + 1, tam);
        printf("%c", inf[pos]);
    }
}

int SeachPosit(char letra, char *in)
{
    int cont;
    for (cont = 0; in[cont] != letra; cont++)
        ;
    return cont;
}
