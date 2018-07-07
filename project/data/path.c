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

t_dll_l new_path_link(int room, t_path prev, t_dll all_path, int size)
{
	t_path_00 path;
	t_dll_l link;

	path.room = room;
	path.prev = prev;
	path.size = size;
	link = new_dll_l(&path, sizeof(t_path_00));
	dll_add(link, all_path);
	return (link);
}

void add_ptr_dll(t_dll_l link, t_dll list)
{
	t_dll_l ptr_link;

	ptr_link = new_dll_l_ptr(link->content);
	dll_add(ptr_link, list);
}

int has_taken_this_room(t_path path, int name)
{
	while (path)
	{
		if (name == path->room)
			return (FALSE);
		path = path->prev;
	}
	return (TRUE);
}


void split_path(t_map map, t_cache cache, t_path current_path, int *res)
{
	char *map_line;
	t_dll_l path_link;
	size_t i;

	map_line = map->start + (current_path->room * map->col);
	i = 0;
	*res = 0;
	while (i < map->col)
	{
		*res = 1;
		if (map_line[i] &&
			has_taken_this_room(current_path, i))
		{
			path_link = new_path_link(i, current_path, cache->all_path,
									  current_path->size + 1);
			add_ptr_dll(path_link, cache->new_path);
		}
		++i;
	}
}
