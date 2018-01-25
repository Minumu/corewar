/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:51:06 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:51:07 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	char	*des_tmp;
	char	*src_tmp;
	size_t	i;

	des_tmp = (char *)destination;
	src_tmp = (char *)source;
	i = 0;
	while (i < n)
	{
		des_tmp[i] = src_tmp[i];
		if (des_tmp[i] == c)
			return (des_tmp + i + 1);
		i++;
	}
	return (0);
}
