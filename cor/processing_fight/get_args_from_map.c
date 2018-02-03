/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args_from_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:09:54 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:11:36 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	get_direct_min(int j, t_cursor *cursor, t_cor *cor, unsigned char *s)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (j >= MEM_SIZE)
			j = ((cursor->sbk + cursor->cci) - MEM_SIZE);
		s[i++] = cor->map[j++].cell;
	}
}

int		ft_dir(t_cor *cor, t_cursor *cursor, unsigned link, int i)
{
	unsigned char	s[4];

	cursor->atp[i] = T_DIR;
	get_direct_min((cursor->cci + cursor->sbk),
				cursor, cor, s);
	if (!link)
	{
		cursor->sbk += 4;
		return ((s[0] << 24) + (s[1] << 16) + (s[2] << 8) + s[3]);
	}
	cursor->sbk += 2;
	return ((unsigned int)((short)(s[0] << 8) + s[1]));
}

int		ft_indir(t_cor *cor, t_cursor *cursor, int i, int curr_i)
{
	cursor->atp[i] = T_IND;
	if (MEM_SIZE <= curr_i)
		curr_i = curr_i - MEM_SIZE;
	cursor->sbk += 2;
	return ((short)((cor->map[curr_i].cell << 8)
				+ cor->map[(curr_i + cor->ada)].cell));
}

int		get_arg_number(t_cursor *cursor, int *j, int *z, int n)
{
	if (n == 1 && (cursor->bnr_code[*j] == 48 && cursor->bnr_code[*z] == 49))
		return (1);
	else if (n == 2 && (cursor->bnr_code[*j] == 49 &&
			cursor->bnr_code[*z] == 48))
		return (1);
	else if (n == 3 && (cursor->bnr_code[*j] == 49 &&
			cursor->bnr_code[*z] == 49))
		return (1);
	else if (n == 4)
	{
		*j = (*j) + 2;
		*z = (*z) + 2;
	}
	return (0);
}

void	get_binary(t_cor *cor, t_cursor *cursor, unsigned link, int i)
{
	int z;
	int j;

	j = cor->lev;
	z = cor->ada;
	while (((int)cursor->op.count_args * (cor->ada + 1)) - cor->ada >= z)
	{
		if (get_arg_number(cursor, &j, &z, 1))
			cursor->op.args[i] = ft_reg(cor, cursor, i,
					(cursor->cci + cursor->sbk));
		else if (get_arg_number(cursor, &j, &z, 2))
			cursor->op.args[i] = ft_dir(cor, cursor, link, i);
		else if (get_arg_number(cursor, &j, &z, 3))
			cursor->op.args[i] = ft_indir(cor, cursor, i,
					(cursor->cci + cursor->sbk));
		i++;
		get_arg_number(cursor, &j, &z, 4);
	}
}
