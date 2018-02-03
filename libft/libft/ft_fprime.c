/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:55:16 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 21:48:44 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		isprime(int c)
{
	int i;

	i = 2;
	while (i < c)
	{
		if (c % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int				ft_fprime(char *c)
{
	int nb;
	int i;

	i = 2;
	nb = ft_atoi(c);
	while (i <= nb)
	{
		while (nb % i == 0 && isprime(i))
		{
			ft_putnbr(i);
			if (nb > i)
				ft_putchar('*');
			nb = nb / i;
		}
		i++;
	}
	return (0);
}
