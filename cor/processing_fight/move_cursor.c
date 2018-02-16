/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:24:37 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:24:47 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	gto(t_cor *cor, t_cursor *cursor, int i)
{
	int cord;

	cursor->sbk += cor->ada;
	if (!g_op_tab[i].octal_coding)
	{
		if (g_op_tab[i].octal_coding == (unsigned int)cor->lev)
			cursor->op.args[0] = ft_dir(cor, cursor, g_op_tab[i].label_size, 0);
	}
	else
	{
		cord = (cursor->sbk + cursor->cci);
		cursor->bnr_code = generate_binary(cor->map[cord].cell,
				cor, (6 + cor->ada), cor->lev);
		cursor->sbk++;
		get_binary(cor, cursor, g_op_tab[i].label_size, cor->lev);
		free(cursor->bnr_code);
	}
	if (g_op_tab[i].opcode == cursor->op.opcode)
		validate_commands(cursor, cor);
}

void	get_op_struct(t_cor *cor, t_cursor *cursor, int i)
{
	if (g_op_tab[i].opcode == (unsigned int)cor->map[cursor->cci].cell)
	{
		cursor->op.opcode = g_op_tab[i].opcode;
		cursor->op.label_size = g_op_tab[i].label_size;
		cursor->op.name = g_op_tab[i].name;
		cursor->opcode_g = i;
		cursor->op.count_args = g_op_tab[i].count_args;
		if (g_op_tab[i].opcode == cursor->op.opcode)
		{
			cursor->op.cycles = g_op_tab[i].cycles - 1;
			if ((int)cursor->op.cycles < 0)
				cursor->op.cycles = 0;
		}
	}
	if (++i < OP_COUNT - 2)
		get_op_struct(cor, cursor, i);
}

void	move_cursor_with_op(t_cursor *cursor, t_cor *cor, int perm)
{
	perm = cursor->cci;
	cor->map[perm].cursor = cor->lev;
	perm = perm + cursor->sbk;
	if (cor->lev < perm)
		perm = (perm % MEM_SIZE);
	if (cor->lev > perm)
		perm = (MEM_SIZE + (perm % MEM_SIZE));
	cor->map[perm].cursor = cor->ada;
	cursor->cci = perm;
}

void	reset_cursor(t_cursor *cursor)
{
	int i;

	i = -1;
	cursor->bnr_code = NULL;
	cursor->sbk = 0;
	cursor->check = FALSE;
	cursor->opcode_g = -1;
	while (++i < 3)
	{
		cursor->atp[i] = 0;
		cursor->op.args[i] = 0;
	}
	cursor->op.name = NULL;
	cursor->op.count_args = 0;
	cursor->op.opcode = 0;
	cursor->op.cycles = 0;
	cursor->op.octal_coding = 0;
	cursor->op.label_size = 0;
}

void	check_current_cursor(t_cor *cor, t_cursor *cursor)
{
	if (cursor->op.cycles)
	{
		cursor->op.cycles -= cor->ada;
		if (!cursor->op.cycles)
		{
			if (cursor->op.opcode)
				gto(cor, cursor, cursor->opcode_g);
			exec_function(cursor, cor, cursor->op.opcode);
		}
	}
	else
	{
		reset_cursor(cursor);
		get_op_struct(cor, cursor, cor->lev);
		if (!cursor->op.cycles)
		{
			cor->map[cursor->cci].cursor = cor->lev;
			if (cor->lev > cursor->cci)
				cursor->cci = (MEM_SIZE - cor->ada) - cursor->cci;
			if ((MEM_SIZE - cor->ada) <= cursor->cci)
				cursor->cci = (cor->ada * -1);
			cursor->cci += cor->ada;
			cor->map[cursor->cci].cursor = cor->ada;
		}
	}
}
