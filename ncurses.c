#include "cor.h"



void	draw_field(WINDOW *win, t_cor *cor)
{
	unsigned int x;
	unsigned int y;
	unsigned int i;
	unsigned int j;
	unsigned int k;

	y = 2;
	j = 0;
	k = 0;
	while (j < MEM_SIZE)
	{
		x = 2;
		i = 0;
//		mvwprintw(win, y, x++, "%d ", y);
		while (i < 64)
		{
			if (k < cor->count_players && j < cor->players[k].prog_size)
			{
//				if (cor->map[j].cursor == 0)
					check_color(k, cor->map[j].pn);
				while (j < cor->players[k].prog_size && i < 64)
				{
					attron(COLOR_PAIR(10));
					mvwprintw(win, y, x++, "%02x", cor->map[j].cell);
					x += 2;
					j++;
					i++;
				}
				attroff(COLOR_PAIR(10));
				if (cor->count_players != 0)
				{
					cor->count_players--;
				}
			}
			else
			{
				attron(COLOR_PAIR(1) | A_BOLD);
				mvwprintw(win, y, x++, "%02x", cor->map[j].cell);
				x += 2;
				i++;
				j++;
			}
			attroff(COLOR_PAIR(1) | A_BOLD);
//			mvwprintw(win, y, x++, "%d ", i);
//			x++;
		}
		y++;
	}
//	wrefresh(stdscr);
}

void	sidebar(t_cor *cor, WINDOW *win)
{
	attron(COLOR_PAIR(3) | A_BOLD);
	if (cor->curses.paused == 1)
	{
		attron(COLOR_PAIR(6));
		mvwprintw(win, 2, 198, "** PAUSED  **");
		attroff(COLOR_PAIR(6));
	}
	else
	{
		attron(COLOR_PAIR(5));
		mvwprintw(win, 2, 198, "** RUNNING **");
		attroff(COLOR_PAIR(5));
	}
	mvwprintw(win, 4, 198, "Game speed : %d ", cor->speed);
	mvwprintw(win, 10, 198, "Cycle : %d ", cor->curses.cycle);
	mvwprintw(win, 12, 198, "Processes : ? ");
	mvwprintw(win, 14, 198, "Player %d: %.51s ", cor->cursor->player_number, cor->players->prog_name);
	mvwprintw(win, 15, 200, "Last live : %20c ", '?');
	mvwprintw(win, 16, 200, "Lives in current period : %6c ", '?');
	mvwprintw(win, 18, 198, "CYCLE TO DIE : %d ", cor->ctd);
	mvwprintw(win, 20, 198, "CYCLE DELTA : %d ", cor->delta);
	mvwprintw(win, 22, 198, "NBR LIVE : %d ", cor->nbr_live);
	mvwprintw(win, 24, 198, "MAX CHECKS : %d ", cor->max_checks);
	attroff(COLOR_PAIR(3) | A_BOLD);
}

void	draw_borders(WINDOW *win)
{
	unsigned int x;
	unsigned int y;
	unsigned int i;

	i = 1;
	y = 68;
	x = 196;
//	getmaxyx(win, y, x); // 4 corners
	attron(COLOR_PAIR(2));
	mvwprintw(win, 0, 0, "+");
	mvwprintw(win, y - 1, 0, "+");
	mvwprintw(win, 0, x + 65, "+");
	mvwprintw(win, y - 1, x + 65, "+"); // sides
	while (i < (y - 1))
	{
		mvwprintw(win, i, 0, "|");
		mvwprintw(win, i, x - 1, "|");
		mvwprintw(win, i, x + 65, "|");
		mvwprintw(win, 0, i + 194, "-");
		mvwprintw(win, y - 1, i + 194, "-");
		mvwprintw(win, 7, i + 194, "-");
		mvwprintw(win, 27, i + 194, "-");
		mvwprintw(win, 46, i + 194, "-");
		i++;
	} // top and bottom
	i = 1;
	while (i < (x - 1))
	{
		mvwprintw(win, 0, i, "-");
		mvwprintw(win, y - 1, i, "-");
		i++;
	}
	attroff(COLOR_PAIR(2));
//	refresh() ;
//	wrefresh(stdscr);
}

void	init_colors(void)
{
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	init_pair(20, COLOR_BLUE, COLOR_BLACK);
	init_pair(30, COLOR_RED, COLOR_BLACK);
	init_pair(40, COLOR_CYAN, COLOR_BLACK);
	init_pair(1, 8, COLOR_BLACK);
	init_pair(2, 8, 8);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	init_pair(4, 167, COLOR_BLACK);
	init_pair(5, 28, COLOR_BLACK);
	init_pair(6, 160, COLOR_BLACK);
}

void	navigation(WINDOW *win)
{
	attron(COLOR_PAIR(4));
	mvwprintw(win, 30, 198, "Pause/run: ");
	mvwprintw(win, 31, 200, "press 'space'");
	mvwprintw(win, 33, 198, "Increase the number of game speed: ");
	mvwprintw(win, 34, 200, "press 'w'");
	mvwprintw(win, 36, 198, "Decrease the number of game speed: ");
	mvwprintw(win, 37, 200, "press 's'");
	mvwprintw(win, 39, 198, "Increase the cycle: ");
	mvwprintw(win, 40, 200, "press 'q'");
	mvwprintw(win, 42, 198, "Exit: ");
	mvwprintw(win, 43, 200, "press 'esc'");
	attroff(COLOR_PAIR(4));
}

void	check_keys(int ch, t_cor *cor)
{
	if (ch == 32)
	{
		if (cor->curses.paused == 0)
			cor->curses.paused = 1;
		else
		{
			cor->curses.paused = 0;
		}
	}
	else if (ch == 119)
		cor->speed = cor->speed + 1;
	else if (ch == 115 && cor->speed > 0)
		cor->speed = cor->speed - 1;
	else if (ch == 113)
		cor->cycle = cor->cycle + 10;
}

void	winner_loop(void)
{
	int quit;
	int key;

	quit = 'o';
	while (quit != 'x')
	{
		key = getch();
		if (key == 'x')
			quit = key;
	}
	endwin();
	exit(1);
}

void	init_ncurses(t_cor *cor)
{
	int ch;

	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	init_colors();
	draw_field(stdscr, cor);
	draw_borders(stdscr);
	navigation(stdscr);
	while ((ch = getch()) != 27)
	{
		check_keys(ch, cor);
		draw_field(stdscr, cor);
		draw_borders(stdscr);
		sidebar(cor, stdscr);
		navigation(stdscr);
//		check_keys(ch, cor);
		init_great_war(cor);
		refresh();
		wrefresh(stdscr);
	}
	endwin(); /* End curses mode */
}