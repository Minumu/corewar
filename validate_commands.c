#include "cor.h"

void    validate_live_zjump_fork_lfork(t_cursor *cursor)
{
    if (cursor->arg_type[0] != T_DIR)
        ft_put_error("Error | Wrong argument type");
    if (cursor->op.count_args != 1)
        ft_put_error("Error | Wrong args count");
    cursor->valid = 1;
}

void    validate_ld(t_cursor *cursor)
{
    if (cursor->op.count_args == 2)
    {
        if (cursor->arg_type[1] == T_REG)
        {
            if (cursor->arg_type[0] == T_IND || cursor->arg_type[0] == T_DIR)
            {
                cursor->valid = 1;
                return ;
            }
        }
    }
    return ;
}

void    validate_st(t_cursor *cursor)
{
    if (cursor->op.count_args == 2)
    {
        if (cursor->arg_type[0] == T_REG)
        {
            if (cursor->arg_type[0] == T_IND || cursor->arg_type[0] == T_REG)
            {
                cursor->valid = 1;
                return ;
            }
        }
    }
}

void    validate_add(t_cursor *cursor)
{
    if (cursor->op.count_args == 3)
    {
        if (cursor->arg_type[0] == T_REG)
        {
            if (cursor->arg_type[1] == T_REG && cursor->arg_type[2] == T_REG)
            {
                cursor->valid = 1;
                return ;
            }
        }
    }
}

void    validate_sub(t_cursor *cursor)
{
    if (cursor->op.count_args == 3)
    {
        if (cursor->arg_type[0] == T_REG)
        {
            if (cursor->arg_type[1] == T_REG && cursor->arg_type[2] == T_REG)
            {
                cursor->valid = 1;
                return ;
            }
        }
    }
}

void    validate_and_or_xor(t_cursor *cursor)
{
    if (cursor->op.count_args == 3)
    {
        if (cursor->arg_type[0] == T_REG
            || cursor->arg_type[0] == T_DIR
            || cursor->arg_type[0] == T_IND)
        {
            if (cursor->arg_type[1] == T_REG
                || cursor->arg_type[1] == T_DIR
                || cursor->arg_type[1] == T_IND)
            {
                if (cursor->arg_type[2] == T_REG
                    || cursor->arg_type[2] == T_DIR)
                {
                    cursor->valid = 1;
                    return ;
                }
            }
        }
    }
}

void    validate_ldi_lldi(t_cursor *cursor)
{
    if (cursor->op.count_args == 3)
    {
        if (cursor->arg_type[0] == T_REG
            || cursor->arg_type[0] == T_DIR
            || cursor->arg_type[0] == T_IND)
        {
            if (cursor->arg_type[1] == T_REG
                || cursor->arg_type[1] == T_DIR)
            {
                if (cursor->arg_type[2] == T_REG)
                {
                    cursor->valid = 1;
                    return ;
                }
            }
        }
    }
}

void    validate_sti(t_cursor *cursor)
{
    if (cursor->op.count_args == 3)
    {
        if (cursor->arg_type[0] == T_REG)
        {
            if (cursor->arg_type[1] == T_REG
                || cursor->arg_type[1] == T_DIR
                || cursor->arg_type[1] == T_IND)
            {
                if (cursor->arg_type[2] == T_REG
                    || cursor->arg_type[2] == T_DIR)
                {
                    cursor->valid = 1;
                    return ;
                }
            }
        }
    }
}

void    validate_lld(t_cursor *cursor)
{
    if (cursor->op.count_args == 2)
    {
        if (cursor->arg_type[0] == T_DIR
            || cursor->arg_type[0] == T_IND)
        {
            if (cursor->arg_type[1] == T_REG)
            {
                cursor->valid = 1;
                return;
            }
        }

    }
}

void    validate_aff(t_cursor *cursor)
{
    if (cursor->op.count_args == 1)
    {
        if (cursor->arg_type[0] == T_REG)
        {
            cursor->valid = 1;
            return ;
        }
    }
}

void    validate_commands(t_cursor *cursor)
{
    if (cursor->op.opcode == 1 || cursor->op.opcode == 9
        || cursor->op.opcode == 12
        || cursor->op.opcode == 15)
        validate_live_zjump_fork_lfork(cursor);
    if (cursor->op.opcode == 2)
        validate_ld(cursor);
    if (cursor->op.opcode == 3)
        validate_st(cursor);
    if (cursor->op.opcode == 4)
        validate_add(cursor);
    if (cursor->op.opcode == 5)
        validate_sub(cursor);
    if (cursor->op.opcode == 6 || cursor->op.opcode == 7
        || cursor->op.opcode == 8)
        validate_and_or_xor(cursor);
    if (cursor->op.opcode == 10
        || cursor->op.opcode == 14)
        validate_ldi_lldi(cursor);
    if (cursor->op.opcode == 11)
        validate_sti(cursor);
    if (cursor->op.opcode == 13)
        validate_lld(cursor);
    if (cursor->op.opcode == 16)
        validate_aff(cursor);
}
