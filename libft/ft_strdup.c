/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:58:33 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:58:35 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *res;

	res = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!res)
		return (0);
	res = ft_strcpy(res, src);
	return (res);
}
