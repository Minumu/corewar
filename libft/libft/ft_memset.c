/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:05:38 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:24:39 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char *s1;

	s1 = s;
	while (len > 0)
	{
		*s1 = (unsigned char)c;
		s1++;
		len--;
	}
	return (s);
}
