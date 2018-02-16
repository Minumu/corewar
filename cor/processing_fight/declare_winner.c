/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare_winner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:06:12 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 20:22:01 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	print_winner(t_cor *cor)
{
	if (cor->n == 1)
		end_game(cor);
	else
	{
		ft_printf("Congratulations!!!\n");
		ft_printf("Player: ");
		ft_printf("%d", cor->players[cor->win_player].nb);
		ft_printf(" (%s)", cor->players[cor->win_player].prog_name);
		ft_printf(" won\n");
		exit(0);
	}
}

int		count_cursors(t_cor *cor, int i)
{
	t_cursor	*nowt;

	nowt = cor->cursor;
	while (nowt)
	{
		nowt = nowt->next;
		i++;
	}
	cor->curses.proc = i;
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
