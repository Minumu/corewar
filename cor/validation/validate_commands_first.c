/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_commands_first.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:33:11 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 18:33:13 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	validate_live_zjump_fork_lfork(t_cursor *cursor)
{
	if (cursor->atp[0] != T_DIR)
		ft_put_error("Error | Wrong argument type");
	if (cursor->op.count_args != 1)
		ft_put_error("Error | Wrong args count");
	cursor->check = 1;
}

void	validate_ld(t_cursor *cursor)
{
	if (cursor->op.count_args == 2)
	{
		if (check_arg(1, cursor, 1))
		{
			if (check_arg(3, cursor, 0) || check_arg(2, cursor, 0))
			{
				cursor->check = 1;
				return ;
			}
		}
	}
	return ;
}

void	validate_st(t_cursor *cursor)
{
	if (cursor->op.count_args == 2)
	{
		if (check_arg(1, cursor, 0))
		{
			if (check_arg(3, cursor, 0) || check_arg(1, cursor, 0))
			{
				cursor->check = 1;
				return ;
			}
		}
	}
}

void	validate_add(t_cursor *cursor)
{
	if (cursor->op.count_args == 3)
	{
		if (check_arg(1, cursor, 0))
		{
			if (check_arg(1, cursor, 1) && check_arg(1, cursor, 2))
			{
				cursor->check = 1;
				return ;
			}
		}
	}
}

void	validate_sub(t_cursor *cursor)
{
	if (cursor->op.count_args == 3)
	{
		if (check_arg(1, cursor, 0))
		{
			if (check_arg(1, cursor, 1) && check_arg(1, cursor, 2))
			{
				cursor->check = 1;
				return ;
			}
		}
	}
}
