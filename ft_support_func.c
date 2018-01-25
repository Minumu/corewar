#include "cor.h"

int     ft_strstr_my(const char *str, const char *to_find, int pos)
{
    size_t i;
    size_t step;
    size_t count;

    i = (size_t) pos;
    step = 0;
    count = 0;
    while (to_find[count])
        count++;
    if (count == 0)
        return (1);
    while (str[i])
    {
        while (to_find[step] == str[i + step])
        {
            if (step == (count - 1))
                return (1);
            step++;
        }
        step = 0;
        i++;
    }
    return (0);
}

void	ft_put_error(char *str)
{
    ft_printf("%s", str);
    exit(0);
}

void    error_name(char **av, int count_arg)
{
    ft_printf("Can't read source file %s\n", av[count_arg - 1]);
    exit(0);
}

void    error_usage(void)
{
    ft_printf("Usage: ./asm <sourcefile.s>\n");
    exit(0);
}

void		free_str(char **str)
{
    int	i;

    i = 0;
    while (str[i])
    {
        free(str[i]);
        i++;
    }
    free(str);
}