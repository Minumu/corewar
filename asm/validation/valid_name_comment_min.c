#include "../asm.h"

void    check_name_and_comment(t_asm *asem)
{
    if (!asem->issetname || !asem->issetcomment)
        ft_put_error("Wrong syntax in Name or Comment");
    if (ft_strlen(asem->name) > PROG_NAME_LENGTH)
        ft_put_error("ERROR(Too large NAME)");
    if (ft_strlen(asem->comment) > COMMENT_LENGTH)
        ft_put_error("ERROR(Too large comment)");
}
