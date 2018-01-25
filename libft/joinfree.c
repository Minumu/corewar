#include "libft.h"

char		*ft_joinfree(char *str1, char *str2, t_del string)
{
    char	*final;
    size_t	i;
    size_t	j;
    size_t	len;

    len = ft_strlen(str1) + ft_strlen(str2);
    if (!str1 || !str2)
        return (0);
    if (!(final = (char *)malloc(sizeof(char) * (len + 1))))
        return (0);
    i = 0;
    while (str1[i])
    {
        final[i] = str1[i];
        i++;
    }
    j = 0;
    while (str2[j])
        final[i++] = str2[j++];
    final[i] = '\0';
    if (string == BOTH || string == FIRST)
        free(str1);
    if (string == BOTH || string == SECOND)
        free(str2);
    return (final);
}