#include "cor.h"

void    move_cursor_with_op(t_cursor *cursor, t_cor *cor)
{
    cor->map[cursor->index].cursor = 0;
    cursor->index = cursor->index + cursor->skip_bytes_cursor;
    if (cursor->index > 0)
        cursor->index = cursor->index % MEM_SIZE;
    if (cursor->index < 0)
        cursor->index = MEM_SIZE + (cursor->index % MEM_SIZE);
    cor->map[cursor->index].cursor = 1;
}

int     get_op_struct(t_cor *cor, t_cursor *cursor, int i)
{
    if ((unsigned int) cor->map[cursor->index].cell == g_op_tab[i].opcode)
    {
        cursor->op.opcode = g_op_tab[i].opcode;
        cursor->op.label_size = g_op_tab[i].label_size;
        cursor->op.name = g_op_tab[i].name;
        cursor->opcode_g = i;
        cursor->op.count_args = g_op_tab[i].count_args;
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
    cursor->binary = NULL;
    cursor->skip_bytes_cursor = 0;
    cursor->valid = FALSE;
    cursor->opcode_g = -1;
    cursor->arg_type[0] = 0;
    cursor->arg_type[1] = 0;
    cursor->arg_type[2] = 0;
    cursor->op.name = NULL;
    cursor->op.count_args = 0;
    cursor->op.args[0] = 0;
    cursor->op.args[1] = 0;
    cursor->op.args[2] = 0;
    cursor->op.opcode = 0;
    cursor->op.cycles = 0;
    cursor->op.octal_coding = 0;
    cursor->op.label_size = 0;
}

void    move_cursor_without_op(t_cursor *cursor, t_cor *cor)
{
    cor->map[cursor->index].cursor = 0;
    if (cursor->index < 0)
        cursor->index = (MEM_SIZE - 1) - cursor->index;
    if (cursor->index >= MEM_SIZE - 1)
        cursor->index = -1;
    cursor->index += 1;
    cor->map[cursor->index].cursor = 1;
}

void    read_current_cell(int i, t_cor *cor, t_cursor *cursor)
{
    while (get_op_struct(cor, cursor, i) != 1 && i < OP_COUNT - 2)
        i++;
}

void	get_octal(t_cor *data, t_cursor *cursor, int i)
{
    cursor->op.count_args = g_op_tab[i].count_args;
    cursor->skip_bytes_cursor++;
    if (g_op_tab[i].octal_coding)
        parse_octal(data, cursor, g_op_tab[i].label_size);
    else if (g_op_tab[i].octal_coding == 0)
        parse_non_octal(data, cursor, g_op_tab[i].label_size);
    if (cursor->op.opcode == g_op_tab[i].opcode)
        validate_commands(cursor);
}

void    exec_function(t_cursor *cursor, t_cor *cor)
{
    if (!cursor->op.cycles)
    {
        if (cursor->op.opcode)
            get_octal(cor ,cursor, cursor->opcode_g);
        if (cursor->op.opcode == 12 || cursor->op.opcode == 15)
        {
            move_cursor_with_op(cursor, cor);
            if (cursor->valid == 1 && cursor->op.opcode == 12)
            {
                fork_func(cursor, cor);
                return ;
            }
            else
            {
                lfork(cursor, cor);
                return ;
            }
        }
        else
        {
            if (cursor->valid == 1)
                manage_functions(cor, cursor);
        }
        move_cursor_with_op(cursor, cor);
    }
    return ;

}

void    check_current_cursor(t_cor *cor, t_cursor *cursor)
{
    int i;

    i = 0;
    if (cursor->op.cycles == 0)
    {
        reset_cursor(cursor);
        read_current_cell(i, cor, cursor);
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

void	headshot(t_cor *data)
{
    t_cursor	*tmp;

    while (data->cursor && data->cursor->live == 0)
    {
        tmp = data->cursor;
        data->cursor = data->cursor->next;
        free(tmp);
    }
}

void    kill_cursor(t_cor *cor)
{
    t_cursor	*current;
    t_cursor	*prev;
    t_cursor	*tmp;

    headshot(cor);
    if (cor->cursor == NULL)
        return ;
    prev = cor->cursor;
    prev->live = 0;
    current = cor->cursor->next;
    while (current != NULL)
    {
        if (current->live == 0)
        {
            tmp = current;
            prev->next = current->next;
            current = prev;
            free(tmp);
        }
        prev = current;
        current->live = 0;
        current = current->next;
    }
}

void print_map(t_cor *cor)
{
    int i;
    int x;

    i = 0;
    x = 0;
    while (i < MEM_SIZE)
    {
        x++;
        ft_printf("%02x ", cor->map[i].cell);
        if (x >= 64)
        {
            x = 0;
            ft_printf("\n");
        }
        i++;
    }
}

void    dump_corewar(t_cor *cor)
{
    int i;

    i = 0;
    while (i < cor->dump_number)
    {
        init_great_war(cor);
        i++;
    }
    print_map(cor);
}

void    corewar(t_cor *cor)
{
    if (cor->d == 1 && cor->dump_number != 0)
        dump_corewar(cor);
    else if (cor->d == 1 && cor->dump_number == 0)
        ft_put_error("Wrong dump number");
    else
    {
        while (1)
        {
            init_great_war(cor);
        }
    }
}

void	decrease_cicle_to_die(t_cor *data)
{
    if ((data->curses.cycle_to_die - CYCLE_DELTA) > 0)
        data->curses.cycle_to_die -= CYCLE_DELTA;
    else
        data->curses.cycle_to_die = 1;
    data->max_checks = 0;
}

void	check_max_checks(t_cor *data)
{
    if (data->max_checks > MAX_CHECKS)
        decrease_cicle_to_die(data);
}

int		count_processes(t_cor *data)
{
    int		processes;
    t_cursor	*current;

    processes = 0;
    current = data->cursor;
    while (current != NULL)
    {
        processes++;
        current = current->next;
    }
    return (processes);
}

void    print_winner(t_cor *cor)
{
    end_game(cor);
}

void    exit_game(t_cor *cor)
{
    kill_cursor(cor);
    cor->max_checks++;
    if (cor->curses.nbr_live > NBR_LIVE)
        decrease_cicle_to_die(cor);
    else
        check_max_checks(cor);
    cor->curses.nbr_live = 0;
    cor->curses.time_to_die = cor->curses.cycle_to_die;
    if (count_processes(cor) == 0)
        print_winner(cor);
}

void    init_great_war(t_cor *cor)
{
    t_cursor *curr_curs;

    curr_curs = cor->cursor;
    while (curr_curs != NULL)
    {
        check_current_cursor(cor, curr_curs);
        curr_curs = curr_curs->next;
    }
    if (cor->curses.time_to_die == 0)
        exit_game(cor);
    cor->curses.cycle++;
    cor->curses.time_to_die--;
}