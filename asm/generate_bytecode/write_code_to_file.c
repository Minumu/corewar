/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code_to_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:34:41 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 14:34:43 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	write_name_to_file(t_asm *asem, int fd)
{
	int i;

	i = (int)ft_strlen(asem->name);
	write(fd, asem->name, (size_t)i);
	while (i < PROG_NAME_LENGTH + 4)
	{
		write(fd, "\0", 1);
		i++;
	}
}

void	write_comment_to_file(t_asm *asem, int fd)
{
	int i;

	i = (int)ft_strlen(asem->comment);
	write(fd, asem->comment, (size_t)i);
	while (i < COMMENT_LENGTH + 4)
	{
		write(fd, "\0", 1);
		i++;
	}
}

void	write_magic_to_file(t_asm *asem, int fd)
{
	int i;

	i = 0;
	while (i < 4)
	{
		write(fd, &asem->magic[i], 1);
		i++;
	}
}

void	write_program_to_file(t_asm *asem, int fd)
{
	int i;

	i = 0;
	while (asem->commands[i] && !asem->commands[i]->check_end)
	{
		write(fd, asem->commands[i]->cd_str, (unsigned)asem->commands[i]->len);
		i++;
	}
}
