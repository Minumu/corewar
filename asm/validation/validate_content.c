/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:37:29 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/05 00:26:01 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	validate_all_content(t_asm *asem, int i)
{
	validate_commands(asem->commands[i]);
	validate_count_args(asem->commands[i]);
	validate_type_args(asem->commands[i]);
	check_exist_label(asem->commands[i], asem);
}

void	validate_content(t_asm *asem)
{
	int i;

	i = 0;
	if (asem->comment == NULL && asem->commands == NULL)
		ft_put_error("Syntax Error in comment");
	while (asem->commands[i])
	{
		validate_all_content(asem, i);
		if (asem->commands[i]->index == -1)
		{
			ft_printf("***--->[%s]<---***\n", asem->commands[i]->command_name);
			ft_put_error("Invalid instruction");
		}
		i++;
	}
}
