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

t_path new_path(int size, t_path prev_path, t_room room, t_dll all_path)
{
	t_path path;
	t_dll_l path_link;

	path = ft_malloc_protect(sizeof(t_path_00));
	path->size = size;
	path->prev = prev_path;
	path->room = room;
	path_link = new_dll_l_ptr(path);
	dll_add(path_link, all_path);
	return (path);
}

void destroy_path(t_path path)
{
	if (path)
		free(path);
}

void print_path(t_path path)
{
	print_room(path->room);
}

void print_path_list(t_path path)
{
	while (path)
	{
		print_path(path);
		path = path->prev;
	}
}