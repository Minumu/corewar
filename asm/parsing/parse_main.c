#include "../asm.h"

int     get_count(t_asm *asem)
{
    int i;

    i = 0;
    while (asem->commands && asem->commands[i])
        i++;
    return (i);
}
void    add_to_struct(t_asm *asem, t_commands *op)
{
    int			i;
    int         count;
    t_commands	**new_commands;

    count = get_count(asem);
    new_commands = (t_commands**)malloc(sizeof(t_commands *) * (count + 2));
    i = 0;
    while (asem->commands && asem->commands[i])
    {
        new_commands[i] = asem->commands[i];
        i++;
    }
    new_commands[i++] = op;
    new_commands[i] = 0;
    if (asem->commands)
        free(asem->commands);
    asem->commands = new_commands;
}

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

int     check_com(char *s, int pos)
{
    int i;

    i = 0;
    while (g_op_tab[i].name)
    {
        if (ft_strstr_my(s, g_op_tab[i].name, pos))
            return (1);
        i++;
    }
    return (0);
}

int parse_str(char *s, t_asm *asem)
{
    size_t i;

    i = 0;
    if (asem->found_label != 1)
        asem->tmp = init_struct_operation();
    i = get_label_name(s, asem->tmp, i, asem);
    if (check_com(s, (int) i) && asem->found_label == 1)
    {
        while (asem->tmp->command_name == NULL)
            i = get_label_name(s, asem->tmp, i, asem);
    }
    parse_arg(s, asem->tmp ,i);
    if (!asem->found_label || asem->found_label == 2)
        add_to_struct(asem, asem->tmp);
    if (asem->found_label == 1)
        asem->tmp_ska = asem->tmp;
    return (0);
}