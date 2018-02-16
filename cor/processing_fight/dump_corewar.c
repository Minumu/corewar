/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_corewar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:07:18 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:07:21 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	print_map(t_cor *cor)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (i < MEM_SIZE)
	{
		x++;
		ft_printf("%02x ", cor->map[i].cell);
		if (x >= 64)
		{
			x = 0;
			ft_printf("\n");
		}
		i++;
	}
}

void	dump_corewar(t_cor *cor)
{
	int i;

	i = 0;
	while (i < cor->dump_number)
	{
		init_great_war(cor, cor->cursor);
		i++;
	}
	print_map(cor);
}
