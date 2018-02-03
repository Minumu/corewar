/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_commands_main.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:38:10 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:38:13 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

static void	validate_commands2(t_cursor *cursor, t_cor *cor)
{
	if (cursor->op.opcode == cor->ldi
		|| cursor->op.opcode == cor->lldi)
		validate_ldi_lldi(cursor);
	if (cursor->op.opcode == cor->sti)
		validate_sti(cursor);
	if (cursor->op.opcode == cor->lld)
		validate_lld(cursor);
	if (cursor->op.opcode == cor->aff)
		validate_aff(cursor);
}

void		validate_commands(t_cursor *cursor, t_cor *cor)
{
	if (cursor->op.opcode == cor->live
		|| cursor->op.opcode == cor->zjump
		|| cursor->op.opcode == cor->fork
		|| cursor->op.opcode == cor->lfork)
		validate_live_zjump_fork_lfork(cursor);
	if (cursor->op.opcode == cor->ld)
		validate_ld(cursor);
	if (cursor->op.opcode == cor->st)
		validate_st(cursor);
	if (cursor->op.opcode == cor->add)
		validate_add(cursor);
	if (cursor->op.opcode == cor->sub)
		validate_sub(cursor);
	if (cursor->op.opcode == cor->and
		|| cursor->op.opcode == cor->or
		|| cursor->op.opcode == cor->xor)
		validate_and_or_xor(cursor);
	validate_commands2(cursor, cor);
}
