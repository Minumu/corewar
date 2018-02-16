/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir_indir_reg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:32:37 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/05 00:41:42 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int		is_register(char *str)
{
	int reg;

	reg = ft_atoi(str + 1);
	if (reg > 16)
		return (0);
	if (str == NULL)
		return (0);
	if (str[0] == REG_CHAR)
	{
		if (!ft_isdigit(str[1]))
			return (0);
	}
	else if (str[0] != REG_CHAR)
		return (0);
	if (!str[2])
		return (1);
	if (!ft_isdigit(str[2]) || str[3])
		return (0);
	return (1);
}

int		is_dir(char *str)
{
	int i;

	i = 1;
	if (str == NULL)
		return (0);
	if (str[0] == DIRECT_CHAR)
	{
		if (str[i] == '-')
			i++;
		while (str[i])
			if (!ft_isdigit(str[i++]))
				return (0);
	}
	else
		return (0);
	if (str[0] == DIRECT_CHAR && !str[1])
		return (0);
	return (1);
}

int		is_indir(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int		is_label(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == DIRECT_CHAR)
		i++;
	if (str[i] == LABEL_CHAR)
	{
		i++;
		while (str[i] && ft_strchr(LABEL_CHARS, str[i]))
			i++;
	}
	else
		return (0);
	if (str[i] != '\0')
		return (0);
	return (1);
}
