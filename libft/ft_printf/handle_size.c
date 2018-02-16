/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:43:51 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 14:47:43 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*turn_to_str(int base, intmax_t nb)
{
	char		*arr;
	char		*str;
	int			len;
	intmax_t	n;

	arr = "0123456789abcdef";
	len = 1;
	n = nb;
	while (nb >= base)
	{
		len++;
		nb = nb / base;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = arr[n % base];
		n = n / base;
		len--;
	}
	return (str);
}

char		*turn_to_ustr(uintmax_t base, uintmax_t nb)
{
	char		*arr;
	char		*str;
	int			len;
	uintmax_t	n;

	arr = "0123456789abcdef";
	len = 1;
	n = nb;
	while (nb >= base)
	{
		len++;
		nb = nb / base;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = arr[n % base];
		n = n / base;
		len--;
	}
	return (str);
}

intmax_t	what_is_size(t_struct *record, intmax_t n, va_list ap)
{
	if (record->type == 'D')
		n = va_arg(ap, long int);
	else
	{
		if (record->size == 0)
			n = va_arg(ap, int);
		else if (record->size == 1)
			n = va_arg(ap, long int);
		else if (record->size == 2)
			n = va_arg(ap, long long int);
		else if (record->size == 3)
			n = (short int)va_arg(ap, int);
		else if (record->size == 4)
			n = (char)va_arg(ap, int);
		else if (record->size == 5)
			n = va_arg(ap, intmax_t);
		else if (record->size == 6)
			n = va_arg(ap, size_t);
	}
	return (n);
}

uintmax_t	what_is_size_u(t_struct *record, uintmax_t n, va_list ap)
{
	if (record->type == 'U' || record->type == 'O')
		n = va_arg(ap, unsigned long int);
	else
	{
		if (record->size == 0)
			n = va_arg(ap, unsigned int);
		else if (record->size == 1)
			n = va_arg(ap, unsigned long int);
		else if (record->size == 2)
			n = va_arg(ap, unsigned long long int);
		else if (record->size == 3)
			n = (unsigned short int)va_arg(ap, unsigned int);
		else if (record->size == 4)
			n = (unsigned char)va_arg(ap, unsigned int);
		else if (record->size == 5)
			n = va_arg(ap, uintmax_t);
		else if (record->size == 6)
			n = va_arg(ap, size_t);
	}
	return (n);
}
