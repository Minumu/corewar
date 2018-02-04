/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:58:34 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:58:45 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void		init_struct(t_asm **asem)
{
	t_asm *tmp;

	tmp = (t_asm*)malloc(sizeof(t_asm));
	tmp->comment = 0;
	tmp->name = 0;
	tmp->prog_size = 0;
	tmp->commands = 0;
	tmp->print = 0;
	tmp->com = 0;
	tmp->k = 0;
	tmp->issetcomment = 0;
	tmp->issetname = 0;
	tmp->found_label = 0;
	tmp->tmp = 0;
	tmp->tmp_ska = 0;
	tmp->grace = 2;
	*asem = tmp;
}

t_commands	*init_struct_operation(void)
{
	t_commands	*commands;

	commands = (t_commands *)malloc(sizeof(t_commands));
	commands->arguments = NULL;
	commands->labels = NULL;
	commands->command_name = NULL;
	commands->index = -1;
	commands->count_args = 0;
	commands->check_end = 0;
	commands->len = 0;
	return (commands);
}
