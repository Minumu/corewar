/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:51:00 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:51:02 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	check_magic(t_cor *cor, int nb)
{
	if (cor->players[nb].magic != COREWAR_EXEC_MAGIC)
		ft_put_error("ERROR | Wrong magic number");
}

void	check_prog_size(t_cor *cor, int nb)
{
	if (cor->players[nb].prog_size > CHAMP_MAX_SIZE)
		ft_put_error("Size too large");
}
