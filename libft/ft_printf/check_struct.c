/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:01:24 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/24 16:46:59 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_flag(const char *s, size_t i)
{
	if (s[i] == '-')
		return (1);
	else if (s[i] == '+')
		return (1);
	else if (s[i] == ' ')
		return (1);
	else if (s[i] == '#')
		return (1);
	else if (s[i] == '0')
		return (1);
	return (0);
}

size_t	find_width(t_struct *record, const char *s, size_t i, va_list ap)
{
	if (s[i] >= 48 && s[i] <= 57)
	{
		record->width = ft_atoipr(s + i);
		while (s[i] >= 48 && s[i] <= 57)
			i++;
	}
	else if (s[i] == '*')
	{
		record->width = va_arg(ap, int);
		if (record->width < 0)
		{
			record->flag_minus = 1;
			record->width *= -1;
		}
		i++;
	}
	return (i);
}

size_t	find_precision(t_struct *record, const char *s,
size_t i, va_list ap)
{
	if (s[i] == '.')
		i++;
	if (s[i] >= 48 && s[i] <= 57)
	{
		record->prec = ft_atoipr(s + i);
		while (s[i] >= 48 && s[i] <= 57)
			i++;
	}
	else if (s[i] == '*')
	{
		record->prec = va_arg(ap, int);
		if (record->prec < 0)
			record->prec = -1;
		i++;
	}
	else
		record->prec = 0;
	return (i);
}

int		find_size(const char *s, size_t i)
{
	if (s[i] == 'l')
		return (1);
	else if (s[i] == 'h')
		return (1);
	else if (s[i] == 'j')
		return (1);
	else if (s[i] == 'z')
		return (1);
	return (0);
}

void	check_flag(t_struct *record, const char *s, size_t i)
{
	if (s[i] == '-')
		record->flag_minus = 1;
	else if (s[i] == '+')
		record->flag_plus = 1;
	else if (s[i] == ' ')
		record->flag_space = 1;
	else if (s[i] == '#')
		record->flag_sharp = 1;
	else if (s[i] == '0')
		record->flag_zero = 1;
}
