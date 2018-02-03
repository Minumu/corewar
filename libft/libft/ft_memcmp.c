/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:12:16 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 15:33:42 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ss1;
	const unsigned char *ss2;

	ss1 = s1;
	ss2 = s2;
	while (n > 0)
	{
		if (*ss1 == *ss2)
		{
			ss1++;
			ss2++;
		}
		else
			return (*ss1 - *ss2);
		n--;
	}
	return (0);
}
