/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_comment_min.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:33:04 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 23:36:25 by afomenko         ###   ########.fr       */
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

void	check_name_comment_min(char **s, char *tmp2, char *str, int check)
{
	if (check > 2)
		ft_put_error("Wrong syntax in Name or Comment | 1");
	else if (check == 2)
	{
		if (ft_strlen((tmp2 = ft_strtrim(s[1]))) > 1 && tmp2[0] != ';')
			ft_put_error("Wrong syntax in Name or Comment | 2");
	}
	else if (check == 1 && str[0] == '"' && !ifspaces(s[0]))
		ft_put_error("Wrong syntax in Name or Comment | 3");
}
