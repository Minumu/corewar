#include "../asm.h"

int     check_arg(int n, int type)
{
    if (n == 1 && type == T_REG)
        return (1);
    if (n == 2 && type == T_DIR)
        return (1);
    if (n == 3 && type == T_IND)
        return (1);
    if (n == 4 && type == T_LAB)
        return (1);
    return (0);
}


int     get_coding_byte(t_commands *commands)
{
    int i;
    int type;
    int k;
    char binary[9];

    k = 0;
    i = 0;
    while (i < 8)
        binary[i++] = 48;
    binary[i] = '\0';
    i = 0;
    while (commands->arguments[i])
    {
        type = check_type_arg(commands->arguments[i]);
        if (check_arg(1, type) || check_arg(3, type)
            || (check_arg(4, type) && commands->arguments[i][0] != DIRECT_CHAR))
            binary[k + 1] = 49;
        if (check_arg(2, type) || check_arg(4, type) || check_arg(3, type))
            binary[k] = 49;
        k += 2;
        i++;
    }
    return (ft_atoi_base(binary, 2));
}