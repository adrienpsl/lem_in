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

t_move algo(t_cache cache, t_data data, t_map map)
{
	t_finder finder;
	t_map path_map;
	t_best_path best;
	t_dll_l path_l;

	finder = new_finder(data, data->start_room, map, cache);

	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	split_path(map, finder, path_l->content);
	clean_woking(finder);

	/*------------------------------------*\
	    cherche les path
	\*------------------------------------*/
	if (DEBUG->little == TRUE ||
		split_all_path(finder, map) == FALSE
	 )
		finder = shorty_baby(cache, data, map);

	if (finder->valid_path->length == 0)
	{
		printf("no solution \n");
		return (NULL);
	}
	// si return false --> faire :

	/*------------------------------------*\
	    genere la map des path
	\*------------------------------------*/
	path_map = generate_path_map(data->room, finder->valid_path);

	/*------------------------------------*\
	    trie les path
	\*------------------------------------*/
	best = new_best_path(path_map->line);
	find_best_path(path_map, best);
	return (new_move(data, &best->data, finder));
}
