/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:01:12 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:01:14 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	while (str[i] != (char)ch && i > 0)
		i--;
	if (str[i] == (char)ch)
		return ((char *)&str[i]);
	return (0);
}
