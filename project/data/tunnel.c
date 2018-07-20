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

int same_name(t_dll_l current_link, void *ptr)
{
	t_room room;

	room = current_link->content;
	if (ft_strcmp(room->name, ptr) == 0)
		return (TRUE);
	return (FALSE);
}

void get_max_path(t_data data, t_map map_ptr)
{
	char *map;
	int end;
	int start;
	size_t i;

	i = 0;
	map = map_ptr->start + (data->start_room * map_ptr->col);
	print_map(map, map_ptr->col);
	print_line_first(map, map_ptr->col, 1);
	end = 0;
	while (i < map_ptr->col)
	{
		if (map[i] == 1)
			end++;
		++i;
	}
	i = 0;
	map = map_ptr->start + (data->end_room * map_ptr->col);
	start = 0;
	while (i < map_ptr->col)
	{
		if (map[i] == 1)
			start++;
		++i;
	}
	data->lim = start > end ? end : start;
}

void set_tunnel(t_data data, t_map map)
{
	t_dll_l tunnel_link;
	t_tunnel tunnel;
	size_t x;
	size_t y;

	tunnel_link = data->tunnel->top;
	/*
	**    orint tunnel
	*/
	//	dll_func(data->tunnel, print_tunnel_dll);
	while (tunnel_link)
	{
		tunnel = tunnel_link->content;
		dll_index_link_func(data->room, same_name, tunnel->c_room_2, &x);
		dll_index_link_func(data->room, same_name, tunnel->c_room_1, &y);
		map->start[(y * data->room->length) + x] = 1;
		map->start[(x * data->room->length) + y] = 1;
		tunnel_link = tunnel_link->next;
	}
	get_max_path(data, map);
}

t_dll_l new_tunnel_link(char *c_room_1, char *c_room_2)
{
	t_tunnel_00 tunnel;
	t_dll_l tunnel_link = NULL;

	tunnel.c_room_1 = ft_strdup(c_room_1);
	tunnel.c_room_2 = ft_strdup(c_room_2);
	tunnel_link = new_dll_l(&tunnel, sizeof(t_tunnel_00));
	return (tunnel_link);
}

void destroy_tunnel(void *ptr_tunnel)
{
	static t_tunnel tunnel;

	tunnel = ptr_tunnel;
	free_str(&tunnel->c_room_1);
	free_str(&tunnel->c_room_2);
	free(tunnel);
}
