/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 13:21:22 by tshevchu          #+#    #+#             */
/*   Updated: 2017/03/30 16:53:19 by tshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*record_rest(char *src)
{
	char *rec_rest;

	rec_rest = NULL;
	while (*src != '\n')
		src++;
	if (*src == '\n' && *src + 1)
		rec_rest = ft_strdup(src + 1);
	return (rec_rest);
}

char	*cut_source(char *src)
{
	char	*cut_src;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\n')
		i++;
	cut_src = (char*)malloc(sizeof(char) * i + 1);
	while (i > 0)
	{
		cut_src[j] = src[j];
		j++;
		i--;
	}
	cut_src[j] = '\0';
	return (cut_src);
}

int		check_buffer(char **line, char *buff, char **rest)
{
	char	*line_new;
	char	*cut_buff;
	int		i;

	cut_buff = NULL;
	i = 0;
	if (!*line)
		*line = ft_memalloc(1);
	if (ft_strchr(buff, '\n'))
	{
		*rest = record_rest(buff);
		cut_buff = cut_source(buff);
		line_new = ft_strjoin(*line, cut_buff);
		ft_strdel(line);
		*line = line_new;
		ft_strdel(&cut_buff);
		return (1);
	}
	line_new = ft_strjoin(*line, buff);
	ft_strdel(line);
	*line = line_new;
	return (0);
}

int		check_rest(char **line, char **rest)
{
	char	*old_rest;
	char	*cut_rest;
	int		i;

	old_rest = NULL;
	cut_rest = NULL;
	i = 0;
	if (ft_strchr(*rest, '\n'))
	{
		old_rest = (char*)malloc(ft_strlen(*rest) + 1);
		ft_strcpy(old_rest, *rest);
		cut_rest = cut_source(*rest);
		*line = ft_strdup(cut_rest);
		ft_strdel(rest);
		*rest = record_rest(old_rest);
		ft_strdel(&old_rest);
		ft_strdel(&cut_rest);
		return (1);
	}
	*line = ft_strdup(*rest);
	ft_strdel(rest);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*rest[4096];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0 || fd > 4096
		|| BUFF_SIZE > 5000000)
		return (-1);
	*line = NULL;
	if (rest[fd])
	{
		if (check_rest(line, &rest[fd]))
			return (1);
	}
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (check_buffer(line, buff, &rest[fd]))
			return (1);
	}
	rest[fd] = NULL;
	if ((*line ? ft_strlen(*line) : 0) != 0 && (ret == 0))
		return (1);
	if (ret < 0)
		return (-1);
	return (0);
}
