/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_l_construct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2018/05/04 16:31:01 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../ft_library_header.h"

t_err1	new_err1(void)
{
	t_err1 err1;

	err1 = ft_0_new_memory(sizeof(t_err1_00));
	err1->list_error = new_dll();
	return (err1);
}

void	destroy_err1_link(void *err1_link_ptr)
{
	t_err1_link err1_link;

	err1_link = err1_link_ptr;
	free_str(&err1_link->where_err);
}

void	destroy_err1(t_err1 err1)
{
	destroy_dll_func(&err1->list_error, &destroy_err1_link);
	free(err1);
}
