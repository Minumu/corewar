/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cursor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:49:35 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:49:39 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void		fill_reg(t_cursor *cursor)
{
	int i;

	i = 2;
	while (i < 17)
	{
		cursor->reg[i] = 0;
		i++;
	}
}

t_cursor	*create_cursor(int nb, t_cor *cor)
{
	t_cursor *cursor;

	cursor = (t_cursor*)malloc(sizeof(t_cursor));
	cursor->set_nb = cor->players[nb].nb_set;
	if (cor->players[nb].nb_set)
		cursor->pln = cor->players[nb].nb_set;
	else
		cursor->pln = -(nb + 1);
	cursor->bnr_code = NULL;
	cursor->carry = 0;
	cursor->live = 0;
	cursor->reg[1] = -(nb + 1);
	fill_reg(cursor);
	cursor->next = NULL;
	cursor->op.cycles = 1;
	cursor->op.opcode = 0;
	cursor->sbk = 0;
	cursor->opcode_g = -1;
	cursor->check = 0;
	cursor->cci = cor->players[nb].start_pos;
	return (cursor);
}

void		init_cursor(t_cor *cor, int i, t_cursor *next_cursor)
{
	while (i < cor->count_players)
	{
		if (cor->cursor)
		{
			next_cursor = create_cursor(i, cor);
			next_cursor->next = cor->cursor;
			cor->cursor = next_cursor;
		}
		else
			cor->cursor = create_cursor(i, cor);
		i++;
	}
}
