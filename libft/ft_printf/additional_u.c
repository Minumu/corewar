/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 14:40:59 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 14:42:00 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unbr(t_struct *record, uintmax_t n, int prec)
{
	uintmax_t	u;

	u = n;
	if (u >= 10)
		ft_nbr(record, u / 10, prec);
	if (prec == -1)
		ft_putcharpr(u % 10 + '0');
	else if (prec != -1 && n != 0)
		ft_putcharpr(u % 10 + '0');
}

int		count_digits_u(t_struct *record, uintmax_t nb)
{
	int i;

	i = 1;
	if (record->prec != -1 && nb == 0)
		i = 0;
	while (nb >= 10)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}
