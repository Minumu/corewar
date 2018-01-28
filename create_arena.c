#include "cor.h"

void    init_start_pos(t_cor *cor)
{
    int i;

    i = 0;

    while (i < cor->count_players)
    {
        cor->players[i].start_pos = (MEM_SIZE / cor->count_players) * i;
        i++;
    }
}

void    fill_arena_zero(t_cor *cor)
{
    int i;

    i = 0;
    while (i < MEM_SIZE)
    {
        cor->map[i].cursor = 0;
        cor->map[i].cell = 0;
        i++;
    }
}

void    fill_arena_program(t_cor *cor)
{
    int i;
    int j;

    i = 0;
    while (i < cor->count_players)
    {
        j = 0;
        while (j < (int)cor->players[i].prog_size)
        {
            cor->map[j + cor->players[i].start_pos].pn = -cor->players[i].nb;
            cor->map[j + cor->players[i].start_pos].cell =
                    (unsigned char) cor->players[i].program[j];
            j++;
        }
        cor->map[cor->players[i].start_pos].cursor = 1;
        i++;
    }
}

void    init_arena(t_cor *cor)
{
    init_start_pos(cor);
    cor->cycle = 0;
    cor->curses.time_to_die = CYCLE_TO_DIE;
    cor->nbr_live = 0;
    cor->speed = 100;
    cor->max_checks = 0;
    cor->delta = 0;
    cor->cursor_cnt = 1;
    cor->winner = 0;
    fill_arena_zero(cor);
    fill_arena_program(cor);
}

void    create_arena(t_cor *cor)
{
    init_arena(cor);
    init_cursor(cor);
}