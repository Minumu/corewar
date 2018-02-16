/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 19:01:55 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 23:38:09 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int			ifspaces(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

static int	count_arr(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_strlen(s[i]))
			i++;
	}
	return (i);
}

static char	*ret_name_com(char *str)
{
	int i;

	i = 0;
	if (str)
		i = (int)ft_strlen(str);
	if (i > 0)
		return (ft_strdup(str));
	return (ft_strdup(""));
}

static char	*min_check_name_comment(char **s, char *tmp)
{
	free_str(s);
	return (tmp);
}

char		*check_name_comment(char *str, int param, char *tmp, char *tmp2)
{
	int		check;
	char	**s;

	s = ft_strsplit(str, '"');
	check = count_arr(s);
	if (param == 1)
		tmp = ret_name_com(s[1]);
	else if (param == 2)
	{
		check_name_comment_min(s, tmp2, str, check);
		tmp = ret_name_com(s[0]);
	}
	else if (param == 3)
	{
		tmp = ret_name_com(s[1]);
		if (check == 3 || (check == 2 && check_empty_line(str) == 1))
			ft_put_error("Wrong syntax in Name or Comment | 4");
	}
	return (min_check_name_comment(s, tmp));
}
