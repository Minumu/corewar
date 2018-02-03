/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 23:04:48 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 16:07:21 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	b;
	char	a;

	i = 0;
	while (str[i] != '\0')
		i++;
	b = -1;
	while (++b < --i)
	{
		a = str[b];
		str[b] = str[i];
		str[i] = a;
	}
	return (str);
}
