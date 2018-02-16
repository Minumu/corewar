/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:01:52 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:01:53 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t i;
	size_t j;
	size_t len;
	size_t tmp;

	if (!s)
		return (0);
	i = 0;
	j = ft_strlen(s);
	tmp = j;
	if (s == 0)
		return (ft_strnew(0));
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n' || s[j] == '\0')
		j--;
	if (i == 0 && ((j + 1) == tmp))
		return (ft_strdup((char *)s));
	len = tmp - i - (tmp - j - 1);
	return (ft_strsub(s, i, len));
}
