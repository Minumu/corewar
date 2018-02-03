#include "../asm.h"

int	ft_strposlen(const char *s, int c)
{
    size_t	i;
    int k;

    i = 0;
    k = 0;
    if (!s || s[0] == '\0')
        return (0);
    while (s[i])
    {
        if (s[i] == (char)c)
            k++;
        i++;
    }
    return (k);
}

int		ft_strcchr(const char *str, char c)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int find_symbol(char *word, char find)
{
    if (ft_strposlen(word, find) > 0)
        return (1);
    return (0);
}

size_t skip_spaces(char *s, size_t i)
{
    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\v'
           || s[i] == '\f' || s[i] == '\r')
        i++;
    return (i);
}

int     check_empty_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\"' && str[i + 1] =='\"')
            return (1);
        i++;
    }
    return (0);
}