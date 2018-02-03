/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:11:59 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:12:01 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cor.h"

int		main(int ac, char **av)
{
	t_cor *cor;

	init_struct(&cor);
	if (ac == 1)
		error_usage();
	parse_arg(av, cor);
	fill_arena(cor);
	init_cursor(cor, 0, 0);
	if (cor->n == 1)
		init_ncurses(cor);
	corewar(cor);
}
