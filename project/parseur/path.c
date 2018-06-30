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

void print_path(t_path path)
{
	while (path)
	{
		printf("%c - ", path->room + 'A');
		path = path->prev;
	}
	printf(" \n");
}

void     print_path_dll(t_dll_l link)
{
	print_path(link->content);
}

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

void set_full(int *tab, int index)
{
	tab[index] = 1;
}

char is_full(int *tab, int index)
{
	return (tab[index]);
}

int room_is_taken(t_path path, int name)
{
	while (path)
	{
		if (name == path->room)
			return (FALSE);
		path = path->prev;
	}
	return (TRUE);
}


void binarie_line(t_map map, t_cache cache, t_path current_path, int *res)
{
	char *map_line;
	t_dll_l path_link;
	size_t i;

	map_line = map->work + (current_path->room * map->y);
	i = 0;
	*res = 0;
	//	print_line(map_line, map->y, current_path->room);
	while (i < map->y)
	{
		*res = 1;
		if (map_line[i] &&
			room_is_taken(current_path, i))
		{
			path_link = new_path_link(i, current_path, cache->all_path, 0);
			add_ptr_dll(path_link, cache->new_path);
		}
		++i;
	}
	//	print_map(map->work, map->y);
}



// filtre binaire pour tout les el de la map, convertie en path

// donner le path a tous les elements de la map

