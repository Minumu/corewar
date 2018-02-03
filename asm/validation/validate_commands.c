#include "../asm.h"

void    validate_commands(t_commands *commands)
{
    int i;

    i = 0;
    while (i < OP_COUNT)
    {
        if (ft_strequ(commands->command_name, g_op_tab[i].name))
        {
            commands->index = i;
            break ;
        }
        i++;
    }
}

