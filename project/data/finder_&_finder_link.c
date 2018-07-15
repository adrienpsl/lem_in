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

t_finder new_finder(t_data data, int new_room_start, t_map map, t_cache cache)
{
	t_finder finder;

	finder = ft_0_new_memory(sizeof(t_finder_00));
	finder->valid_path = cache->close_path;
	finder->new_path = new_dll();
	finder->all_path = cache->all_path;
	finder->working_path = new_dll();
	finder->end_room = data->end_room;
	finder->start_room = new_room_start;
	finder->taken_room = ft_0_new_memory(sizeof(char) * map->line);
	return (finder);
}

void destroy_finder(t_finder finder)
{
	free(finder->taken_room);
	destroy_dll_func(&finder->working_path, dll_l_notfree_content);
	destroy_dll_func(&finder->new_path, dll_l_notfree_content);
	free(finder);
}

// je met start en cocher, et je get tout les link a prendre.
int init_finder(t_finder finder, t_map map)
{
	t_dll_l path_l;
	t_path path;
	int res;

	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	path = path_l->content;

	split_path(map, finder, path_l->content, &res);
	clean_woking(finder);
//	if (clean_woking(finder) == TRUE)
//	{
//		destroy_finder(finder);
//		return (FALSE);
//	}
	//	dll_func(finder->working_path, print_path_dll);
	return (TRUE);
}

t_dll_l new_finder_link(t_data data, t_map map, int new_start_room, t_cache cache)
{
	t_finder finder;
	t_dll_l link;

	// je passe le tab des connection pour trouver les chemin possible
	finder = new_finder(data, new_start_room, map, cache);

	finder->taken_room[data->start_room] = 1;
	finder->taken_room[new_start_room] = 1;
	//	print_line_first(finder->taken_room, map->line, new_start_room);
	//	print_line(map->start + new_start_room, map->line, new_start_room);

	if (init_finder(finder, map)== FALSE)
		return (NULL);
	link = new_dll_l_ptr(finder);
	return (link);
}