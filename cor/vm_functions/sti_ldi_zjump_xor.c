/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti_ldi_zjump_xor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:54:19 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:54:52 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	xor(t_cursor *cursor, t_cor *cor)
{
	int i;
	int s[(cor->ada * 2)];

	i = 0;
	while (i < (cor->ada * 2))
	{
		if (check_arg(1, cursor, i))
			s[i] = cursor->reg[cursor->op.args[i]];
		else if (check_arg(2, cursor, i))
			s[i] = cursor->op.args[i];
		else if (check_arg(3, cursor, i))
			s[i] = indir_from_cell(cor,
				(cursor->cci + cursor->op.args[i]));
		i++;
	}
	cursor->reg[cursor->op.args[2]] = s[cor->lev] ^ s[cor->ada];
	if (cursor->reg[cursor->op.args[2]] == cor->lev)
		cursor->carry = cor->ada;
	else
		cursor->carry = cor->lev;
}

void	zjump(t_cursor *cursor, t_cor *cor, int bytes)
{
	if (cursor->carry)
	{
		bytes = cursor->op.args[cor->lev] % IDX_MOD;
		cursor->sbk = bytes;
	}
}

void	ldi(t_cursor *cursor, t_cor *cor)
{
	int k;
	int s[(cor->ada * 2)];

	if (check_arg(1, cursor, cor->lev))
		s[cor->lev] = cursor->reg[cursor->op.args[cor->lev]];
	else if (check_arg(2, cursor, cor->lev))
		s[cor->lev] = cursor->op.args[cor->lev];
	else if (check_arg(3, cursor, cor->lev))
		s[cor->lev] =
				indir_from_cell(cor, cursor->cci
				+ (cursor->cci
				+ (cursor->op.args[cor->lev] % IDX_MOD)));
	if (check_arg(1, cursor, cor->ada))
		s[cor->ada] = cursor->reg[cursor->op.args[cor->ada]];
	else if (check_arg(2, cursor, cor->ada))
		s[cor->ada] = cursor->op.args[cor->ada];
	k = s[cor->lev] + s[cor->ada];
	k = cursor->cci + (k % IDX_MOD);
	cursor->reg[cursor->op.args[2]] = indir_from_cell(cor, k);
}

void	sti(t_cursor *cursor, t_cor *cor)
{
	int				k;
	int				s[(cor->ada * 2)];
	unsigned char	*binary;

	if (check_arg(1, cursor, cor->ada))
		s[cor->lev] = cursor->reg[cursor->op.args[cor->ada]];
	else if (check_arg(2, cursor, cor->ada))
		s[cor->lev] = cursor->op.args[cor->ada];
	else if (check_arg(3, cursor, cor->ada))
		s[cor->lev] = indir_from_cell(cor,
					cursor->cci +
					(cursor->op.args[cor->lev] % IDX_MOD));
	if (check_arg(1, cursor, 2))
		s[cor->ada] = cursor->reg[cursor->op.args[2]];
	else if (check_arg(2, cursor, 2))
		s[cor->ada] = cursor->op.args[2];
	k = s[cor->lev] + s[cor->ada];
	binary = convert_int_to_str(cursor->reg[cursor->op.args[cor->lev]]);
	put_on_arena(cursor, cor, binary, k);
	free(binary);
}
