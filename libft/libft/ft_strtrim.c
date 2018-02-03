/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:55:38 by tshevchu          #+#    #+#             */
/*   Updated: 2016/12/09 17:20:39 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int		check(char const *s)
{
	int len;
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		len = 0;
	else
	{
		len = ft_strlen(s + i);
		while (s[i] != '\0')
			i++;
		while (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == '\n')
		{
			i--;
			j++;
		}
	}
	size = len - j;
	return (size);
}

char			*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	new = (char*)malloc(check(s) + 1);
	if (new == NULL)
		return (NULL);
	while (j < check(s))
	{
		new[j] = s[j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
