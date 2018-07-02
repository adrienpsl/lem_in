/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adpusel <adpusel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 10:48:07 by adpusel           #+#    #+#             */
/*   Updated: 2017/11/16 12:45:50 by adpusel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../all_includes.h"

t_dll_l get_dll_by_path(t_path path)
{
	t_dll path_list;
	t_dll_l link;
	t_dll_l link_path_list;

	path_list = new_dll();
	while (path)
	{
		link = new_dll_l(path, sizeof(t_path_00));
		dll_push(link, path_list);
		path = path->prev;
	}
	link_path_list = new_dll_l_ptr(path_list);
	return (link_path_list);
}

void free_list_list_path(void *list_ptr)
{
	t_dll list;

	list = list_ptr;
	destroy_dll(&list);
}

void print_list_dll_path(t_dll_l dll_path_link)
{
	t_dll list;

	list = dll_path_link->content;
	dll_func(list, print_path_link);
}

void copy_all_path_order(t_dll_l close_path_link, t_dll *dll_path_free,
 t_dll *dll_path_ptr)
{
	t_dll_l link_path_list;
	t_dll_l link_ptr;

	*dll_path_free = new_dll();
	*dll_path_ptr = new_dll();
	while (close_path_link)
	{
		link_path_list = get_dll_by_path(close_path_link->content);
		link_ptr = new_dll_l_ptr(link_path_list->content);
		dll_push(link_path_list, *dll_path_free);
		dll_push(link_ptr, dll_path_ptr);
		close_path_link = close_path_link->next;
	}
}
