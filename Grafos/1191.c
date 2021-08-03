#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void PosFixa(char *, char *, int, int);
int SeachPosit(char, char *);

int g;
int main()
{
    char Infixa[27], PreFixa[27];
    while (scanf("%s%s", PreFixa, Infixa) != EOF)
    {
        g = -1;
        PosFixa(PreFixa, Infixa, 0, strlen(PreFixa) - 1);
        puts("");
    }

    return 0;
}

void PosFixa(char *pre, char *inf, int i, int j)
{
    int pos;
    if (i <= j)
    {
        g++;
        pos = SeachPosit(pre[g], inf);
        PosFixa(pre, inf, i, pos - 1);
        PosFixa(pre, inf, pos + 1, j);
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
