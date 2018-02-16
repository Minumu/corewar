/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:03:00 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/05 00:11:39 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		main(int ac, char **av)
{
	int		fd;
	t_asm	*asem;

	init_struct(&asem);
	fd = open(av[ac - 1], O_RDONLY);
	if (ac < 2)
		error_usage();
	if (!check_filename(av[ac - 1], asem) || fd < 0)
		error_name(av, ac);
	if (ft_strequ("-a", av[1]))
		asem->print = 1;
	if (!validation(fd, 0, asem))
		ft_put_error("Validation Error");
	generate_bytecode(asem);
}
