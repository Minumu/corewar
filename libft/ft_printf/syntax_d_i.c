/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:04:41 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 14:55:57 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		flags_wt_single_nb(t_struct *record, intmax_t n, int f, int prec)
{
	if (record->flag_minus)
	{
		ft_sign(record, n, f);
		ft_nbr(record, n, prec);
		record->width = record->width - count_digits(record, n);
		while (record->width--)
			ft_putcharpr(' ');
		return (1);
	}
	else if (record->flag_zero && !record->flag_minus &&
			record->prec == -1)
	{
		ft_sign(record, n, f);
		if (record->width > count_digits(record, n))
		{
			while (record->width-- > count_digits(record, n))
				ft_putcharpr('0');
		}
		ft_nbr(record, n, prec);
		return (1);
	}
	return (0);
}

void	check_single_nb(t_struct *record, intmax_t n, int f, int prec)
{
	if (record->width && record->prec == -1)
	{
		if (record->width <= count_digits(record, n))
		{
			ft_sign(record, n, f);
			ft_nbr(record, n, prec);
		}
		else if (record->width > count_digits(record, n) &&
				(!(flags_wt_single_nb(record, n, f, prec))))
		{
			while (record->width-- > count_digits(record, n))
				ft_putcharpr(' ');
			ft_sign(record, n, f);
			ft_nbr(record, n, prec);
		}
	}
	else if (record->prec != -1 && !record->width)
	{
		ft_sign(record, n, f);
		while (record->prec-- > count_digits(record, n))
			ft_putcharpr('0');
		ft_nbr(record, n, prec);
	}
}

int		flags_wt_both_nb(t_struct *record, intmax_t nb, int f, int prec)
{
	if (record->flag_minus)
	{
		ft_sign(record, nb, f);
		record->width = record->width - record->prec;
		while (record->prec > count_digits(record, nb))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_nbr(record, nb, prec);
		while (record->width)
		{
			ft_putcharpr(' ');
			record->width--;
		}
		return (1);
	}
	return (0);
}

void	width_prec_nb(t_struct *record, intmax_t n, int f, int prec)
{
	if (record->width < record->prec)
	{
		ft_sign(record, n, f);
		while (record->prec > count_digits(record, n))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_nbr(record, n, prec);
	}
	else if (record->width >= record->prec &&
			!(flags_wt_both_nb(record, n, f, prec)))
	{
		while (record->width-- > record->prec)
			ft_putcharpr(' ');
		ft_sign(record, n, f);
		while (record->prec > count_digits(record, n))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_nbr(record, n, prec);
	}
}

void	check_both_nb(t_struct *record, intmax_t n, int f, int prec)
{
	if (record->width && record->prec != -1)
	{
		if (record->prec > count_digits(record, n))
			width_prec_nb(record, n, f, prec);
		else
		{
			if (record->width < count_digits(record, n))
			{
				ft_sign(record, n, f);
				ft_nbr(record, n, prec);
			}
			else if (record->width >= count_digits(record, n) &&
					!(flags_wt_single_nb(record, n, f, prec)))
			{
				while (record->width-- != count_digits(record, n))
					ft_putcharpr(' ');
				ft_sign(record, n, f);
				ft_nbr(record, n, prec);
			}
		}
	}
}
