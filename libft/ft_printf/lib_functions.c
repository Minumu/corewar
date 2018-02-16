/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:46:48 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/22 15:48:58 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putcharpr(char c)
{
	write(1, &c, 1);
	g_all_count++;
}

void	ft_putstrpr(char const *s)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putcharpr(s[i]);
			i++;
		}
	}
}

size_t	ft_strlenpr(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_atoipr(const char *str)
{
	int i;
	int result;
	int f;

	i = 0;
	result = 0;
	f = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		f = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * f);
}

char	*ft_upper(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = (char)(str[i] - 32);
		i++;
	}
	return (str);
}
