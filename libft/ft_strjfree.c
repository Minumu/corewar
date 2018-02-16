/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:36:17 by afomenko          #+#    #+#             */
/*   Updated: 2018/02/05 15:38:03 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjfree(char *s1, char *s2, t_del str)
{
	char	*res;
	int		i;
	int		j;
	int		len;

	len = (int)(ft_strlen(s1) + ft_strlen(s2));
	if (!s1 || !s2)
		return (0);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	if (str == 2 || str == 0)
		free(s1);
	if (str == 2 || str == 1)
		free(s2);
	return (res);
}
