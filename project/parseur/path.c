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

void set_full(int *tab, int index)
{
	tab[index] = 1;
}

char is_full(int *tab, int index)
{
	return (tab[index]);
}

void set_taken(int x, int y, t_tab_room tab_room, int map_y)
{
	t_tab_room tmp;
	int a;

	a = x * map_y;
	tmp = tab_room + a;
	tmp[y].taken = 1;

	a = y * map_y;
	tmp = tab_room + a;
	tmp[x].taken = 1;
}




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
		c = i + 'A';
		if (is_full(cache->is_full, i) == FALSE && map_line[i].link)
		{
//			print_map_taken(map->work, map->y);
			if (map_line[i].path == 0 && map_line[i].taken == 0)
			{
				set_taken(i, , map->work, map->y);
				set_full(cache->is_full, i);
				path_link = new_path_link(i, current_path, cache->all_path, 0);
				add_ptr_dll(path_link, cache->new_path);
				debug_print_tab_nb(cache->is_full, map->y);
			}
//			print_map_taken(map->work, map->y);
		}
		++i;
	}
//	print_map_taken(map->work, map->y);
}



// filtre binaire pour tout les el de la map, convertie en path

// donner le path a tous les elements de la map

