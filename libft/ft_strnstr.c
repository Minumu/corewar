/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:01:03 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:01:04 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (str[i] && (i < n))
	{
		j = 0;
		while ((str[i + j] == to_find[j]) && str[i + j] && ((i + j) < n))
			j++;
		if (to_find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
