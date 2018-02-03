/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:26:40 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 15:08:59 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wctype.h>

int				g_all_count;

typedef	struct	s_struct
{
	char		type;
	int			flag_minus;
	int			flag_plus;
	int			flag_space;
	int			flag_sharp;
	int			flag_zero;
	int			width;
	int			prec;
	int			size;
}				t_struct;

int				ft_printf(const char *format, ...);
void			do_printf(const char *format, va_list ap);
void			check_type(t_struct *record, va_list ap);
size_t			move_to_type(const char *s, size_t i);
int				find_flag(const char *s, size_t i);
size_t			find_width(t_struct *record, const char *s,
size_t i, va_list ap);
size_t			find_precision(t_struct *record, const char *s,
size_t i, va_list ap);
int				find_size(const char *s, size_t i);
void			check_flag(t_struct *record, const char *s, size_t i);
int				check_size(const char *s, size_t i);
int				find_type(const char *s, size_t i);
size_t			move_i(const char *s, size_t i);
t_struct		*create_struct(void);
t_struct		*record_struct(const char *s, size_t i,
va_list ap, t_struct *record);
void			char_wt_flags(t_struct *record, char c);
void			print_char(t_struct *record, va_list ap);
int				flags_wt_single_nb(t_struct *record, intmax_t n, int f,
int prec);
void			check_single_nb(t_struct *record, intmax_t n, int f, int prec);
int				flags_wt_both_nb(t_struct *record, intmax_t nb, int f,
int prec);
void			width_prec_nb(t_struct *record, intmax_t n, int f, int prec);
void			check_both_nb(t_struct *record, intmax_t n, int f, int prec);
void			print_d_i(t_struct *record, va_list ap);
void			print_u(t_struct *record, va_list ap);
int				flags_wt_single_o_x(t_struct *record, char *str);
void			check_single_o_x(t_struct *record, char *str);
int				flags_wt_both_o_x(t_struct *record, char *str);
void			width_prec_o_x(t_struct *record, char *str);
void			check_both_o_x(t_struct *record, char *str);
void			print_o(t_struct *record, va_list ap);
void			print_x(t_struct *record, va_list ap);
void			print_p(t_struct *record, va_list ap);
char			*turn_to_str(int base, intmax_t nb);
char			*turn_to_ustr(uintmax_t base, uintmax_t nb);
int				count_digits(t_struct *record, intmax_t nb);
int				is_signed(t_struct *record, intmax_t n, int f);
void			ft_prefix_x(t_struct *record, char *str);
void			ft_sign(t_struct *record, intmax_t n, int f);
void			ft_nbr(t_struct *record, intmax_t n, int prec);
int				ft_atoi_base(char *str, int base);
int				flags_wt_both(t_struct *record, char *str);
int				flags_wt_single(t_struct *record, char *str);
void			check_single(t_struct *record, char *str);
void			help_check_both(t_struct *record, char *str);
void			check_both(t_struct *record, char *str);
void			print_string(t_struct *record, va_list ap);
char			*do_record(int size, char *str);
char			*rec_one_wc(wchar_t n);
void			print_wc(t_struct *record, va_list ap);
void			print_ws(t_struct *record, va_list ap);
int				find_size_wstr(wchar_t *wstr);
int				find_new_prec_ws(t_struct *record, wchar_t *wstr);
int				find_new_prec_wc(t_struct *record, wchar_t n);
int				find_size_wchar(wchar_t n);
int				where_is_index(int size);
void			help_record(char *str, char *new, int *i, int *len);
char			*record_to_str(char *str, int size);
intmax_t		what_is_size(t_struct *record, intmax_t n, va_list ap);
uintmax_t		what_is_size_u(t_struct *record, uintmax_t n, va_list ap);
void			ft_putcharpr(char c);
void			ft_putstrpr(char const *s);
size_t			ft_strlenpr(const char *str);
int				ft_atoipr(const char *str);
char			*ft_upper(char *str);
char			*ft_strjoinpr(char const *s1, char const *s2);
char			*ft_strduppr(const char *src);
void			ft_strdelpr(char **as);
int				get_nb(char c);
int				ft_power(int nb, int power);
void			check_char(t_struct *record, char c);
int				flags_wt_single_u(t_struct *record, uintmax_t n, int prec);
void			check_single_u(t_struct *record, uintmax_t n, int prec);
int				flags_wt_both_u(t_struct *record, uintmax_t nb, int prec);
void			width_prec_u(t_struct *record, uintmax_t n, int prec);
void			check_both_u(t_struct *record, uintmax_t n, int prec);
void			ft_unbr(t_struct *record, uintmax_t n, int prec);
int				count_digits_u(t_struct *record, uintmax_t nb);
void			help_print_ws(t_struct *record, char *end, wchar_t *wstr);

#endif
