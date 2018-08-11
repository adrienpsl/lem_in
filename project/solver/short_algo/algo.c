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

t_move short_algo(t_cache cache, t_data data, t_map map)
{
	t_finder finder;
	t_map path_map;
	t_best_path best;
	t_move move = NULL;
	t_dll_l path_l;

	finder = new_finder(data, data->start_room, map, cache);

	path_l = new_path_link(finder->start_room, NULL, finder->all_path, 0);
	split_path(map, finder, path_l->content);
	clean_woking(finder);

	/*------------------------------------*\
	    cherche les path
	\*------------------------------------*/
	split_all_path(finder, map);

	/*------------------------------------*\
	    genere la map des path
	\*------------------------------------*/
	path_map = generate_path_map(data->room, finder->valid_path);

	/*------------------------------------*\
	    trie les path
	\*------------------------------------*/
	best = new_best_path(path_map->line);
	find_best_path(path_map, best);

//	dll_func(finder->valid_path, print_path_dll);
	//	print_line_first_int(best->data.tab, path_map->line, 0);

	move = new_move(data, &best->data, finder);
	/*------------------------------------*\
	    init et return move pour lancer le move des fourmis
	\*------------------------------------*/
	//	t_real_path move = new_real_path();
	//	move->tab_best_path = best->data.tab;

	return (move);
}
