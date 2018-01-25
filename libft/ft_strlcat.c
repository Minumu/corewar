/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:59:34 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:59:35 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *append, size_t n)
{
	size_t i;
	size_t w;

	i = 0;
	while (destination[i] && i < n)
		i++;
	w = i;
	while (append[i - w] && i < (n - 1))
	{
		destination[i] = append[i - w];
		i++;
	}
	if (w < n)
		destination[i] = '\0';
	return (w + ft_strlen(append));
}
