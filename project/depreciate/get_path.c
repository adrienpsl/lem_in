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

/*------------------------------------*\
    va creer pour chaque connectoion de start, un finder
\*------------------------------------*/
void preparer_debut(t_data data, t_map map, t_dll list_finder, t_cache cache)
{
	(void) list_finder;
//	char *connection_start_room;
	size_t i;
	t_dll_l finder_link;

	i = 0;
//	connection_start_room = map->start + data->start_room * map->line;
	// pour tout les conenction de start
//	print_line(connection_start_room, map->line, data->start_room);

	while (i < map->line)
	{
//		if (connection_start_room[i] == TRUE)
//		{
//			finder_link = new_finder_link(data, map, i, cache);
//			if (finder_link)
//			    dll_add(finder_link, list_finder);
//		}
		++i;
	}
	/*------------------------------------*\

	\*------------------------------------*/
	(void)finder_link;(void)cache;
	finder_link = new_finder_link(data, map, 1, cache);
				if (finder_link)
				    dll_add(finder_link, list_finder);

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

void get_all_path(t_dll list_finder, t_map map, t_data data, t_cache cache)
{

	(void) list_finder;
	t_finder finder = NULL;
	(void) finder;
	//	finder = new_finder(data);
	preparer_debut(data, map, list_finder, cache);
//	print_finder(list_finder);

	// je end le premier finder
	int res = 1;

	finder = list_finder->top->content;

	t_dll_l link;

	dll_func(finder->working_path, print_path_dll_order);
	while (finder->working_path->length)
	{
		link = finder->working_path->top;
		while (link)
		{
			split_path(map, finder, link->content, &res);
			link = link->next;
		}

		dll_func(finder->new_path, print_path_dll_order);
		printf("********************** \n");

		clean_woking(finder);

		dll_func(finder->working_path, print_path_dll_order);
	}

	print_finder(list_finder);

	//	dll_func(finder->working_path, print_path_dll);
	//	dll_func(cache->working_path, print_path_link_nb);
	//	while (fill_path(finder, map))
	//	{
	//				dll_func(finder->working_path, print_path_dll);
	//		if (cache->valid_path->length >= 10)
	//			break;
	//		printf("%lu \n", cache->working_path->length);
	//	}
	//	dll_func(finder->valid_path, print_path_dll);
}