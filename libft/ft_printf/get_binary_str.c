/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_binary_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 12:54:02 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 12:54:03 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_binary_str(t_saver *saver, va_list arg)
{
	char				*str;
	char				*final;
	unsigned long long	unsigned_nbr;

	unsigned_nbr = get_unsigned_number_arg(saver, arg);
	str = ft_utoa_base(unsigned_nbr, 2);
	if (saver->specifier == 'b' && saver->hash == '#' && str[0] != '0')
		final = ft_join("0b", str, SECOND);
	else
		final = str;
	if (unsigned_nbr == 0 && saver->precision == 0)
	{
		free(final);
		final = ft_strdup("");
	}
	final = add_precision(saver, final);
	final = add_min_width(saver, final);
	return (final);
}
