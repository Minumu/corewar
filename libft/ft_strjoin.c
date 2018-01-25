/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:59:24 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:59:25 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	z;
	char	*str;

	i = 0;
	z = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (0);
	while (s1[z])
	{
		str[i] = s1[z];
		z++;
		i++;
	}
	z = 0;
	while (s2[z])
	{
		str[i] = s2[z];
		z++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
