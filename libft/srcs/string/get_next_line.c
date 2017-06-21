/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:14:19 by mvillemi          #+#    #+#             */
/*   Updated: 2017/04/06 09:08:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static t_gnl	*list_init(int fd)
{
	t_gnl *list;

	list = ft_memalloc(sizeof(t_gnl));
	list->fd = fd;
	list->save = NULL;
	list->next = NULL;
	return (list);
}

static t_gnl	*add_new(t_gnl *list, int fd)
{
	t_gnl		*tmp;

	tmp = list;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = list_init(fd);
	return (tmp->next);
}

static int		read_fd(int fd, char **save)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret <= 0)
		return (ret);
	buff[ret] = '\0';
	if (!(tmp = ft_strjoin(*save, buff)))
		return (-1);
	free(*save);
	*save = tmp;
	return (ret);
}

static int		give_line(char **end, char **save, char **line, t_gnl *list)
{
	*end = ft_strchr(*save, '\0');
	if (ft_strequ(*end, *save))
		return (0);
	*line = ft_strdup(*save);
	free(*save);
	*save = ft_strdup(*end);
	ft_strclr(*end);
	if (!ft_strchr(*save, '\n'))
		list->save = NULL;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			*save;
	char			*end;
	int				ret;
	static t_gnl	*list = NULL;
	t_gnl			*tmp;

	if (fd == -1 || BUFF_SIZE <= 0 || !(line))
		return (-1);
	list || (list = list_init(fd));
	tmp = list;
	while (tmp && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
		tmp = add_new(list, fd);
	save = (tmp->save ? ft_strdup(tmp->save) : ft_strnew(BUFF_SIZE));
	while (!(end = ft_strchr(save, '\n')) || (ret -= ret))
		if ((ret = read_fd(fd, &save)) <= 0)
			return (ret < 0 ? -1 : give_line(&end, &save, line, tmp));
	*line = ft_strsub(save, 0, end - save);
	end = ft_strsub(end, 1, ft_strlen(end) - 1);
	free(save);
	while ((tmp->save && !ret && ++ret) || !(tmp->save = ft_strdup(end)))
		free(tmp->save);
	free(end);
	return (1);
}
