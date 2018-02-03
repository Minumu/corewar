/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:35:22 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:47:26 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && find[j] == '\0')
		return ((char*)str);
	while (str[i] != '\0')
	{
		j = 0;
		while (find[j] == str[i + j] && find[j] != '\0')
			j++;
		if (find[j] == '\0')
			return ((char*)str + i);
		i++;
	}
	return (0);
}
