/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_functions2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:49:17 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/22 15:51:36 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_strjoinpr(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = (char*)malloc(ft_strlenpr(s1) + ft_strlenpr(s2) + 1);
	if (new == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strduppr(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*str;

	src_len = ft_strlenpr(src);
	str = (char*)malloc(sizeof(*str) * (src_len + 1));
	if (str)
	{
		i = 0;
		while (i < src_len)
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}

void	ft_strdelpr(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
}

int		get_nb(char c)
{
	return (c - '0');
}

int		ft_power(int nb, int power)
{
	int result;

	result = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		result = result * nb;
		power--;
	}
	return (result);
}
