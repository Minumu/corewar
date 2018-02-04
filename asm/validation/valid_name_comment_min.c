/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_comment_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:33:04 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 15:33:08 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	check_name_and_comment(t_asm *asem)
{
	if (!asem->issetname || !asem->issetcomment)
		ft_put_error("Wrong syntax in Name or Comment");
	if (ft_strlen(asem->name) > PROG_NAME_LENGTH)
		ft_put_error("ERROR(Too large NAME)");
	if (ft_strlen(asem->comment) > COMMENT_LENGTH)
		ft_put_error("ERROR(Too large comment)");
}
