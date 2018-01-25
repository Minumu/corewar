/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:00:10 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:00:12 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *append, size_t n)
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
	while (arr[w] && w < n)
	{
		input[i] = arr[w];
		w++;
		i++;
	}
	input[i] = '\0';
	return (input);
}
