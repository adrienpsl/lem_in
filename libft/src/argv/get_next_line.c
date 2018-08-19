/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_argv_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:14:30 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

int		ft_strclen(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		read_left(t_gnl *gnl, char **line, char c)
{
	char	*tmp;
	int		len;
	int		s_len;

	len = (int)ft_strlen(gnl->str);
	if (c != 0)
	{
		s_len = ft_strclen(gnl->str, c);
		*line = ft_strsub(gnl->str, 0, s_len);
		tmp = gnl->str;
		gnl->str = ft_strsub(gnl->str, s_len + 1, len - s_len - 1);
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strsub(gnl->str, 0, len);
		gnl->str ? free(gnl->str) : 0;
		gnl->str = ft_strnew(0);
		return (1);
	}
}

int		read_line(t_gnl *gnl, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	while ((gnl->r_stt = read(gnl->fd, buf, BUFF_SIZE)) > 0)
	{
		buf[gnl->r_stt] = '\0';
		tmp = gnl->str;
		gnl->str = ft_strjoin(gnl->str, buf);
		free(tmp);
		if (ft_strclen(gnl->str, '\n') != -1)
			return (read_left(gnl, line, '\n'));
	}
	if (gnl->r_stt == 0 && (int)ft_strlen(gnl->str) > 0)
		return (read_left(gnl, line, 0));
	return (gnl->r_stt);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;
	static int		count = 0;

	if (fd < 0 || !line)
		return (-1);
	if (count == 0)
	{
		gnl.str = ft_strnew(0);
		gnl.fd = fd;
		++count;
	}
	if (ft_strclen(gnl.str, '\n') != -1)
		return (read_left(&gnl, line, '\n'));
	return (read_line(&gnl, line));
}
