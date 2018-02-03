/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:19:29 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/22 15:30:18 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		flags_wt_both(t_struct *record, char *str)
{
	if (record->flag_zero && !record->flag_minus)
	{
		if (record->prec <= record->width)
		{
			while (record->width-- != record->prec)
				ft_putcharpr('0');
			while (record->prec--)
				ft_putcharpr(*str++);
		}
		return (1);
	}
	else if (record->flag_minus)
	{
		if (record->prec <= record->width)
		{
			record->width = record->width - record->prec;
			while (record->prec--)
				ft_putcharpr(*str++);
			while (record->width--)
				ft_putcharpr(' ');
		}
		return (1);
	}
	return (0);
}

int		flags_wt_single(t_struct *record, char *str)
{
	if (record->flag_zero && !record->flag_minus)
	{
		if (record->width > (int)ft_strlenpr(str))
		{
			while (record->width-- != (int)ft_strlenpr(str))
				ft_putcharpr('0');
		}
		ft_putstrpr(str);
		return (1);
	}
	else if (record->flag_minus)
	{
		ft_putstrpr(str);
		if (record->width > (int)ft_strlenpr(str))
		{
			record->width = record->width - (int)ft_strlenpr(str);
			while (record->width--)
				ft_putcharpr(' ');
		}
		return (1);
	}
	return (0);
}

void	check_single(t_struct *record, char *str)
{
	if (record->prec != -1 && !record->width &&
		record->prec <= (int)ft_strlenpr(str))
	{
		while (record->prec--)
			ft_putcharpr(*str++);
	}
	else if (!record->width && record->prec > (int)ft_strlenpr(str))
		ft_putstrpr(str);
	else if (record->width && record->prec == -1 &&
			record->width > (int)ft_strlenpr(str))
	{
		if (!(flags_wt_single(record, str)))
		{
			while (record->width-- != (int)ft_strlenpr(str))
				ft_putcharpr(' ');
			ft_putstrpr(str);
		}
	}
	else if (record->width && record->prec == -1 &&
			record->width <= (int)ft_strlenpr(str))
		ft_putstrpr(str);
}

void	help_check_both(t_struct *record, char *str)
{
	if (record->width < (int)ft_strlenpr(str))
		ft_putstrpr(str);
	else if (record->width >= (int)ft_strlenpr(str) &&
			!(flags_wt_single(record, str)))
	{
		while (record->width-- != (int)ft_strlenpr(str))
			ft_putcharpr(' ');
		ft_putstrpr(str);
	}
}

void	check_both(t_struct *record, char *str)
{
	if (record->width && record->prec != -1)
	{
		if (record->prec < (int)ft_strlenpr(str))
		{
			if (record->prec <= record->width &&
				!(flags_wt_both(record, str)))
			{
				while (record->width-- != record->prec)
					ft_putcharpr(' ');
				while (record->prec--)
					ft_putcharpr(*str++);
			}
			else if (record->prec > record->width)
			{
				while (record->prec--)
					ft_putcharpr(*str++);
			}
		}
		else
			help_check_both(record, str);
	}
}
