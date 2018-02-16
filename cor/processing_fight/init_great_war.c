/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_great_war.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:16:05 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/05 15:29:14 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	corewar(t_cor *cor)
{
	int end;
	int i;

	end = 1;
	i = 0;
	ft_printf("Introducing contestants: \n\n");
	while (i < cor->count_players)
	{
		ft_printf("Player %d :  \"%s\" weighting %d bytes  (\"%s\")\n",
				i + 1, cor->players[i].prog_name, cor->players[i].prog_size,
				cor->players[i].comment);
		i++;
	}
	ft_printf("\n.\n.\n.\n\n");
	if (cor->d == 1 && cor->dump_number != cor->lev)
		dump_corewar(cor);
	else if (cor->d == 1 && cor->dump_number == cor->lev)
		ft_put_error("Wrong dump number");
	else
	{
		while (end)
			init_great_war(cor, cor->cursor);
	}
}

void	init_great_war(t_cor *cor, t_cursor *curr_curs)
{
	t_cursor *temp;

	while (curr_curs)
	{
		check_current_cursor(cor, curr_curs);
		curr_curs = curr_curs->next;
	}
	if (!cor->curses.to_die)
	{
		cor->checks += cor->ada;
		while (cor->cursor && !cor->cursor->live)
		{
			temp = cor->cursor;
			cor->map[cor->cursor->cci].cursor = 0;
			cor->cursor = cor->cursor->next;
			free(temp);
		}
		cursor_kaput(cor, cor->cursor, 0);
		decrease_cycles(cor);
		if (!count_cursors(cor, cor->lev))
			print_winner(cor);
	}
	cor->curses.cycle += cor->ada;
	cor->curses.to_die -= cor->ada;
}
