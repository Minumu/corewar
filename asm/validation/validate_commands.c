/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:36:32 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 15:36:34 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	validate_commands(t_commands *commands)
{
	int i;

	i = 0;
	while (i < OP_COUNT)
	{
		if (ft_strequ(commands->command_name, g_op_tab[i].name))
		{
			commands->index = i;
			break ;
		}
		i++;
	}
}
