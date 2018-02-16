/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:11:26 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 23:38:34 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "../libft/libft.h"
# include "op.h"

typedef struct		s_commands
{
	char			*command_name;
	char			**arguments;
	int				index;
	unsigned char	cd_str[14];
	int				len;
	unsigned int	count_args;
	int				check_end;
	char			**labels;
}					t_commands;

typedef struct		s_asm
{
	char			*file;
	unsigned int	magic[4];
	char			*name;
	unsigned int	prog_size;
	char			*comment;
	t_commands		**commands;
	t_commands		*tmp;
	int				print;
	int				com;
	int				k;
	t_commands		*tmp_ska;
	int				issetname;
	int				issetcomment;
	int				found_label;
	int				grace;
}					t_asm;

int					validation(int fd, char *line, t_asm *asem);
void				error_name(char **av, int count_arg);
void				ft_put_error(char *str);
void				error_usage(void);
void				init_struct(t_asm **asem);
char				*check_name_comment(char *str, int param, char *tmp,
								char *tmp2);
int					ft_strposlen(const char *s, int c);
int					check_type_arg(char *str);
void				get_prog_len(t_asm *content);
void				get_prog_size(t_asm *asem);
void				free_str(char **str);
void				detailed_print(t_asm *asem);
int					ft_strcchr(const char *str, char c);
t_commands			*init_struct_operation(void);
char				*remove_comments(char *str);
int					find_symbol(char *word, char find);
size_t				skip_spaces(char *s, size_t i);
void				find_name_comment(char *line, t_asm *asem, char **str_new);
size_t				get_label_name(char *s, t_commands *commands, size_t i,
							t_asm *asem);
void				parse_arg(char *s, t_commands *commands, size_t i);
int					parse_str(char *s, t_asm *asem);
void				validate_count_args(t_commands *commands);
void				validate_commands(t_commands *commands);
int					is_register(char *str);
int					is_dir(char *str);
int					is_indir(char *str);
int					is_label(char *str);
void				validate_type_args(t_commands *commands);
int					check_conformity(char *str, int type,
								t_commands *commands, int i);
void				check_exist_label(t_commands *commands, t_asm *asem);
void				validate_content(t_asm *asem);
int					check_filename(const char *str, t_asm *asem);
void				generate_bytecode(t_asm *asem);
void				write_name_to_file(t_asm *asem, int fd);
void				write_comment_to_file(t_asm *asem, int fd);
void				write_magic_to_file(t_asm *asem, int fd);
void				write_program_to_file(t_asm *asem, int fd);
void				get_magic(t_asm *asem, unsigned int i);
void				generate_hex(t_asm *asem);
void				convert_code(t_commands *commands, t_asm *asem, int a);
int					get_indir(t_asm *asem, int i, int v, int a);
int					get_t_dir(t_asm *asem, int i, int v, int a);
int					l_length(t_asm *asem, char *label, int i);
int					get_pos(t_asm *asem, char *l, int k, int o);
int					distance(t_asm *asem, int start, int index, int length);
int					get_coding_byte(t_commands *commands);
void				check_name_and_comment(t_asm *asem);
int					check_empty_line(char *str);
int					check_line(char *line);
int					check_command(char *word);
void				add_to_struct(t_asm *asem, t_commands *op);
int					check_arg(int n, int type);
int					ifspaces(const char *str);
void				check_name_comment_min(char **s,
		char *tmp2, char *str, int check);

#endif
