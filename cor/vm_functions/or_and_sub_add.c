/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_and_sub_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:49:08 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:49:27 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	add(t_cursor *cursor, t_cor *cor)
{
	cursor->reg[cursor->op.args[2]] =
			cursor->reg[cursor->op.args[cor->lev]]
			+ cursor->reg[cursor->op.args[cor->ada]];
	if (cursor->reg[cursor->op.args[2]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}

void	sub(t_cursor *cursor, t_cor *cor)
{
	cursor->reg[cursor->op.args[2]] =
			cursor->reg[cursor->op.args[cor->lev]]
			- cursor->reg[cursor->op.args[cor->ada]];
	if (cursor->reg[cursor->op.args[2]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}

void	and(t_cursor *cursor, t_cor *cor)
{
	int i;
	int s[(cor->ada * 2)];

	i = 0;
	while (i < (cor->ada * 2))
	{
		if (check_arg(1, cursor, i))
			s[i] = cursor->reg[cursor->op.args[i]];
		else if (check_arg(2, cursor, i))
			s[i] = cursor->op.args[i];
		else if (check_arg(3, cursor, i))
			s[i] = indir_from_cell(cor,
				(cursor->cci + cursor->op.args[i]));
		i++;
	}
	cursor->reg[cursor->op.args[(cor->ada * 2)]] = s[cor->lev] & s[cor->ada];
	if (cursor->reg[cursor->op.args[(cor->ada * 2)]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}

void	or(t_cursor *cursor, t_cor *cor)
{
	int i;
	int s[(cor->ada * 2)];

	i = 0;
	while (i < (cor->ada * 2))
	{
		if (check_arg(1, cursor, i))
			s[i] = cursor->reg[cursor->op.args[i]];
		else if (check_arg(2, cursor, i))
			s[i] = cursor->op.args[i];
		else if (check_arg(3, cursor, i))
			s[i] = indir_from_cell(cor,
				(cursor->cci + cursor->op.args[i]));
		i++;
	}
	cursor->reg[cursor->op.args[2]] = s[cor->lev] | s[cor->ada];
	if (cursor->reg[cursor->op.args[2]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}
