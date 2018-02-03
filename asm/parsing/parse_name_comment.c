#include "../asm.h"

static void    write_name_comment(t_asm *asem, char *str_new)
{
    asem->k = 0;
    if (asem->com == 1)
    {
        asem->name = ft_strdup(str_new);
        asem->issetname = 1;
    }
    else if (asem->com == 2)
    {
        asem->comment = ft_strdup(str_new);
        asem->issetcomment = 1;
    }
    free(str_new);
}


void    find_name_comment(char *line, t_asm* asem, char **str_new)
{
    if (ft_strposlen(line, '"') == 2 && !asem->k)
    {
        write_name_comment(asem, check_name_comment(line, 3, 0 ,0));
        free(*str_new);
    }
    else if (ft_strposlen(line, '"') == 1 && !asem->k)
    {
        *str_new = check_name_comment(line, 1, 0, 0);
        asem->k = 1;
    }
    else if (asem->k == 1 && ft_strposlen(line, '"') == 0)
    {
        *str_new = ft_joinfree(*str_new, line, FIRST);
        *str_new = ft_joinfree(*str_new, "\n", FIRST);
    }
    else if (ft_strposlen(line, '"') == 1 && asem->k == 1)
    {
        *str_new = ft_joinfree(*str_new, "\n", FIRST);
        *str_new = ft_joinfree(*str_new, check_name_comment(line, 2, 0 , 0), BOTH);
        write_name_comment(asem, *str_new);
    }
    else
        ft_put_error("Error in Name or Comment");
}

