/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:13:01 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 16:09:00 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && find[j] == '\0')
		return ((char*)str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (find[j] == str[i + j] && find[j] != '\0' && (i + j) < len)
			j++;
		if (find[j] == '\0')
			return ((char*)str + i);
		i++;
	}
	return (0);
}
