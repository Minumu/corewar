/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st_ld_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:51:22 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:51:34 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	live(t_cursor *cursor, t_cor *cor)
{
	int i;

	i = cor->lev;
	cursor->live += cor->ada;
	cor->curses.nbr_live += cor->ada;
	while (i < cor->count_players)
	{
		if (cursor->op.args[cor->lev] == cor->players[i].nb)
		{
			cor->win_player = i;
			cor->players[i].last_live = cor->curses.cycle;
		}
		i++;
	}
}

void	ld(t_cursor *cursor, t_cor *cor)
{
	if (check_arg(2, cursor, cor->lev))
		cursor->reg[cursor->op.args[cor->ada]] = cursor->op.args[cor->lev];
	else
	{
		if (check_arg(3, cursor, cor->lev))
			cursor->reg[cursor->op.args[cor->ada]] =
					indir_from_cell(cor, (cursor->cci
					+ (cursor->op.args[cor->lev] % IDX_MOD)));
	}
	if (cursor->reg[cursor->op.args[cor->ada]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}

void	st(t_cursor *cursor, t_cor *cor)
{
	int				i;
	unsigned char	*binary;

	if (check_arg(3, cursor, cor->ada))
	{
		i = cursor->op.args[cor->ada];
		binary = convert_int_to_str(cursor->reg[cursor->op.args[cor->lev]]);
		put_on_arena(cursor, cor, binary, i);
		free(binary);
	}
	else if (check_arg(1, cursor, cor->ada))
		cursor->reg[cursor->op.args[cor->ada]] =
				cursor->reg[cursor->op.args[cor->lev]];
}
