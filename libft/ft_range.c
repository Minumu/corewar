/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:57:12 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:57:15 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *unswer;

	i = 0;
	if (max <= min)
		return (0);
	unswer = (int *)malloc(sizeof(int) * ((max - min) + 1));
	while (i < (max - min))
	{
		unswer[i] = min + i;
		i++;
	}
	return (unswer);
}
