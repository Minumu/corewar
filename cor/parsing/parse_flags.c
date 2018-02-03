/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:03:02 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:03:04 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	check_set_nb(t_cor *cor, char *av)
{
	int i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-')
			i++;
		if (!ft_isdigit(av[i]))
			ft_put_error("Wrong player number");
		i++;
	}
	cor->players[cor->count_players].nb_set = ft_atoi(av);
	cor->set_pn = 1;
}

void	parse_flags_cor(t_cor *cor, char **av, int i)
{
	if (ft_strequ("-n", av[i]))
		cor->n = 1;
	else if (ft_strequ("-d", av[i]))
		cor->d = 1;
	else if (cor->d == 1 && !cor->dump_number)
		cor->dump_number = (-1 * ft_atoi(av[i]));
	else if (ft_strequ("-p", av[i]))
		cor->p = 1;
	else if (cor->p == 1 && cor->players[cor->count_players].nb_set == 0)
		check_set_nb(cor, av[i]);
	else
		ft_put_error("Bad file");
}

void	check_flags(t_cor *cor)
{
	if (cor->p == 1 && !cor->set_pn)
		ft_put_error("Wrong Player Number!\n");
	else if (cor->d == 1 && !cor->dump_number)
		ft_put_error("Wrong dump Number!\n");
	if (cor->count_players == 0)
		ft_put_error("Wrong count of players\n");
}
