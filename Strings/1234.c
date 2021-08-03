#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TRUE 0
#define FALSE 1

int main()
{
    char Str[52], flag, i;
    while (fgets(Str, 51, stdin) != NULL)
    {
        flag = TRUE;
        for (i = 0; Str[i] != '\0'; i++)
        {
            if (isalpha(Str[i]))
            {
                if (flag == TRUE)
                {
                    Str[i] = toupper(Str[i]);
                    flag = FALSE;
                }
                else if (flag == FALSE)
                {
                    Str[i] = tolower(Str[i]);
                    flag = TRUE;
                }
            }
        }
        printf("%s", Str);
    }
    return 0;
}