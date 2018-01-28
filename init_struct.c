#include "cor.h"

void	init_struct(t_cor **cor)
{
    t_cor *tmp;

    tmp = (t_cor*)malloc(sizeof(t_cor));
    tmp->count_players = 0;
    tmp->n = 0;
    tmp->map = malloc(sizeof(t_arena) * MEM_SIZE);
    tmp->curses.cycle = 0;
    tmp->curses.cycle_to_die = CYCLE_TO_DIE;
    tmp->curses.paused = 1;
    tmp->curses.nbr_live = 0;
    tmp->d = 0;
    *cor = tmp;
}