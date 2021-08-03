#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VET 16

int main()
{
    char CPF[MAX_VET];
    while (scanf("%s", CPF) != EOF)
    {
        printf("%c%c%c\n", CPF[0], CPF[1], CPF[2]);
        printf("%c%c%c\n", CPF[4], CPF[5], CPF[6]);
        printf("%c%c%c\n", CPF[8], CPF[9], CPF[10]);
        printf("%c%c\n", CPF[12], CPF[13]);
    }
    return 0;
}