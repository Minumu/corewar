/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:57:45 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:57:47 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (str[i])
	{
		if (s[i] == ch)
			return (s + i);
		i++;
	}
	if (ch == 0)
		return (s + i);
	return (0);
}
