#include "cor.h"

int				unsigned_to_int(unsigned nbr)
{
    int x;

    x = (int16_t)nbr;
    return (x);
}

unsigned char	*int_to_str(int n)
{
    unsigned char *str;

    str = (unsigned char *)malloc(sizeof(char) * 4);
    str[0] = (unsigned char)((n >> 24) & 0xFF);
    str[1] = (unsigned char)((n >> 16) & 0xFF);
    str[2] = (unsigned char)((n >> 8) & 0xFF);
    str[3] = (unsigned char)(n & 0xFF);
    return (str);
}

int				char_to_int(unsigned char *str)
{
    int nbr;

    nbr = str[0] << 24;
    nbr += str[1] << 16;
    nbr += str[2] << 8;
    nbr += str[3];
    return (nbr);
}

void	place_on_map(t_cursor *carr, t_arena *map, int nbr, int index)
{
    int				i;
    int				pos;
    unsigned char	*bytes;

    bytes = int_to_str(nbr);
    index = carr->index + (index % IDX_MOD);
    index = index % MEM_SIZE;
    i = 0;
    while (i < 4)
    {
        pos = index + i;
        if (pos < 0)
            pos = MEM_SIZE + pos;
        if (pos >= MEM_SIZE)
            pos = pos % MEM_SIZE;
        map[pos].cell = bytes[i];
        map[pos].pn = -carr->player_number;
        i++;
    }
    free(bytes);
}

int		get_indirect_from_map(t_arena *map, int index)
{
    unsigned char	str[4];
    int				nbr;

    if (index > MEM_SIZE)
        index = (index % MEM_SIZE);
    str[0] = map[index].cell;
    str[1] = map[index + 1].cell;
    str[2] = map[index + 2].cell;
    str[3] = map[index + 3].cell;
    nbr = char_to_int(str);
    return (nbr);
}

void    live(t_cursor *cursor, t_cor *cor)
{
    int i;

    i = 0;
    cursor->live++;
    cor->curses.nbr_live++;
    while (i < cor->count_players)
    {
        if (cursor->op.args[0] == cor->players[i].nb_set)
        {
            cor->winner = i;
            cor->players[i].last_live = cor->curses.cycle;
        }
        i++;
    }
}

