#ifndef VIRTUALMACHINE_COR_H
#define VIRTUALMACHINE_COR_H

# include "libft/libft.h"
# include "op.h"

typedef struct		s_cursor
{
    int				player_number;
    int				index;
    int				carry;
    int				live;
    int				id;
    char			*binary;
    int             label;
    int             direct;
    int             registr;
    int             indirect;
    int				reg[1 + 16];
    int             set_number;
    t_op			op;
    struct s_cursor	*next;
}					t_cursor;

typedef struct		s_arena
{
    unsigned char	cell;
    int             cursor;

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
    t_champ        players[MAX_PLAYERS + 1];
    t_arena        *map;
    t_cursor        *cursor;
    int				nbr_live;
    int				ctd;
    int				cycle;
    int             speed;
    int             max_checks;
    int             delta;
    int             cursor_cnt;
    int             winner;
	int 			pause;
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
void    check_name(t_cor *cor, int nb);
void    create_arena(t_cor *cor);
void    init_great_war(t_cor *cor);
void    init_cursor(t_cor *cor);


void	start_ncurses(t_cor *cor);

#endif
