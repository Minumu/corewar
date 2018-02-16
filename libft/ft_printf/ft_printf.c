/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:58:45 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 15:39:52 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		move_to_type(const char *s, size_t i)
{
	while (s[i] && !(find_type(s, i)))
	{
		if (find_flag(s, i))
			i = move_i(s, i);
		else if ((s[i] >= 48 && s[i] <= 57) || s[i] == '*')
		{
			i++;
			while (s[i] >= 48 && s[i] <= 57)
				i++;
		}
		else if (s[i] == '.')
		{
			i++;
			if (s[i] == '*')
				i++;
			while (s[i] >= 48 && s[i] <= 57)
				i++;
		}
		else if (find_size(s, i))
			i = move_i(s, i);
		else
			break ;
	}
	return (i);
}

void		check_type(t_struct *record, va_list ap)
{
	if (record->type == 'c' || record->type == '%')
		print_char(record, ap);
	if (record->type == 'C')
		print_char(record, ap);
	if (record->type == 'S')
		print_ws(record, ap);
	if (record->type == 's')
		print_string(record, ap);
	if (record->type == 'd' || record->type == 'i' || record->type == 'D')
		print_d_i(record, ap);
	if (record->type == 'u' || record->type == 'U')
		print_u(record, ap);
	if (record->type == 'o' || record->type == 'O')
		print_o(record, ap);
	if (record->type == 'x' || record->type == 'X')
		print_x(record, ap);
	if (record->type == 'p')
		print_p(record, ap);
}

void		check_char(t_struct *record, char c)
{
	if (record->flag_zero || record->flag_minus)
		char_wt_flags(record, c);
	else if (record->width)
	{
		if (record->width > 0)
		{
			while (record->width > 1)
			{
				ft_putcharpr(' ');
				record->width--;
			}
			ft_putcharpr(c);
		}
	}
	else
		ft_putcharpr(c);
}

void		do_printf(const char *format, va_list ap)
{
	size_t		i;
	t_struct	*p;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			p = create_struct();
			record_struct(format, i, ap, p);
			i = move_to_type(format, i);
			if (!find_type(format, i))
				check_char(p, format[i]);
			check_type(p, ap);
			free(p);
		}
		else
			ft_putcharpr(format[i]);
		i++;
	}
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;

	if (!format)
		return (-1);
	va_start(ap, format);
	do_printf(format, ap);
	va_end(ap);
	count = g_all_count;
	g_all_count = 0;
	return (count);
}
