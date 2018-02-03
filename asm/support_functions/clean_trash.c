#include "../asm.h"

char *remove_comments(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == COMMENT_CHAR)
        {
            str[i] = '\0';
            break;
        }
        i++;
    }
    return (str);
}

