/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wc_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:58:29 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/26 15:08:27 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_atoi_base(char *str, int base)
{
	int power;
	int value;

	power = (int)(ft_strlenpr(str) - 1);
	value = 0;
	while (power >= 0)
	{
		value = value + ft_power(base, power) * get_nb(*str);
		power--;
		str++;
	}
	return (value);
}

char	*do_record(int size, char *str)
{
	int		j;
	int		i;
	int		k;
	char	*end;
	char	*res;

	k = 0;
	i = 0;
	res = malloc(size + 1);
	while (size > 0)
	{
		end = malloc(9);
		j = 0;
		while (j < 8)
			end[j++] = str[i++];
		end[j] = '\0';
		res[k] = (char)ft_atoi_base(end, 2);
		ft_strdelpr(&end);
		k++;
		size--;
	}
	res[k] = '\0';
	return (res);
}

char	*rec_one_wc(wchar_t n)
{
	int		size;
	char	*str;
	char	*check;
	char	*result;

	size = find_size_wchar(n);
	if (size > 1)
	{
		str = turn_to_str(2, n);
		check = record_to_str(str, size);
		ft_strdelpr(&str);
		result = do_record(size, check);
		ft_strdelpr(&check);
	}
	else
	{
		result = malloc(sizeof(size + 1));
		result[0] = (char)n;
		result[1] = '\0';
	}
	return (result);
}

void	help_print_ws(t_struct *record, char *end, wchar_t *wstr)
{
	if (record->width || record->prec >= 0)
	{
		if (record->prec != -1)
			record->prec = find_new_prec_ws(record, wstr);
		check_single(record, end);
		check_both(record, end);
	}
	else
		ft_putstrpr(end);
	ft_strdelpr(&end);
}

void	print_ws(t_struct *record, va_list ap)
{
	wchar_t	*wstr;
	char	*str;
	char	*res;
	char	*end;
	int		i;

	i = 0;
	wstr = va_arg(ap, wchar_t *);
	if (wstr == NULL)
		end = ft_strduppr("(null)");
	else
	{
		end = ft_strduppr("");
		while (wstr[i])
		{
			res = ft_strduppr(end);
			ft_strdelpr(&end);
			str = rec_one_wc(wstr[i]);
			i++;
			end = ft_strjoinpr(res, str);
			ft_strdelpr(&str);
			ft_strdelpr(&res);
		}
	}
	help_print_ws(record, end, wstr);
}
