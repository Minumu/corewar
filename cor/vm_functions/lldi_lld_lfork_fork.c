/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi_lld_lfork_fork.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:46:54 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:47:05 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

int		ft_fork(t_cursor *cursor, t_cor *cor)
{
	int			i;
	int			r;
	t_cursor	*new_carr;
	t_cursor	*old_head;

	i = (cursor->cci - cursor->sbk) + (cursor->op.args[cor->lev] % IDX_MOD);
	if (i > MEM_SIZE)
		i = i % MEM_SIZE;
	cor->players[cursor->pln - cor->ada].carr_count++;
	new_carr = (t_cursor *)malloc(sizeof(t_cursor));
	cor->cursor_cnt++;
	new_carr->pln = cursor->pln;
	new_carr->cci = i;
	new_carr->live = cursor->live;
	new_carr->carry = cursor->carry;
	r = cor->lev;
	while (++r < 17)
		new_carr->reg[r] = cursor->reg[r];
	reset_cursor(new_carr);
	old_head = cor->cursor;
	new_carr->next = old_head;
	cor->cursor = new_carr;
	return (cor->lev);
}

int		lfork(t_cursor *cursor, t_cor *cor, int i, int r)
{
	t_cursor *new_carr;
	t_cursor *old_head;

	i = (cursor->cci - cursor->sbk) + cursor->op.args[cor->lev];
	if (i > cor->lev)
		i = i % MEM_SIZE;
	if (i < cor->lev)
		i = MEM_SIZE + (i % MEM_SIZE);
	if (i > MEM_SIZE)
		i = i % MEM_SIZE;
	cor->players[cursor->pln - cor->ada].carr_count++;
	new_carr = (t_cursor *)malloc(sizeof(t_cursor));
	cor->cursor_cnt++;
	new_carr->pln = cursor->pln;
	new_carr->cci = i;
	new_carr->live = cursor->live;
	new_carr->carry = cursor->carry;
	while (++r < 17)
		new_carr->reg[r] = cursor->reg[r];
	reset_cursor(new_carr);
	old_head = cor->cursor;
	new_carr->next = old_head;
	cor->cursor = new_carr;
	return (cor->lev);
}

void	lld(t_cursor *cursor, t_cor *cor)
{
	if (check_arg(2, cursor, cor->lev))
		cursor->reg[cursor->op.args[cor->ada]] = cursor->op.args[cor->lev];
	else if (check_arg(3, cursor, cor->lev))
		cursor->reg[cursor->op.args[cor->ada]] = indir_from_cell(cor,
				(cursor->cci + cursor->op.args[cor->lev]));
	if (cursor->reg[cursor->op.args[cor->ada]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}

void	lldi(t_cursor *cursor, t_cor *cor)
{
	int res;
	int s[(cor->ada * 2)];

	if (check_arg(1, cursor, cor->lev))
		s[cor->lev] = cursor->reg[cursor->op.args[cor->lev]];
	else if (check_arg(2, cursor, cor->lev))
		s[cor->lev] = cursor->op.args[cor->lev];
	else if (check_arg(3, cursor, cor->lev))
		s[cor->lev] = indir_from_cell(cor, cursor->cci +
				cursor->op.args[cor->lev]);
	if (check_arg(1, cursor, cor->ada))
		s[cor->ada] = cursor->reg[cursor->op.args[cor->ada]];
	else if (check_arg(2, cursor, cor->ada))
		s[cor->ada] = cursor->op.args[cor->ada];
	s[cor->lev] = convert_uns_int((unsigned int)s[cor->lev]);
	res = s[cor->lev] + s[cor->ada];
	cursor->reg[cursor->op.args[2]] = indir_from_cell(cor, cursor->cci + res);
	if (cursor->reg[cursor->op.args[2]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}
