#include "cor.h"

void	init_struct(t_cor **cor)
{
    t_cor *tmp;

    tmp = (t_cor*)malloc(sizeof(t_cor));
    tmp->pause = 0;
    tmp->count_players = 0;
    tmp->n = 0;
    tmp->map = malloc(sizeof(t_arena*) * MEM_SIZE);
    *cor = tmp;
}