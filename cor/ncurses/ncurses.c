/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 16:36:36 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:09:24 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void		print_player(t_cor *cor)
{
	int k;
	int y;

	k = 0;
	y = 14;
	while (k < cor->count_players)
	{
		check_player_color(k + 1, cor);
		mvwprintw(cor->curses.win, (y + 4 / cor->count_players - 1), 198,
				"Player %d: %.51s ", cor->players[k].nb,
				cor->players[k].prog_name);
		y++;
		attron(COLOR_PAIR(3));
		mvwprintw(cor->curses.win, (y + 4 / cor->count_players - 1), 200,
				"Last live : %10d ", cor->players[k].last_live);
		k++;
		y += 2;
	}
}

static void	start_game(t_cor *cor)
{
	int ch;

	while ((ch = getch()) != 27)
	{
		if (ch == 32)
		{
			if (cor->curses.paused == 0)
				cor->curses.paused = 1;
			pause_game(cor);
		}
		timeout(cor->spd);
		if (ch == 119)
			cor->spd = cor->spd + 1;
		else if (ch == 115 && cor->spd > 1)
			cor->spd = cor->spd - 1;
		init_great_war(cor, cor->cursor);
		draw_field(cor);
		refresh();
		wrefresh(cor->curses.win);
	}
	endwin();
	exit(1);
}

void		pause_game(t_cor *cor)
{
	int ch;

	while ((ch = getch()) != 27)
	{
		if (ch == 32)
		{
			if (cor->curses.paused == 1)
				cor->curses.paused = 0;
			sidebar(cor);
			wrefresh(cor->curses.win);
			start_game(cor);
		}
		else
		{
			if (ch == 119)
				cor->spd = cor->spd + 1;
			else if (ch == 115 && cor->spd > 1)
				cor->spd = cor->spd - 1;
			sidebar(cor);
			wrefresh(cor->curses.win);
		}
	}
	endwin();
	exit(1);
}

void		init_ncurses(t_cor *cor)
{
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	cor->curses.win = stdscr;
	nodelay(stdscr, TRUE);
	start_color();
	init_colors();
	draw_field(cor);
	refresh();
	wrefresh(cor->curses.win);
	pause_game(cor);
}
