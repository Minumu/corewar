/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:36:08 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 16:36:12 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	check_cursor_color(int pn, t_cor *cor)
{
	if (pn == 0)
		wattron(cor->curses.win, COLOR_PAIR(15));
	else if (pn == 1)
		wattron(cor->curses.win, COLOR_PAIR(11));
	else if (pn == 2)
		wattron(cor->curses.win, COLOR_PAIR(12));
	else if (pn == 3)
		wattron(cor->curses.win, COLOR_PAIR(13));
	else if (pn == 4)
		wattron(cor->curses.win, COLOR_PAIR(14));
}

void	check_player_color(int pn, t_cor *cor)
{
	if (pn == 0)
		wattron(cor->curses.win, COLOR_PAIR(1));
	else if (pn == 1 || pn == -1)
		wattron(cor->curses.win, COLOR_PAIR(10));
	else if (pn == 2 || pn == -2)
		wattron(cor->curses.win, COLOR_PAIR(20));
	else if (pn == 3 || pn == -3)
		wattron(cor->curses.win, COLOR_PAIR(30));
	else if (pn == 4 || pn == -4)
		wattron(cor->curses.win, COLOR_PAIR(40));
}

void	init_colors(void)
{
	init_pair(1, 8, COLOR_BLACK);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	init_pair(20, COLOR_BLUE, COLOR_BLACK);
	init_pair(30, COLOR_RED, COLOR_BLACK);
	init_pair(40, COLOR_CYAN, COLOR_BLACK);
	init_pair(11, COLOR_BLACK, COLOR_GREEN);
	init_pair(12, COLOR_BLACK, COLOR_BLUE);
	init_pair(13, COLOR_BLACK, COLOR_RED);
	init_pair(14, COLOR_BLACK, COLOR_CYAN);
	init_pair(15, COLOR_BLACK, 8);
	init_pair(2, 8, 8);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, 167, COLOR_BLACK);
	init_pair(5, 28, COLOR_BLACK);
	init_pair(6, 160, COLOR_BLACK);
}
