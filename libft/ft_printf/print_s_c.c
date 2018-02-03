/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:16:18 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 15:16:39 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	char_wt_flags(t_struct *record, char c)
{
	if (record->flag_zero && !record->flag_minus &&
		record->width)
	{
		if (record->width > 0)
		{
			while (record->width - 1 != 0)
			{
				ft_putcharpr('0');
				record->width--;
			}
		}
		ft_putcharpr(c);
	}
	else if (record->flag_minus && record->width)
	{
		if (record->width > 0)
		{
			ft_putcharpr(c);
			while (record->width - 1 >= 1)
			{
				ft_putcharpr(' ');
				record->width--;
			}
		}
	}
}

void	print_char(t_struct *record, va_list ap)
{
	char c;

	if (record->type == '%')
		c = '%';
	else
		c = va_arg(ap, int);
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

void	print_string(t_struct *record, va_list ap)
{
	char	*str;
	int		i;

	i = 0;
	if (record->size == 1)
		print_ws(record, ap);
	else
	{
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			str = ft_strduppr("(null)");
			i = 1;
		}
		if (record->width || record->prec >= 0)
		{
			check_single(record, str);
			check_both(record, str);
		}
		else
			ft_putstrpr(str);
		if (i == 1)
			ft_strdelpr(&str);
	}
}
