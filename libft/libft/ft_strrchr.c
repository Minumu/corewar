/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 12:52:51 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 19:03:41 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *find;

	find = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			find = (char*)s;
		s++;
	}
	if (*s == c)
		return ((char*)s);
	else
		return (find);
}
