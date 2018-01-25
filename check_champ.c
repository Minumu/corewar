#include "cor.h"

void    check_magic(t_cor *cor, int nb)
{
    if (cor->players[nb].magic != COREWAR_EXEC_MAGIC)
        ft_put_error("ERROR | Wrong magic number");
}

void    check_size(t_cor *cor, int nb)
{
    if (cor->players[nb].prog_size > CHAMP_MAX_SIZE)
        ft_put_error("Size too large");
}