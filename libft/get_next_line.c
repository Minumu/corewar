/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afomenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:02:30 by afomenko          #+#    #+#             */
/*   Updated: 2017/12/13 13:02:43 by afomenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft.h"

static int		read_file(int fd, t_gnl *list)
{
	ssize_t	size;
	char	buffer[BUFF_SIZE + 1];
	char	*result;
	char	*tmp;

	result = ft_strdup("");
	while ((size = read(fd, buffer, BUFF_SIZE)))
	{
		if (size == -1)
			return (0);
		buffer[size] = '\0';
		tmp = result;
		result = ft_strjoin(result, buffer);
		free(tmp);
	}
	list->content = result;
	return (1);
}

static int		count_str(t_gnl *g)
{
	size_t	i;
	int		z;

	i = 0;
	z = 0;
	while (g->content[i] != '\0')
	{
		if (g->content[i] == '\n' || g->content[i + 1] == '\0')
			z++;
		i++;
	}
	return (z);
}

static void		ft_line(char **line, t_gnl *g, size_t i, size_t char_count)
{
	int		n_str;

	n_str = 0;
	while (g->content[i])
	{
		if (g->content[i] == '\n' || g->content[i + 1] == '\0')
		{
			if (g->content[i + 1] == '\0' && g->content[i] != '\n')
			{
				char_count++;
				i++;
			}
			if (n_str == g->line_num)
			{
				*line = ft_strsub(g->content, (i - char_count), char_count);
				g->line_num += 1;
				break ;
			}
			char_count = 0;
			n_str++;
		}
		else
			char_count++;
		i++;
	}
}

static t_gnl	*get_fd_list(int fd, t_gnl **list, int *new)
{
	t_gnl *test;
	t_gnl *tmp;
	t_gnl *find;

	find = *list;
	while (find)
	{
		if (find->fd == fd)
			return (find);
		find = find->next;
	}
	free(find);
	if (!(test = (t_gnl*)malloc(sizeof(t_gnl))))
		return (0);
	*new = 1;
	test->line_num = 0;
	test->fd = fd;
	test->content = NULL;
	test->next = 0;
	tmp = test;
	tmp->next = *list;
	*list = tmp;
	return (test);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*all;
	t_gnl			*list;
	int				new;

	new = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!(list = get_fd_list(fd, &all, &new)))
		return (-1);
	if (new)
		if (!read_file(fd, list))
			return (-1);
	if (list->fd == fd)
	{
		if (count_str(list) == list->line_num)
			return (0);
		ft_line(line, list, 0, 0);
	}
	return (1);
}