void    ld(t_cursor *cursor, t_cor *cor)
{
    int i;

    if (cursor->arg_type[0] == T_DIR)
        cursor->reg[cursor->op.args[1]] = cursor->op.args[0];
    else if (cursor->arg_type[0] == T_IND)
    {
        i = cursor->index + (cursor->op.args[0] % IDX_MOD);
        cursor->reg[cursor->op.args[1]] = get_indirect_from_map(cor->map, i);
    }
    if (cursor->reg[cursor->op.args[1]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    st(t_cursor *cursor, t_cor *cor)
{
    int i;

    if (cursor->arg_type[1] == T_IND)
    {
        i = cursor->op.args[1];
        place_on_map(cursor, cor->map, cursor->reg[cursor->op.args[0]], i);
    }
    else if (cursor->arg_type[1] == T_REG)
        cursor->reg[cursor->op.args[1]] = cursor->reg[cursor->op.args[0]];
}

void    add(t_cursor *cursor)
{
    cursor->reg[cursor->op.args[2]] =
            cursor->reg[cursor->op.args[0]]
            + cursor->reg[cursor->op.args[1]];
    if (cursor->reg[cursor->op.args[2]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    sub(t_cursor *cursor)
{
    cursor->reg[cursor->op.args[2]] =
            cursor->reg[cursor->op.args[0]]
            - cursor->reg[cursor->op.args[1]];
    if (cursor->reg[cursor->op.args[2]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    and(t_cursor *cursor, t_cor *cor)
{
    int i;
    int argv[2];
    int index;

    i = -1;
    while (++i < 2)
    {
        if (cursor->arg_type[i] == T_REG)
            argv[i] = cursor->reg[cursor->op.args[i]];
        else if (cursor->arg_type[i] == T_DIR)
            argv[i] = cursor->op.args[i];
        else if (cursor->arg_type[i] == T_IND)
        {
            index = cursor->index + cursor->op.args[i];
            argv[i] = get_indirect_from_map(cor->map, index);
        }
    }
    cursor->reg[cursor->op.args[2]] = argv[0] & argv[1];
    if (cursor->reg[cursor->op.args[2]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    or(t_cursor *cursor, t_cor *cor)
{
    int i;
    int argv[2];
    int index;

    i = -1;
    while (++i < 2)
    {
        if (cursor->arg_type[i] == T_REG)
            argv[i] = cursor->reg[cursor->op.args[i]];
        else if (cursor->arg_type[i] == T_DIR)
            argv[i] = cursor->op.args[i];
        else if (cursor->arg_type[i] == T_IND)
        {
            index = cursor->index + cursor->op.args[i];
            argv[i] = get_indirect_from_map(cor->map, index);
        }
    }
    cursor->reg[cursor->op.args[2]] = argv[0] | argv[1];
    if (cursor->reg[cursor->op.args[2]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    xor(t_cursor *cursor, t_cor *cor)
{
    int i;
    int argv[2];
    int index;

    i = -1;
    while (++i < 2)
    {
        if (cursor->arg_type[i] == T_REG)
            argv[i] = cursor->reg[cursor->op.args[i]];
        else if (cursor->arg_type[i] == T_DIR)
            argv[i] = cursor->op.args[i];
        else if (cursor->arg_type[i] == T_IND)
        {
            index = cursor->index + cursor->op.args[i];
            argv[i] = get_indirect_from_map(cor->map, index);
        }
    }
    cursor->reg[cursor->op.args[2]] = argv[0] ^ argv[1];
    if (cursor->reg[cursor->op.args[2]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    zjump(t_cursor *cursor)
{
    if (cursor->carry)
    {
        cursor->skip_bytes_cursor = (cursor->op.args[0] % IDX_MOD);
    }
}

void    ldi(t_cursor *cursor, t_cor *cor)
{
    int res;
    int argv[2];
    int index;

    if (cursor->arg_type[0] == T_REG)
        argv[0] = cursor->reg[cursor->op.args[0]];
    else if (cursor->arg_type[0] == T_DIR)
        argv[0] = cursor->op.args[0];
    else if (cursor->arg_type[0] == T_IND)
    {
        index = cursor->index + (cursor->op.args[0] % IDX_MOD);
        argv[0] = get_indirect_from_map(cor->map, cursor->index + index);
    }
    if (cursor->arg_type[1] == T_REG)
        argv[1] = cursor->reg[cursor->op.args[1]];
    else if (cursor->arg_type[1] == T_DIR)
        argv[1] = cursor->op.args[1];
    res = argv[0] + argv[1];
    res = cursor->index + (res % IDX_MOD);
    cursor->reg[cursor->op.args[2]] = get_indirect_from_map(cor->map, res);
}

void    sti(t_cursor *cursor, t_cor *cor)
{
    int res;
    int argv[2];
    int index;

    if (cursor->arg_type[1] == T_REG)
        argv[0] = cursor->reg[cursor->op.args[1]];
    else if (cursor->arg_type[1] == T_DIR)
        argv[0] = cursor->op.args[1];
    else if (cursor->arg_type[1] == T_IND)
    {
        index = cursor->index + (cursor->op.args[0] % IDX_MOD);
        argv[0] = get_indirect_from_map(cor->map, index);
    }
    if (cursor->arg_type[2] == T_REG)
        argv[1] = cursor->reg[cursor->op.args[2]];
    else if (cursor->arg_type[2] == T_DIR)
        argv[1] = cursor->op.args[2];
    res = argv[0] + argv[1];
    place_on_map(cursor, cor->map, cursor->reg[cursor->op.args[0]], res);
}

void    fork_func(t_cursor *cursor, t_cor *cor)
{
    int i;
    int r;
    t_cursor	*new_carr;
    t_cursor	*old_head;

    i = (cursor->index - cursor->skip_bytes_cursor) + (cursor->op.args[0] % IDX_MOD);
    if (i > MEM_SIZE)
        i = i % MEM_SIZE;
    cor->players[cursor->player_number - 1].carr_count++;
    new_carr = (t_cursor *)malloc(sizeof(t_cursor));
    new_carr->id = cor->cursor_cnt;
    cor->cursor_cnt++;
    new_carr->player_number = cursor->player_number;
    new_carr->index = i;
    new_carr->live = cursor->live;
    new_carr->carry = cursor->carry;
    r = 0;
    while (++r < 17)
        new_carr->reg[r] = cursor->reg[r];
    reset_cursor(new_carr);
    old_head = cor->cursor;
    new_carr->next = old_head;
    cor->cursor = new_carr;
}

void    lfork(t_cursor *cursor, t_cor *cor)
{
    int i;
    int r;
    t_cursor	*new_carr;
    t_cursor	*old_head;

    i = (cursor->index - cursor->skip_bytes_cursor) + cursor->op.args[0];
    if (i > 0)
        i = i % MEM_SIZE;
    if (i < 0)
        i = MEM_SIZE + (i % MEM_SIZE);
    if (i > MEM_SIZE)
        i = i % MEM_SIZE;
    cor->players[cursor->player_number - 1].carr_count++;
    new_carr = (t_cursor *)malloc(sizeof(t_cursor));
    new_carr->id = cor->cursor_cnt;
    cor->cursor_cnt++;
    new_carr->player_number = cursor->player_number;
    new_carr->index = i;
    new_carr->live = cursor->live;
    new_carr->carry = cursor->carry;
    r = 0;
    while (++r < 17)
        new_carr->reg[r] = cursor->reg[r];
    reset_cursor(new_carr);
    old_head = cor->cursor;
    new_carr->next = old_head;
    cor->cursor = new_carr;
}

void    lld(t_cursor *cursor, t_cor *cor)
{
    int index;

    if (cursor->arg_type[0] == T_DIR)
        cursor->reg[cursor->op.args[1]] = cursor->op.args[0];
    else if (cursor->arg_type[0] == T_IND)
    {
        index = cursor->index + cursor->op.args[0];
        cursor->reg[cursor->op.args[1]] = get_indirect_from_map(cor->map, index);
    }
    if (cursor->reg[cursor->op.args[1]] == 0)
        cursor->carry = 1;
    else
        cursor->carry = 0;
}

void    lldi(t_cursor *cursor, t_cor *cor)
{
    int res;
    int argv[2];

    if (cursor->arg_type[0] == T_REG)
        argv[0] = cursor->reg[cursor->op.args[0]];
    else if (cursor->arg_type[0] == T_DIR)
        argv[0] = cursor->op.args[0];
    else if (cursor->arg_type[0] == T_IND)
        argv[0] = get_indirect_from_map(cor->map, cursor->index + cursor->op.args[0]);
    if (cursor->arg_type[1] == T_REG)
        argv[1] = cursor->reg[cursor->op.args[1]];
    else if (cursor->arg_type[1] == T_DIR)
        argv[1] = cursor->op.args[1];
    argv[0] = unsigned_to_int((unsigned int) argv[0]);
    res = argv[0] + argv[1];
    cursor->reg[cursor->op.args[2]] = get_indirect_from_map(cor->map, cursor->index + res);
}

void    manage_functions(t_cor *cor, t_cursor *cursor)
{
    if (cursor->op.opcode == 1)
        live(cursor, cor);
    if (cursor->op.opcode == 2)
        ld(cursor, cor);
    if (cursor->op.opcode == 3)
        st(cursor, cor);
    if (cursor->op.opcode == 4)
        add(cursor);
    if (cursor->op.opcode == 5)
        sub(cursor);
    if (cursor->op.opcode == 6)
        and(cursor, cor);
    if (cursor->op.opcode == 7)
       or(cursor, cor);
    if (cursor->op.opcode == 8)
       xor(cursor, cor);
    if (cursor->op.opcode == 9)
        zjump(cursor);
    if (cursor->op.opcode == 10)
        ldi(cursor, cor);
    if (cursor->op.opcode == 11)
        sti(cursor, cor);
    if (cursor->op.opcode == 13)
        lld(cursor, cor);
    if (cursor->op.opcode == 14)
        lldi(cursor, cor);
}
