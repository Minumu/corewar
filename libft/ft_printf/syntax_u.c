/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:56:29 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 15:00:51 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		flags_wt_single_u(t_struct *record, uintmax_t n, int prec)
{
	if (record->flag_minus)
	{
		ft_unbr(record, n, prec);
		record->width = record->width - count_digits_u(record, n);
		while (record->width--)
			ft_putcharpr(' ');
		return (1);
	}
	else if (record->flag_zero && !record->flag_minus &&
			record->prec == -1)
	{
		if (record->width > count_digits_u(record, n))
		{
			while (record->width-- > count_digits_u(record, n))
				ft_putcharpr('0');
		}
		ft_unbr(record, n, prec);
		return (1);
	}
	return (0);
}

void	check_single_u(t_struct *record, uintmax_t n, int prec)
{
	if (record->width && record->prec == -1)
	{
		if (record->width <= count_digits_u(record, n))
			ft_unbr(record, n, prec);
		else if (record->width > count_digits_u(record, n) &&
				(!(flags_wt_single_u(record, n, prec))))
		{
			while (record->width-- > count_digits_u(record, n))
				ft_putcharpr(' ');
			ft_unbr(record, n, prec);
		}
	}
	else if (record->prec != -1 && !record->width)
	{
		while (record->prec-- > count_digits_u(record, n))
			ft_putcharpr('0');
		ft_unbr(record, n, prec);
	}
}

int		flags_wt_both_u(t_struct *record, uintmax_t nb, int prec)
{
	if (record->flag_minus)
	{
		record->width = record->width - record->prec;
		while (record->prec > count_digits_u(record, nb))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_unbr(record, nb, prec);
		while (record->width)
		{
			ft_putcharpr(' ');
			record->width--;
		}
		return (1);
	}
	return (0);
}

void	width_prec_u(t_struct *record, uintmax_t n, int prec)
{
	if (record->width < record->prec)
	{
		while (record->prec > count_digits_u(record, n))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_unbr(record, n, prec);
	}
	else if (record->width >= record->prec &&
			!(flags_wt_both_u(record, n, prec)))
	{
		while (record->width-- > record->prec)
			ft_putcharpr(' ');
		while (record->prec > count_digits_u(record, n))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_unbr(record, n, prec);
	}
}

void	check_both_u(t_struct *record, uintmax_t n, int prec)
{
	if (record->width && record->prec != -1)
	{
		if (record->prec > count_digits_u(record, n))
			width_prec_u(record, n, prec);
		else
		{
			if (record->width < count_digits_u(record, n))
				ft_unbr(record, n, prec);
			else if (record->width >= count_digits_u(record, n) &&
					!(flags_wt_single_u(record, n, prec)))
			{
				while (record->width-- != count_digits_u(record, n))
					ft_putcharpr(' ');
				ft_unbr(record, n, prec);
			}
		}
	}
}
