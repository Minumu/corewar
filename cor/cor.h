/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:29:12 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:30:26 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COR_H
# define COR_H

# include "../libft/include/libft.h"
# include "op.h"
# include <ncurses.h>
# include <fcntl.h>

typedef struct		s_curses
{
	WINDOW			*win;
	int				nbr_live;
	int				to_die;
	int				cycle_to_die;
	int				cycle;
	int				paused;
	int				proc;
}					t_curses;

typedef struct		s_cursor
{
	int				pln;
	int				cci;
	int				carry;
	int				live;
	char			*bnr_code;
	int				atp[3];
	int				reg[1 + 16];
	int				check;
	t_op			op;
	int				sbk;
	int				opcode_g;
	struct s_cursor	*next;
	int				set_nb;
}					t_cursor;

typedef struct		s_arena
{
	unsigned char	cell;
	int				cursor;
	int				pn;

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
	int				fd;
	unsigned char	magic_bin[4];
	unsigned char	size_bin[4];
}					t_champ;

typedef struct		s_cor
{
	int				count_players;
	int				n;
	int				d;
	int				p;
	int				dump_number;
	t_champ			players[MAX_PLAYERS + 1];
	t_arena			*map;
	t_cursor		*cursor;
	t_curses		curses;
	int				checks;
	int				cursor_cnt;
	int				win_player;
	int				lev;
	int				ada;
	int				bod;
	int				spd;
	int				set_pn;
	unsigned int	live;
	unsigned int	add;
	unsigned int	sub;
	unsigned int	aff;
	unsigned int	or;
	unsigned int	xor;
	unsigned int	fork;
	unsigned int	lfork;
	unsigned int	ld;
	unsigned int	ldi;
	unsigned int	lld;
	unsigned int	lldi;
	unsigned int	st;
	unsigned int	sti;
	unsigned int	zjump;
	unsigned int	and;
}					t_cor;

void				init_struct(t_cor **cor);
int					ft_strstr_my(const char *str, const char *to_find, int pos);
void				ft_put_error(char *str);
void				parse_arg(char **av, t_cor *cor);
void				parse_magic_number(t_cor *cor, int nb, char *content);
int					convert_chr_to_int(const unsigned char *s);
void				check_magic(t_cor *cor, int nb);
int					parse_prog_name(t_cor *cor, int nb, char *content,
							int move);
int					parse_prog_size(t_cor *cor, int nb, char *content,
							int move);
void				check_prog_size(t_cor *cor, int nb);
int					parse_prog_comment(t_cor *cor, int nb, char *content,
							int move);
void				parse_program(t_cor *cor, int nb, char *content, int move);
void				init_great_war(t_cor *cor, t_cursor *curr_curs);
void				init_cursor(t_cor *cor, int i, t_cursor *next_cursor);
void				get_binary(t_cor *cor, t_cursor *cursor, unsigned link,
							int cord);
void				validate_commands(t_cursor *cursor, t_cor *cor);
void				exec(t_cor *cor, t_cursor *cursor, unsigned int cd);
void				move_cursor_with_op(t_cursor *cursor, t_cor *cor, int perm);
void				reset_cursor(t_cursor *cursor);
int					ft_fork(t_cursor *cursor, t_cor *cor);
int					lfork(t_cursor *cursor, t_cor *cor, int i, int r);
void				fill_arena(t_cor *cor);
int					ft_dir(t_cor *data, t_cursor *carr, unsigned link, int i);
char				*generate_binary(unsigned char c, t_cor *cor, int curr_i,
							int z);
int					check_arg(int n, t_cursor *cursor, int levada);
void				error_usage(void);
void				parse_flags_cor(t_cor *cor, char **av, int i);
void				check_flags(t_cor *cor);
int					convert_uns_int(unsigned n);
unsigned char		*convert_int_to_str(int nbr);
void				validate_live_zjump_fork_lfork(t_cursor *cursor);
void				validate_ld(t_cursor *cursor);
void				validate_st(t_cursor *cursor);
void				validate_add(t_cursor *cursor);
void				validate_sub(t_cursor *cursor);
void				validate_and_or_xor(t_cursor *cursor);
void				validate_ldi_lldi(t_cursor *cursor);
void				validate_sti(t_cursor *cursor);
void				validate_lld(t_cursor *cursor);
void				validate_aff(t_cursor *cursor);
int					indir_from_cell(t_cor *cor, int start);
void				put_on_arena(t_cursor *cursor, t_cor *cor,
							const unsigned char *binary, int start);
void				live(t_cursor *cursor, t_cor *cor);
void				ld(t_cursor *cursor, t_cor *cor);
void				st(t_cursor *cursor, t_cor *cor);
void				lld(t_cursor *cursor, t_cor *cor);
void				lldi(t_cursor *cursor, t_cor *cor);
void				xor(t_cursor *cursor, t_cor *cor);
void				zjump(t_cursor *cursor, t_cor *cor, int bytes);
void				ldi(t_cursor *cursor, t_cor *cor);
void				sti(t_cursor *cursor, t_cor *cor);
void				add(t_cursor *cursor, t_cor *cor);
void				sub(t_cursor *cursor, t_cor *cor);
void				and(t_cursor *cursor, t_cor *cor);
void				or(t_cursor *cursor, t_cor *cor);
int					ft_reg(t_cor *cor, t_cursor *cursor, int i, int curr_i);
void				dump_corewar(t_cor *cor);
void				check_current_cursor(t_cor *cor, t_cursor *cursor);
int					exec_function(t_cursor *cursor, t_cor *cor,
							unsigned int cd);
void				cursor_kaput(t_cor *cor, t_cursor *old, t_cursor *temp);
int					count_cursors(t_cor *data, int i);
void				decrease_cycles(t_cor *cor);
void				corewar(t_cor *cor);
void				init_ncurses(t_cor *cor);
void				draw_field(t_cor *cor);
void				sidebar(t_cor *cor);
void				init_colors(void);
void				print_player(t_cor *cor);
void				check_player_color(int pn, t_cor *cor);
void				check_cursor_color(int pn, t_cor *cor);
void				pause_game(t_cor *cor);
void				end_game(t_cor *cor);
void				print_winner(t_cor *cor);

#endif
