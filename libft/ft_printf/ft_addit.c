/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:53:14 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:53:15 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_write(int fildes, const void *buf, size_t nbyte)
{
	g_count += write(fildes, buf, nbyte);
}

void		ft_put_char(const char c)
{
	ft_write(1, &c, 1);
}

void		ft_put_string(const char *str)
{
	if (!str)
		return ;
	ft_write(1, str, ft_strlen(str));
}

char		*ft_lower(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char		*ft_utoa_base(unsigned long long value, int base)
{
	int					i;
	unsigned long long	tmp;
	char				*res;
	char				*b;

	b = "0123456789ABCDEF";
	i = 1;
	tmp = value;
	while (value /= base)
		i++;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	while (--i >= 0)
	{
		res[i] = b[tmp % base];
		tmp /= base;
	}
	return (res);
}
