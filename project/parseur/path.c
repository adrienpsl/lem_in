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

//void set_line_all_1(t_map map)
//{
//	ft_memset(map->line, )
//}


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

// filtre binaire pour la ligne de la map
/*
 * le nb de la room donnee == sa place dans le tab
 * */
void binarie_line(t_map map, t_cache cache, t_path current_path)
{
	t_tab_room map_line;
	t_dll_l path_link;
	t_tab_room current;
	char c;
	size_t i;

	map_line = map->work + (current_path->room * map->y);
	i = 0;
	print_line(map_line, map->y, current_path->room);
	while (i < map->y)
	{
		current = &map_line[i];
		c = current->link;
		if (map_line[i].link)
		{
			if (map_line[i].path == 0 && map_line[i].taken == 0)
			{
				path_link = new_path_link(i, current_path, cache->all_path, 0);
				add_ptr_dll(path_link, cache->new_path);
			}
		}
		++i;
	}
}



// filtre binaire pour tout les el de la map, convertie en path

// donner le path a tous les elements de la map

