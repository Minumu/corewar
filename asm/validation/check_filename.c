/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filename.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:24:41 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 15:24:43 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		check_filename(const char *str, t_asm *asem)
{
	int		i;
	int		k;
	char	*new_file;
	char	*sub_old;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == '.')
			k = i;
		i++;
	}
	if ((str[k + 1]) != 's' || k == 0)
		return (0);
	sub_old = ft_strsub(str, 0, (size_t)k);
	new_file = ft_strjfree(sub_old, ".cor", FIRST);
	asem->file = new_file;
	return (1);
}
