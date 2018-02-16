/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_cursor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:17:37 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:17:39 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	cursor_kaput(t_cor *cor, t_cursor *old, t_cursor *temp)
{
	t_cursor *now;

	if (!cor->cursor || !old)
		return ;
	now = cor->cursor->next;
	old->live = cor->lev;
	while (now)
	{
		if (!now->live)
		{
			temp = now;
			old->next = now->next;
			now = old;
			free(temp);
		}
		old = now;
		now->live = cor->lev;
		now = now->next;
	}
}

int		exec_function(t_cursor *cursor, t_cor *cor, unsigned int cd)
{
	if (cd == cor->fork || cd == cor->lfork)
	{
		move_cursor_with_op(cursor, cor, cor->lev);
		if (cd == cor->fork && cursor->check == cor->ada)
			return (ft_fork(cursor, cor));
		else
			return (lfork(cursor, cor, 0, 0));
	}
	else if (cursor->check == cor->ada)
		exec(cor, cursor, cd);
	move_cursor_with_op(cursor, cor, cor->lev);
	return (cor->lev);
}
