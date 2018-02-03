#include "../asm.h"

static int get_count_label(t_commands *commands)
{
    int i;

    i = 0;
    while (commands->labels && commands->labels[i])
        i++;
    return (i);
}

static void	add_label_struct(t_commands *commands, char *l)
{
    char	**s;
    int		i;
    int count;

    count = get_count_label(commands);
    s = (char **)malloc(sizeof(char *) * (count + 2));
    i = 0;
    while (commands->labels && commands->labels[i])
    {
        s[i] = commands->labels[i];
        i++;
    }
    s[i++] = l;
    s[i] = NULL;
    if (commands->labels)
        free(commands->labels);
    commands->labels = s;
}

size_t    get_label_name(char *s, t_commands *commands, size_t i, t_asm *asem)
{
    size_t k;

    i = skip_spaces(s, i);
    k = 0;
    while (ft_strcchr(LABEL_CHARS, s[i + k]))
        k++;
    if (s[i + k] == LABEL_CHAR && k > 0)
    {
        add_label_struct(commands, ft_strsub(s, 0, k));
        asem->found_label = 1;
        return (i + k + 1);
    }
    else
    {
        asem->found_label = 2;
        commands->command_name = ft_strsub(s, (unsigned int) i, k);
    }
    return (i + k);
}