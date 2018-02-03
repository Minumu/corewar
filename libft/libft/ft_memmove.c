/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:02:21 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:27:38 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst1;
	const char	*src1;

	dst1 = dst;
	src1 = src;
	if (dst1 <= src1)
		ft_memcpy(dst1, src1, len);
	else
	{
		dst1 = dst1 + len;
		src1 = src1 + len;
		while (len > 0)
		{
			*(--dst1) = *(--src1);
			len--;
		}
	}
	return (dst);
}
