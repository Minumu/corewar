/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:57:35 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:57:37 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *destination, const char *append)
{
	char	*input;
	char	*arr;
	size_t	i;
	size_t	w;

	i = 0;
	w = 0;
	input = destination;
	arr = (char *)append;
	while (destination[i])
		i++;
	while (arr[w])
	{
		input[i] = arr[w];
		w++;
		i++;
	}
	input[i] = '\0';
	return (input);
}
