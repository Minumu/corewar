/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:51:40 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:51:41 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	char *des_tmp;
	char *src_tmp;

	des_tmp = (char *)destination;
	src_tmp = (char *)source;
	if (destination == source || !n)
		return (destination);
	while (--n)
		*des_tmp++ = *src_tmp++;
	*des_tmp = *src_tmp;
	return (destination);
}
