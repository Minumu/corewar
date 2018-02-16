/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:49:33 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:49:35 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	int		i;
	int		minus;
	long	tmp;
	char	*res;
	char	*b;

	b = "0123456789ABCDEF";
	i = 1;
	minus = 0;
	tmp = value;
	while (value /= base)
		i++;
	if (tmp < 0 && ((base == 10) || (minus = 1)))
		tmp = -tmp;
	res = (char *)malloc(sizeof(char) * ((i + minus) + 1));
	res[i] = '\0';
	while (--i >= 0)
	{
		res[i] = b[tmp % base];
		tmp /= base;
	}
	if (minus && base == 10)
		res[i] = '-';
	return (res);
}
