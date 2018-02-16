/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:12:54 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/24 15:18:31 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_size(const char *s, size_t i)
{
	int size;

	size = 0;
	if (s[i] == 'l' && s[i + 1] != 'l')
		size = 1;
	else if (s[i] == 'l' && s[i + 1] == 'l')
		size = 2;
	else if (s[i] == 'h' && s[i + 1] != 'h')
		size = 3;
	else if (s[i] == 'h' && s[i + 1] == 'h')
		size = 4;
	else if (s[i] == 'j')
		size = 5;
	else if (s[i] == 'z')
		size = 6;
	return (size);
}

size_t		move_i(const char *s, size_t i)
{
	if (find_flag(s, i))
	{
		i++;
		return (i);
	}
	if (find_size(s, i))
	{
		while (find_size(s, i))
			i++;
		return (i);
	}
	return (i);
}

int			find_type(const char *s, size_t i)
{
	if (s[i] == 's' || s[i] == 'S')
		return (1);
	else if (s[i] == 'p' || s[i] == '%')
		return (1);
	else if (s[i] == 'd' || s[i] == 'D')
		return (1);
	else if (s[i] == 'i')
		return (1);
	else if (s[i] == 'o' || s[i] == 'O')
		return (1);
	else if (s[i] == 'u' || s[i] == 'U')
		return (1);
	else if (s[i] == 'x' || s[i] == 'X')
		return (1);
	else if (s[i] == 'c' || s[i] == 'C')
		return (1);
	return (0);
}

t_struct	*create_struct(void)
{
	t_struct *empty;

	empty = malloc(sizeof(t_struct));
	empty->type = '0';
	empty->flag_minus = 0;
	empty->flag_plus = 0;
	empty->flag_space = 0;
	empty->flag_sharp = 0;
	empty->flag_zero = 0;
	empty->size = 0;
	empty->prec = -1;
	empty->width = 0;
	return (empty);
}

t_struct	*record_struct(const char *s, size_t i, va_list ap,
t_struct *record)
{
	while (!(find_type(s, i)) && s[i])
	{
		if (find_flag(s, i))
		{
			check_flag(record, s, i);
			i = move_i(s, i);
		}
		else if ((s[i] >= 48 && s[i] <= 57) || s[i] == '*')
			i = find_width(record, s, i, ap);
		else if (s[i] == '.')
			i = find_precision(record, s, i, ap);
		else if (find_size(s, i))
		{
			record->size = check_size(s, i);
			i = move_i(s, i);
		}
		else
			break ;
	}
	if (find_type(s, i))
		record->type = s[i];
	return (record);
}
