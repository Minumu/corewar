/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:28:20 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:28:23 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	fill_commands(t_cor *cor)
{
	cor->live = 1;
	cor->ld = 2;
	cor->st = 3;
	cor->add = 4;
	cor->sub = 5;
	cor->and = 6;
	cor->or = 7;
	cor->xor = 8;
	cor->zjump = 9;
	cor->ldi = 10;
	cor->sti = 11;
	cor->fork = 12;
	cor->lld = 13;
	cor->lldi = 14;
	cor->lfork = 15;
	cor->aff = 16;
}

void	init_struct(t_cor **cor)
{
	t_cor *tmp;

	tmp = (t_cor*)malloc(sizeof(t_cor));
	tmp->count_players = 0;
	tmp->n = 0;
	tmp->map = malloc(sizeof(t_arena) * MEM_SIZE);
	tmp->curses.cycle = 0;
	tmp->curses.cycle_to_die = CYCLE_TO_DIE;
	tmp->curses.paused = 1;
	tmp->curses.nbr_live = 0;
	tmp->d = 0;
	tmp->cursor = 0;
	tmp->spd = 1;
	tmp->lev = 0;
	tmp->ada = 1;
	tmp->bod = 0;
	tmp->p = 0;
	tmp->set_pn = 0;
	fill_commands(tmp);
	*cor = tmp;
}
