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

t_dll_l	new_err1_link(char *name_err, int code_err, char *where_err)
{
	t_err1_link	err1_link;
	t_dll_l		link_ptr;

	err1_link = ft_0_new_memory(sizeof(t_err1_link_00));
	err1_link->code_err = code_err;
	if (name_err != NULL)
		err1_link->name_err = ft_strdup(name_err);
	if (where_err != NULL)
		err1_link->where_err = ft_strdup(where_err);
	link_ptr = new_dll_l_ptr(err1_link);
	return (link_ptr);
}

void	err1_add_err(t_err1 err1, char *name_err, int code_err, char *where_err)
{
	t_dll_l err1_link;

	err1->is_error = 1;
	err1_link = new_err1_link(name_err, code_err, where_err);
	dll_add_at_index(err1_link, err1->list_error, err1->list_error->length);
}
