#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VET 10

int main()
{
    char DATA[MAX_VET];
    while (scanf("%s", DATA) != EOF)
    {
        printf("%c%c/%c%c/%c%c\n", DATA[3], DATA[4], DATA[0], DATA[1], DATA[6], DATA[7]);
        printf("%c%c/%c%c/%c%c\n", DATA[6], DATA[7], DATA[3], DATA[4], DATA[0], DATA[1]);
        printf("%c%c-%c%c-%c%c\n", DATA[0], DATA[1], DATA[3], DATA[4], DATA[6], DATA[7]);
    }
    return 0;
}
