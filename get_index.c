#include "cor.h"

char			*to_two_base(unsigned char c) {
    int i;
    int j;
    char *binary;

    binary = ft_strnew(7);
    i = 7;
    j = 0;
    while (i >= 0) {
        if (c & (1 << i))
            binary[j] = '1';
        else
            binary[j] = '0';
        --i;
        j++;
    }
    return (binary);
}

int		get_register(t_cor *data, t_cursor *carr, int i)
{
    int index;
    int	nb_reg;

    index = carr->index + carr->skip_bytes_cursor;
    if (index >= MEM_SIZE)
        index = (carr->index + carr->skip_bytes_cursor) - MEM_SIZE;
    nb_reg = (int)data->map[index].cell;
    carr->arg_type[i] = T_REG;
    carr->skip_bytes_cursor++;
    return (nb_reg);
}

int		get_direct(t_cor *data, t_cursor *carr, unsigned label, int i)
{
    unsigned int	nbr;
    unsigned char	str[4];
    int				j;
    int				index;

    index = carr->index + carr->skip_bytes_cursor;
    j = -1;
    while (++j < 4)
    {
        if (index >= MEM_SIZE)
            index = (carr->index + carr->skip_bytes_cursor) - MEM_SIZE;
        str[j] = data->map[index].cell;
        index++;
        carr->skip_bytes_cursor++;
    }
    if (label)
    {
        nbr = (short)(str[0] << 8) + str[1];
        carr->skip_bytes_cursor -= 2;
    }
    else
        nbr = (str[0] << 24) + (str[1] << 16) + (str[2] << 8) + str[3];
    carr->arg_type[i] = T_DIR;
    return (nbr);
}

int		get_indirect(t_cor *data, t_cursor *carr, int i)
{
    unsigned int	nbr;
    unsigned char	one;
    unsigned char	two;
    int				index;

    index = carr->index + carr->skip_bytes_cursor;
    if (index >= MEM_SIZE)
        index = (carr->index + carr->skip_bytes_cursor) - MEM_SIZE;
    one = data->map[index].cell;
    index++;
    carr->skip_bytes_cursor++;
    two = data->map[index].cell;
    carr->skip_bytes_cursor++;
    nbr = (short)((one << 8) + two);
    carr->arg_type[i] = T_IND;
    return (nbr);
}

void	parse_octal(t_cor *data, t_cursor *carr, unsigned label)
{
    int		i;
    int		one;
    int		two;

    carr->binary = to_two_base(data->map[carr->index + carr->skip_bytes_cursor].cell);
    carr->skip_bytes_cursor++;
    i = 0;
    one = 0;
    two = 1;
    while (two <= ((int)carr->op.count_args * 2) - 1)
    {
        if (carr->binary[one] == '0' && carr->binary[two] == '1')
            carr->op.args[i] = get_register(data, carr, i);
        else if (carr->binary[one] == '1' && carr->binary[two] == '0')
            carr->op.args[i] = get_direct(data, carr, label, i);
        else if (carr->binary[one] == '1' && carr->binary[two] == '1')
            carr->op.args[i] = get_indirect(data, carr, i);
        i++;
        one += 2;
        two += 2;
    }
    free(carr->binary);
}

void	parse_non_octal(t_cor *data, t_cursor *carr, unsigned label)
{
    carr->op.args[0] = get_direct(data, carr, label, 0);
}
