/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:37:08 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:37:12 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		count_arr(char **s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	parse_arg_min(char **args, char *str,
		t_commands *commands, size_t k)
{
	while (args[k])
	{
		str = args[k];
		commands->count_args++;
		args[k] = ft_strtrim(args[k]);
		free(str);
		k++;
	}
}

void	parse_arg(char *s, t_commands *commands, size_t i)
{
	size_t	tmp;
	char	*str;
	char	**args;
	size_t	k;

	tmp = i;
	k = 0;
	while (s[i])
		i++;
	str = ft_strsub(s, (unsigned int)tmp, i);
	args = ft_strsplit(str, SEPARATOR_CHAR);
	free(str);
	parse_arg_min(args, str, commands, k);
	if (commands->arguments)
		free(commands->arguments);
	commands->arguments = args;
}
