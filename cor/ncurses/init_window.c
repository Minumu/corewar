/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:43:39 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:08:52 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

static void	navigation(t_cor *cor)
{
	attron(COLOR_PAIR(4));
	mvwprintw(cor->curses.win, 35, 198, "Pause/run: ");
	mvwprintw(cor->curses.win, 36, 200, "press 'space'");
	mvwprintw(cor->curses.win, 38, 198, "Increase the number of game speed: ");
	mvwprintw(cor->curses.win, 39, 200, "press 'w'");
	mvwprintw(cor->curses.win, 41, 198, "Decrease the number of game speed: ");
	mvwprintw(cor->curses.win, 42, 200, "press 's'");
	mvwprintw(cor->curses.win, 44, 198, "Exit: ");
	mvwprintw(cor->curses.win, 45, 200, "press 'esc'");
	attroff(COLOR_PAIR(4));
}

void		sidebar(t_cor *cor)
{
	attron(COLOR_PAIR(3) | A_BOLD);
	if (cor->curses.paused == 1)
	{
		attron(COLOR_PAIR(6));
		mvwprintw(cor->curses.win, 2, 198, "** PAUSED  **");
		attroff(COLOR_PAIR(6));
	}
	else
	{
		attron(COLOR_PAIR(5));
		mvwprintw(cor->curses.win, 2, 198, "** RUNNING **");
		attroff(COLOR_PAIR(5));
	}
	mvwprintw(cor->curses.win, 4, 198, "Game speed : %d ", cor->spd);
	mvwprintw(cor->curses.win, 10, 198, "Cycle : %d ", cor->curses.cycle);
	mvwprintw(cor->curses.win, 12, 198, "Processes : %d ", cor->curses.proc);
	print_player(cor);
	mvwprintw(cor->curses.win, 27, 198, "CYCLE TO DIE : %d ",
			cor->curses.cycle_to_die);
	mvwprintw(cor->curses.win, 29, 198, "CYCLE DELTA : %d ", CYCLE_DELTA);
	mvwprintw(cor->curses.win, 31, 198, "NBR LIVE : %d ", NBR_LIVE);
	attroff(COLOR_PAIR(3) | A_BOLD);
	navigation(cor);
}

static void	draw_borders2(t_cor *cor, int i, int x, int y)
{
	mvwprintw(cor->curses.win, i, 0, "|");
	mvwprintw(cor->curses.win, i, x - 1, "|");
	mvwprintw(cor->curses.win, i, x + 65, "|");
	mvwprintw(cor->curses.win, 0, i + 194, "-");
	mvwprintw(cor->curses.win, y - 1, i + 194, "-");
	mvwprintw(cor->curses.win, 7, i + 194, "-");
	mvwprintw(cor->curses.win, 33, i + 194, "-");
	mvwprintw(cor->curses.win, 47, i + 194, "-");
}

static void	draw_borders(t_cor *cor)
{
	unsigned int x;
	unsigned int y;
	unsigned int i;

	i = 0;
	y = 68;
	x = 196;
	attron(COLOR_PAIR(2));
	mvwprintw(cor->curses.win, 0, 0, "+");
	mvwprintw(cor->curses.win, y - 1, 0, "+");
	mvwprintw(cor->curses.win, 0, x + 65, "+");
	mvwprintw(cor->curses.win, y - 1, x + 65, "+");
	while (++i < (y - 1))
		draw_borders2(cor, i, x, y);
	i = 0;
	while (++i < (x - 1))
	{
		mvwprintw(cor->curses.win, 0, i, "-");
		mvwprintw(cor->curses.win, y - 1, i, "-");
	}
	attroff(COLOR_PAIR(2));
	sidebar(cor);
}

void		draw_field(t_cor *cor)
{
	unsigned int	x;
	unsigned int	y;
	int				i;
	unsigned int	j;

	y = 2;
	j = 0;
	while (j < MEM_SIZE)
	{
		x = 2;
		i = -1;
		while (++i < 64)
		{
			if (cor->map[j].cursor == 1)
				check_cursor_color(cor->map[j].pn, cor);
			else
				check_player_color(cor->map[j].pn, cor);
			mvwprintw(cor->curses.win, y, x++, "%02x", cor->map[j].cell);
			x += 2;
			j++;
			attron(COLOR_PAIR(1));
		}
		y++;
	}
	draw_borders(cor);
}
