#include "cor.h"

int     get_op_struct(t_cor *cor, t_cursor *cursor, int i)
{
    if ((unsigned int) cor->map[cursor->index].cell == g_op_tab[i].opcode)
    {
        cursor->op.opcode = g_op_tab[i].opcode;
        cursor->op.label_size = g_op_tab[i].label_size;
        cursor->op.name = g_op_tab[i].name;
        cursor->op.count_args = g_op_tab[i].count_args;
        cursor->op.carry = g_op_tab[i].carry;
        if (g_op_tab[i].opcode == cursor->op.opcode)
        {
            cursor->op.cycles = g_op_tab[i].cycles - 1;
            if ((int) cursor->op.cycles < 0)
                cursor->op.cycles = 0;
        }
        return (1);
    }
    return (0);
}

void    reset_cursor(t_cursor *cursor)
{
    cursor->op.name = NULL;
    cursor->op.opcode = 0;
    cursor->op.label_size = 0;
    cursor->op.count_args = 0;
    cursor->op.carry = 0;
}

void    move_cursor_without_op(t_cursor *cursor, t_cor *cor)
{
    cor->map[cursor->index].cursor = 0;
    cursor->index += 1;
    cor->map[cursor->index].cursor = 1;
}

void    read_cell(int i,t_cor *cor, t_cursor *cursor)
{
    while (get_op_struct(cor, cursor, i) != 1 && i < OP_COUNT)
        i++;
}

void    exec_function(t_cursor *cursor, t_cor *cor)
{
    if (!cursor->op.opcode)
    {
        move_cursor_without_op(cursor, cor);
    }
}

void    check_current_cursor(t_cor *cor, t_cursor *cursor)
{
    int i;

    i = 0;
    if (cursor->op.cycles == 0)
    {
        reset_cursor(cursor);
        read_cell(i, cor, cursor);
        if (cursor->op.cycles == 0)
            move_cursor_without_op(cursor, cor);
    }
    else
    {
        cursor->op.cycles--;
        if (cursor->op.cycles == 0)
            exec_function(cursor, cor);
    }
}

void    init_great_war(t_cor *cor)
{
    t_cursor *curr_curs;

    while (1)
    {
        curr_curs = cor->cursor;
        while (curr_curs != NULL)
        {
            check_current_cursor(cor, curr_curs);
            curr_curs = curr_curs->next;
        }
    }
}