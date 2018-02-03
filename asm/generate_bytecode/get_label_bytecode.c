#include "../asm.h"

int distance(t_asm *asem, int start, int index, int length)
{
    while (start < index)
        length += asem->commands[start++]->len;
    return (length);
}

int get_pos(t_asm *asem, char *l, int k, int o)
{
    while (asem->commands && asem->commands[k])
    {
        o = 0;
        while (asem->commands[k]->labels && asem->commands[k]->labels[o])
        {
            if (ft_strequ(asem->commands[k]->labels[o], l))
                return (k);
            o++;
        }
        k++;
    }
    return (-1);
}
