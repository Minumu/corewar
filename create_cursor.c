#include "cor.h"

t_cursor    *create_cursor(int nb, t_cor *cor)
{
    int r;
    t_cursor *cursor;

    r = 1;
    cursor = (t_cursor*)malloc(sizeof(t_cursor));
    cursor->player_number = -(nb + 1);
    cursor->set_number = -(nb + 1);
    cursor->binary = NULL;
    cursor->carry = 0;
    cursor->live = 0;
    cursor->reg[1] = -(nb + 1);
    while (++r < 17)
        cursor->reg[r] = 0;
    cursor->next = NULL;
    cursor->op.cycles = 1;
    cursor->op.opcode = 0;
    cursor->skip_bytes_cursor = 0;
    cursor->opcode_g = -1;
    cursor->valid = 0;
    cursor->index = cor->players[nb].start_pos;
    return (cursor);
}

void    init_cursor(t_cor *cor)
{
    int nb;
    t_cursor *next_cursor;

    nb = 0;
    cor->cursor = NULL;
    while (nb < cor->count_players)
    {
        if (cor->cursor == NULL)
            cor->cursor = create_cursor(nb, cor);
        else
        {
            next_cursor = create_cursor(nb,cor);
            next_cursor->next = cor->cursor;
            cor->cursor = next_cursor;
        }
        nb++;
    }
}