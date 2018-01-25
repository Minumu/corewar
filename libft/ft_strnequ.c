/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:00:45 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:00:47 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (str1 && str2)
	{
		while (i < n)
		{
			if (str1[i] == '\0' && str2[i] == '\0')
				return (1);
			if (str1[i] != str2[i])
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}
