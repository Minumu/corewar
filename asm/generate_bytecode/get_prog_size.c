/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prog_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:30:22 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:30:24 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	get_command_size(int comm, t_asm *asem)
{
	int j;
	int	type;

	j = 0;
	while (asem->commands[comm]->arguments[j])
	{
		type = check_type_arg(asem->commands[comm]->arguments[j]);
		if (check_arg(3, type)
			|| (check_arg(4, type)
				&& asem->commands[comm]->arguments[j][0] != DIRECT_CHAR))
			asem->commands[comm]->len += asem->grace;
		else if (check_arg(1, type))
			asem->commands[comm]->len += (asem->grace - 1);
		else if (check_arg(2, type) || check_arg(4, type))
		{
			asem->commands[comm]->len += (asem->grace * 2);
			if (g_op_tab[asem->commands[comm]->index].label_size)
				asem->commands[comm]->len -= asem->grace;
		}
		j++;
	}
}

void	get_prog_len(t_asm *asem)
{
	int i;

	i = 0;
	while (asem->commands[i])
	{
		asem->commands[i]->len = (asem->grace - 1);
		if (g_op_tab[asem->commands[i]->index].octal_coding)
			asem->commands[i]->len += (asem->grace - 1);
		get_command_size(i, asem);
		i++;
	}
}

void	get_prog_size(t_asm *asem)
{
	int i;

	i = 0;
	while (asem->commands[i] && !asem->commands[i]->check_end)
	{
		asem->prog_size += asem->commands[i]->len;
		i++;
	}
}
