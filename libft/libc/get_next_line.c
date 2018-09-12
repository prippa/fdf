/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:47:04 by prippa            #+#    #+#             */
/*   Updated: 2017/11/22 17:47:18 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		gnl_sub_line(t_gnl *file, char **line)
{
	unsigned int start;

	if (!file->s[file->i])
	{
		ft_strdel(&file->s);
		return (0);
	}
	start = (unsigned int)file->i;
	while (file->s[file->i] && file->s[file->i] != '\n')
		++file->i;
	if (!(*line = ft_strsub(file->s, start, file->i - start)))
		return (-1);
	if (file->s[file->i])
		++file->i;
	return (1);
}

static int		gnl_remainder(t_gnl *file)
{
	char *tmp;

	if (!file->s)
	{
		if (!(file->s = ft_strdup("")))
			return (-1);
		return (1);
	}
	tmp = file->s;
	if (!(file->s = ft_strdup(&file->s[file->i])))
		return (-1);
	free(tmp);
	file->i = 0;
	return (1);
}

static int		gnl_read_file(t_gnl *file, char **line)
{
	ssize_t	ret;
	char	buf[BUFF_SIZE + 1];

	while ((ret = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(ft_strjoin_free(&file->s, buf, ft_strlen(file->s), ret)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	return (gnl_sub_line(file, line));
}

static t_gnl	*gnl_add_or_get_file(t_gnl **g, int fd)
{
	t_gnl *file;

	file = *g;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	if (!(file = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	file->s = NULL;
	file->i = 0;
	file->fd = fd;
	file->next = *g;
	*g = file;
	return (file);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl	*g;
	t_gnl			*curent;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	if (!(curent = gnl_add_or_get_file(&g, fd)))
		return (-1);
	if (curent->s && ft_strchr(&curent->s[curent->i], '\n'))
		return (gnl_sub_line(curent, line));
	if ((gnl_remainder(curent)) == -1)
		return (-1);
	return (gnl_read_file(curent, line));
}
