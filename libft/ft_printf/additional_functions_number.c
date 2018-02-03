/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions_number.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:33:35 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/24 18:38:53 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		count_digits(t_struct *record, intmax_t nb)
{
	int i;

	i = 1;
	if (record->prec != -1 && nb == 0)
		i = 0;
	if (nb < 0)
		nb *= -1;
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int		is_signed(t_struct *record, intmax_t n, int f)
{
	if (record->type != 'u' && record->type != 'U')
	{
		if (record->flag_plus || n < 0 || record->flag_space)
		{
			if (record->width > 1)
				record->width = record->width - 1;
			if (n < 0)
			{
				f = 1;
				record->flag_plus = 1;
			}
		}
	}
	return (f);
}

void	ft_prefix_x(t_struct *record, char *str)
{
	if (*str || record->type == 'p')
	{
		if ((record->flag_sharp && str[0] != '0') || record->type == 'p')
		{
			if (record->type == 'x' || record->type == 'p')
			{
				ft_putcharpr('0');
				ft_putcharpr('x');
			}
			if (record->type == 'X')
			{
				ft_putcharpr('0');
				ft_putcharpr('X');
			}
		}
	}
}

void	ft_sign(t_struct *record, intmax_t n, int f)
{
	if (record->type != 'u' && record->type != 'U')
	{
		if (record->flag_plus)
		{
			if (f == 0)
				ft_putcharpr('+');
			else
				ft_putcharpr('-');
		}
		else if (record->flag_space && !record->flag_plus &&
				n >= 0)
			ft_putcharpr(' ');
	}
}

void	ft_nbr(t_struct *record, intmax_t n, int prec)
{
	intmax_t	nb;
	uintmax_t	u;

	u = n;
	nb = n;
	if (nb < 0)
		u = nb * -1;
	if (u >= 10)
		ft_nbr(record, u / 10, prec);
	if (prec == -1)
		ft_putcharpr(u % 10 + '0');
	else if (prec != -1 && n != 0)
		ft_putcharpr(u % 10 + '0');
}
