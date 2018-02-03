/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arena.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:46:43 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:47:12 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	init_start_pos(t_cor *cor)
{
	int i;

	i = 0;
	while (i < cor->count_players)
	{
		cor->players[i].start_pos = (MEM_SIZE / cor->count_players) * i;
		i++;
	}
}

void	fill_arena_zero(t_cor *cor, int i)
{
	while (++i < MEM_SIZE)
	{
		cor->map[i].cursor = 0;
		cor->map[i].cell = 0;
	}
}

void	fill_arena_program(t_cor *cor, int i, int j, int placed)
{
	while (++i < cor->count_players)
	{
		j = 0;
		while (j < (int)cor->players[i].prog_size)
		{
			cor->map[j + cor->players[i].start_pos].pn = -cor->players[i].nb;
			cor->map[j + cor->players[i].start_pos].cell =
				(unsigned char)cor->players[i].program[j];
			j++;
		}
		cor->map[cor->players[i].start_pos].cursor = placed;
	}
}

void	fill_arena(t_cor *cor)
{
	init_start_pos(cor);
	cor->curses.to_die = CYCLE_TO_DIE;
	cor->checks = 0;
	cor->cursor_cnt = 1;
	cor->win_player = 0;
	fill_arena_zero(cor, -1);
	fill_arena_program(cor, -1, 0, 1);
}
