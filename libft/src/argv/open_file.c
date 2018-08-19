/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 18:37:49 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/07 18:37:49 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../../ft_library_header.h"

int	open_file(char *name)
{
	int fd;

	fd = open(name, O_RDONLY);
	return (fd > 0 ?
			fd
					:
			ft_error("error opening file !"));
}
