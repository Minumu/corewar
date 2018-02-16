/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 17:54:47 by tshevchu          #+#    #+#             */
/*   Updated: 2018/02/03 17:55:00 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cor.h"

void	fill_and_check_player(t_cor *cor, int nb)
{
	char	*content;
	int		skip_bytes;

	skip_bytes = 4;
	content = ft_strnew((size_t)cor->players[nb].full_prog_size);
	read(cor->players[nb].fd, content, (size_t)cor->players[nb].full_prog_size);
	parse_magic_number(cor, nb, content);
	check_magic(cor, nb);
	skip_bytes = parse_prog_name(cor, nb, content, skip_bytes) +
			skip_bytes + 4;
	skip_bytes = parse_prog_size(cor, nb, content, skip_bytes) + skip_bytes;
	check_prog_size(cor, nb);
	skip_bytes = parse_prog_comment(cor, nb, content, skip_bytes) +
			4 + skip_bytes;
	parse_program(cor, nb, content, skip_bytes);
	free(content);
}

void	parse_cor_files(t_cor *cor)
{
	int i;

	i = 0;
	while (i < cor->count_players)
	{
		fill_and_check_player(cor, i);
		i++;
	}
}

void	add_players(char *player, t_cor *cor)
{
	cor->players[cor->count_players].file_name = player;
	cor->count_players++;
	if (cor->count_players > 4)
		ft_put_error("ERROR | Too much players\n");
}

void	isset_cor_files(t_cor *cor)
{
	int		i;
	int		fd;
	off_t	size;

	i = 0;
	while (i < cor->count_players)
	{
		if ((fd = open(cor->players[i].file_name, O_RDONLY)) == -1)
			ft_put_error("Can't read source file\n");
		if ((size = lseek(fd, 0, SEEK_END)) < 0)
			ft_put_error("Bad file\n");
		lseek(fd, 0, SEEK_SET);
		cor->players[i].fd = fd;
		cor->players[i].full_prog_size = (size_t)size;
		if (!cor->players[i].nb_set)
			cor->players[i].nb = -(i + 1);
		else
			cor->players[i].nb = cor->players[i].nb_set;
		i++;
	}
}

void	parse_arg(char **av, t_cor *cor)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '-')
			parse_flags_cor(cor, av, i);
		else if (ft_strstr_my(av[i], ".cor", 0))
			add_players(av[i], cor);
		else
			ft_put_error("Bad file");
		i++;
	}
	check_flags(cor);
	isset_cor_files(cor);
	parse_cor_files(cor);
}
