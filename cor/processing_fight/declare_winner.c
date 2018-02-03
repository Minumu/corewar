/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:06:12 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:06:14 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

int		count_cursors(t_cor *data, int i)
{
	t_cursor	*nowt;

	nowt = data->cursor;
	while (nowt)
	{
		nowt = nowt->next;
		i++;
	}
	data->curses.proc = i;
	return (i);
}

void	decrease_cycles(t_cor *cor)
{
	if (cor->curses.nbr_live < NBR_LIVE)
	{
		if (cor->checks > MAX_CHECKS)
		{
			if (cor->lev < (cor->curses.cycle_to_die - CYCLE_DELTA))
				cor->curses.cycle_to_die -= CYCLE_DELTA;
			else
				cor->curses.cycle_to_die = cor->ada;
			cor->checks = cor->lev;
		}
	}
	else
	{
		if (cor->lev < (cor->curses.cycle_to_die - CYCLE_DELTA))
			cor->curses.cycle_to_die -= CYCLE_DELTA;
		else
			cor->curses.cycle_to_die = cor->ada;
		cor->checks = cor->lev;
	}
	cor->curses.nbr_live = cor->lev;
	cor->curses.to_die = cor->curses.cycle_to_die;
}
