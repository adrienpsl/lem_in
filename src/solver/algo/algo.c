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

#include "../../includes/all_includes.h"

void *destroy_finder(t_finder finder)
{
	free(finder->taken_room);
	destroy_dll_func(&finder->working_path, dll_l_notfree_content);
	destroy_dll_func(&finder->new_path, dll_l_notfree_content);
	free(finder);
	return (NULL);
}

//static t_move algo_end(t_move move, t_map map, t_finder finder)
//{
//
//	destroy_map(map);
//	destroy_finder(finder);
//	return (move);
//}

t_move is_solution(t_finder finder, t_data data)
{
	t_move move;
	t_map path_map;
	t_best_path best;

	move = NULL;

	path_map = generate_path_map(data->room, finder->valid_path);
	//	/*------------------------------------*\
//	    trie les path
	//	\*------------------------------------*/
	best = new_best_path(path_map->line);
	find_best_path(path_map, best);
	//	return (new_move(data, &best->data, finder));

	free_str(&best->cache.tab);
	free_str(&best->data.tab);
	free(best);
	destroy_map(path_map);
	return (move);
}

t_move algo(t_cache cache, t_data data, t_map map)
{
	t_finder finder;

	t_dll_l path_l;
	(void) path_l;

	finder = new_finder(data, data->start_room, map, cache);

	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	split_path(map, finder, path_l->content);
	clean_woking(finder);
	destroy_dll_l_func(&path_l, dll_l_notfree_content);
	/*------------------------------------*\
		cherche les path
	\*------------------------------------*/
	if (DEBUG->little == TRUE ||
		split_all_path(finder, map) == FALSE
	 )
	{
		split_all_path(finder, map);
		destroy_finder(finder);
		finder = shorty_baby(cache, data, map);
	}

	if (finder->valid_path->length > 0)
	{
		is_solution(finder, data);
	}
	destroy_finder(finder);

	return (NULL);
}
