/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:52:36 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:52:38 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	char	*des;
	char	*src;
	size_t	i;

	i = -1;
	src = (char *)source;
	des = (char *)destination;
	if (n)
	{
		if (src < des)
		{
			while ((int)(--n) >= 0)
				*(des + n) = *(src + n);
		}
		else
		{
			while (++i < n)
				*(des + i) = *(src + i);
		}
	}
	return (des);
}
