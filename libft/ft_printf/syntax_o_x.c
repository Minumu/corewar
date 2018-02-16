/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_o_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 16:36:00 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/23 18:24:12 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags_wt_single_o_x(t_struct *record, char *str)
{
	if (record->flag_minus)
	{
		ft_prefix_x(record, str);
		ft_putstrpr(str);
		record->width = record->width - (int)ft_strlenpr(str);
		while (record->width--)
			ft_putcharpr(' ');
		return (1);
	}
	else if (record->flag_zero && !record->flag_minus &&
			record->prec == -1)
	{
		ft_prefix_x(record, str);
		if (record->width > (int)ft_strlenpr(str))
		{
			while (record->width-- > (int)ft_strlenpr(str))
				ft_putcharpr('0');
		}
		ft_putstrpr(str);
		return (1);
	}
	return (0);
}

void	check_single_o_x(t_struct *record, char *str)
{
	if (record->width && record->prec == -1)
	{
		if (record->width <= (int)ft_strlenpr(str))
		{
			ft_prefix_x(record, str);
			ft_putstrpr(str);
		}
		else if (record->width > (int)ft_strlenpr(str) &&
				(!(flags_wt_single_o_x(record, str))))
		{
			while (record->width-- > (int)ft_strlenpr(str))
				ft_putcharpr(' ');
			ft_prefix_x(record, str);
			ft_putstrpr(str);
		}
	}
	else if (record->prec != -1 && !record->width)
	{
		ft_prefix_x(record, str);
		while (record->prec-- > (int)ft_strlenpr(str))
			ft_putcharpr('0');
		ft_putstrpr(str);
	}
}

int		flags_wt_both_o_x(t_struct *record, char *str)
{
	if (record->flag_minus)
	{
		ft_prefix_x(record, str);
		record->width = record->width - record->prec;
		while (record->prec > (int)ft_strlenpr(str))
		{
			ft_putcharpr('0');
			record->prec--;
		}
		ft_putstrpr(str);
		while (record->width)
		{
			ft_putcharpr(' ');
			record->width--;
		}
		return (1);
	}
	return (0);
}

void	width_prec_o_x(t_struct *record, char *str)
{
	if (record->width < record->prec)
	{
		ft_prefix_x(record, str);
		while (record->prec-- > (int)ft_strlenpr(str))
			ft_putcharpr('0');
		ft_putstrpr(str);
	}
	else if (record->width >= record->prec &&
			!(flags_wt_both_o_x(record, str)))
	{
		while (record->width-- > record->prec)
			ft_putcharpr(' ');
		ft_prefix_x(record, str);
		while (record->prec-- > (int)ft_strlenpr(str))
			ft_putcharpr('0');
		ft_putstrpr(str);
	}
}

void	check_both_o_x(t_struct *record, char *str)
{
	if (record->width && record->prec != -1)
	{
		if (record->prec > (int)ft_strlenpr(str))
			width_prec_o_x(record, str);
		else
		{
			if (record->width < (int)ft_strlenpr(str))
			{
				ft_prefix_x(record, str);
				ft_putstrpr(str);
			}
			else if (record->width >= (int)ft_strlenpr(str) &&
					!(flags_wt_single_o_x(record, str)))
			{
				while (record->width-- != (int)ft_strlenpr(str))
					ft_putcharpr(' ');
				ft_prefix_x(record, str);
				ft_putstrpr(str);
			}
		}
	}
}
