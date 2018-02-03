/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:07:42 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:08:06 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	winner_loop(t_cor *cor)
{
	while (getch() != 27)
	{
		attron(COLOR_PAIR(5) | A_BOLD);
		mvwprintw(cor->curses.win, 2, 198, "** WASTED  **");
		attroff(COLOR_PAIR(5) | A_BOLD);
	}
	endwin();
	exit(1);
}

void	end_game(t_cor *cor)
{
	mvwprintw(cor->curses.win, 50, 218, "Congratulations!!!");
	check_player_color(cor->players[cor->win_player].nb, cor);
	mvwprintw(cor->curses.win, 55, 218, "Player: %d",
			cor->players[cor->win_player].nb);
	attron(COLOR_PAIR(3));
	mvwprintw(cor->curses.win, 56, 218, "(%s) won",
			cor->players[cor->win_player].prog_name);
	winner_loop(cor);
}
