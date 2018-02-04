/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:54:49 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:54:51 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	detailed_print(t_asm *asem)
{
	int i;
	int c;
	int j;

	i = 0;
	ft_printf("Name : \"%s\"\n", asem->name);
	ft_printf("Comment : \"%s\"\n", asem->comment);
	ft_printf("Size : \"%d bytes\"\n", asem->prog_size);
	while (asem->commands[i])
	{
		j = 0;
		while (asem->commands[i]->labels && asem->commands[i]->labels[j])
			ft_printf("%s:\n", asem->commands[i]->labels[j++]);
		ft_printf("\t\t%s\t->\t", asem->commands[i]->command_name);
		j = 0;
		while (asem->commands[i]->arguments[j] && asem->commands[i]->arguments)
			ft_printf("'%s'", asem->commands[i]->arguments[j++]);
		c = 0;
		ft_printf("\t\t");
		while (c < 8)
			ft_printf("[%02x]", asem->commands[i]->cd_str[c++]);
		i++;
		ft_printf("\n");
	}
}
