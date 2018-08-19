/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_print_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:24:35 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

int	ask_gnl(int fd, char **line, size_t *nb_line_ptr)
{
	static int		ret = 0;
	static ssize_t	nb_line = -1;

	nb_line += 1;
	if (nb_line_ptr)
		*nb_line_ptr = (size_t)nb_line;
	free_str(line);
	ret = get_next_line(fd, line);
	if (ret == -1)
		errno_exit();
	return (ret > 0 ? nb_line : ret);
}
