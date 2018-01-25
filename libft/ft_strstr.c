/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:01:32 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:01:33 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *	ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t step;
	size_t count;

	i = 0;
	step = 0;
	count = 0;
	while (to_find[count])
		count++;
	if (count == 0)
		return ((char *)str);
	while (str[i])
	{
		while (to_find[step] == str[i + step])
		{
			if (step == (count - 1))
                return ((char *)str + i);
			step++;
		}
		step = 0;
		i++;
	}
	return (0);
}
