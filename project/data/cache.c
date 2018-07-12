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

void init_cache(t_cache cache, t_data data)
{
	cache->all_path = new_dll();
	cache->new_path = new_dll();
	cache->working_path = new_dll();
	cache->close_path = new_dll();
//	cache->room = data->room;
	cache->end_room = data->end_room;
}

void destroy_cache(t_cache cache)
{
	destroy_dll_func(&cache->new_path, dll_l_notfree_content);
	destroy_dll_func(&cache->close_path, dll_l_notfree_content);
	destroy_dll_func(&cache->working_path, dll_l_notfree_content);
	destroy_dll(&cache->all_path);
}

int is_close_path(t_dll_l link, void *name_end_room)
{
	t_path path;

	path = link->content;
	if (path->room == *(int *) name_end_room)
		return (TRUE);
	return (FALSE);
}

void drop_closed_path(t_dll working_path, t_dll closed_path, int name_end)
{
	t_dll_l link;

	while (dll_find_and_drop(working_path, is_close_path, &name_end, &link))
	{
		dll_add(link, closed_path);
	}
}

void clean_woking(t_cache cache)
{
	destroy_dll_func(&cache->working_path, dll_l_notfree_content);
	dll_func(cache->new_path, print_path_dll);
	drop_closed_path(cache->new_path, cache->close_path, cache->end_room);
	cache->working_path = cache->new_path;
	option_print_list(cache, cache->working_path,
					  "path en cours de recherche");
	option_print_list(cache, cache->close_path,
					  "path finish");
	cache->new_path = new_dll();
}