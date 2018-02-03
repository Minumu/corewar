#include "../asm.h"

static int    check_label(t_asm *asem, char *str)
{
    int i;
    int j;

    if (str[0] != DIRECT_CHAR)
        str = str + (asem->grace - 1);
    else
        str = str + asem->grace;
    i = 0;
    while (asem->commands && asem->commands[i])
    {
        j = 0;
        while (asem->commands[i]->labels && asem->commands[i]->labels[j])
        {
            if (ft_strequ(asem->commands[i]->labels[j], str))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void    check_exist_label(t_commands *commands, t_asm *asem)
{
    int i;

    i = 0;
    if (commands->arguments)
    {
        while (commands->arguments[i])
        {
            if (is_label(commands->arguments[i]))
            {
                if (!check_label(asem, commands->arguments[i]))
                {
                    ft_printf("***--->[%s]<---***\n", commands->arguments[i]);
                    ft_put_error("Invalid label");
                }
            }
            i++;
        }
    }
}
