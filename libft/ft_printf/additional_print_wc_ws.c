/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_print_wc_ws.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 15:41:56 by tshevchu          #+#    #+#             */
/*   Updated: 2017/05/22 15:43:32 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		find_size_wstr(wchar_t *wstr)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (wstr[i])
	{
		size = size + find_size_wchar(wstr[i]);
		i++;
	}
	return (size);
}

int		find_new_prec_ws(t_struct *record, wchar_t *wstr)
{
	int size;
	int i;
	int count;
	int prec;

	i = 0;
	size = find_size_wstr(wstr);
	prec = 0;
	if (record->prec != -1 && record->prec < size)
	{
		count = 1;
		while (count > 0)
		{
			count = record->prec - find_size_wchar(wstr[i]);
			if (count >= 0)
			{
				prec = prec + find_size_wchar(wstr[i]);
				record->prec = record->prec - find_size_wchar(wstr[i]);
			}
			i++;
		}
	}
	else
		prec = record->prec;
	return (prec);
}

int		find_new_prec_wc(t_struct *record, wchar_t n)
{
	int size;
	int prec;

	size = find_size_wchar(n);
	if (record->prec != -1 && record->prec < size)
		prec = size;
	else
		prec = record->prec;
	return (prec);
}
