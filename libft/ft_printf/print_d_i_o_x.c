/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_i_o_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:52:42 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 15:12:02 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d_i(t_struct *record, va_list ap)
{
	intmax_t	n;
	int			f;
	int			prec;

	f = 0;
	n = 0;
	prec = record->prec;
	n = what_is_size(record, n, ap);
	if (record->prec == 0 && n == 0)
		prec = 0;
	if (record->width || record->prec != -1)
	{
		f = is_signed(record, n, f);
		check_single_nb(record, n, f, prec);
		check_both_nb(record, n, f, prec);
	}
	else if (record->prec == -1 || record->prec > 0)
	{
		f = is_signed(record, n, f);
		ft_sign(record, n, f);
		ft_nbr(record, n, prec);
	}
}

void	print_u(t_struct *record, va_list ap)
{
	uintmax_t	n;
	int			prec;

	prec = record->prec;
	n = 0;
	n = what_is_size_u(record, n, ap);
	if (record->width || record->prec != -1)
	{
		check_single_u(record, n, prec);
		check_both_u(record, n, prec);
	}
	else if (record->prec == -1 || record->prec > 0)
		ft_unbr(record, n, prec);
}

void	print_o(t_struct *record, va_list ap)
{
	uintmax_t	n;
	char		*str;
	char		*new;

	n = 0;
	n = what_is_size_u(record, n, ap);
	if (n == 0 && record->prec == 0 && !record->flag_sharp)
		str = ft_strduppr("");
	else
		str = turn_to_ustr(8, n);
	if (record->flag_sharp && str[0] != '0')
	{
		new = ft_strjoinpr("0", str);
		ft_strdelpr(&str);
	}
	else
		new = str;
	if (record->width || record->prec != -1)
	{
		check_single_o_x(record, new);
		check_both_o_x(record, new);
	}
	else
		ft_putstrpr(new);
	ft_strdelpr(&new);
}

void	print_x(t_struct *record, va_list ap)
{
	uintmax_t	n;
	char		*str;

	n = 0;
	n = what_is_size_u(record, n, ap);
	if (n == 0 && record->prec == 0)
		str = ft_strduppr("");
	else
		str = turn_to_ustr(16, n);
	if (record->type == 'X')
		str = ft_upper(str);
	if (record->flag_sharp && record->width > 2)
		record->width = record->width - 2;
	if (record->width || record->prec != -1)
	{
		check_single_o_x(record, str);
		check_both_o_x(record, str);
	}
	else
	{
		ft_prefix_x(record, str);
		ft_putstrpr(str);
	}
	ft_strdelpr(&str);
}

void	print_p(t_struct *record, va_list ap)
{
	uintmax_t	p;
	char		*str;

	p = (uintmax_t)va_arg(ap, void *);
	if (p == 0 && record->prec == 0)
		str = ft_strduppr("");
	else
		str = turn_to_ustr(16, p);
	if (record->width > 2)
		record->width = record->width - 2;
	if (record->width || record->prec != -1)
	{
		check_single_o_x(record, str);
		check_both_o_x(record, str);
	}
	else
	{
		ft_prefix_x(record, str);
		ft_putstrpr(str);
	}
	ft_strdelpr(&str);
}
