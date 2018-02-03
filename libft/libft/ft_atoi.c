/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:39:47 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 20:26:43 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int result;
	int f;

	i = 0;
	result = 0;
	f = 1;
	while (str[i] == ' ' || (str[i] >= 0 && str[i] <= 31))
		i++;
	if (str[i] == 45)
		f = -1;
	if (str[i] == 43 || str[i] == 45)
		i++;
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * f);
}
