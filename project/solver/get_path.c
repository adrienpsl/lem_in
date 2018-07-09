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


/*------------------------------------*\
    va faire un cache pour chaque list
\*------------------------------------*/
void preparer_debut(t_finder cache, t_map map)
{
	t_dll_l path_l;
	int res;

	path_l = new_path_link(cache->start_room, NULL, cache->all_path, 0);
	split_path(map, cache, path_l->content, &res);
	clean_woking(cache);
	dll_func(cache->working_path, print_path_dll);
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

void get_all_path(t_finder cache, t_map map)
{
	preparer_debut(cache, map);
	dll_func(cache->working_path, print_path_dll);
	//	dll_func(cache->working_path, print_path_link_nb);
	while (fill_path(cache, map))
	{
				dll_func(cache->working_path, print_path_dll);
		//		if (cache->close_path->length >= 10)
		//			break;
		//		printf("%lu \n", cache->working_path->length);
	}
	dll_func(cache->close_path, print_path_dll);
}