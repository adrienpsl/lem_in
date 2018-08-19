/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:49:07 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_library_header.h"

int		print_err_retrun_int(char *err_name, int display)
{
	if (display)
		printf("%s \n", err_name);
	return (FALSE);
}

void	*print_err_retrun_null(char *err_name, int display)
{
	if (display)
		printf("%s \n", err_name);
	return (NULL);
}
