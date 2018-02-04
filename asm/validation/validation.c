/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 15:41:48 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 15:41:51 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static char	*convert_str(char *str)
{
	int		i;
	int		k;
	int		count;
	char	*new_str;

	i = 0;
	k = 0;
	count = (int)ft_strlen(str);
	new_str = malloc(sizeof(char) * count + 1);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
		{
			new_str[k] = str[i];
			i++;
			k++;
		}
		if (str[i] == '\"')
			break ;
	}
	new_str[k] = '\0';
	return (new_str);
}

int			check_command(char *word)
{
	char **s;
	char *str;

	if (word[0] == '\0' || word[0] == '\"')
		return (0);
	str = convert_str(word);
	s = ft_strsplit(str, '\"');
	free(str);
	if (find_symbol(word, '.'))
	{
		if (ft_strequ(s[0], NAME_CMD_STRING))
		{
			free_str(s);
			return (1);
		}
		else if (ft_strequ(s[0], COMMENT_CMD_STRING))
		{
			free_str(s);
			return (2);
		}
		else
			ft_put_error("Syntax error in name or comment");
	}
	free_str(s);
	return (3);
}

int			check_line(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (ft_isalpha(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int			validation(int fd, char *line, t_asm *asem)
{
	char *str;
	char *str_new;

	str_new = 0;
	while (get_next_line(fd, &line))
	{
		str = remove_comments(line);
		if (!asem->k)
			asem->com = check_command(str);
		if (!asem->k && (asem->com == 0 || !check_line(line)))
			;
		else if (asem->com == 1 || asem->com == 2 || asem->k == 1)
			find_name_comment(line, asem, &str_new);
		else if (asem->com == 3 && asem->k != 1)
		{
			check_name_and_comment(asem);
			parse_str(str, asem);
		}
		if (line[0] != '\n')
			free(line);
	}
	if (asem->found_label == 1 && (asem->tmp_ska->check_end = 1))
		add_to_struct(asem, asem->tmp_ska);
	return (1);
}
