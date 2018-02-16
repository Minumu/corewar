/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_bytecode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 14:20:27 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/04 21:41:08 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

void	get_arg(t_commands *commands, int v, t_asm *asem, int a)
{
	int i;
	int type;

	i = 0;
	while (commands->arguments[i])
	{
		type = check_type_arg(commands->arguments[i]);
		if (check_arg(1, type))
			commands->cd_str[v++] =
					(unsigned char)ft_atoi(commands->arguments[i] + 1);
		else if (check_arg(3, type) || (check_arg(4, type)
					&& asem->commands[a]->arguments[i][0] != DIRECT_CHAR))
			v = get_indir(asem, a, v, i);
		else if (check_arg(2, type) || check_arg(4, type))
			v = get_t_dir(asem, a, v, i);
		i++;
	}
}

void	convert_code(t_commands *commands, t_asm *asem, int a)
{
	int v;

	v = 0;
	commands->cd_str[v++] = (unsigned char)g_op_tab[commands->index].opcode;
	if (g_op_tab[commands->index].octal_coding)
		commands->cd_str[v++] = (unsigned char)get_coding_byte(commands);
	get_arg(commands, v, asem, a);
}

void	generate_hex(t_asm *asem)
{
	int i;

	i = 0;
	get_prog_len(asem);
	while (asem->commands[i] && !asem->commands[i]->check_end)
	{
		convert_code(asem->commands[i], asem, i);
		i++;
	}
}

void	write_bytecode(t_asm *asem, int fd)
{
	write_magic_to_file(asem, fd);
	write_name_to_file(asem, fd);
	get_magic(asem, asem->prog_size);
	write_magic_to_file(asem, fd);
	write_comment_to_file(asem, fd);
	write_program_to_file(asem, fd);
}

void	generate_bytecode(t_asm *asem)
{
	int fd;

	fd = open(asem->file, O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
		ft_put_error("OOOPS, something went wrong");
	validate_content(asem);
	generate_hex(asem);
	get_magic(asem, COREWAR_EXEC_MAGIC);
	get_prog_size(asem);
	if (!asem->print)
	{
		write_bytecode(asem, fd);
		ft_printf("Writing output program to %s\n", asem->file);
	}
	else
		detailed_print(asem);
}
