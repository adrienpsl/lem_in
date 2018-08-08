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

#include "../../all_includes.h"

/*------------------------------------*\
    il me faut : le tab des taken room,
    les trois liste pour gerer le cache
    la liste pour tout free

\*------------------------------------*/


/*!
 *
 * @param data  permet fafas  d
 * @param start_rom  adasfd
 * @param map  a
 * @param cache
 * @return
 */
t_finder
new_finder_big_algo(t_data data, t_map map)
{
	t_finder finder;

	finder = ft_0_new_memory(sizeof(t_finder_00));
	(void)" manage le cache ";
	finder->all_path = new_dll();
	finder->new_path = new_dll();
	finder->working_path = new_dll();
	(void)"  autres reglage  ";
	finder->start_room = data->start_room;
	finder->end_room = data->end_room;
	finder->taken_room = ft_0_new_memory(sizeof(char) * map->line);
	return (finder);
}

// function pour get generer tout les paths
// je garde
size_t split_all_path_big(t_finder finder/*, t_map map*/)
{
	char *taken_room;
//	t_dll_l cur_working_link;

	taken_room = finder->taken_room;
	return (TRUE);
}


// get les x chemin possible les plus cours
// il me faut que je prenne toujour le chemin en haut a gauche ?
// je regarde le nombre de chemin qui passe par la room ?


//	je repend le principe du cache,
// 	while working path
// 		stack --> working path, tout les chemin avancent d'une case
// 				en verifiant que la room n'est pas prise et que
t_move big_algo(t_data data, t_map map)
{
	t_finder finder;


	finder = new_finder_big_algo(data, map);
	init_finder(finder, map);
	//	t_map  path_map;
	//	t_move  move;
	return (NULL);

}
