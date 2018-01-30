#include "cor.h"

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

void	draw_field(t_cor *cor)
{
	unsigned int x;
	unsigned int y;
	unsigned int i;
	unsigned int j;

	y = 2;
	j = 0;
	while (j < MEM_SIZE)
	{
		x = 2;
		i = 0;
		while (i < 64)
		{
//			if (j < cor->players[k].prog_size)
//			{
				if (cor->map[j].cursor == 1)
					check_cursor_color(cor->map[j].pn, cor);
				else
					check_player_color(cor->map[j].pn, cor);
				mvwprintw(cor->curses.win, y, x++, "%02x", cor->map[j].cell);
//				while (j < cor->players[k].prog_size && i < 64)
//				{
//					attron(COLOR_PAIR(10));
//					mvwprintw(win, y, x++, "%02x", cor->map[j].cell);
				x += 2;
				j++;
				i++;
//				}
				attron(COLOR_PAIR(1));
//			}
//			 attroff(COLOR_PAIR(1) | A_BOLD);
//			mvwprintw(win, y, x++, "%d ", i);
//			x++;
		}
		y++;
//	wrefresh(stdscr);
	}
}

void	print_player(t_cor *cor)
{
	int k;
	int y;

	k = 0;
	y = 14;
	while (k < cor->count_players)
	{
		check_player_color(k + 1, cor);
		mvwprintw(cor->curses.win, y++, 198, "Player %d: %.51s ", cor->players[k].nb,
				  cor->players[k].prog_name);
		attron(COLOR_PAIR(3));
		mvwprintw(cor->curses.win, y++, 200, "Last live : %20d ", cor->players[k].last_live);
//		mvwprintw(cor->curses.win, y, 200, "Lives in current period : %6c ", '?');
		k++;
		y += 2;
	}
}

void	sidebar(t_cor *cor)
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
	mvwprintw(cor->curses.win, 4, 198, "Game speed : %d ", cor->speed);
	mvwprintw(cor->curses.win, 10, 198, "Cycle : %d ", cor->curses.cycle);
	mvwprintw(cor->curses.win, 12, 198, "Processes : ?");
	print_player(cor);
	mvwprintw(cor->curses.win, 21, 198, "CYCLE TO DIE : %d ", cor->curses.cycle_to_die);
	mvwprintw(cor->curses.win, 23, 198, "CYCLE DELTA : %d ", CYCLE_DELTA);
	mvwprintw(cor->curses.win, 25, 198, "NBR LIVE : %d ", cor->curses.nbr_live);
	mvwprintw(cor->curses.win, 27, 198, "MAX CHECKS : %d ", cor->max_checks);
	attroff(COLOR_PAIR(3) | A_BOLD);
}

void	draw_borders(t_cor *cor)
{
	unsigned int x;
	unsigned int y;
	unsigned int i;

	i = 1;
	y = 68;
	x = 196;
//	getmaxyx(win, y, x); // 4 corners
	attron(COLOR_PAIR(2));
	mvwprintw(cor->curses.win, 0, 0, "+");
	mvwprintw(cor->curses.win, y - 1, 0, "+");
	mvwprintw(cor->curses.win, 0, x + 65, "+");
	mvwprintw(cor->curses.win, y - 1, x + 65, "+"); // sides
	while (i < (y - 1))
	{
		mvwprintw(cor->curses.win, i, 0, "|");
		mvwprintw(cor->curses.win, i, x - 1, "|");
		mvwprintw(cor->curses.win, i, x + 65, "|");
		mvwprintw(cor->curses.win, 0, i + 194, "-");
		mvwprintw(cor->curses.win, y - 1, i + 194, "-");
		mvwprintw(cor->curses.win, 7, i + 194, "-");
		mvwprintw(cor->curses.win, 29, i + 194, "-");
		mvwprintw(cor->curses.win, 46, i + 194, "-");
		i++;
	} // top and bottom
	i = 1;
	while (i < (x - 1))
	{
		mvwprintw(cor->curses.win, 0, i, "-");
		mvwprintw(cor->curses.win, y - 1, i, "-");
		i++;
	}
	attroff(COLOR_PAIR(2));
	sidebar(cor);
//	refresh() ;
//	wrefresh(stdscr);
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

void	navigation(t_cor *cor)
{
	attron(COLOR_PAIR(4));
	mvwprintw(cor->curses.win, 30, 198, "Pause/run: ");
	mvwprintw(cor->curses.win, 31, 200, "press 'space'");
	mvwprintw(cor->curses.win, 33, 198, "Increase the number of game speed: ");
	mvwprintw(cor->curses.win, 34, 200, "press 'w'");
	mvwprintw(cor->curses.win, 36, 198, "Decrease the number of game speed: ");
	mvwprintw(cor->curses.win, 37, 200, "press 's'");
	mvwprintw(cor->curses.win, 39, 198, "Increase the cycle: ");
	mvwprintw(cor->curses.win, 40, 200, "press 'q'");
	mvwprintw(cor->curses.win, 42, 198, "Exit: ");
	mvwprintw(cor->curses.win, 43, 200, "press 'esc'");
	attroff(COLOR_PAIR(4));
}

void	check_keys(int ch, t_cor *cor)
{
	if (ch == 119)
		cor->speed = cor->speed + 1;
	else if (ch == 115 && cor->speed > 0)
		cor->speed = cor->speed - 1;
	else if (ch == 113)
		cor->curses.cycle = cor->curses.cycle + 10;
}

void	end_game(t_cor *cor)
{
	mvwprintw(cor->curses.win, 48, 210, "Congratulations!!!");
	check_player_color(cor->players[cor->winner].nb, cor);
	mvwprintw(cor->curses.win, 50, 198, "Player: %d", cor->players[cor->winner].nb);
	attron(COLOR_PAIR(3));
	mvwprintw(cor->curses.win, 51, 198, " (%s) won", cor->players[cor->winner].prog_name);
	winner_loop();
}

void	winner_loop(void)
{
	while (getch() != 27)
	{
		;
	}
	endwin();
	exit(1);
}

void	start_game(t_cor *cor)
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
		timeout(cor->speed);
		check_keys(ch, cor);
		init_great_war(cor);
		draw_field(cor);
		draw_borders(cor);
		navigation(cor);
		refresh();
		wrefresh(cor->curses.win);
	}
	endwin();
	exit(1);
}

void	pause_game(t_cor *cor)
{
	int ch;

	while ((ch = getch()) != 27)
	{
//
//
//		}
		if (ch == 32)
		{
			if (cor->curses.paused == 1)
				cor->curses.paused = 0;
			sidebar(cor);
			refresh();
			wrefresh(cor->curses.win);
			start_game(cor);
		}
		else
		{
			check_keys(ch, cor);
			sidebar(cor);
			refresh();
			wrefresh(cor->curses.win);
		}
	}
	endwin();
	exit(1);
}

void	init_ncurses(t_cor *cor)
{
	initscr();
	cbreak();
	noecho();
	cor->curses.win = stdscr;
	nodelay(stdscr, TRUE);
	start_color();
	init_colors();
	draw_field(cor);
	draw_borders(cor);
	navigation(cor);
	refresh();
	wrefresh(cor->curses.win);
	pause_game(cor);
}