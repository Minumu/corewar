/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:30:39 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/22 15:33:07 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		find_size_wchar(wchar_t n)
{
	int size;

	size = 0;
	if (n > 0 && n < 128)
		size = 1;
	else if (n > 127 && n < 2048)
		size = 2;
	else if (n > 2047 && n < 65536)
		size = 3;
	else if (n > 65535 && n < 2097152)
		size = 4;
	return (size);
}

int		where_is_index(int size)
{
	int i;

	i = 0;
	if (size == 1)
		i = 8;
	else if (size == 2)
		i = 16;
	else if (size == 3)
		i = 24;
	else if (size == 4)
		i = 32;
	return (i);
}

void	help_record(char *str, char *new, int *i, int *len)
{
	int count;

	while (*i >= 4)
	{
		count = 6;
		while (count > 0 && *len >= 0)
		{
			new[(*i)--] = str[(*len)--];
			count--;
		}
		while (count > 0 && *len < 0 && *i >= 4)
		{
			new[(*i)] = '0';
			count--;
			(*i)--;
		}
		if (*i >= 4)
		{
			new[(*i)--] = '0';
			if (*i >= 4)
				new[(*i)--] = '1';
		}
	}
}

char	*record_to_str(char *str, int size)
{
	int		len;
	char	*new;
	int		i;

	i = where_is_index(size);
	new = (char*)malloc((size_t)i + 1);
	new[i--] = '\0';
	len = (int)(ft_strlenpr(str) - 1);
	help_record(str, new, &i, &len);
	new[0] = '1';
	new[1] = (char)(size >= 2 ? '1' : '0');
	new[2] = (char)(size >= 3 ? '1' : '0');
	new[3] = (char)(size >= 4 ? '1' : '0');
	return (new);
}
