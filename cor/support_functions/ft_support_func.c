/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_support_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:27:03 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:27:05 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

int		ft_strstr_my(const char *str, const char *to_find, int pos)
{
	size_t i;
	size_t step;
	size_t count;

	i = (size_t)pos;
	step = 0;
	count = 0;
	while (to_find[count])
		count++;
	if (count == 0)
		return (1);
	while (str[i])
	{
		while (to_find[step] == str[i + step])
		{
			if (step == (count - 1))
				return (1);
			step++;
		}
		step = 0;
		i++;
	}
	return (0);
}

void	ft_put_error(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

void	error_usage(void)
{
	ft_printf("Usage: ./corewar <sourcefile.cor>\n");
	ft_printf("Bonuses: \n");
	ft_printf("Set player number [-p [-number]] \n");
	ft_printf("Turn on visualisation [-n] \n");
	ft_printf("Show map on placed cycle [-d [-cycle_number]] \n");
	exit(0);
}

int		check_arg(int n, t_cursor *cursor, int levada)
{
	if (n == 1 && (cursor->atp[levada] == T_REG))
		return (1);
	if (n == 2 && (cursor->atp[levada] == T_DIR))
		return (1);
	if (n == 3 && (cursor->atp[levada] == T_IND))
		return (1);
	return (0);
}
