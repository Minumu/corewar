/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:21:32 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:21:40 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void		put_on_arena(t_cursor *cursor, t_cor *cor,
			const unsigned char *binary, int start)
{
	int	i;

	i = cor->lev;
	while ((cor->ada * 4) > i)
	{
		if (i == cor->lev)
			start = (cursor->cci + (start % IDX_MOD)) % MEM_SIZE;
		if (cor->lev > (cor->bod = start + i))
			cor->bod = (cor->bod + MEM_SIZE);
		if (MEM_SIZE <= cor->bod)
			cor->bod = (cor->bod % MEM_SIZE);
		cor->map[cor->bod].pn = -cursor->pln;
		cor->map[cor->bod].cell = binary[i++];
	}
}

int			indir_from_cell(t_cor *cor, int start)
{
	unsigned char	str[(cor->ada * 4)];
	int				i;

	i = -cor->ada;
	if (MEM_SIZE < start)
		start = (start % MEM_SIZE);
	while (++i < 4)
		str[i] = cor->map[start + i].cell;
	return (convert_chr_to_int(str));
}

static void	exec2(t_cor *cor, t_cursor *cursor, unsigned int cd)
{
	if (cd == cor->xor)
		xor(cursor, cor);
	if (cd == cor->zjump)
		zjump(cursor, cor, 0);
	if (cd == cor->ldi)
		ldi(cursor, cor);
	if (cd == cor->sti)
		sti(cursor, cor);
	if (cd == cor->lld)
		lld(cursor, cor);
	if (cd == cor->lldi)
		lldi(cursor, cor);
}

void		exec(t_cor *cor, t_cursor *cursor, unsigned int cd)
{
	if (cd == cor->live)
		live(cursor, cor);
	if (cd == cor->ld)
		ld(cursor, cor);
	if (cd == cor->st)
		st(cursor, cor);
	if (cd == cor->add)
		add(cursor, cor);
	if (cd == cor->sub)
		sub(cursor, cor);
	if (cd == cor->and)
		and(cursor, cor);
	if (cd == cor->or)
		or(cursor, cor);
	exec2(cor, cursor, cd);
}
