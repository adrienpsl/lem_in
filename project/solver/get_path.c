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

int option_print_list(t_finder cache, t_dll list, char *explain)
{

	if (cache->option == TRUE && list->length)
	{
		printf("%s \n", explain);
		printf("--------------------------------------------- \n");
		dll_func(list, print_path_dll);
	}
	return (TRUE);
}

// je met start en cocher, et je get tout les link a prendre.
void init_finder(t_finder finder, t_map map)
{
	t_dll_l path_l;
	t_path path;
	int res;

	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	path = path_l->content;

	split_path(map, finder, path_l->content, &res);
	clean_woking(finder);
	dll_func(finder->working_path, print_path_dll);
}

t_dll_l new_finder_link(t_data data, t_map map, int new_start_room)
{
	t_finder finder;
	t_dll_l link;

	// je passe le tab des connection pour trouver les chemin possible
	finder = new_finder(data, new_start_room, map);
	finder->taken_room[data->start_room] = 1;
	print_line(map->start + new_start_room, map->line, new_start_room);
	print_line(finder->taken_room, map->line, new_start_room);

	init_finder(finder, map);
	link = new_dll_l_ptr(finder);
	return (link);
}

/*------------------------------------*\
    va creer pour chaque connectoion de start, un finder
\*------------------------------------*/
void preparer_debut(t_data data, t_map map, t_dll list_finder)
{
	(void) list_finder;
	char *connection_start_room;
	size_t i;

	i = 0;
	connection_start_room = map->start + data->start_room * map->line;
	// pour tout les conenction de start
	print_line(connection_start_room, map->line, data->start_room);

	while (i < map->line)
	{
		if (connection_start_room[i] == TRUE)
			new_finder_link(data, map, i);
		++i;
	}
}

size_t fill_path(t_finder cache, t_map map)
{
	t_dll_l current_work;
	int res;

	current_work = cache->working_path->top;
	while (current_work)
	{
		split_path(map, cache, current_work->content, &res);
		current_work = current_work->next;
		if (res == 0)
			dll_drop_link(cache->working_path, current_work->prev);
	}
	clean_woking(cache);
	return (cache->working_path->length);
}

void get_all_path(t_dll list_finder, t_map map, t_data data)
{

	(void) list_finder;
	t_finder finder = NULL;
	(void) finder;
	//	finder = new_finder(data);
	preparer_debut(data, map, list_finder);


	//	dll_func(finder->working_path, print_path_dll);
	//	dll_func(cache->working_path, print_path_link_nb);
	//	while (fill_path(finder, map))
	//	{
	//				dll_func(finder->working_path, print_path_dll);
	//		if (cache->close_path->length >= 10)
	//			break;
	//		printf("%lu \n", cache->working_path->length);
	//	}
	//	dll_func(finder->close_path, print_path_dll);
}