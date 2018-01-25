/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:44:01 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:44:03 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char *str)
{
	size_t				i;
	int					minus;
	long long int		res;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		res = (res * 10) + (str[i] - '0');
		if (res >= 9223372036854775807 && minus == 1)
			return (9223372036854775807);
		else if (res > 9223372036854775807 && minus == -1)
			return (0);
		i++;
	}
	return ((res * minus));
}
