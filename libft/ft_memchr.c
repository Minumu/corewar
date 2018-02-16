/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:51:16 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:51:17 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*src;
	int				i;

	i = 0;
	src = (unsigned char *)arr;
	while (n--)
	{
		if (src[i] == (unsigned char)c)
			return (src + i);
		i++;
	}
	return (0);
}
