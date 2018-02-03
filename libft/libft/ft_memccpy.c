/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:51:06 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:26:56 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	while (n > 0)
	{
		*dst1++ = *src1++;
		if (*(src1 - 1) == c)
			return (dst1);
		n--;
	}
	return (NULL);
}
