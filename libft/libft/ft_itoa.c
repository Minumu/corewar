/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:03:47 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 16:04:13 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		ft_size(long n)
{
	size_t i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	long	nb;
	char	*arr;
	size_t	i;

	nb = n;
	arr = (char*)malloc(sizeof(*arr) * ft_size(n) + 1);
	if (!arr)
		return (NULL);
	i = ft_size(n);
	arr[i] = '\0';
	if (nb == 0)
		arr[0] = '0';
	if (nb < 0)
	{
		arr[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		arr[--i] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (arr);
}
