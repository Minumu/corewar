/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:56:49 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 16:54:04 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		count_words(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int		world_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	size = count_words(s, c);
	arr = (char**)malloc(sizeof(*arr) * size + 1);
	if (arr == NULL)
		return (NULL);
	while (i < size && *s != '\0')
	{
		while (*s == c)
			s++;
		arr[i] = ft_strsub(s, 0, world_len(s, c));
		s = s + world_len(s, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
