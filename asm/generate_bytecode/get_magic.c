/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_magic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:28:17 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:28:20 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	get_magic(t_asm *asem, unsigned int i)
{
	int k;
	int bytes;

	k = 0;
	bytes = 24;
	while (k < 4)
	{
		asem->magic[k] = (i >> bytes) & 0xFF;
		k++;
		bytes -= 8;
	}
}
