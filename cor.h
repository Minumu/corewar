#ifndef VIRTUALMACHINE_COR_H
#define VIRTUALMACHINE_COR_H

# include "libft/libft.h"
# include "op.h"
# include <ncurses.h>
# include <fcntl.h>
# include <stdio.h>
# define GREEN "\x1B[32m\0"
# define BLUE "\x1B[34m\0"
# define RED "\x1B[31m\0"
# define CYAN "\x1B[36m\0"
# define WHITE "\x1B[37m\0"

/*TEST*/
 typedef struct		s_curses
{
	int				nbr_live;
	int				time_to_die;
	int				cycle_to_die;
	int				cycle;
	int				paused;
}					t_curses;
/*TEST*/

typedef struct		s_cursor
{
    int				player_number;
    int				index;
    int				carry;
    int				live;
    int				id;
    char			*binary;
    int				arg_type[3];
    int				reg[1 + 16];
    int             set_number;
    int             valid;
    t_op			op;
    int				skip_bytes_cursor;
    int             opcode_g;
    struct s_cursor	*next;
}					t_cursor;

typedef struct		s_arena
{
    unsigned char	cell;
    int             cursor;
    int             pn;

}					t_arena;

typedef struct		s_champ
{
    int				nb;
    int				nb_set;
    int				start_pos;
    char			*file_name;
    int				last_live;
    unsigned int	magic;
    char			prog_name[PROG_NAME_LENGTH + 1];
    unsigned int	prog_size;
    size_t			full_prog_size;
    char			comment[COMMENT_LENGTH + 1];
    char			*program;
    int				carr_count;
    int             fd;
    unsigned char   magic_bin[4];
    unsigned char   size_bin[4];
}					t_champ;


typedef struct s_cor
{
    int count_players;
    int n;
    int d;
    int dump_number;
    t_champ        players[MAX_PLAYERS + 1];
    t_arena        *map;
    t_cursor        *cursor;
    t_curses        curses;
    int				nbr_live;
    int				ctd;
    int				cycle;
    int             speed;
    int             max_checks;
    int             delta;
    int             cursor_cnt;
    int             winner;
    int             time_to_die;

}              t_cor;

void	init_struct(t_cor **cor);
int     ft_strstr_my(const char *str, const char *to_find, int pos);
void	ft_put_error(char *str);
void parse_arg(char **av, t_cor *cor);
void    parse_magic_number(t_cor *cor, int nb, char *content);
int    convert_int_from_binary(unsigned char *str);
void    check_magic(t_cor *cor, int nb);
int    parse_prog_name(t_cor *cor, int nb, char *content, int move);
int    parse_prog_size(t_cor *cor, int nb, char *content, int move);
void    check_size(t_cor *cor, int nb);
int    parse_prog_comment(t_cor *cor, int nb, char *content, int move);
void    parse_program(t_cor *cor, int nb, char *content, int move);
void    create_arena(t_cor *cor);
void    init_great_war(t_cor *cor);
void    init_cursor(t_cor *cor);
void	parse_octal(t_cor *data, t_cursor *carr, unsigned label);
void	parse_non_octal(t_cor *data, t_cursor *carr, unsigned label);
void    validate_commands(t_cursor *cursor);
void    manage_functions(t_cor *cor, t_cursor *cursor);
void    move_cursor_with_op(t_cursor *cursor, t_cor *cor);
void    reset_cursor(t_cursor *cursor);
void    fork_func(t_cursor *cursor, t_cor *cor);
void    lfork(t_cursor *cursor, t_cor *cor);
//Test//
//void	nc_print_stat(t_cor *data, WINDOW *win);
//void	nc_print_map(t_cor *data, WINDOW *win);
//void	change_speed(t_cor *data, int key);
//void	get_color(int pn, WINDOW *win);
//void	get_carriage_color(int pn, WINDOW *win);
//void	nc_refresh(t_cor *data, t_print *print);
//void	shut_down_nc(t_cor *data);
//void	print_cell(unsigned char cell, WINDOW *win);
//void	print_stat_status(t_cor *data, WINDOW *win);
//void	print_stat_cycle(t_cor *data, WINDOW *win);
//void	print_champs(t_cor *data, WINDOW *win);
//void	print_rules(t_cor *data, WINDOW *win);
//void	winner_loop(t_cor *data);
//void	nc_print_winner(t_cor *data, t_ *p, int winner);
//void	nc_start(t_cor *data);
//void	nc_pause(t_cor *data);
//void	init_colors(void);
//void	nc_prepare(t_cor *data, t_curses *curses);

void	winner_loop();
void	init_ncurses(t_cor *cor);
void    corewar(t_cor *cor);

#endif
