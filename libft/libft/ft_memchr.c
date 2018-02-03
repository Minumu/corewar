/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:45:05 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:28:26 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *s1;

	s1 = (char*)s;
	while (n > 0)
	{
		if (*s1 != (char)c)
			s1++;
		else
			return (s1);
		n--;
	}
	return (NULL);
}
