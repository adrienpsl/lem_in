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

void init_finder(t_finder finder, t_map map)
{
	t_dll_l path_l;
	int res;

	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	split_path(map, finder, path_l->content, &res);
	clean_woking(finder);
	dll_func(finder->working_path, print_path_dll);
}

t_dll_l new_finder_link(t_data data, t_map map)
{
	t_finder finder;
	t_dll_l link;

	finder = new_finder(data);
	init_finder(finder, map);
	link = new_dll_l_ptr(finder);
	return (link);
}



/*------------------------------------*\
    va creer pour chaque connectoion de start, un finder
\*------------------------------------*/
void preparer_debut(t_data data, t_map map, t_dll list_finder)
{
	(void)list_finder;
	new_finder_link(data, map);
}

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

	(void)list_finder;
	t_finder finder;

	finder = new_finder(data);
	preparer_debut(data, map, list_finder);


	dll_func(finder->working_path, print_path_dll);
	//	dll_func(cache->working_path, print_path_link_nb);
	while (fill_path(finder, map))
	{
				dll_func(finder->working_path, print_path_dll);
		//		if (cache->close_path->length >= 10)
		//			break;
		//		printf("%lu \n", cache->working_path->length);
	}
	dll_func(finder->close_path, print_path_dll);
}